################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/MPU6050/%.o: ../Drivers/MPU6050/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/sy/test/Drivers/BNO08X_UART_RVC" -I"D:/sy/test/Drivers/Ultrasonic_GPIO" -I"D:/sy/test/Drivers/Ultrasonic_Capture" -I"D:/sy/test/Drivers/OLED_Hardware_I2C" -I"D:/sy/test/Drivers/OLED_Hardware_SPI" -I"D:/sy/test/Drivers/OLED_Software_I2C" -I"D:/sy/test/Drivers/OLED_Software_SPI" -I"D:/sy/test/Drivers/MPU6050" -I"D:/sy/test" -I"D:/sy/test/Debug" -I"D:/CCS/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/CCS/mspm0_sdk_2_05_01_00/source" -I"D:/sy/test/Drivers/MSPM0" -I"D:/sy/test/Drivers/WIT" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Drivers/MPU6050/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


