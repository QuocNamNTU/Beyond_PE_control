################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
app/DC-DC_Control/DC-DC_Control.obj: ../app/DC-DC_Control/DC-DC_Control.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="C:/ti/ccs710/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/headers/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/common/include" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/inc" --include_path="C:/ti/c2000/C2000Ware_1_00_00_00/device_support/f2806x/examples/c28/Wireless_charger_system/driverlib/source" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="app/DC-DC_Control/DC-DC_Control.d" --obj_directory="app/DC-DC_Control" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


