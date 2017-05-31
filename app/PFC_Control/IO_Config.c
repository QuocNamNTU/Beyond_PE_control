/*
 * IO_Setting.c
 *
 *  Created on: April 21, 2017
 *      Author: tqnam
 */


#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File
#include "Main.h"

#define ADC_usDELAY  1000L


void GPIO_init()
{

        EALLOW;

        //##################  PFC PWM   ########################################

        //PWM_PFC_1A  GPIO40/EPWM7

        GpioCtrlRegs.GPBPUD.bit.GPIO40 = 1; // Disable Pull-up RES on GPIO40

        GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 1;  // GPIO40 = PWM7A

        GpioCtrlRegs.GPBDIR.bit.GPIO40 = 1;  // GPIO40 = OUTPUT


        //##################  Relay control   ########################################

        //STA_PFC_RELAY1  GPIO27  NTC BY PASS RELAY
        //STA_PFC_RELAY2  GPIO26  START-UP RELAY

        GpioCtrlRegs.GPAPUD.bit.GPIO26 = 1; // Disable Pull-up RES on GPIO26
        GpioCtrlRegs.GPAPUD.bit.GPIO27 = 1; // Disable Pull-up RES on GPIO27

        GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 0;  //GPIO26 as START-UP RELAY
        GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 0;  //GPIO27 as NTC BY PASS RELAY

        GpioCtrlRegs.GPADIR.bit.GPIO26 = 1;   // GPIO26 = OUTPUT
        GpioCtrlRegs.GPADIR.bit.GPIO27 = 1;   // GPIO27 = OUTPUT


        //##################  PFC Status   ########################################

        //NTC_STATUS            GPIO57/HRCAP4   Active low
        //ECAP                  GPIO24/ECAP1
        //STA_PFC_VDC_TRIP_L    GPIO13/TZ2      Active low

        GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0;     // Enable Pull-up RES on GPIO13
        GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0;     // Enable Pull-up RES on GPIO24
        GpioCtrlRegs.GPBPUD.bit.GPIO57 = 0;     // Enable Pull-up RES on GPIO57

        GpioCtrlRegs.GPADIR.bit.GPIO13 = 0;     // GPIO13 = INPUT
        GpioCtrlRegs.GPADIR.bit.GPIO24 = 0;     // GPIO13 = INPUT
        GpioCtrlRegs.GPBDIR.bit.GPIO57 = 0;     // GPIO13 = INPUT


        GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 0;  //GPIO13 as Over DC voltage detection TZ2 ???
        GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0;  //GPIO24 as ???
        GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 0;  //GPIO57 as NTC Relay Open circuit detection ???


        //###########################  Inverter PWMs   ###################################

        //PWM_INV_1A GPIO0/EPWM1A
        //PWM_INV_1B  GPIO1/EPWM1B
        //PWM_INV_2A  GPIO2/EPWM2A
        //PWM_INV_2B  GPIO3/EPWM2B

        GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;   // Disable Pull-up RES on GPIO0
        GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;   // Disable Pull-up RES on GPIO1
        GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;   // Disable Pull-up RES on GPIO2
        GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;   // Disable Pull-up RES on GPIO3

        GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;  // GPIO0 = PWM1A
        GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;  // GPIO1 = PWM1B
        GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;  // GPIO2 = PWM2A
        GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;  // GPIO3 = PWM2B

        GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;  // GPIO0 = OUTPUT
        GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;  // GPIO1 = OUTPUT
        GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;  // GPIO2 = OUTPUT
        GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;  // GPIO3 = OUTPUT


        //##################  DC-DC converter PWMs   ########################################

        //PWM_DCDC_1A GPIO6/EPWM4A
        //PWM_DCDC_1B GPIO7/EPWM4B


        GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;   // Disable Pull-up RES on GPIO6
        GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;   // Disable Pull-up RES on GPIO7

        GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;  // GPIO6 = PWM4A
        GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;  // GPIO7 = PWM4B

        GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;  // GPIO6 = OUTPUT
        GpioCtrlRegs.GPADIR.bit.GPIO7 = 1;  // GPIO7 = OUTPUT


        //##################  FAN control PWM   ########################################

        //PWM_FAN_MCU   GPIO41/PWM8A

        GpioCtrlRegs.GPBPUD.bit.GPIO41 = 1; // Disable Pull-up RES on GPIO41

        GpioCtrlRegs.GPBMUX1.bit.GPIO41 = 1;  // GPIO41 = PWM8A

        GpioCtrlRegs.GPBDIR.bit.GPIO41 = 1;  // GPIO41 = OUTPUT


        //##################  FAN status   ########################################

        //STA_FAN_FAULT_L GPIO14/TZ3  ACTIVE LOW

        GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;     // Enable Pull-up RES on GPIO14

        GpioCtrlRegs.GPADIR.bit.GPIO14 = 0;     // GPIO14 = INPUT

        GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0;  //GPIO14 as FAN fault detection



        //##################  Push Buttons   ########################################

        //STA_PB1 GPIO11  LOW MEANS PUSHED
        //STA_PB2 GPIO10  LOW MEANS PUSHED

        GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;   // Disable Pull-up RES on GPIO10
        GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;   // Disable Pull-up RES on GPIO11

        GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0;  // GPIO10 = Push button
        GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;  // GPIO11 = Push button

        GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;  // GPIO10 = INPUT
        GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;  // GPIO11 = INPUT



        //##################  LED Indicators   ########################################
        //STA_LEDG    GPIO51  LOW TO LIGHT LED
        //STA_LEDR    GPIO9   LOW TO LIGHT LED

        GpioCtrlRegs.GPBPUD.bit.GPIO51 = 1;     //Disable Pull-up RES on GPIO51
        GpioCtrlRegs.GPAPUD.bit.GPIO9 = 1;   // Disable Pull-up RES on GPIO9

        GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 0;  // GPIO51 = Green LED
        GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 0;  // GPIO9 = Red LED

        GpioCtrlRegs.GPBDIR.bit.GPIO51 = 1;  // GPIO51 = OUTPUT
        GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;  // GPIO9 = OUTPUT



        //##################  LED Indicators   ########################################
        //GPIO31  LED on DSP CARD
        //GPIO34  LED on DSP CARD

        GpioCtrlRegs.GPAPUD.bit.GPIO31 = 1;     //Disable Pull-up RES on GPIO51
        GpioCtrlRegs.GPBPUD.bit.GPIO34 = 1;   // Disable Pull-up RES on GPIO9

        GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;  // GPIO51 = Green LED
        GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;  // GPIO9 = Red LED

        GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;  // GPIO51 = OUTPUT
        GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;  // GPIO9 = OUTPUT




        EDIS;


}

/*==========================================================================================

===========================================================================================*/



void ADC_init(void)
{

    //
        // Configure ADC
        //
        EALLOW;
        AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 1; // Enable non-overlap mode

        //
        // ADCINT1 trips after AdcResults latch
        //
        AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1;

        AdcRegs.INTSEL1N2.bit.INT1E     = 1;  // Enabled ADCINT1
        AdcRegs.INTSEL1N2.bit.INT1CONT  = 0;  // Disable ADCINT1 Continuous mode

        //
        // setup EOC1 to trigger ADCINT1 to fire
        //
        AdcRegs.INTSEL1N2.bit.INT1SEL   = 1;



        //##################  PFC ANA   ########################################

        //ANA_PFC_I_SENSE_OUT   ADCINA6   23.4A:2.5V
        //ANA_PFC_VAC_OUT       ADCINA7   500V:3V
        //ANA_PFC_VDC_OUT       ADCINA5   500V:3V
        //ANA_PFC_TEMP_OUT      ADCINB0   PULL UP TO 3.3V BY A 510OHM RESISTOR


        //##################  DC-DC Converter ANA   ########################################

        //ANA_DCDC_I_SENSE_OUT      ADCINA4   23.4A:2.5V
        //ANA_DCDC_VDC_OUT          ADCINA3   500V:3V
        //ANA_DCDC_VOUT             ADCINA1   500V:3V


        //##################  Inverter ANA   ########################################

        //ANA_INV_I_SENSE_OUT     ADCINA2   I*3.3/100+1.25
        //ANA_INV_VDC_OUT         ADCINA0   500V:3V
        //ANA_INV_TEMP_OUT        ADCINB1   PULL UP TO 3.3V BY A 510OHM RESISTOR



        AdcRegs.ADCSOC0CTL.bit.CHSEL    = 7;  // Vin -> A7

        AdcRegs.ADCSOC1CTL.bit.CHSEL    = 6;  // Iin -> A6

        AdcRegs.ADCSOC2CTL.bit.CHSEL    = 5;  // Vdc -> A5

        AdcRegs.ADCSOC3CTL.bit.CHSEL    = 8;  // PFC Heatsink temp -> B0


        AdcRegs.ADCSOC4CTL.bit.CHSEL    = 3;  // Vdc -> A3

        AdcRegs.ADCSOC5CTL.bit.CHSEL    = 1;  // Vinv -> A1

        AdcRegs.ADCSOC6CTL.bit.CHSEL    = 4;  // Idc -> A4


        AdcRegs.ADCSOC7CTL.bit.CHSEL    = 0;  // Vinv -> A0

        AdcRegs.ADCSOC8CTL.bit.CHSEL    = 2;  // Iout -> A2

        AdcRegs.ADCSOC9CTL.bit.CHSEL    = 9;  // INV Heatsink temp -> B1



        //
        // set SOC0-9 start trigger on EPWM7A, due to round-robin SOC0 converts first then SOC1
        //0x05h ADCTRIG5 – ePWM1, ADCSOCA
        //0x06h ADCTRIG6 – ePWM1, ADCSOCB
        //0x11h ADCTRIG17 - ePWM7, ADCSOCA
        //
        AdcRegs.ADCSOC0CTL.bit.TRIGSEL  = 0x11;
        AdcRegs.ADCSOC1CTL.bit.TRIGSEL  = 0x11;
        AdcRegs.ADCSOC2CTL.bit.TRIGSEL  = 0x11;
        AdcRegs.ADCSOC3CTL.bit.TRIGSEL  = 0x11;
        AdcRegs.ADCSOC4CTL.bit.TRIGSEL  = 0x11;
        AdcRegs.ADCSOC5CTL.bit.TRIGSEL  = 0x11;
        AdcRegs.ADCSOC6CTL.bit.TRIGSEL  = 0x11;
        AdcRegs.ADCSOC7CTL.bit.TRIGSEL  = 0x11;
        AdcRegs.ADCSOC8CTL.bit.TRIGSEL  = 0x11;
        AdcRegs.ADCSOC9CTL.bit.TRIGSEL  = 0x11;

        //
        // set SOC0 S/H Window to 7 ADC Clock Cycles, (6 ACQPS plus 1)
        //
        AdcRegs.ADCSOC0CTL.bit.ACQPS  = 6;
        AdcRegs.ADCSOC1CTL.bit.ACQPS  = 6;
        AdcRegs.ADCSOC2CTL.bit.ACQPS  = 6;
        AdcRegs.ADCSOC3CTL.bit.ACQPS  = 6;
        AdcRegs.ADCSOC4CTL.bit.ACQPS  = 6;
        AdcRegs.ADCSOC5CTL.bit.ACQPS  = 6;
        AdcRegs.ADCSOC6CTL.bit.ACQPS  = 6;
        AdcRegs.ADCSOC7CTL.bit.ACQPS  = 6;
        AdcRegs.ADCSOC8CTL.bit.ACQPS  = 6;
        AdcRegs.ADCSOC9CTL.bit.ACQPS  = 6;



        //
        // Setup each SOC's ADCINT trigger source
        //
        AdcRegs.ADCINTSOCSEL1.bit.SOC0  = 1;    // ADCINT1 starts SOC0-9
        AdcRegs.ADCINTSOCSEL1.bit.SOC1  = 1;
        AdcRegs.ADCINTSOCSEL1.bit.SOC2  = 1;
        AdcRegs.ADCINTSOCSEL1.bit.SOC3  = 1;
        AdcRegs.ADCINTSOCSEL1.bit.SOC4  = 1;
        AdcRegs.ADCINTSOCSEL1.bit.SOC5  = 1;
        AdcRegs.ADCINTSOCSEL1.bit.SOC6  = 1;
        AdcRegs.ADCINTSOCSEL1.bit.SOC7  = 1;
        AdcRegs.ADCINTSOCSEL2.bit.SOC8  = 1;
        AdcRegs.ADCINTSOCSEL2.bit.SOC9  = 1;


        DELAY_US(ADC_usDELAY);              // Delay before converting ADC channels


        EDIS;





}




void EPWM_init()
{
        EALLOW;
        SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;      // Stop all the TB clocks
        EDIS;


        //##################  PWM7 for PFC PWM   ########################################

        //PFC_PWM_Period = 65kHz

        EPwm7Regs.TBPRD = PFC_PWM_Period; // Period = ??? TBCLK counts      //65kHz

        EPwm7Regs.TBPHS.half.TBPHS = 0; // Set Phase register to zero
        EPwm7Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;// Symmetrical mode
        EPwm7Regs.TBCTL.bit.PHSEN = TB_DISABLE; // Master module
        EPwm7Regs.TBCTL.bit.PRDLD = TB_SHADOW;
        EPwm7Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO; // Sync down-stream module
        EPwm7Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
        EPwm7Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
        EPwm7Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO_PRD; // load on CTR=Zero
        EPwm7Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO_PRD; // load on CTR=Zero


        EPwm7Regs.ETSEL.bit.INTSEL = 1;     // select_PWM INT on Zero event
        EPwm7Regs.ETSEL.bit.INTEN = 1;      // Enable INT
        EPwm7Regs.ETPS.bit.INTPRD = 1;      // Generate INT on 1st event

        EPwm7Regs.ETSEL.bit.SOCAEN = 1;     // Enable SOCA
        EPwm7Regs.ETSEL.bit.SOCASEL = 1;    // Select_PWM SOCA on Zero event
        EPwm7Regs.ETPS.bit.SOCAPRD = 1;     // Generate INT on 1st event


        EPwm7Regs.AQCTLA.bit.CAU = AQ_CLEAR; // set actions active low for EPWM7A
        EPwm7Regs.AQCTLA.bit.CAD = AQ_SET;



        //##################  PWM1-2 for Inverter PWMs   ########################################

        //INV_PWM_Period = 350kHz


        EPwm1Regs.TBPRD = INV_PWM_Period; // Period = ??? TBCLK counts      //350Khz

        EPwm1Regs.TBPHS.half.TBPHS = 0; // Set Phase register to zero
        EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;// Symmetrical mode
        EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE; // Master module
        EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;
        EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // Sync down-stream module
        EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
        EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
        EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO_PRD; // load on CTR=Zero
        EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO_PRD; // load on CTR=Zero

        EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR; // set actions active low for EPWM1A
        EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;
        EPwm1Regs.AQCTLB.bit.CAU = AQ_SET;// set actions active high for EPWM1B
        EPwm1Regs.AQCTLB.bit.CAD = AQ_CLEAR;


        EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE; // Enable Dead-band module
        EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC; // Active Hi complementary
        EPwm1Regs.DBFED = Deadtime; // FED = 50 TBCLKs
        EPwm1Regs.DBRED = Deadtime; // RED = 50 TBCLKs


        EPwm2Regs.TBPRD = INV_PWM_Period; // Period = ??? TBCLK counts      //350Khz

        EPwm2Regs.TBPHS.half.TBPHS = 0; // Set Phase register to zero
        EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;// Symmetrical mode
        EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE; // Master module
        EPwm2Regs.TBCTL.bit.PRDLD = TB_SHADOW;
        EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // Sync down-stream module
        EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
        EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
        EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO_PRD; // load on CTR=Zero
        EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO_PRD; // load on CTR=Zero


        EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;    // set actions active low for EPWM2A
        EPwm2Regs.AQCTLA.bit.CAD = AQ_CLEAR;
        EPwm2Regs.AQCTLB.bit.CAU = AQ_CLEAR;      // set actions active high for EPWM2B
        EPwm2Regs.AQCTLB.bit.CAD = AQ_SET;


        EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE; // Enable Dead-band module
        EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC; // Active Hi complementary
        EPwm2Regs.DBFED = Deadtime; // FED = 50 TBCLKs
        EPwm2Regs.DBRED = Deadtime; // RED = 50 TBCLKs



        //##################  PWM4 for DC-DC Converter PWM   ########################################

        //DC_PWM_Period = 65kHz


        EPwm4Regs.TBPRD = DCDC_PWM_Period; // Period = ??? TBCLK counts   65kHz

        EPwm4Regs.TBPHS.half.TBPHS = 0; // Set Phase register to zero
        EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;// Symmetrical mode
        EPwm4Regs.TBCTL.bit.PHSEN = TB_DISABLE; // Slave module
        EPwm4Regs.TBCTL.bit.PRDLD = TB_SHADOW;
        EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // sync flow-through
        EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
        EPwm4Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
        EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO_PRD; // load on CTR=Zero and PWM_Period
        EPwm4Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO_PRD; // load on CTR=Zero


        EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR; // set actions active low for EPWM4A
        EPwm4Regs.AQCTLA.bit.CAD = AQ_SET;
        EPwm4Regs.AQCTLB.bit.CAU = AQ_SET;// set actions active high for EPWM4B
        EPwm4Regs.AQCTLB.bit.CAD = AQ_CLEAR;


        EPwm4Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE; // Enable Dead-band module
        EPwm4Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC; // Active Hi complementary
        EPwm4Regs.DBFED = Deadtime; // FED = 50 TBCLKs
        EPwm4Regs.DBRED = Deadtime; // RED = 50 TBCLKs


        //##################  PWM8 for FAN Control   ########################################

        //FAN_PWM_Period = 5kHz


        EPwm8Regs.TBPRD = FAN_PWM_Period; // Period = ??? TBCLK counts      5kHz

        EPwm8Regs.TBPHS.half.TBPHS = 0; // Set Phase register to zero
        EPwm8Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;// Symmetrical mode
        EPwm8Regs.TBCTL.bit.PHSEN = TB_DISABLE; // Slave module
        EPwm8Regs.TBCTL.bit.PRDLD = TB_SHADOW;
        EPwm8Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // sync flow-through
        EPwm8Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
        EPwm8Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
        EPwm8Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO_PRD; // load on CTR=Zero
        EPwm8Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO_PRD; // load on CTR=Zero


        EPwm8Regs.AQCTLA.bit.CAU = AQ_CLEAR; // set actions active low for EPWM2A
        EPwm8Regs.AQCTLA.bit.CAD = AQ_SET;




        /*

        //For TZ5 tripzone set up
        EALLOW;

        EPwm1Regs.TZSEL.bit.OSHT5 = 1;;     //Disable TZ5 tripzone
        EPwm2Regs.TZSEL.bit.OSHT5 = 1;;     //Disable TZ5 tripzone
        EPwm3Regs.TZSEL.bit.OSHT5 = 1;;     //Disable TZ5 tripzone
        EPwm4Regs.TZSEL.bit.OSHT5 = 1;;     //Disable TZ5 tripzone
        EPwm5Regs.TZSEL.bit.OSHT5 = 1;;     //Disable TZ5 tripzone
        EPwm6Regs.TZSEL.bit.OSHT5 = 1;;     //Disable TZ5 tripzone


        EPwm1Regs.TZCTL.bit.TZA = 2;                  //Force low state for All PWMs
        EPwm1Regs.TZCTL.bit.TZB = 2;

        EPwm2Regs.TZCTL.bit.TZA = 2;
        EPwm2Regs.TZCTL.bit.TZB = 2;

        EPwm3Regs.TZCTL.bit.TZA = 2;
        EPwm3Regs.TZCTL.bit.TZB = 2;

        EPwm4Regs.TZCTL.bit.TZA = 2;
        EPwm4Regs.TZCTL.bit.TZB = 2;

        EPwm5Regs.TZCTL.bit.TZA = 2;
        EPwm5Regs.TZCTL.bit.TZB = 2;

        EPwm6Regs.TZCTL.bit.TZA = 2;
        EPwm6Regs.TZCTL.bit.TZB = 2;

        // Enable TZ interrupt

        EPwm1Regs.TZEINT.bit.OST = 1;

        EDIS;

        */


        EALLOW;
        SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;         // Start all the timers synced
        EDIS;



}



void Interrupt_Setting()
{

  InitPieCtrl();           //Disable PIE interrupt, Clear interrupt flag

  IER = 0x0000;           //Disable CPU interrupt, Clear interrupt flag
  IFR = 0x0000;

  InitPieVectTable();     //// This function initializes the PIE vector table to a known state.



   EALLOW;
   PieVectTable.EPWM7_INT = &epwm7_isr;    //PWM
   PieVectTable.TINT0 = &cpu_timer0_isr;        //Timer 0
   //PieVectTable.SCIRXINTC = &scic_rx_isr;       //SCI-C
   PieVectTable.TINT1 = &cpu_timer1_isr;
   //PieVectTable.TINT2 = &cpu_timer2_isr;
   //PieVectTable.ECAN1INTB = &ecan1_intb_isr;        //ECAN interrupt
   PieVectTable.ADCINT1 = &adc_isr;                  //ADC interrupt

   EDIS;

    IER |= M_INT1;  //ADC and Timer0
    IER |= M_INT3;  //PWM
    //IER |= M_INT8;  //RXD-C
    IER |= M_INT13; //Timer1
    //IER |= M_INT14; //Timer2
    //IER |= M_INT9;  //ECAN-B


    PieCtrlRegs.PIEIER1.bit.INTx1 = 1;  //ADC1

    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;  //timer0

    PieCtrlRegs.PIEIER3.bit.INTx7 = 1;  //enable ePWM7_INT

    //PieCtrlRegs.PIEIER8.bit.INTx5 = 1;  // RXD-C
    //PieCtrlRegs.PIEIER9.bit.INTx8 = 1;  // ECAN-B



    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
    //PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;
    //PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;


   // Enable global Interrupts and higher priority real-time debug events:
   EINT;   // Enable Global interrupt INTM
   ERTM;   // Enable Global realtime interrupt DBGM
}




/*   end of file*/

