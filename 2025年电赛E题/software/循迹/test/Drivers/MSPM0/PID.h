#ifndef __PID_H__
#define __PID_H__

#include "ti_msp_dl_config.h"

typedef struct
{
    double Kp,Ki,Kd;    //比例，积分，微分系数
    double target_val;  //目标值
    double actual_val;  //实际值
    double err;         //当前偏差
    double err_last;    //上次偏差
    double err_sum;     //误差累计值
    double output;      //输出
}tPid;

extern tPid EncoderLPid,EncoderRPid,GxPid,TurnErrorPid,jiaoduPid;

void Pid_Init(void);
void PID_caculate(tPid * pid,double actual_val,double target_val);
void I_limit(tPid * pid, double low, double high);
int constrain_double(double amt, double low, double high);


#endif
