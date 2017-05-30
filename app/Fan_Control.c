/*
 * Fan_Control.c
 *
 *  Created on: May 30, 2017
 *      Author: tqnam
 */


#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File


Uint16 Fan_PWM(float power, float power_max);


extern float Pin_avg;

//#define POWER_IN_MAX        2800            //Pin_max
//#define POWER_IN_MAX_1      0.0000357       //  1/Pin_max

#define FAN_PWM_Period      9000        //FAN Control PWM Period = 5 kHz = 9000



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
