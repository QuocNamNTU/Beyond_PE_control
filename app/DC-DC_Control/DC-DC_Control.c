/*
 * DC-DC_Control.c
 *
 *  Created on: May 13, 2017
 *      Author: tqnam
 */


#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File
#include "Main.h"


extern float Ts;           //sampling time = 1/65kHz

//DC-DC measurements

float DCDC_Vin_ADC, DCDC_Iout_ADC, DCDC_Vout_ADC;
float DCDC_Vin_offset = 0, DCDC_Iout_offset = 0, DCDC_Vout_offset= 0;

//PI controller gains for Vdc control
//float DCDC_Vout_ref = 0;
float DCDC_KpVdc = 0.2, DCDC_KiVdc = 50;           //PI VOLTAGE CONTROL LOOP
float DCDC_Err_Vdc, DCDC_Err_Vdc1;
float DCDC_Pwm = 0, DCDC_VloopCtr = 0;
float DCDC_Ctrl_Limit = 100;


//DCDC variables
float DCDC_Vin, DCDC_Iout, DCDC_Vout;
int DCDC_operation_flag;

//Low pass filter
extern float Vdc_LPF;      //Low pass filter of DC bus voltage Vdc

void DCDC_ADC_result(void)
{

    //Input AC voltage

    DCDC_Vin_ADC = AdcResult.ADCRESULT4;

    DCDC_Vin = (DCDC_Vin_ADC - DCDC_Vin_offset)*kV_DCDC;          //DCDC Input voltage

    //Input AC current

    DCDC_Vout_ADC = AdcResult.ADCRESULT5;

    DCDC_Vout = (DCDC_Vout_ADC - DCDC_Iout_offset)*kI_DCDC;          //DCDC output current

    //Output DC voltage

    DCDC_Iout_ADC = AdcResult.ADCRESULT5;

    DCDC_Iout = (DCDC_Iout_ADC - DCDC_Vout_offset)*kV_DCDC;          //DCDC Output DC voltage



}



void DCDC_Init(void)
{

    DCDC_PWM = 0;

    DCDC_operation_flag = 0;


}



Uint16 DCDC_Voltage_Control(float voltage_ref,float voltage_fb)
{

    Uint16 PWM_out;

    DCDC_Err_Vdc1 = DCDC_Err_Vdc;


    DCDC_Err_Vdc = voltage_ref - voltage_fb;


    DCDC_VloopCtr = DCDC_VloopCtr + DCDC_KpVdc*(DCDC_Err_Vdc - DCDC_Err_Vdc1) + DCDC_KiVdc*DCDC_Err_Vdc*Ts;


    if(DCDC_VloopCtr > DCDC_Ctrl_Limit)
    {
        DCDC_VloopCtr = DCDC_Ctrl_Limit;
    }
    else if(DCDC_VloopCtr < -DCDC_Ctrl_Limit)
    {
        DCDC_VloopCtr = -DCDC_Ctrl_Limit;
    }


    DCDC_Pwm = DCDC_VloopCtr + DCDC_PWM_Period*voltage_ref/Vdc_LPF;             //add Vout/Vin feed-forward term


    if(DCDC_Pwm > DCDC_PWM_Period)
    {
        DCDC_Pwm = DCDC_PWM_Period;
    }
    else if(DCDC_Pwm < 0)
    {
        DCDC_Pwm = 0;
    }


    PWM_out = (Uint16)DCDC_Pwm;

    return PWM_out;

    //EPwm4Regs.CMPA.half.CMPA = DCDC_Pwm;

}
