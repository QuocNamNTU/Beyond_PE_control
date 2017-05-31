/*
 * Fan_Control.c
 *
 *  Created on: May 14, 2017
 *      Author: tqnam
 */


#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File
#include "Main.h"




Uint16 Fan_PWM(float power, float power_max)
{

    float temp;
    Uint16  temp_out;

    temp = 0.333 + 0.666*power/power_max;         //Fan run at 33% speed at no load

    if(temp > 1){

        temp = 1;
    }

    temp_out = (Uint16)temp*FAN_PWM_Period;

    return temp_out;

}
