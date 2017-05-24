
//###########################################################################

// FILE:   PFC_Control.c

// TITLE:  PFC Control Functions

//Last update  23/05/2017

//###########################################################################

//###########################################################################


#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File



void RMS_Calculation(void);


#define Ts      0.00001538;           //sampling time = 1/65kHz

//ADC measurement gains

#define kVac    0.134310            //gain = 4095/3.3*(3V/500V)

#define kVdc    0.134310            //gain = 4095/3.3*(3V/500V)

#define kIac    0.0075428           //gain = 4095/3.3*(2.5V/23.4V)


#define kV_Inv  0.134310            //gain = 4095/3.3*(3V/500V)

#define kI_Inv  0.02442            //gain = 4095/3.3*(3.3V/100A)



//PI controller gains for Vdc, Iac control

float Vdc_ref = 0, IS_ref = 0, Iac_ref;

float Vac_peak = 325;

float KpVdc = 0.2, KiVdc = 50;           //PI VOLTAGE CONTROL LOOP

float KpIac = 40, KiIac = 10;          //PI CURRENT CONTROL LOOP

float Err_Vdc, Err_Vdc1;

float Err_Isa, Err_Isa1;

float PFC_Pwm = 0, VloopCtr = 0;

Uint16 PFC_PWM_Period = 692;

float Limit = 50;



//PFC measurements

Uint16 Vac_ADC, Iac_ADC, Vdc_ADC;

float PFC_Vac_fb, PFC_Iac_fb, PFC_Vdc_fb;

float Vac_offset, Iac_offset, Vdc_offset;


//RMS value calculation

float Vac_RMS = 0, Iac_RMS = 0;

float Sum_Vac = 0, Sum_Iac = 0;

Uint16 RMS_Cnt = 0;

Uint16 RMS_Cnt_Max = 1300;

float RMS_Cnt_Max_Invserve = 0.000769;

float Pac_avg = 0;




//Low pass filter

float Vdc_LPF = 0;      //Low pass filter of DC bus voltage Vdc

float PFC_Vdc1 = 0;


//Status and flag

long    temp_zero;

int     init_boost;     // Small boost command when PFC is enabled the first time

int16   start_flag, pfc_on_flag, Soft_Start_Phase, OV_flag, flag_NL_Vloop;//Set NL Vloop flag for NL Vloop Control






void ADC_result(void)
{

        //Input AC voltage

        Vac_ADC = AdcResult.ADCRESULT0;

        PFC_Vac_fb = (Vac_ADC - Vac_offset)*kVac;          //Rectifier voltage

        //Input AC current

        Iac_ADC = AdcResult.ADCRESULT1;

        PFC_Iac_fb = (Iac_ADC - Iac_offset)*kIac;          //Rectifier current

        //Output DC voltage

        Vdc_ADC = AdcResult.ADCRESULT2;

        PFC_Vdc_fb = (Vdc_ADC - Vdc_offset)*kVdc;          //Output DC voltage




        //Low-pass filter for Vdc


        //VDC_LPF = 0.99748988*VDC_LPF + 0.0012550599*(VDC + VDC1);     //30Hz at 50kHz


        Vdc_LPF = 0.99731083*Vdc_LPF + 0.0013445865*(PFC_Vdc_fb + PFC_Vdc1);       //30Hz at 70kHz


        PFC_Vdc1 = PFC_Vdc_fb;


        RMS_Calculation();      //RMS value of AC voltage and current


}



void RMS_Calculation(void)
{

        Sum_Vac = Sum_Vac + PFC_Vac_fb;

        Sum_Iac = Sum_Iac + PFC_Iac_fb;

        RMS_Cnt++;

        if(RMS_Cnt == RMS_Cnt_Max)
        {

            Vac_RMS = Sum_Vac*RMS_Cnt_Max_Invserve;

            Iac_RMS = Sum_Iac*RMS_Cnt_Max_Invserve;

            RMS_Cnt = 0;

            Sum_Vac = 0;

            Sum_Iac = 0;

            Pac_avg = Vac_RMS*Iac_RMS;

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





void PFC_Control(void)
{


            Err_Vdc1 = Err_Vdc;


            Err_Vdc = Vdc_ref - Vdc_LPF;


            IS_ref = IS_ref + KpVdc*(Err_Vdc - Err_Vdc1) + KiVdc*Err_Vdc*Ts;


            if(IS_ref > 22)     //22A peak ~ 15A rms
            {
                IS_ref = 22;
            }
            else if(IS_ref < 0)
            {
                IS_ref = 0;

            }




            //IS_REF = 25;




            Iac_ref = IS_ref*PFC_Vac_fb/Vac_peak;      //input current reference


            Err_Isa1 = Err_Isa;

            Err_Isa = Iac_ref - PFC_Iac_fb;


            VloopCtr = VloopCtr + KpIac*(Err_Isa - Err_Isa1) + KiIac*Err_Isa*Ts;


            if(VloopCtr > Limit)
            {
                VloopCtr = Limit;
            }
            else if(VloopCtr < -Limit)
            {
                VloopCtr = -Limit;
            }



            PFC_Pwm = VloopCtr + PFC_PWM_Period*(1 - PFC_Vac_fb/Vdc_ref);


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
