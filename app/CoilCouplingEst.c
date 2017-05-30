/*
 * CoilCouplingEst.c
 *
 *  Created on: May 29, 2017
 *      Author: tqnam
 */

#include "math.h"


float k_estimate(float voltage_in, float current_in, float resistor);
float Vinv_ref(float current, float coupling_factor);


#define pi          3.14159318
#define piSqr       9.8696
//#define RL          20
#define fsw         350000          //  fsw = 350kHz
#define SqrtL1L2    0.00004542     //   sqrt(L1*L2)
#define SqrtL1L2_1   22016.7         //  1/sqrt(L1*L2)





float k_estimate(float voltage_in, float current_in, float resistor)
{

    float temp, temp1, temp2;
    float temp_out;

    temp = 2*voltage_in*resistor/current_in;

    temp1 = sqrt(temp);

    temp2 = temp1/(piSqr*fsw);

    temp_out = temp2*SqrtL1L2_1;

    return temp_out;


}



float Vinv_ref(float current, float coupling_factor)
{
    float Voltage_ref;

    Voltage_ref = current*127.3375*coupling_factor;

    return Voltage_ref;

    //Vdc_inv_equi = Idc_REC*127.3375*k_est;

}
