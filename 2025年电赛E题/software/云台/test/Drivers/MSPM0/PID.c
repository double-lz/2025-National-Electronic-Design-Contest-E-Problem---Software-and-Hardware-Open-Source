#include "PID.h"

//给结构体类型变量赋初值
void Pid_Init(double kp,double ki,double kd)
{
	// x_stepPid.Kp=0.084;
	// x_stepPid.Ki=0.00047;
	// x_stepPid.Kd=0;

	// y_stepPid.Kp=-0.092;                                                                                                               ;
	// y_stepPid.Ki=-0.00032;
	// y_stepPid.Kd=0;
	x_stepPid.Kp=kp;
	x_stepPid.Ki=ki;
	x_stepPid.Kd=kd;

	y_stepPid.Kp=-kp;                                                                                                               ;
	y_stepPid.Ki=-ki;
	y_stepPid.Kd=kd;
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
