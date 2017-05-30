/*
 * PFC_Control.c
 *
 *  Created on: April 21, 2017
 *      Author: tqnam
 */


#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File



void PFC_ADC_result(void);
void RMS_Calculation(void);
void PFC_Init(void);
void PFC_DC_Voltage_Control(void);
void PFC_Current_Control(void);




//ADC measurement gains

#define kVac    0.134310            //gain = 4095/3.3*(3V/500V)
#define kVdc    0.134310            //gain = 4095/3.3*(3V/500V)
#define kIac    0.0075428           //gain = 4095/3.3*(2.5V/23.4V)

#define kV_Inv  0.134310            //gain = 4095/3.3*(3V/500V)
#define kI_Inv  0.02442            //gain = 4095/3.3*(3.3V/100A)


#define CLOSE_NTC_RELAY     GpioDataRegs.GPASET.bit.GPIO27 = 1
#define OPEN_NTC_RELAY      GpioDataRegs.GPACLEAR.bit.GPIO27 = 1

#define NTC_RELAY_STATUS    GpioDataRegs.GPBDAT.bit.GPIO61



float Ts = 0.00001538;           //sampling time = 1/65kHz

//PI controller gains for Vdc, Iac control

float PFC_Vdc_ref = 0, IS_ref = 0, Iac_ref;
float Vac_peak = 325;
float PFC_KpVdc = 0.2, PFC_KiVdc = 50;           //PI VOLTAGE CONTROL LOOP
float KpIac = 40, KiIac = 10;          //PI CURRENT CONTROL LOOP
float Err_Vdc, Err_Vdc1;
float Err_Isa, Err_Isa1;
float PFC_Pwm = 0, PFC_VloopCtr = 0;
Uint16 PFC_PWM_Period = 692;
float PFC_Ctrl_Limit = 50;



//PFC measurements

float PFC_Vac_ADC, PFC_Iac_ADC, PFC_Vdc_ADC;

float PFC_Vac, PFC_Iac, PFC_Vdc;

float Vac_offset = 0, Iac_offset = 0, Vdc_offset = 0;


//RMS value calculation

float Vac_RMS = 0, Iac_RMS = 0;

float Sum_Vac = 0, Sum_Iac = 0;

Uint16 RMS_Cnt = 0;

Uint16 RMS_Cnt_Max = 1300;

float RMS_Cnt_Max_Invserve = 0.000769;

float Pin_avg = 0;




//Low pass filter

float Vdc_LPF = 0;      //Low pass filter of DC bus voltage Vdc

float PFC_Vdc1 = 0;


//Status and flag

long    temp_zero;

int     init_boost;     // Small boost command when PFC is enabled the first time

int16   start_flag, pfc_on_flag, Soft_Start_Phase, OV_flag, flag_NL_Vloop;//Set NL Vloop flag for NL Vloop Control








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


        //VDC_LPF = 0.99748988*VDC_LPF + 0.0012550599*(VDC + VDC1);     //30Hz at 50kHz


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


        //error_v=0;

        //pfc_slew_temp = 0;

        start_flag = 1;//initialize to 1 for standalone start-up when min Vbus volt is established.
                        //Init to 0 when starting from CCS watch window.
        pfc_on_flag = 0;

        Soft_Start_Phase = 0;

        temp_zero = 0;

        //disable_auto_cloop_coeff_change = 0;//0 => Auto coeff update enabled, 1=> auto coeff update disabled

        flag_NL_Vloop=0;//Enable/disable flag for NL voltage loop control. 1=>Enable NL Vot Loop, 0=>disable NL V Loop


}





void PFC_DC_Voltage_Control(void)
{


            Err_Vdc1 = Err_Vdc;


            Err_Vdc = PFC_Vdc_ref - Vdc_LPF;


            IS_ref = IS_ref + PFC_KpVdc*(Err_Vdc - Err_Vdc1) + PFC_KiVdc*Err_Vdc*Ts;


            if(IS_ref > 22)     //22A peak ~ 15A rms
            {
                IS_ref = 22;
            }
            else if(IS_ref < 0)
            {
                IS_ref = 0;

            }

}


void PFC_Current_Control(void)
{

            //IS_ref = 25;


            Iac_ref = IS_ref*PFC_Vac/Vac_peak;      //input current reference


            Err_Isa1 = Err_Isa;

            Err_Isa = Iac_ref - PFC_Iac;


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


            EPwm7Regs.CMPA.half.CMPA = PFC_Pwm;


}
