/*
 * Main.c
 *
 *  Created on: April 21, 2017
 *      Author: tqnam
 */

//
// Included Files
//
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
//#include "F2806x_CpuTimers.h"
#include "string.h"


__interrupt void  epwm7_isr(void);
__interrupt void  cpu_timer0_isr(void);
__interrupt void  adc_isr(void);



extern void GPIO_init(void);
extern void ADC_init(void);
extern void EPWM_init(void);
extern void Interrupt_Setting(void);

extern void PFC_ADC_result(void);
extern void RMS_Calculation(void);
extern void PFC_Init(void);

extern float PFC_DC_Voltage_Control(float voltage_ref, float voltage_fb);

extern Uint16 PFC_Current_Control(float current_ref, float current_fb);

extern void DCDC_ADC_result(void);
extern void DCDC_Init(void);
extern Uint16 DCDC_Voltage_Control(float voltage_ref,float voltage_fb);

extern void INV_Init(void);
extern void INV_PWM_Setting(Uint16 System_CLk, Uint16 fsw_INV);
extern void INV_Init(void);
extern float k_estimate(float voltage_in, float current_in, float resistor);
extern float Vinv_ref(float current, float coupling_factor);


//
// Functions that will be run from RAM need to be assigned to
// a different section.  This section will then be mapped using
// the linker cmd file.
//
#pragma CODE_SECTION(epwm7_isr, "ramfuncs");
#pragma CODE_SECTION(adc_isr, "ramfuncs");



//Blinking LED on DSP CARD

#define BLINK_LED()     GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1



int Test_mode;

int Operation_stage;


extern float PFC_Vac, PFC_Iac, PFC_Vdc;
extern float PFC_Vdc_ref, Is_ref, Iac_ref;
extern float DCDC_Vin, DCDC_Iout, DCDC_Vout;
float DCDC_Vout_ref = 0;

extern float Vdc_LPF;      //Low pass filter of DC bus voltage Vdc

// These are defined by the linker (see F2808.cmd)
//
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;
extern Uint16 RamfuncsLoadSize;



//
// Main
//
void main(void)
{

    GPIO_init();       //Initialize GPIO

    InitSysCtrl();              //Initialize System Control

    EPWM_init();       //Initialize EPWM

    Interrupt_Setting();        // Initialize interrupt and enable interrupt

    //memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (Uint32)&RamfuncsLoadSize);

    InitFlash();

    InitCpuTimers();            //Initialize Timer0

    ConfigCpuTimer(&CpuTimer0, 90, 500000);       //Timer0 500ms

    StartCpuTimer0();           //Start Timer0

    ADC_init();

    //AdcOffsetSelfCal();

    PFC_Init();     //Initial status of PFC

    DCDC_Init();     //Initial status of DCDC

    INV_Init();     //Initial status of inverter

    INV_PWM_Setting(90, 350);       //(system clock, pwm frequency)


    while(1)
        {
            //switch(Test_mode)


        }


}




//
// adc_isr -
//
__interrupt void adc_isr(void)
{


           PFC_ADC_result();        //Get ADC measurement of PFC

           Is_ref = PFC_DC_Voltage_Control(PFC_Vdc_ref, Vdc_LPF);

           EPwm7Regs.CMPA.half.CMPA = PFC_Current_Control(Is_ref, PFC_Iac);     //PFC current control

           EPwm4Regs.CMPA.half.CMPA = DCDC_Voltage_Control(DCDC_Vout_ref, DCDC_Vout);      //DC-DC converter control



    //
    // Clear ADCINT1 flag reinitialize for next SOC
    //
    AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;   // Acknowledge interrupt to PIE

    return;
}



//
// epwm1_isr -
//
__interrupt void epwm7_isr(void)
{



    EPwm7Regs.ETCLR.bit.INT = 1;        // Clear INT flag for this timer

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;     // Acknowledge this interrupt to receive more interrupts from group 3
    
}


//
// timer0_isr -
//

__interrupt void cpu_timer0_isr(void)
{


    BLINK_LED();      //Blinking LED every 0.5s


    // Acknowledge this interrupt to receive more interrupts from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

}



//
// End of File
//

