/*
 * Main.c
 *
 *  Created on: April 22, 2017
 *      Author: tqnam
 */

//
// Included Files
//
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "Main.h"
#include "string.h"


__interrupt void  epwm7_isr(void);
__interrupt void  cpu_timer0_isr(void);
__interrupt void  adc_isr(void);


//
// Functions that will be run from RAM need to be assigned to
// a different section.  This section will then be mapped using
// the linker cmd file.
//
#pragma CODE_SECTION(epwm7_isr, "ramfuncs");
#pragma CODE_SECTION(adc_isr, "ramfuncs");


float Ts = 0.00001538;           //sampling time = 1/65kHz


float PMax = 2800;       //Pmax = 2800W
float PFC_Vdc_ref_target, PFC_Vdc_ref = 0;
float DCDC_Vout_ref_target, DCDC_Vout_ref = 0;

//inverter voltage variables
float Vinv_equi_ref;
float Irec, k_est;
int INV_Voltage_Range;

//Status and flag
int est_k_flag = 0;
Uint16 est_k_cnt = 0;

int input_power_status = 0;

//PFC variables
extern float PFC_Vac, PFC_Iac, PFC_Vdc;
extern float PFC_Vdc_ref;
extern float Is_ref, Iac_ref;
extern float Vac_RMS, Iac_RMS;
extern float Pin_avg;

//Low pass filter
extern float Vdc_LPF;      //Low pass filter of DC bus voltage Vdc
extern float PFC_Vdc1;

//Status and flag
extern int PFC_operation_flag;
extern int PFC_1st_start_up;

//DCDC variables
extern float DCDC_Vin, DCDC_Iout, DCDC_Vout;
extern int DCDC_operation_flag;


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

    ConfigCpuTimer(&CpuTimer1, 90, 50000);       //Timer0 50ms

    StartCpuTimer0();           //Start Timer0

    StartCpuTimer1();           //Start Timer1

    ADC_init();

    //AdcOffsetSelfCal();

    PFC_Init();     //Initial status of PFC

    DCDC_Init();     //Initial status of DCDC

    INV_Init();     //Initial status of inverter

    INV_PWM_Set(350);       //(pwm frequency)


    while(1)
        {
            Protection();
        }


}


void Reference_Gen(void)
{

    INV_Voltage_Range = Range_Selection(Vinv_equi_ref);

    switch(INV_Voltage_Range)
    {
        case 1:
        {
            PFC_Vdc_ref_target = Vinv_equi_ref;
            DCDC_Vout_ref_target = Vinv_equi_ref;
        }
        break;
        case 2:
        {
            PFC_Vdc_ref_target = 360;
            DCDC_Vout_ref_target = Vinv_equi_ref;
        }
        break;
        case 3:
        {
            PFC_Vdc_ref_target = 430;
            DCDC_Vout_ref_target = 3*Vinv_equi_ref;
            //Read PWM Period before set
            INV_PWM_Set(117);
        }
        break;
        case 4:
        {
            PFC_Vdc_ref_target = 360;
            DCDC_Vout_ref_target = 3*Vinv_equi_ref;
            //Read PWM Period before set
            INV_PWM_Set(117);
        }
        break;
        case 5:
        {
            PFC_Vdc_ref_target = 430;
            DCDC_Vout_ref_target = 5*Vinv_equi_ref;
            //Read PWM Period before set
            INV_PWM_Set(70);
        }
        break;
        case 6:
        {
            PFC_Vdc_ref_target = 360;
            DCDC_Vout_ref_target = 5*Vinv_equi_ref;
            //Read PWM Period before set
            INV_PWM_Set(70);
        }
        break;
        case 7:
        {
            PFC_Vdc_ref_target = 360;
            DCDC_Vout_ref_target = 7*Vinv_equi_ref;
            //Read PWM Period before set
            INV_PWM_Set(50);
        }
        break;
        case 8:
        {
            PFC_Vdc_ref_target = 230;
            DCDC_Vout_ref_target = 7*Vinv_equi_ref;
            //Read PWM Period before set
            INV_PWM_Set(50);
        }
        break;
        case 9:
        {
            PFC_Vdc_ref_target = 230;
            DCDC_Vout_ref_target = 9*Vinv_equi_ref;
            //Read PWM Period before set
            INV_PWM_Set(39);
        }
        break;
        default:
        {

        }
        break;

    }


}



void Protection(void)
{

}

//
// adc_isr -
//
__interrupt void adc_isr(void)
{

    PFC_ADC_result();        //Get ADC measurement of PFC

    DCDC_ADC_result();


    if(PFC_operation_flag == 1)
    {

        Vinv_equi_ref = Vinv_ref(Irec, k_est);

        Reference_Gen();

        CLOSE_NTC_RELAY();          //close NTC relay

        GREEN_LED_ON();             //On Green LED

        PFC_Vdc_ref = Votage_Ramp(PFC_Vdc_ref, PFC_Vdc_ref_target);         //Ramp up PFC ref voltage

        Is_ref = PFC_DC_Voltage_Control(PFC_Vdc_ref, Vdc_LPF);

        PFC_PWM = PFC_Current_Control(Is_ref, PFC_Iac);     //PFC current control

    }


    if(DCDC_operation_flag == 1)
    {
        DCDC_Vout_ref = Votage_Ramp(DCDC_Vout_ref, DCDC_Vout_ref_target);    //Ramp up DCDC ref voltage

        DCDC_PWM = DCDC_Voltage_Control(DCDC_Vout_ref, DCDC_Vout);      //DC-DC converter control
    }


    //
    // Clear ADCINT1 flag reinitialize for next SOC
    //
    AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;   // Acknowledge interrupt to PIE

    return;

}


//
// timer1_isr - every 20ms
//

__interrupt void cpu_timer1_isr(void)
{

    if(Vac_RMS > Vac_RMS_Min)       //self test AC input available
    {
        input_power_status = 1;
    }
    else
    {
        input_power_status = 0;
        Turn_off_PFC();
    }

    if((ON_BUTTON == 0)&&(OFF_BUTTON == 1)&&(input_power_status == 1))     //if press ON button
    {
        PFC_operation_flag = 1;
        if(PFC_1st_start_up == 0)
        {
            PFC_Vdc_ref = PFC_Vdc;
            PFC_1st_start_up = 1;
        }

    }

    if(OFF_BUTTON == 0)
    {
        Turn_off_PFC();
    }

}


//
// timer0_isr - every 500ms
//

__interrupt void cpu_timer0_isr(void)
{

    FAN_PWM = Fan_PWM(Pin_avg, PMax);          //Control the heatsink fan

    BLINK_LED();      //Blinking LED every 0.5s


    // Acknowledge this interrupt to receive more interrupts from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

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
// End of File
//

