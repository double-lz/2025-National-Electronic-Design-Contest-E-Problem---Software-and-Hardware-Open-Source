#ifndef MOTOR_HH
#define MOTOR_HH

#include "ti_msp_dl_config.h"
#include "mpu6050.h"

void Car_Move(double PL,double PR);


void PWM_D0(double Compare);
void PWM_D1(double Compare);
void PWM_D2(double Compare);
void PWM_D3(double Compare);

int16_t Encoder1_Get(void);
int16_t Encoder2_Get(void);
void servo_control(double an1,double an2);
void Car_setspeed(uint8_t Motor1,uint8_t Motor2);//设定目标速度
void xun(void);
float get_sensor_actual(void);
void xunji_pid(void);
float convert_to_continuous_yaw(float current_yaw);
#endif