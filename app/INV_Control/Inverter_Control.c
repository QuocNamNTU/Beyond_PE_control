/*
 * Inverter_Control.c
 *
 *  Created on: May 14, 2017
 *      Author: tqnam
 */



#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File


void INV_PWM_Setting(Uint16 System_CLk, Uint16 fsw_INV);
void INV_Init(void);

//ADC measurement gains

#define kV_Inv  0.134310            //gain = 4095/3.3*(3V/500V)
#define kI_Inv  0.02442            //gain = 4095/3.3*(3.3V/100A)




void INV_PWM_Setting(Uint16 System_CLk, Uint16 fsw_INV)     //Update Inverter PWM frequency at kHz
{

        Uint16 temp;

        temp = System_CLk*0.5/fsw_INV;


        EALLOW;
        SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;      // Stop all the TB clocks
        EDIS;

        EPwm1Regs.TBPRD = temp; // Period = ??? TBCLK counts      //350Khz

        EPwm2Regs.TBPRD = temp; // Period = ??? TBCLK counts      //350Khz


        EALLOW;
        SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;      // Stop all the TB clocks
        EDIS;


        //Set PWM duty cycle = 50%

        EPwm1Regs.CMPA.half.CMPA = temp*0.5;

        EPwm2Regs.CMPA.half.CMPA = temp*0.5;

}



void INV_Init(void)
{



}
