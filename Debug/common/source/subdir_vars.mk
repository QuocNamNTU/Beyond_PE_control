################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../common/source/F2806x_CSMPasswords.asm \
../common/source/F2806x_CodeStartBranch.asm \
../common/source/F2806x_DBGIER.asm \
../common/source/F2806x_DisInt.asm \
../common/source/F2806x_usDelay.asm 

C_SRCS += \
../common/source/F2806x_Adc.c \
../common/source/F2806x_Comp.c \
../common/source/F2806x_CpuTimers.c \
../common/source/F2806x_DefaultIsr.c \
../common/source/F2806x_Dma.c \
../common/source/F2806x_ECan.c \
../common/source/F2806x_ECap.c \
../common/source/F2806x_EPwm.c \
../common/source/F2806x_EQep.c \
../common/source/F2806x_Gpio.c \
../common/source/F2806x_HRCap.c \
../common/source/F2806x_I2C.c \
../common/source/F2806x_Mcbsp.c \
../common/source/F2806x_OscComp.c \
../common/source/F2806x_PieCtrl.c \
../common/source/F2806x_PieVect.c \
../common/source/F2806x_SWPrioritizedPieVect.c \
../common/source/F2806x_Sci.c \
../common/source/F2806x_Spi.c \
../common/source/F2806x_SysCtrl.c \
../common/source/F2806x_TempSensorConv.c 

C_DEPS += \
./common/source/F2806x_Adc.d \
./common/source/F2806x_Comp.d \
./common/source/F2806x_CpuTimers.d \
./common/source/F2806x_DefaultIsr.d \
./common/source/F2806x_Dma.d \
./common/source/F2806x_ECan.d \
./common/source/F2806x_ECap.d \
./common/source/F2806x_EPwm.d \
./common/source/F2806x_EQep.d \
./common/source/F2806x_Gpio.d \
./common/source/F2806x_HRCap.d \
./common/source/F2806x_I2C.d \
./common/source/F2806x_Mcbsp.d \
./common/source/F2806x_OscComp.d \
./common/source/F2806x_PieCtrl.d \
./common/source/F2806x_PieVect.d \
./common/source/F2806x_SWPrioritizedPieVect.d \
./common/source/F2806x_Sci.d \
./common/source/F2806x_Spi.d \
./common/source/F2806x_SysCtrl.d \
./common/source/F2806x_TempSensorConv.d 

OBJS += \
./common/source/F2806x_Adc.obj \
./common/source/F2806x_CSMPasswords.obj \
./common/source/F2806x_CodeStartBranch.obj \
./common/source/F2806x_Comp.obj \
./common/source/F2806x_CpuTimers.obj \
./common/source/F2806x_DBGIER.obj \
./common/source/F2806x_DefaultIsr.obj \
./common/source/F2806x_DisInt.obj \
./common/source/F2806x_Dma.obj \
./common/source/F2806x_ECan.obj \
./common/source/F2806x_ECap.obj \
./common/source/F2806x_EPwm.obj \
./common/source/F2806x_EQep.obj \
./common/source/F2806x_Gpio.obj \
./common/source/F2806x_HRCap.obj \
./common/source/F2806x_I2C.obj \
./common/source/F2806x_Mcbsp.obj \
./common/source/F2806x_OscComp.obj \
./common/source/F2806x_PieCtrl.obj \
./common/source/F2806x_PieVect.obj \
./common/source/F2806x_SWPrioritizedPieVect.obj \
./common/source/F2806x_Sci.obj \
./common/source/F2806x_Spi.obj \
./common/source/F2806x_SysCtrl.obj \
./common/source/F2806x_TempSensorConv.obj \
./common/source/F2806x_usDelay.obj 

ASM_DEPS += \
./common/source/F2806x_CSMPasswords.d \
./common/source/F2806x_CodeStartBranch.d \
./common/source/F2806x_DBGIER.d \
./common/source/F2806x_DisInt.d \
./common/source/F2806x_usDelay.d 

OBJS__QUOTED += \
"common\source\F2806x_Adc.obj" \
"common\source\F2806x_CSMPasswords.obj" \
"common\source\F2806x_CodeStartBranch.obj" \
"common\source\F2806x_Comp.obj" \
"common\source\F2806x_CpuTimers.obj" \
"common\source\F2806x_DBGIER.obj" \
"common\source\F2806x_DefaultIsr.obj" \
"common\source\F2806x_DisInt.obj" \
"common\source\F2806x_Dma.obj" \
"common\source\F2806x_ECan.obj" \
"common\source\F2806x_ECap.obj" \
"common\source\F2806x_EPwm.obj" \
"common\source\F2806x_EQep.obj" \
"common\source\F2806x_Gpio.obj" \
"common\source\F2806x_HRCap.obj" \
"common\source\F2806x_I2C.obj" \
"common\source\F2806x_Mcbsp.obj" \
"common\source\F2806x_OscComp.obj" \
"common\source\F2806x_PieCtrl.obj" \
"common\source\F2806x_PieVect.obj" \
"common\source\F2806x_SWPrioritizedPieVect.obj" \
"common\source\F2806x_Sci.obj" \
"common\source\F2806x_Spi.obj" \
"common\source\F2806x_SysCtrl.obj" \
"common\source\F2806x_TempSensorConv.obj" \
"common\source\F2806x_usDelay.obj" 

C_DEPS__QUOTED += \
"common\source\F2806x_Adc.d" \
"common\source\F2806x_Comp.d" \
"common\source\F2806x_CpuTimers.d" \
"common\source\F2806x_DefaultIsr.d" \
"common\source\F2806x_Dma.d" \
"common\source\F2806x_ECan.d" \
"common\source\F2806x_ECap.d" \
"common\source\F2806x_EPwm.d" \
"common\source\F2806x_EQep.d" \
"common\source\F2806x_Gpio.d" \
"common\source\F2806x_HRCap.d" \
"common\source\F2806x_I2C.d" \
"common\source\F2806x_Mcbsp.d" \
"common\source\F2806x_OscComp.d" \
"common\source\F2806x_PieCtrl.d" \
"common\source\F2806x_PieVect.d" \
"common\source\F2806x_SWPrioritizedPieVect.d" \
"common\source\F2806x_Sci.d" \
"common\source\F2806x_Spi.d" \
"common\source\F2806x_SysCtrl.d" \
"common\source\F2806x_TempSensorConv.d" 

ASM_DEPS__QUOTED += \
"common\source\F2806x_CSMPasswords.d" \
"common\source\F2806x_CodeStartBranch.d" \
"common\source\F2806x_DBGIER.d" \
"common\source\F2806x_DisInt.d" \
"common\source\F2806x_usDelay.d" 

C_SRCS__QUOTED += \
"../common/source/F2806x_Adc.c" \
"../common/source/F2806x_Comp.c" \
"../common/source/F2806x_CpuTimers.c" \
"../common/source/F2806x_DefaultIsr.c" \
"../common/source/F2806x_Dma.c" \
"../common/source/F2806x_ECan.c" \
"../common/source/F2806x_ECap.c" \
"../common/source/F2806x_EPwm.c" \
"../common/source/F2806x_EQep.c" \
"../common/source/F2806x_Gpio.c" \
"../common/source/F2806x_HRCap.c" \
"../common/source/F2806x_I2C.c" \
"../common/source/F2806x_Mcbsp.c" \
"../common/source/F2806x_OscComp.c" \
"../common/source/F2806x_PieCtrl.c" \
"../common/source/F2806x_PieVect.c" \
"../common/source/F2806x_SWPrioritizedPieVect.c" \
"../common/source/F2806x_Sci.c" \
"../common/source/F2806x_Spi.c" \
"../common/source/F2806x_SysCtrl.c" \
"../common/source/F2806x_TempSensorConv.c" 

ASM_SRCS__QUOTED += \
"../common/source/F2806x_CSMPasswords.asm" \
"../common/source/F2806x_CodeStartBranch.asm" \
"../common/source/F2806x_DBGIER.asm" \
"../common/source/F2806x_DisInt.asm" \
"../common/source/F2806x_usDelay.asm" 


