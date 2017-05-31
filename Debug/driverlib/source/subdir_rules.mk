################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
driverlib/source/adc.obj: ../driverlib/source/adc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/adc.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/asysctl.obj: ../driverlib/source/asysctl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/asysctl.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/can.obj: ../driverlib/source/can.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/can.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/cla.obj: ../driverlib/source/cla.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/cla.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/cmpss.obj: ../driverlib/source/cmpss.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/cmpss.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/cputimer.obj: ../driverlib/source/cputimer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/cputimer.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/dac.obj: ../driverlib/source/dac.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/dac.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/dcsm.obj: ../driverlib/source/dcsm.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/dcsm.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/dma.obj: ../driverlib/source/dma.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/dma.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/ecap.obj: ../driverlib/source/ecap.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/ecap.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/emif.obj: ../driverlib/source/emif.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/emif.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/epwm.obj: ../driverlib/source/epwm.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/epwm.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/eqep.obj: ../driverlib/source/eqep.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/eqep.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/flash.obj: ../driverlib/source/flash.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/flash.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/gpio.obj: ../driverlib/source/gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/gpio.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/hrpwm.obj: ../driverlib/source/hrpwm.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/hrpwm.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/i2c.obj: ../driverlib/source/i2c.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/i2c.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/interrupt.obj: ../driverlib/source/interrupt.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/interrupt.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/mcbsp.obj: ../driverlib/source/mcbsp.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/mcbsp.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/memcfg.obj: ../driverlib/source/memcfg.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/memcfg.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/sci.obj: ../driverlib/source/sci.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/sci.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/sdfm.obj: ../driverlib/source/sdfm.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/sdfm.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/spi.obj: ../driverlib/source/spi.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/spi.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/sysctl.obj: ../driverlib/source/sysctl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/sysctl.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/version.obj: ../driverlib/source/version.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/version.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/source/xbar.obj: ../driverlib/source/xbar.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="driverlib/source/xbar.d" --obj_directory="driverlib/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


