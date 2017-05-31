/*
 * Main.h
 *
 *  Created on: May 31, 2017
 *      Author: tqnam
 */

#ifndef MAIN_H_
#define MAIN_H_


#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File



#define BLINK_LED()             GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1
#define CLOSE_NTC_RELAY()       GpioDataRegs.GPASET.bit.GPIO27 = 1
#define OPEN_NTC_RELAY()        GpioDataRegs.GPACLEAR.bit.GPIO27 = 1
#define NTC_RELAY_STATUS        GpioDataRegs.GPBDAT.bit.GPIO57
#define ON_BUTTON               GpioDataRegs.GPADAT.bit.GPIO10
#define OFF_BUTTON              GpioDataRegs.GPADAT.bit.GPIO11

#define GREEN_LED_OFF()         GpioDataRegs.GPBSET.bit.GPIO51 = 1
#define GREEN_LED_ON()          GpioDataRegs.GPBCLEAR.bit.GPIO51 = 1
#define RED_LED_OFF()           GpioDataRegs.GPASET.bit.GPIO9 = 1
#define RED_LED_ON()            GpioDataRegs.GPACLEAR.bit.GPIO9 = 1

#define PFC_PWM                 EPwm7Regs.CMPA.half.CMPA
#define DCDC_PWM                EPwm4Regs.CMPA.half.CMPA
#define FAN_PWM                 EPwm8Regs.CMPA.half.CMPA

//ADC measurement gains

#define kV_DCDC     0.134310            //gain = 4095/3.3*(3V/500V)
#define kI_DCDC     0.0075428           //gain = 4095/3.3*(2.5V/23.4V)

#define kVac        0.134310            //gain = 4095/3.3*(3V/500V)
#define kVdc        0.134310            //gain = 4095/3.3*(3V/500V)
#define kIac        0.0075428           //gain = 4095/3.3*(2.5V/23.4V)

#define kV_Inv      0.134310            //gain = 4095/3.3*(3V/500V)
#define kI_Inv      0.02442            //gain = 4095/3.3*(3.3V/100A)


#define Voltage_1_Lower_Limit     360
#define Voltage_2_Upper_Limit     359
#define Voltage_2_Lower_Limit     140
#define Voltage_3_Upper_Limit     139
#define Voltage_3_Lower_Limit     110
#define Voltage_4_Upper_Limit     109
#define Voltage_4_Lower_Limit     80
#define Voltage_5_Upper_Limit     79
#define Voltage_5_Lower_Limit     65
#define Voltage_6_Upper_Limit     64
#define Voltage_6_Lower_Limit     35
#define Voltage_7_Upper_Limit     34
#define Voltage_7_Lower_Limit     20
#define Voltage_8_Upper_Limit     19
#define Voltage_8_Lower_Limit     7

#define Vac_RMS_Min         100
#define Vac_Peak_Min        141


#define Ramp_rate           20              // Ramp_rate = 20V/s


#define PFC_PWM_Period      692         //PFC PWM Period = 65 kHz = 692.3
#define INV_PWM_Period      128         //INV PWM Period = 350 kHz = 128.6
#define DCDC_PWM_Period     692         //DC-DC Converter PWM Period = 65 kHz = 692.3
#define FAN_PWM_Period      9000        //FAN Control PWM Period = 5 kHz = 9000

#define Deadtime            15              //Deadband 15 ~ 200ns



//
void GPIO_init(void);
void ADC_init(void);
void EPWM_init(void);
void Interrupt_Setting(void);


void PFC_ADC_result(void);
void RMS_Calculation(void);
void PFC_Init(void);
float PFC_DC_Voltage_Control(float voltage_ref, float voltage_fb);
Uint16 PFC_Current_Control(float current_ref, float current_fb);
float Votage_Ramp(float voltage_current, float voltage_target);

void DCDC_ADC_result(void);
void DCDC_Init(void);
Uint16 DCDC_Voltage_Control(float voltage_ref,float voltage_fb);

void INV_Init(void);
void INV_PWM_Set(Uint16 fsw_INV);
float k_estimate(float voltage_in, float current_in, float resistor);
float Vinv_ref(float current, float coupling_factor);
int Range_Selection(float voltage);
Uint16 Fan_PWM(float power, float power_max);

void Reference_Gen(void);
void Turn_off_PFC(void);
void Protection(void);


__interrupt void  epwm7_isr(void);
__interrupt void  cpu_timer0_isr(void);
__interrupt void  adc_isr(void);
__interrupt void  cpu_timer1_isr(void);


#endif /* MAIN_H_ */
