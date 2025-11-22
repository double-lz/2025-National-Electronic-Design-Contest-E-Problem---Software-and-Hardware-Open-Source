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



int main(void)
{
    SYSCFG_DL_init();
    SysTick_Init();
    DL_TimerA_startCounter(PWM_ALL_INST);       //启用PWM计数器
    DL_TimerG_startCounter(TIMER_0_INST);       //启动定时器计数器
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);       //启用串口0接收中断

    DL_Timer_startCounter(PWM_0_INST);          //步进电机1PWM
    DL_Timer_startCounter(PWM_1_INST);          //步进电机2PWM
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);        //启用定时器中断
    //外设初始化
    Pid_Init(0.084,0.00047,0);
    OLED_Init();
    //Pid_Init();
    BUZZER_OFF(); 
    LED1_OFF();
    LED2_OFF();
    while (1) 
    {  
        Timer_work(); 
        key_work();
        uart_work();
        oled_show();   
        Tick.mpu_flag=1;
        //LED2_ON();
      
                
        if(mode==1&&keycnt==4){

        if(x_site>=-2&&x_site<=2&&y_site<=20&&y_site>=15)
        {
            Motor.button=0;
            LED2_ON();
            L_PWM=R_PWM=0;
            Set_PWM(L_PWM,R_PWM); 
            mode=0;
        }
        else
        { 
            Motor.button=1;   
        
        }
        }
        
        if(mode==1&&keycnt==3)
        {
            //Pid_Init(0.7,0.0001,0);
            Pid_Init(0.8,0,0);
            Motor.button=1;
            LED2_ON();
            // if(x_site>=30)
            // {
            //     x_buchang=200;
            // }
            if(keycnt==4)
            { 
                Motor.button=0;
                L_PWM=R_PWM=0;
                Set_PWM(L_PWM,R_PWM); 
                LED2_OFF();

            }
        }
        if(mode==5)
        {
            mode=0;
            keycnt=0;
        }
               
            
}
}
              
        
    



void TIMER_0_INST_IRQHandler(void)
 {   
    

    if(Motor.button!=0)
    {
    if(Tick.steppid++>=2)
    {
        Tick.steppid=0;  
        Tick.step_flag=1;
       //2.12
        PID_caculate(&x_stepPid,x_site,0);
        PID_caculate(&y_stepPid,y_site,18);
        L_PWM=Calculate_target(x_stepPid.output+x_buchang);
        R_PWM=Calculate_target(y_stepPid.output);
        //x_stepPid.output=constrain_double(x_stepPid.output,-50,50);

        // I_limit(&x_stepPid, -4000, 4000);
        // I_limit(&y_stepPid, -4000, 4000);
        Set_PWM(L_PWM,R_PWM);                    
    }
    }
    if(mode==2&&keycnt==4)
    {
        // time_x++;
        // if(time_x<=500)
        // {
        //     L_PWM=0;
        //     R_PWM=Calculate_target(20);
        //     Set_PWM(L_PWM,R_PWM);
        // }
        // else
        // {
            L_PWM=Calculate_target(30);
            R_PWM=0;
            Set_PWM(L_PWM,R_PWM);
        //}
         if(x_site>0&&x_site<=80)
        {
            L_PWM=R_PWM=0;
            mode=1;
            time_x=0;
     
            Set_PWM(L_PWM,R_PWM);
        }
    
    }
     if(mode==4&&keycnt==4)
    {
        // time_x++;
        // if(time_x<=500)
        // {
        //     L_PWM=0;
        //     R_PWM=Calculate_target(20);
        //     Set_PWM(L_PWM,R_PWM);
        // }
        // else
        // {
            L_PWM=Calculate_target(-30);
            R_PWM=0;
            Set_PWM(L_PWM,R_PWM);
        //}
         if(x_site>0&&x_site<=80)
        {
            L_PWM=R_PWM=0;
            mode=1;
            time_x=0;
            Set_PWM(L_PWM,R_PWM);
        }
    
    } 
 }
   

void SysTick_Handler(void)
{
    tick_ms++;	
    
}

