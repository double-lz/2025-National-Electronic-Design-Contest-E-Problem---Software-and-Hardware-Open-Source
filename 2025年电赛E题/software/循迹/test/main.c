/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior 
 */


#include "alldata.h"
extern float base_speed;
void renwu(void) //任务函数
{   

    if(quanshu==1)//选择圈数为一的时候
    {   if(keyquan==0)
    {
        if(m0<=4)//yaw小于352
        {
            
           base_speed=30; xunji_flag=1;
        }
        else 
        {
            // far_flag=1;
            //清除循迹标志位,并停车
        xunji_flag=0;Car_setspeed(0, 0);Car_Move(0, 0);base_speed=0;quanshu=0;
        keycnt=0;
        
        }
    }
    else if(keyquan==1){
        if(m0<=4)//yaw小于352
        { 
           base_speed=20; xunji_flag=1;
        //    if(L2==1)
        //     {
        //         base_speed=15;biansu_flag=1;
        //     }
        }
        else {
         xunji_flag=0;Car_setspeed(0, 0);Car_Move(0, 0);base_speed=0;quanshu=0;
        keycnt=0;
        }
    }
    else {
        if(m0<=8)//yaw小于352
        { 
           base_speed=20; xunji_flag=1;
        }
        else {
         xunji_flag=0;Car_setspeed(0, 0);Car_Move(0, 0);base_speed=0;quanshu=0;
        keycnt=0;
        }
    }
    }
    


    if(quanshu==2)//选择圈数为一的时候
    {
        
        if(m0<=8)//yaw小于352
        {
            base_speed=30; xunji_flag=1;
        }
        else 
        {
            // far_flag=1;
            //清除循迹标志位,并停车
        xunji_flag=0;Car_setspeed(0, 0);Car_Move(0, 0);base_speed=0;quanshu=0;
        keycnt=0;
        }
    }
    if(quanshu==3)//选择圈数为一的时候
    {
        if(m0<=12)//yaw小于352
        {
            base_speed=30; xunji_flag=1;
        }
        else 
        {
            //清除循迹标志位,并停车
        xunji_flag=0;Car_setspeed(0, 0);Car_Move(0, 0);base_speed=0;quanshu=0;
        keycnt=0;
        }
    }
        if(quanshu==4)//选择圈数为一的时候
    {
        if(m0<=16)//yaw小于352
        {
            base_speed=30; xunji_flag=1;
        }
        else 
        {
            //清除循迹标志位,并停车
        xunji_flag=0;Car_setspeed(0, 0);Car_Move(0, 0);base_speed=0;quanshu=0;
        keycnt=0;
        }
    }
    if(quanshu==5)//选择圈数为一的时候
    {
        if(m0<=20)//yaw小于352
        {
            base_speed=30; xunji_flag=1;
        }
        else 
        {
            //清除循迹标志位,并停车
        xunji_flag=0;Car_setspeed(0, 0);Car_Move(0, 0);base_speed=0;quanshu=0;
        keycnt=0;
        }
    }
    
}

int main(void)
{
    SYSCFG_DL_init();
    SysTick_Init();
    DL_TimerA_startCounter(PWM_ALL_INST);       //启用PWM计数器
    // DL_TimerA_startCounter(PWM_ALL_INST);       //启用PWM计数器
    DL_TimerG_startCounter(TIMER_0_INST);       //启动定时器计数

    //NVIC_EnableIRQ(GPIO_Encoder_GPIOA_INT_IRQN);
    NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOA_INT_IRQN); //陀螺仪中断
    NVIC_EnableIRQ(GPIO_Encoder_GPIOB_INT_IRQN);  //编码器中断

    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);        //启用定时器中断
    //外设初始化
    MPU6050_Init();
    OLED_Init();
    Pid_Init();
    BUZZER_OFF(); 
    LED1_OFF();
    LED2_OFF();
    while (1) 
    {
        Motor.button=1;
        Timer_work(); 
        key_work();
        oled_show();   
        // if(L2==1&&far_flag==0)
        // {
        //     far_flag=1;
        //     m0++;
        // }
        // if(m0==5){Car_setspeed(0, 0);Car_Move(0, 0);}
        //从白到黑的时候计次加一,完成一次拐弯检测
        if(baohu_flag==0)
        {

            switch (xia_flag) {
            case 0:if(L2==1){xia_flag=1;}break;
            case 1:if(L2==0){baohu_flag=1;m0++;if(keyquan!=0)biansu_flag=1;}break;
         }
        }
        
        if(keyquan==0)
        {
       if(keycnt==1){if(keynum==2){quanshu++;if(quanshu>=6){quanshu=1;}}}//状态一:圈数选择
       if(keycnt==2)
       {
                    kaishi_flag=1;//开始计算PID                  
                    if(kaishi_flag==1){renwu();}//只有零漂结束后才能进行任务
       }
        }
        else
        {
            if(start_flag==1)
            {
                if(keyquan==1)
                {
                    kaishi_flag=1;//开始计算PID
                    quanshu=1;
                    if(kaishi_flag==1){renwu();}//只有零漂结束后才能进行任务

                }
            }
        }

    }
}


void TIMER_0_INST_IRQHandler(void)
 {   
    if(kaishi_flag==1)
    {

     if(Tick.turnerrorpid++>=6)
    {       
        if(xunji_flag>=1)//当圈数不满足时,一直循迹
        {
              xunji_pid();
        }

        
        Tick.turnerrorpid=0;
    }       
    //速度环
    if(Tick.encoderpid++>=5)
    {
            PID_caculate(&EncoderLPid,Encoder.left,Motor.run_Lspeed);
            PID_caculate(&EncoderRPid,Encoder.right,Motor.run_Rspeed);
            // I_limit(&EncoderLPid, -3000, 3000);
            // I_limit(&EncoderRPid, -3000, 3000);
            EncoderLPid.output=constrain_double(EncoderLPid.output,-3000,3000);
            EncoderRPid.output=constrain_double(EncoderRPid.output,-3000,3000);
            Car_Move(EncoderLPid.output, EncoderRPid.output);
        Tick.encoderpid=0;
    }
    //编码器读数
	if(Tick.encoder++>=4)
	{
		Tick.encoder_flag=1;
		Tick.encoder=0;
	}
    if(baohu_flag==1)
    {
        time_3s++;if(time_3s==3000){baohu_flag=0;time_3s=0;xia_flag=0;}//3s内xia_flag不清零

    }

    }
   
    //陀螺仪零飘
    // if(Tick.mpu_flag==0)
    // {
    //     Tick.mpu++;
    //     if(Tick.mpu>=20000)
    //     {           
    //         Tick.mpu_flag=1;
    //         Tick.mpu=0;
    //         Mpu.chazhi_pitch = pitch;
    //         Mpu.chazhi_roll = roll;
    //         Mpu.chazhi_yaw = yaw;
    //     }   	 
    // }
    if(biansu_flag==1)
    {
      time_2s++;if(time_2s<3000){base_speed=10;}
                else {time_2s=0;biansu_flag=0;yizhi_flag=1;}
    }
    if(yizhi_flag==1)
    {
        if(++t_200ms==500){if(base_speed<20){base_speed++;t_200ms=0;}else {yizhi_flag=0;
        
        }}
    }
}
void SysTick_Handler(void)
{
    tick_ms++;	
    
}

