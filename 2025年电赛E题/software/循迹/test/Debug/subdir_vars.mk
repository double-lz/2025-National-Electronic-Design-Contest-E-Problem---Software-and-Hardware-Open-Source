################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
SYSCFG_SRCS += \
../test.syscfg 

C_SRCS += \
../main.c \
./ti_msp_dl_config.c \
D:/CCS/mspm0_sdk_2_05_01_00/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c 

GEN_CMDS += \
./device_linker.cmd 

GEN_FILES += \
./device_linker.cmd \
./device.opt \
./ti_msp_dl_config.c 

C_DEPS += \
./main.d \
./ti_msp_dl_config.d \
./startup_mspm0g350x_ticlang.d 

GEN_OPTS += \
./device.opt 

OBJS += \
./main.o \
./ti_msp_dl_config.o \
./startup_mspm0g350x_ticlang.o 

GEN_MISC_FILES += \
./device.cmd.genlibs \
./ti_msp_dl_config.h \
./Event.dot 

OBJS__QUOTED += \
"main.o" \
"ti_msp_dl_config.o" \
"startup_mspm0g350x_ticlang.o" 

GEN_MISC_FILES__QUOTED += \
"device.cmd.genlibs" \
"ti_msp_dl_config.h" \
"Event.dot" 

C_DEPS__QUOTED += \
"main.d" \
"ti_msp_dl_config.d" \
"startup_mspm0g350x_ticlang.d" 

GEN_FILES__QUOTED += \
"device_linker.cmd" \
"device.opt" \
"ti_msp_dl_config.c" 

C_SRCS__QUOTED += \
"../main.c" \
"./ti_msp_dl_config.c" \
"D:/CCS/mspm0_sdk_2_05_01_00/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c" 

SYSCFG_SRCS__QUOTED += \
"../test.syscfg" 


