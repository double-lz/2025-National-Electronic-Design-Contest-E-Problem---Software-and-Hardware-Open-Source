################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/empty_LP_MSPM0G3507_nortos_ticlang/%.o: ../Drivers/empty_LP_MSPM0G3507_nortos_ticlang/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/BNO08X_UART_RVC" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/Ultrasonic_GPIO" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/Ultrasonic_Capture" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/OLED_Hardware_I2C" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/OLED_Hardware_SPI" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/OLED_Software_I2C" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/OLED_Software_SPI" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/MPU6050" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/MSPM0" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/WIT" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Drivers/empty_LP_MSPM0G3507_nortos_ticlang/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-577550351: ../Drivers/empty_LP_MSPM0G3507_nortos_ticlang/empty.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs2011/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/empty_LP_MSPM0G3507_nortos_ticlang/empty.syscfg" -o "." -s "C:/ti/mspm0_sdk_2_04_00_06/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-577550351 ../Drivers/empty_LP_MSPM0G3507_nortos_ticlang/empty.syscfg
device.opt: build-577550351
device.cmd.genlibs: build-577550351
ti_msp_dl_config.c: build-577550351
ti_msp_dl_config.h: build-577550351

Drivers/empty_LP_MSPM0G3507_nortos_ticlang/startup_mspm0g350x_ticlang.o: C:/ti/mspm0_sdk_2_04_00_06/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/BNO08X_UART_RVC" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/Ultrasonic_GPIO" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/Ultrasonic_Capture" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/OLED_Hardware_I2C" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/OLED_Hardware_SPI" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/OLED_Software_I2C" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/OLED_Software_SPI" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/MPU6050" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/MSPM0" -I"C:/Users/llz/workspace_ccstheia/mpu6050-oled-hardware-i2c/Drivers/WIT" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


