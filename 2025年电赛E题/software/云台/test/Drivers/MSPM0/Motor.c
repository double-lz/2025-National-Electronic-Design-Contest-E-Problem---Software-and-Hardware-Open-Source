#include "ti_msp_dl_config.h"
#include "Motor.h"
#include "interrupt.h"
#include "clock.h"
#include "mpu6050.h"
#include "bno08x_uart_rvc.h"
#include "wit.h"
#include "main.h"
uint32_t gpioA;
uint32_t gpioB;
int32_t gEncoderCount = 0;
int32_t gEncoderCount1 = 0;
volatile int32_t Front_Left_Count = 0;
volatile int32_t Front_Right_Count = 0;
void Car_Move(double PL,double PR)
{	
	if(PR==0){PWM_D0(0);DL_GPIO_clearPins(MOTOR_AIN1_PORT,MOTOR_AIN1_PIN);DL_GPIO_clearPins(MOTOR_AIN2_PORT, MOTOR_AIN2_PIN);}	
	if(PR<0){PWM_D0(-PR);DL_GPIO_clearPins(MOTOR_AIN1_PORT,MOTOR_AIN1_PIN);DL_GPIO_setPins(MOTOR_AIN2_PORT,MOTOR_AIN2_PIN);}
	if(PR>0){PWM_D0(PR);DL_GPIO_clearPins(MOTOR_AIN2_PORT,MOTOR_AIN2_PIN);DL_GPIO_setPins(MOTOR_AIN1_PORT,MOTOR_AIN1_PIN);}
			
			
	
	if(PL==0){PWM_D1(0);DL_GPIO_clearPins(MOTOR_BIN1_PORT,MOTOR_BIN1_PIN);DL_GPIO_clearPins(MOTOR_BIN2_PORT, MOTOR_BIN2_PIN);}
	if(PL<0){PWM_D1(-PL);DL_GPIO_clearPins(MOTOR_BIN2_PORT,MOTOR_BIN2_PIN);DL_GPIO_setPins(MOTOR_BIN1_PORT,MOTOR_BIN1_PIN);}
	if(PL>0){PWM_D1(PL);DL_GPIO_clearPins(MOTOR_BIN1_PORT,MOTOR_BIN1_PIN);DL_GPIO_setPins(MOTOR_BIN2_PORT,MOTOR_BIN2_PIN);}
			
			
}
void servo_control(double an1,double an2)
{
  double ser1,ser2;
  uint32_t CompareValue1;
  ser1=5*an1/135+2.5;
  ser2=5*an2/135+2.5;
  CompareValue1=40000-40000*ser1/100.0;
  DL_TimerG_setCaptureCompareValue(PWM_SERVO_INST,CompareValue1,DL_TIMER_CC_0_INDEX);

  uint32_t CompareValue2;
  CompareValue2=40000-40000*ser2/100.0;
  DL_TimerG_setCaptureCompareValue(PWM_SERVO_INST,CompareValue2,DL_TIMER_CC_1_INDEX);
}

void PWM_D0(double Compare)
{
	DL_TimerA_setCaptureCompareValue(PWM_ALL_INST, 3200-Compare, DL_TIMER_CC_0_INDEX);
}

void PWM_D1(double Compare)
{
	DL_TimerA_setCaptureCompareValue(PWM_ALL_INST, 3200-Compare, DL_TIMER_CC_1_INDEX);
}
void PWM_D2(double Compare)
{
	DL_TimerA_setCaptureCompareValue(PWM_ALL_INST, 3200-Compare, DL_TIMER_CC_2_INDEX);
}
void PWM_D3(double Compare)
{
	DL_TimerA_setCaptureCompareValue(PWM_ALL_INST, 3200-Compare, DL_TIMER_CC_3_INDEX);
}


int16_t Encoder1_Get(void)
{
    int16_t temp;
    temp=-Front_Left_Count;
    Front_Left_Count=0;
    return temp;
}

int16_t Encoder2_Get(void)
{
    int16_t temp;
    temp=Front_Right_Count;
    Front_Right_Count=0;
    return temp;
}


void GROUP1_IRQHandler(void)
{
//    uint32_t gpioA = DL_GPIO_getEnabledInterruptStatus(GPIOA, GPIO_Encoder_PIN_Front_Left_A_PIN|GPIO_MPU6050_PIN_INT_PIN );
//     uint32_t gpioB = DL_GPIO_getEnabledInterruptStatus(GPIOB, GPIO_Encoder_PIN_Front_Right_A_PIN  );

//     if (gpioA & GPIO_Encoder_PIN_Front_Left_A_PIN) //left编码器
//     {
//         if(DL_GPIO_readPins(GPIO_Encoder_PIN_Front_Left_B_PORT, GPIO_Encoder_PIN_Front_Left_B_PIN))
//             Front_Left_Count--;
//         else 
//             Front_Left_Count++;
//         DL_GPIO_clearInterruptStatus(GPIO_Encoder_PIN_Front_Left_A_PORT, GPIO_Encoder_PIN_Front_Left_A_PIN);
//     }

//     if (gpioB & GPIO_Encoder_PIN_Front_Right_A_PIN) //right编码器
//     {
//         if(DL_GPIO_readPins(GPIO_Encoder_PIN_Front_Right_B_PORT, GPIO_Encoder_PIN_Front_Right_B_PIN))
//             Front_Right_Count--;
//         else
//             Front_Right_Count++;
//         DL_GPIO_clearInterruptStatus(GPIO_Encoder_PIN_Front_Right_A_PORT, GPIO_Encoder_PIN_Front_Right_A_PIN);
//     }
//     if(gpioA & GPIO_MPU6050_PIN_INT_PIN) //陀螺仪读取
//     {
//          Read_Quad();
//          Mpu.pitch=pitch-Mpu.chazhi_pitch;
//          Mpu.roll=roll-Mpu.chazhi_roll;
//          Mpu.yaw=yaw-Mpu.chazhi_yaw;
//          Mpu.gx=gyro[0];
//          Mpu.gy=gyro[1];
//          Mpu.gz=gyro[2];
//          DL_GPIO_clearInterruptStatus(GPIO_MPU6050_PORT, GPIO_MPU6050_PIN_INT_PIN);
//     }    
}
void Car_setspeed(uint8_t Motor1,uint8_t Motor2)//设定目标速度
{
    Motor.run_Lspeed=Motor1;
    Motor.run_Rspeed=Motor2;

}