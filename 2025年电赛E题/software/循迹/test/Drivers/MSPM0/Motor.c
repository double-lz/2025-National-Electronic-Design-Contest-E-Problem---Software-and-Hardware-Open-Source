#include "ti_msp_dl_config.h"
#include "Motor.h"
#include "interrupt.h"
#include "clock.h"
#include "mpu6050.h"
#include "bno08x_uart_rvc.h"
#include "wit.h"
#include "main.h"
#include "PID.h"
#include <stdbool.h>
#include "alldata.h"
extern tPid TurnErrorPid;
extern float new_yaw;

int sensor[5]={0,0,0,0,0};
float sensor_weight[5]={12.2,3.1,0,-3.1,-12.2};
float base_speed =0;  // ????,???????
static float last_valid_bias = 0;
uint32_t gpioA;
uint32_t gpioB;
int32_t gEncoderCount = 0;
int32_t gEncoderCount1 = 0;
volatile int32_t Front_Left_Count = 0;
volatile int32_t Front_Right_Count = 0;
static float g_last_yaw = 0.0f;
static int g_revolution_count = 0;
static bool g_is_yaw_initialized = false;
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
   uint32_t gpioA = DL_GPIO_getEnabledInterruptStatus(GPIOA, GPIO_Encoder_PIN_Front_Left_A_PIN|GPIO_MPU6050_PIN_INT_PIN );
    uint32_t gpioB = DL_GPIO_getEnabledInterruptStatus(GPIOB, GPIO_Encoder_PIN_Front_Right_A_PIN  );

    if (gpioA & GPIO_Encoder_PIN_Front_Left_A_PIN) //left编码器
    {
        if(DL_GPIO_readPins(GPIO_Encoder_PIN_Front_Left_B_PORT, GPIO_Encoder_PIN_Front_Left_B_PIN))
            Front_Left_Count--;
        else 
            Front_Left_Count++;
        DL_GPIO_clearInterruptStatus(GPIO_Encoder_PIN_Front_Left_A_PORT, GPIO_Encoder_PIN_Front_Left_A_PIN);
    }

    if (gpioB & GPIO_Encoder_PIN_Front_Right_A_PIN) //right编码器
    {
        if(DL_GPIO_readPins(GPIO_Encoder_PIN_Front_Right_B_PORT, GPIO_Encoder_PIN_Front_Right_B_PIN))
            Front_Right_Count--;
        else
            Front_Right_Count++;
        DL_GPIO_clearInterruptStatus(GPIO_Encoder_PIN_Front_Right_A_PORT, GPIO_Encoder_PIN_Front_Right_A_PIN);
    }
    // if(gpioA & GPIO_MPU6050_PIN_INT_PIN) //陀螺仪读取
    // {
    //      Read_Quad();
    //      Mpu.pitch=pitch-Mpu.chazhi_pitch;
    //      Mpu.roll=roll-Mpu.chazhi_roll;
    //      Mpu.yaw=yaw-Mpu.chazhi_yaw;
    //      new_yaw=convert_to_continuous_yaw(Mpu.yaw);
    //      Mpu.gx=gyro[0];
    //      Mpu.gy=gyro[1];
    //      Mpu.gz=gyro[2];
    //      DL_GPIO_clearInterruptStatus(GPIO_MPU6050_PORT, GPIO_MPU6050_PIN_INT_PIN);
    // }    
}
void Car_setspeed(uint8_t Motor1,uint8_t Motor2)//设定目标速度
{
    Motor.run_Lspeed=Motor1;
    Motor.run_Rspeed=Motor2;

}
void xun(void)
{
   
    if(DL_GPIO_readPins(Track_L1_PORT, Track_L1_PIN) == 0){L1=0;}else{L1=1;}
    if(DL_GPIO_readPins(Track_L2_PORT, Track_L2_PIN) == 0){L2=0;}else{L2=1;}
    if(DL_GPIO_readPins(Track_M0_PORT, Track_M0_PIN) == 0){M0=0;}else{M0=1;}
    if(DL_GPIO_readPins(Track_R1_PORT, Track_R1_PIN) == 0){R1=0;}else{R1=1;}
    if(DL_GPIO_readPins(Track_R2_PORT, Track_R2_PIN) == 0){R2=0;}else{R2=1;}



	sensor[0]=L2;
	sensor[1]=L1;
	sensor[2]=M0;
	sensor[3]=R1;
	sensor[4]=R2;


}
float get_sensor_actual(void)
{
    float numerator = 0;//权重值
    float denominator = 0;//扫到黑线的灰度个数
    
    xun();//获取状态
    
   
    for(int i=0; i<5; i++) 
	{
        if(sensor[i] == 1)//扫到黑线进入,累加权重
			{
            numerator += sensor_weight[i];//
            denominator += 1.0;//计次加一
            }
    }
    
    //无线状态
    if(denominator == 0) {
		return last_valid_bias;//返回上一次的值

    }
    
 
	last_valid_bias =numerator / denominator;//上一次状态的获取
    return numerator / denominator;
}
void xunji_pid(void)
{
    float sensor_actual;//灰度实际值
    
    

    sensor_actual = get_sensor_actual();//获取实际权重

    PID_caculate(&TurnErrorPid, sensor_actual, 0);
    //防止轮子反转
    if(TurnErrorPid.output > base_speed-1) {
        TurnErrorPid.output = base_speed-1;
    }
    if(TurnErrorPid.output < -(base_speed-1)) {
        TurnErrorPid.output = -(base_speed-1);
    }
    Car_setspeed(base_speed + TurnErrorPid.output, base_speed - TurnErrorPid.output);
}
float convert_to_continuous_yaw(float current_yaw) 
{
    // 定义一个阈值来检测“跳变”。这个值应该大于180，通常取270或300比较安全。
    const float WRAP_AROUND_THRESHOLD = 300.0f;

    // 首次调用时进行初始化
    if (!g_is_yaw_initialized) {
        g_last_yaw = current_yaw;
        g_is_yaw_initialized = true;
        g_revolution_count = 0;
    }

    // 计算与上次读数的差异
    float diff = current_yaw - g_last_yaw;

    // 检测是否发生了“跳变”
    if (diff > WRAP_AROUND_THRESHOLD) {
        // 从正角度跳到负角度 (例如, 从 170° 到 -175°), 实际是向右转, 圈数应该增加
        // 此时 diff 接近 -360 (例如 -175 - 170 = -345)
        // 这段逻辑处理的是从-180跳变到+180的情况，说明是向左转过界
        g_revolution_count--;
    } else if (diff < -WRAP_AROUND_THRESHOLD) {
        // 从负角度跳到正角度 (例如, 从 -170° 到 175°), 实际是向左转, 圈数应该减小
        // 此时 diff 接近 360 (例如 175 - (-170) = 345)
        // 这段逻辑处理的是从+180跳变到-180的情况，说明是向右转过界
        g_revolution_count++;
    }

    // 更新上次的yaw值以备下次调用
    g_last_yaw = current_yaw;

    // 计算连续的yaw值
    float continuous_yaw = current_yaw + (float)g_revolution_count * 360.0f;

    return continuous_yaw;
}