#ifndef _MAIN_H_
#define _MAIN_H_

#include "clock.h"

#include "mpu6050.h"
#include "oled_software_i2c.h"
#include "oled_hardware_i2c.h"
#include "oled_software_spi.h"
#include "oled_hardware_spi.h"
#include "ultrasonic_capture.h"
#include "ultrasonic_gpio.h"
#include "bno08x_uart_rvc.h"


typedef struct{
		uint8_t encoder;
        uint8_t encoder_flag;
		uint16_t mpu;
        uint8_t mpu_flag;
		uint8_t encoderpid;
        uint8_t encoderpid_flag;
		uint8_t gxpid;
        uint8_t gxpid_flag;
		uint8_t jiaodupid;
        uint8_t jiaodu_flag;
		uint8_t turnerrorpid;
        uint8_t turnerrorpid_flag;
		uint8_t motor;
        uint8_t motor_flag;
		uint8_t steppid;
		uint16_t step_flag;
		uint16_t fristep_flag;
}_st_tick;

typedef struct{
		int16_t left;
		int16_t right;
}_st_encoder;

typedef struct{
		double left;
		double right;
		double run_Lspeed;
		double run_Rspeed;
		double turn_error;
		double track_l;
		double track_r;
		uint8_t button;
		int16_t Lbuchang;
		int16_t Rbuchang;
}_st_motor;

typedef struct{
        short gyro[3];
		int16_t gx;
		int16_t gy;
		int16_t gz;
		float pitch;
		float roll;
		float yaw;
		float chazhi_pitch;
		float chazhi_roll;
		float chazhi_yaw;
		float CAL_pitch;
		float CAL_roll;
		float CAL_yaw;
}_st_mpu;
extern _st_tick Tick;
extern _st_encoder Encoder;
extern _st_motor Motor;
extern _st_mpu Mpu;

#endif  /* #ifndef _MAIN_H_ */
