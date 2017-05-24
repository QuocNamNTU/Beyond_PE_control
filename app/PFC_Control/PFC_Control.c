
//###########################################################################

// FILE:   PFC_Control.c

// TITLE:  PFC Control Functions

//Last update  23/05/2017

//###########################################################################

//###########################################################################


#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File




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

float PWM_PFC = 0, V_CTRL = 0;

Uint16 PFC_PWM_Period = 692;

float Limit = 50;



//PFC measurements

Uint16 Vac_ADC, Iac_ADC, Vdc_ADC;

float PFC_Vac, PFC_Iac, PFC_Vdc;

float Vac_OFFSET, Iac_OFFSET, Vdc_OFFSET;


//Low pass filter

float VDC_LPF = 0;

float PFC_Vdc1 = 0;




void ADC_result(void)
{

        //Input AC voltage

        Vac_ADC = AdcResult.ADCRESULT0;

        PFC_Vac = (Vac_ADC - Vac_OFFSET)*kVac;          //Rectifier voltage

        //Input AC current

        Iac_ADC = AdcResult.ADCRESULT1;

        PFC_Iac = (Iac_ADC - Iac_OFFSET)*kIac;          //Rectifier current

        //Output DC voltage

        Vdc_ADC = AdcResult.ADCRESULT2;

        PFC_Vdc = (Vdc_ADC - Vdc_OFFSET)*kVdc;          //Output DC voltage




        //Low-pass filter for Vdc


        //VDC_LPF = 0.99748988*VDC_LPF + 0.0012550599*(VDC + VDC1);     //30Hz at 50kHz


        VDC_LPF = 0.99731083*VDC_LPF + 0.0013445865*(PFC_Vdc + PFC_Vdc1);       //30Hz at 70kHz


        PFC_Vdc1 = PFC_Vdc;


}


void PFC_Control(void)
{


            Err_Vdc1 = Err_Vdc;


            Err_Vdc = Vdc_ref - VDC_LPF;


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




            Iac_ref = IS_ref*PFC_Vac/Vac_peak;      //input current reference


            Err_Isa1 = Err_Isa;

            Err_Isa = Iac_ref - PFC_Iac;


            V_CTRL = V_CTRL + KpIac*(Err_Isa - Err_Isa1) + KiIac*Err_Isa*Ts;


            if(V_CTRL > Limit)
            {
                V_CTRL = Limit;
            }
            else if(V_CTRL < -Limit)
            {
                V_CTRL = -Limit;
            }



            PWM_PFC = V_CTRL + PFC_PD*(1 - PFC_Vac/Vdc_ref);


            if(PWM_PFC > PFC_PD)
            {
                PWM_PFC = PFC_PD;
            }
            else if(PWM_PFC < 0)
            {
                PWM_PFC = 0;
            }


            EPwm7Regs.CMPA.half.CMPA = PWM_PFC;


}
