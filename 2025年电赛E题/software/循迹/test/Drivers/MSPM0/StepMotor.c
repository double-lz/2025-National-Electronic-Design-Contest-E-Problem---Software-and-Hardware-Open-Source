// #include "StepMotor.h"

// // 步进电机参数配置
// #define STEPS_PER_REVOLUTION 200    // 电机固有步数/圈(360°/1.8°=200步)
// #define MICROSTEPS 16               // 细分数
// #define PWM_CLOCK_FREQ 10000000     // PWM时钟频率（Hz）
// //Target为目标转速,单位:rpm
// // 计算目标转速对应的PWM周期计数值
// int Calculate_target(int Target) 
// {
	
// 	if (Target==0) return 0;//如果目标值为0，直接返回0失能电机
//     // 方向由Target的符号决定，数值部分表示转速（RPM）
//     int direction = (Target >= 0) ? 1 : -1;
//     float speed = (float)abs(Target); // 转速绝对值（RPM）
    
//     // 计算每转需要的总步数（考虑细分）
//     float stepsPerRevolution = STEPS_PER_REVOLUTION * MICROSTEPS;
    
//     // 计算每秒需要的步数（SPM: Steps Per Minute -> SPS: Steps Per Second）
//     float stepsPerSecond = (speed * stepsPerRevolution) / 60.0f;
    
//     // 计算PWM频率（Hz）：每秒需要的脉冲数
//     float pwmFrequency = stepsPerSecond;
    
//     // 计算对应的PWM周期值（Period_PWM_Count）
//     // 周期值 = PWM时钟频率 / PWM目标频率 - 1
//     uint16_t periodValue = (uint16_t)((PWM_CLOCK_FREQ / pwmFrequency) - 1);
    
//     // 确保计算结果在有效范围内（0-65535）
//     if (periodValue > 65535) {
//         periodValue = 65535; // 限制最大值
//     }
//     // 返回带方向的周期值
//     return direction * periodValue;
// }
// //步进电机驱动函数
// void Set_PWM(int L_Target,int R_Target)
// {
// 	 if(L_Target>0)//步进电机1控制
//     {
// 		DL_GPIO_setPins(EN_PORT,EN_MA_PIN);//设置使能引脚
// 		DL_GPIO_setPins(DIR_PORT,DIR_A_PIN);//设置方向引脚
// 		DL_TimerA_setLoadValue(PWM_0_INST,abs(L_Target));//设置Period_PWM_Count,改变PWM频率
// 		DL_Timer_setCaptureCompareValue(PWM_0_INST,abs(L_Target/2),GPIO_PWM_0_C0_IDX);//设置PWM占空比为50%
//     }
//     else if(L_Target<0)
//     {
// 		DL_GPIO_setPins(EN_PORT,EN_MA_PIN);//设置使能引脚
// 		DL_GPIO_clearPins(DIR_PORT,DIR_A_PIN);//设置方向引脚
// 		DL_TimerA_setLoadValue(PWM_0_INST,abs(L_Target));//设置Period_PWM_Count,改变PWM频率
// 		DL_Timer_setCaptureCompareValue(PWM_0_INST,abs(L_Target/2),GPIO_PWM_0_C0_IDX);//设置PWM占空比为50%
//     }
// 	else DL_GPIO_clearPins(EN_PORT,EN_MA_PIN);//使能引脚失能
// 	if(R_Target>0)//步进电机2控制
//     {
// 		DL_GPIO_setPins(EN_PORT,EN_MB_PIN);//设置使能引脚
// 		DL_GPIO_setPins(DIR_PORT,DIR_B_PIN);//设置方向引脚
// 		DL_TimerG_setLoadValue(PWM_1_INST,abs(R_Target));//设置Period_PWM_Count,改变PWM频率
//         DL_Timer_setCaptureCompareValue(PWM_1_INST,abs(R_Target/2),GPIO_PWM_1_C1_IDX);//设置PWM占空比为50%
//     }
//     else if(R_Target<0)
//     {
// 		DL_GPIO_setPins(EN_PORT,EN_MB_PIN);//设置使能引脚
// 		DL_GPIO_clearPins(DIR_PORT,DIR_B_PIN);//设置方向引脚
// 		DL_TimerG_setLoadValue(PWM_1_INST,abs(R_Target));//设置Period_PWM_Count,改变PWM频率
// 		DL_Timer_setCaptureCompareValue(PWM_1_INST,abs(R_Target/2),GPIO_PWM_1_C1_IDX);//设置PWM占空比为50%
//     }

// 	else 
//   {DL_GPIO_clearPins(EN_PORT,EN_MB_PIN);}//使能引脚失能
// }
