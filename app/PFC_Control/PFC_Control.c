/*
 * PFC_Control.c
 *
 *  Created on: April 22, 2017
 *      Author: tqnam
 */


#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File
#include "Main.h"

extern float Ts;           //sampling time = 1/65kHz

//PFC measurements
float PFC_Vac_ADC, PFC_Iac_ADC, PFC_Vdc_ADC;
float Vac_offset = 0, Iac_offset = 0, Vdc_offset = 0;

//PI controller gains for Vdc, Iac control
float Vac_peak = 325;
float PFC_KpVdc = 0.2, PFC_KiVdc = 50;           //PI VOLTAGE CONTROL LOOP
float KpIac = 40, KiIac = 10;          //PI CURRENT CONTROL LOOP
float Err_Vdc, Err_Vdc1;
float Err_Isa, Err_Isa1;
float PFC_Pwm = 0, PFC_VloopCtr = 0;
float PFC_Ctrl_Limit = 50;
//float current_ref = 0;

//RMS calculation
float Sum_Vac = 0, Sum_Iac = 0;
Uint16 RMS_Cnt = 0;
Uint16 RMS_Cnt_Max = 1300;
float RMS_Cnt_Max_Invserve = 0.000769;

//PFC variables
float PFC_Vac, PFC_Iac, PFC_Vdc;
extern float PFC_Vdc_ref, PFC_Vdc_ref_target;
float Is_ref, Iac_ref;
float Vac_RMS, Iac_RMS;
float Pin_avg = 0;

//Low pass filter
float Vdc_LPF;      //Low pass filter of DC bus voltage Vdc
float PFC_Vdc1;

//Status and flag
int PFC_operation_flag = 0;
int PFC_1st_start_up = 0;


void PFC_ADC_result(void)
{
    //Input AC voltage
    PFC_Vac_ADC = AdcResult.ADCRESULT0;
    PFC_Vac = (PFC_Vac_ADC - Vac_offset)*kVac;          //Rectifier voltage

    //Input AC current
    PFC_Iac_ADC = AdcResult.ADCRESULT1;
    PFC_Iac = (PFC_Iac_ADC - Iac_offset)*kIac;          //Rectifier current

    //Output DC voltage
    PFC_Vdc_ADC = AdcResult.ADCRESULT2;
    PFC_Vdc = (PFC_Vdc_ADC - Vdc_offset)*kVdc;          //Output DC voltage


    //Low-pass filter for Vdc
    Vdc_LPF = 0.99731083*Vdc_LPF + 0.0013445865*(PFC_Vdc + PFC_Vdc1);       //30Hz at 70kHz

    PFC_Vdc1 = PFC_Vdc;

    RMS_Calculation();      //RMS value of AC voltage and current

}



void RMS_Calculation(void)
{
    Sum_Vac = Sum_Vac + PFC_Vac*PFC_Vac;

    Sum_Iac = Sum_Iac + PFC_Iac*PFC_Iac;

    RMS_Cnt++;

    if(RMS_Cnt == RMS_Cnt_Max)
    {
        Vac_RMS = Sum_Vac*RMS_Cnt_Max_Invserve;

        Iac_RMS = Sum_Iac*RMS_Cnt_Max_Invserve;

        RMS_Cnt = 0;

        Sum_Vac = 0;

        Sum_Iac = 0;

        Pin_avg = Vac_RMS*Iac_RMS;
    }

}


void PFC_Init(void)
{

    PFC_Vdc_ref = 0;            //
    PFC_Vdc_ref_target = 0;
    PFC_PWM = 0;
    OPEN_NTC_RELAY();
    GREEN_LED_OFF();
    PFC_operation_flag = 0;
    PFC_1st_start_up = 0;

}


void Turn_off_PFC(void)
{
    PFC_Vdc_ref = 0;            //
    PFC_Vdc_ref_target = 0;
    PFC_PWM = 0;
    OPEN_NTC_RELAY();
    GREEN_LED_OFF();
    PFC_operation_flag = 0;
    PFC_1st_start_up = 0;
}



float Votage_Ramp(float current_voltage, float target_voltage)
{
    float temp;

    if(current_voltage < target_voltage)        //Ramp up
    {
        current_voltage = current_voltage + Ramp_rate*Ts;
    }
    else if(current_voltage > target_voltage)    //Ramp down
    {
        current_voltage = current_voltage + Ramp_rate*Ts;
    }

    temp = current_voltage;

    return temp;

}



float PFC_DC_Voltage_Control(float voltage_ref, float voltage_fb)
{

    float current_ref;

    Err_Vdc1 = Err_Vdc;


    Err_Vdc = voltage_ref - voltage_fb;


    Is_ref = Is_ref + PFC_KpVdc*(Err_Vdc - Err_Vdc1) + PFC_KiVdc*Err_Vdc*Ts;


    if(Is_ref > 22)     //22A peak ~ 15A rms
    {
        Is_ref = 22;
    }
    else if(Is_ref < 0)
    {
        Is_ref = 0;

    }

    current_ref = Is_ref;


    return current_ref;

}


Uint16 PFC_Current_Control(float current_ref, float current_fb)
{

    //current_ref = 25;

    Uint16 PWM_out;


    Iac_ref = current_ref*PFC_Vac/Vac_peak;      //input current reference
                                                 //Reference current is generated according to shape of input voltage


    Err_Isa1 = Err_Isa;

    Err_Isa = Iac_ref - current_fb;


    PFC_VloopCtr = PFC_VloopCtr + KpIac*(Err_Isa - Err_Isa1) + KiIac*Err_Isa*Ts;


    if(PFC_VloopCtr > PFC_Ctrl_Limit)
    {
        PFC_VloopCtr = PFC_Ctrl_Limit;
    }
    else if(PFC_VloopCtr < -PFC_Ctrl_Limit)
    {
        PFC_VloopCtr = -PFC_Ctrl_Limit;
    }



    PFC_Pwm = PFC_VloopCtr + PFC_PWM_Period*(1 - PFC_Vac/PFC_Vdc_ref);       //add supply voltage feed-forward term


    if(PFC_Pwm > PFC_PWM_Period)
    {
        PFC_Pwm = PFC_PWM_Period;
    }
    else if(PFC_Pwm < 0)
    {
        PFC_Pwm = 0;
    }


    PWM_out = (Uint16)PFC_Pwm;

    return PWM_out;


    //EPwm7Regs.CMPA.half.CMPA = PFC_Pwm;


}
