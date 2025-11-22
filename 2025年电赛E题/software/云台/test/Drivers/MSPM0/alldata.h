#ifndef __ALLDATA_H__
#define __ALLDATA_H__

#include "main.h"
#include "ti_msp_dl_config.h"
#include "main.h"
#include "stdio.h"
#include "string.h"
#include  "Delay.h"
#include "Key.h"
#include "Motor.h"
#include "LED.h"
#include "mpu6050.h"
#include "mspm0_i2c.h"
#include "PID.h"
#include "Uart.h"
#include "adc.h"
#include "CCD.h"
#include "work.h"
#include "StepMotor.h"

uint8_t oled_buffer[32];
uint8_t keynum,keycnt,clear_flag,work_1,work_flag,mode,step_first;
int16_t Tick_work;
_st_tick Tick;
_st_encoder Encoder;
_st_motor Motor;
_st_mpu Mpu;
tPid EncoderLPid,EncoderRPid,GxPid,TurnErrorPid,jiaoduPid,x_stepPid,y_stepPid;
uint8_t target_yaw;
int data;
void Timer_work(void);
int32_t L_PWM,R_PWM,jiaodu,tick_jiaodu,time_x;
int16_t x_site,y_site;
uint16_t x_buchang;

#endif
