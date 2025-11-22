################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/empty_LP_MSPM0G3507_nortos_ticlang/Debug/%.o: ../Drivers/empty_LP_MSPM0G3507_nortos_ticlang/Debug/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/BNO08X_UART_RVC" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/Ultrasonic_GPIO" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/Ultrasonic_Capture" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/OLED_Hardware_I2C" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/OLED_Hardware_SPI" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/OLED_Software_I2C" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/OLED_Software_SPI" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/MPU6050" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/MSPM0" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/WIT" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Drivers/empty_LP_MSPM0G3507_nortos_ticlang/Debug/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


