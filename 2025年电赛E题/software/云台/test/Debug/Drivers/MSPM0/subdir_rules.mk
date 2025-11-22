################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/MSPM0/%.o: ../Drivers/MSPM0/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/llz/workspace_ccstheia/test/Drivers/BNO08X_UART_RVC" -I"C:/Users/llz/workspace_ccstheia/test/Drivers/Ultrasonic_GPIO" -I"C:/Users/llz/workspace_ccstheia/test/Drivers/Ultrasonic_Capture" -I"C:/Users/llz/workspace_ccstheia/test/Drivers/OLED_Hardware_I2C" -I"C:/Users/llz/workspace_ccstheia/test/Drivers/OLED_Hardware_SPI" -I"C:/Users/llz/workspace_ccstheia/test/Drivers/OLED_Software_I2C" -I"C:/Users/llz/workspace_ccstheia/test/Drivers/OLED_Software_SPI" -I"C:/Users/llz/workspace_ccstheia/test/Drivers/MPU6050" -I"C:/Users/llz/workspace_ccstheia/test" -I"C:/Users/llz/workspace_ccstheia/test/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/llz/workspace_ccstheia/test/Drivers/MSPM0" -I"C:/Users/llz/workspace_ccstheia/test/Drivers/WIT" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Drivers/MSPM0/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


