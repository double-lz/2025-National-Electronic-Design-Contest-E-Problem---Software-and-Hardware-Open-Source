################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS

GEN_OPTS__FLAG := @"./device.opt" 
GEN_CMDS__FLAG := -Wl,-l"./device_linker.cmd" 

ORDERED_OBJS += \
"./main.o" \
"./ti_msp_dl_config.o" \
"./startup_mspm0g350x_ticlang.o" \
"./Drivers/MPU6050/inv_mpu.o" \
"./Drivers/MPU6050/inv_mpu_dmp_motion_driver.o" \
"./Drivers/MPU6050/mpu6050.o" \
"./Drivers/MPU6050/mspm0_i2c.o" \
"./Drivers/MSPM0/CCD.o" \
"./Drivers/MSPM0/Delay.o" \
"./Drivers/MSPM0/Key.o" \
"./Drivers/MSPM0/LED.o" \
"./Drivers/MSPM0/Motor.o" \
"./Drivers/MSPM0/PID.o" \
"./Drivers/MSPM0/StepMotor.o" \
"./Drivers/MSPM0/Uart.o" \
"./Drivers/MSPM0/adc.o" \
"./Drivers/MSPM0/clock.o" \
"./Drivers/MSPM0/interrupt.o" \
"./Drivers/MSPM0/work.o" \
"./Drivers/OLED_Hardware_I2C/oled_hardware_i2c.o" \
$(GEN_CMDS__FLAG) \
-Wl,-ldevice.cmd.genlibs \
-Wl,-llibc.a \
-Wl,-l"D:/CCS/mspm0_sdk_2_05_01_00/source/ti/driverlib/lib/ticlang/m0p/mspm0g1x0x_g3x0x/driverlib.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Drivers/MPU6050/subdir_vars.mk
-include Drivers/MSPM0/subdir_vars.mk
-include Drivers/OLED_Hardware_I2C/subdir_vars.mk
-include subdir_rules.mk
-include Drivers/MPU6050/subdir_rules.mk
-include Drivers/MSPM0/subdir_rules.mk
-include Drivers/OLED_Hardware_I2C/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
test.out 

EXE_OUTPUTS__QUOTED += \
"test.out" 


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "test.out"

# Tool invocations
test.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"D:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -Wl,-m"test.map" -Wl,-i"D:/CCS/mspm0_sdk_2_05_01_00/source" -Wl,-i"D:/sy/test" -Wl,-i"D:/sy/test/Debug/syscfg" -Wl,-i"D:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/lib" -Wl,--diag_wrap=off -Wl,--display_error_number -Wl,--warn_sections -Wl,--xml_link_info="test_linkInfo.xml" -Wl,--rom_model -o "test.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.o" "ti_msp_dl_config.o" "startup_mspm0g350x_ticlang.o" "Drivers\MPU6050\inv_mpu.o" "Drivers\MPU6050\inv_mpu_dmp_motion_driver.o" "Drivers\MPU6050\mpu6050.o" "Drivers\MPU6050\mspm0_i2c.o" "Drivers\MSPM0\CCD.o" "Drivers\MSPM0\Delay.o" "Drivers\MSPM0\Key.o" "Drivers\MSPM0\LED.o" "Drivers\MSPM0\Motor.o" "Drivers\MSPM0\PID.o" "Drivers\MSPM0\StepMotor.o" "Drivers\MSPM0\Uart.o" "Drivers\MSPM0\adc.o" "Drivers\MSPM0\clock.o" "Drivers\MSPM0\interrupt.o" "Drivers\MSPM0\work.o" "Drivers\OLED_Hardware_I2C\oled_hardware_i2c.o" 
	-$(RM) "main.d" "ti_msp_dl_config.d" "startup_mspm0g350x_ticlang.d" "Drivers\MPU6050\inv_mpu.d" "Drivers\MPU6050\inv_mpu_dmp_motion_driver.d" "Drivers\MPU6050\mpu6050.d" "Drivers\MPU6050\mspm0_i2c.d" "Drivers\MSPM0\CCD.d" "Drivers\MSPM0\Delay.d" "Drivers\MSPM0\Key.d" "Drivers\MSPM0\LED.d" "Drivers\MSPM0\Motor.d" "Drivers\MSPM0\PID.d" "Drivers\MSPM0\StepMotor.d" "Drivers\MSPM0\Uart.d" "Drivers\MSPM0\adc.d" "Drivers\MSPM0\clock.d" "Drivers\MSPM0\interrupt.d" "Drivers\MSPM0\work.d" "Drivers\OLED_Hardware_I2C\oled_hardware_i2c.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

