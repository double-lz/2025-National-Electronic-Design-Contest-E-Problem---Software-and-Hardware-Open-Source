#include "PID.h"

//给结构体类型变量赋初值
void Pid_Init(void)
{
	EncoderLPid.Kp=40.455;
	EncoderLPid.Ki=0;
	EncoderLPid.Kd=0;
	EncoderRPid.Kp=40.455;
	EncoderRPid.Ki=0;
	EncoderRPid.Kd=0;

	TurnErrorPid.Kp=5.2;
	TurnErrorPid.Ki=0;
	TurnErrorPid.Kd=10;
}

void PID_caculate(tPid * pid,double actual_val,double target_val)
{
    pid->actual_val = actual_val;                   //传递真实值
    pid->target_val = target_val;

    pid->err =  pid->target_val-pid->actual_val;   //当前误差=目标值-真实值
		
    pid->err_sum += pid->err;                       //误差累计值 = 当前误差累计和
	
	// I_limit(&EncoderLPid, -5000, 5000);
	// I_limit(&EncoderRPid, -5000, 5000);
    //输出 = Kp*当前误差 + Ki*误差累计值 + Kd*(当前误差-上次误差)
    pid->output = pid->Kp*pid->err + pid->Ki*pid->err_sum + pid->Kd*(pid->err - pid->err_last);

    pid->err_last = pid->err;   //保存上次误差: 这次误差赋值给上次误差
}

//I限幅：
void I_limit(tPid * pid, double low, double high)
{
    if(pid->err_sum<low)pid->err_sum=low;
    if(pid->err_sum>high)pid->err_sum=high;
}

int constrain_double(double amt, double low, double high)
{
    return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}
