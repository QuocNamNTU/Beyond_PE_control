/*
 * Inverter_Control.c
 *
 *  Created on: May 14, 2017
 *      Author: tqnam
 */



#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File
#include "Main.h"


extern float k_est;         //coupling factor k estimate



void INV_Init(void)
{


}


void INV_PWM_Set(Uint16 fsw_INV)     //Update Inverter PWM frequency at kHz
{

    Uint16 pwm_write, pwm_read;

    pwm_write = 45000/fsw_INV;       //45 Mhz/fsw

    pwm_read = EPwm1Regs.TBPRD;

    if(pwm_write != pwm_read)         //if current fsw is different from new fsw set value
    {

    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;      // Stop all the TB clocks
    EDIS;

    EPwm1Regs.TBPRD = pwm_write; // Period = ??? TBCLK counts      //350Khz

    EPwm2Regs.TBPRD = pwm_write; // Period = ??? TBCLK counts      //350Khz


    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;      // Stop all the TB clocks
    EDIS;


    //Set PWM duty cycle = 50%

    EPwm1Regs.CMPA.half.CMPA = pwm_write*0.5;

    EPwm2Regs.CMPA.half.CMPA = pwm_write*0.5;

    }

}



int Range_Selection(float voltage)
{

    int temp;

    if(voltage > Voltage_1_Lower_Limit)
    {
        temp = 1;
    }
    else if((voltage > Voltage_2_Lower_Limit)&&(voltage < Voltage_2_Upper_Limit))
    {
        temp = 2;
    }
    else if((voltage > Voltage_3_Lower_Limit)&&(voltage < Voltage_3_Upper_Limit))
    {
        temp = 3;
    }
    else if((voltage > Voltage_4_Lower_Limit)&&(voltage < Voltage_4_Upper_Limit))
    {
        temp = 4;
    }
    else if((voltage > Voltage_5_Lower_Limit)&&(voltage < Voltage_5_Upper_Limit))
    {
        temp = 5;
    }
    else if((voltage > Voltage_6_Lower_Limit)&&(voltage < Voltage_6_Upper_Limit))
    {
        temp = 6;
    }
    else if((voltage > Voltage_7_Lower_Limit)&&(voltage < Voltage_7_Upper_Limit))
    {
        if(k_est < 0.25)
            temp = 7;
        else
            temp = 8;
    }
    else if((voltage > Voltage_8_Lower_Limit)&&(voltage < Voltage_8_Upper_Limit))
    {
        temp = 9;
    }

    return temp;

}



