//###########################################################################
//
//DSP 28069 firmware for Wireless charger system

//
// FILE:   Main.c
//
// TITLE:  F2806x PFC Control Functions.
//
//###########################################################################

//###########################################################################

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


//
// Functions that will be run from RAM need to be assigned to
// a different section.  This section will then be mapped using
// the linker cmd file.
//
#pragma CODE_SECTION(epwm7_isr, "ramfuncs");
#pragma CODE_SECTION(adc_isr, "ramfuncs");




//
// Globals variables for ADC example test
//
Uint16 LoopCount;
Uint16 ConversionCount;
Uint16 Voltage1[10];
Uint16 Voltage2[10];
Uint16 Voltage3[10];
Uint16 Voltage4[10];
Uint16 Voltage5[10];
Uint16 Voltage6[10];
Uint16 Voltage7[10];
Uint16 Voltage8[10];
Uint16 Voltage9[10];
Uint16 Voltage10[10];


//Blinking LED on DSP CARD

#define BLINK_LED() GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1


//Test PWM duty
Uint16 pwm_cnt = 0;



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


    // Copy time critical code and Flash setup code to RAM
    // This includes the following ISR functions: epwm1_timer_isr(),
    // epwm2_timer_isr(), epwm3_timer_isr and and InitFlash();
    // The  RamfuncsLoadStart, RamfuncsLoadSize, and RamfuncsRunStart
    // symbols are created by the linker. Refer to the F2808.cmd file.
    //

    //memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (Uint32)&RamfuncsLoadSize);

    //
    // Call Flash Initialization to setup flash waitstates
    // This function must reside in RAM
    //
    InitFlash();


    InitCpuTimers();            //Initialize Timer0


    ConfigCpuTimer(&CpuTimer0, 90, 500000);       //Timer0 500ms

    //ConfigCpuTimer(&CpuTimer1, 150, 100000);      //Timer1 100ms

    //ConfigCpuTimer(&CpuTimer2, 150, 1000000);     //Timer2 1s


    StartCpuTimer0();           //Start Timer0


    ADC_init();


    //AdcOffsetSelfCal();

    while(1)
        {
            ;
        }





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


    EPwm1Regs.CMPA.half.CMPA = pwm_cnt;

    EPwm2Regs.CMPA.half.CMPA = pwm_cnt;

    EPwm4Regs.CMPA.half.CMPA = pwm_cnt*5;

    EPwm7Regs.CMPA.half.CMPA = pwm_cnt*5;

    EPwm8Regs.CMPA.half.CMPA = pwm_cnt*50;

    pwm_cnt++;

    if(pwm_cnt > 128)
    {
        pwm_cnt = 0;
    }


    // Acknowledge this interrupt to receive more interrupts from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

}


//
// adc_isr -
//
__interrupt void adc_isr(void)
{

        Voltage1[ConversionCount] = AdcResult.ADCRESULT0;
        Voltage2[ConversionCount] = AdcResult.ADCRESULT1;
        Voltage3[ConversionCount] = AdcResult.ADCRESULT2;
        Voltage4[ConversionCount] = AdcResult.ADCRESULT3;
        Voltage5[ConversionCount] = AdcResult.ADCRESULT4;
        Voltage6[ConversionCount] = AdcResult.ADCRESULT5;
        Voltage7[ConversionCount] = AdcResult.ADCRESULT6;
        Voltage8[ConversionCount] = AdcResult.ADCRESULT7;
        Voltage9[ConversionCount] = AdcResult.ADCRESULT8;
        Voltage10[ConversionCount] = AdcResult.ADCRESULT9;


        //
        // If 20 conversions have been logged, start over
        //
        if(ConversionCount == 9)
        {
            ConversionCount = 0;
        }
        else
        {
            ConversionCount++;
        }


    //
    // Clear ADCINT1 flag reinitialize for next SOC
    //
    AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;   // Acknowledge interrupt to PIE

    return;
}


//
// End of File
//

