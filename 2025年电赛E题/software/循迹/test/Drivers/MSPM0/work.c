#include "main.h"
#include "work.h"
#include "alldata.h"
extern float base_speed;
extern uint8_t quanshu,m0;
extern unsigned char L2,L1,M0,R1,R2;
void oled_show(void)  //oled显示函数
{
    // if(Tick.mpu_flag==1)
    // {
       
        // if(Tick.mpu_flag==1&&clear_flag==0){OLED_Clear();clear_flag=1;}
        // OLED_ShowString(15*6,0,(uint8_t *)"L:",16);
        // OLED_ShowString(15*6,2,(uint8_t *)"R:",16);
        // OLED_ShowString(15*6,4,(uint8_t *)"D:",16);
        // //OLED_ShowString(0,6,(uint8_t *)"Keynum",16);   
        // OLED_ShowString(0,0,(uint8_t *)"Pitch",8);
        // OLED_ShowString(0,2,(uint8_t *)" Roll",8);
        OLED_ShowString(0,4,(uint8_t *)"  Yaw",8);

        // sprintf((char *)oled_buffer, "%d", L2);
        // OLED_ShowString(15*3,0,oled_buffer,16);
        sprintf((char *)oled_buffer, "%-3.1f", new_yaw);
        OLED_ShowString(15*3,2,oled_buffer,16);
        // sprintf((char *)oled_buffer, "%-3.1f", Mpu.yaw);
        // OLED_ShowString(15*3,4,oled_buffer,16);

        sprintf((char *)oled_buffer, "%3d", Encoder.left);
        OLED_ShowString(7*15,0,oled_buffer,16);
        sprintf((char *)oled_buffer, "%3d", Encoder.right);
        OLED_ShowString(7*15,2,oled_buffer,16);

        // sprintf((char *)oled_buffer, "%d", data);
        // OLED_ShowString(7*15,4,oled_buffer,16);
        // sprintf((char *)oled_buffer, "%3d", Tick.encoder);
        // OLED_ShowString(5*15,6,oled_buffer,16);
        
        //按键值
        sprintf((char *)oled_buffer, "%3d", m0);
        OLED_ShowString(0,6,oled_buffer,16);
        sprintf((char *)oled_buffer, "%4d", quanshu);
        OLED_ShowString(15*5,6,oled_buffer,16);
        //pid电机输出值
        // sprintf((char *)oled_buffer, "%4.1f", Motor.left);
        // OLED_ShowString(0,6,oled_buffer,16);
        // sprintf((char *)oled_buffer, "%4.1f", Motor.right);
        // OLED_ShowString(15*5,6,oled_buffer,16);

        //ccd读值
        // sprintf((char *)oled_buffer, "%3d", CCD_Zhongzhi);
        // OLED_ShowString(15*7,4,oled_buffer,16);

    //     sprintf((char *)oled_buffer, "%6d", accel[0]);
    //     OLED_ShowString(15*6,0,oled_buffer,8);
    //     sprintf((char *)oled_buffer, "%6d", accel[1]);
    //     OLED_ShowString(15*6,1,oled_buffer,8);
    //     sprintf((char *)oled_buffer, "%6d", accel[2]);
    //     OLED_ShowString(15*6,2,oled_buffer,8);

    //     sprintf((char *)oled_buffer, "%6d", gyro[0]);
    //     OLED_ShowString(15*6,5,oled_buffer,8);
    //     sprintf((char *)oled_buffer, "%6d", gyro[1]);
    //     OLED_ShowString(15*6,6,oled_buffer,8);
    //     sprintf((char *)oled_buffer, "%6d", gyro[2]);
    //     OLED_ShowString(15*6,7,oled_buffer,8);
    // }
    // else
    // {
        
    //     OLED_ShowString(0,0,(uint8_t *)"MPU6050Init....",16);
    //     OLED_ShowString(0,4,(uint8_t *)"Time:",16);
    //     sprintf((char *)oled_buffer, "%5d", Tick.mpu);
    //     OLED_ShowString(15*3,4,oled_buffer,16);
    // }
}



void uart_work(void) //串口函数
{
    if (Serial_RxFlag == 1) {
        // // 处理接收到的数据
        // data=atoi(Serial_RxPacket);
        // printf("收到数据包: %s\n", Serial_RxPacket);      
        // printf("data: %d\n", data);    
        // LED1_ON();LED2_ON();
        // // 重置标志位以接收下一个包
        Serial_RxFlag = 0;
    }
    //printf
}

void ccd_work(void) //ccd
{
    RD_TSL();             // 读取CCD数据
    Find_CCD_Median();    // 计算CCD数据中值
}

void stepmotor1_ONUP(void) //X步进电机开
{
    L_PWM=Calculate_target(30); //设置电机每分钟120转
    //R_PWM=Calculate_target(30);  //设置电机每分钟120转
    Set_PWM(L_PWM,R_PWM);
}
void stepmotor1_ONDOWN(void) //X步进电机开
{
    L_PWM=Calculate_target(-30); //设置电机每分钟120转
    //R_PWM=Calculate_target(-30);  //设置电机每分钟120转
    Set_PWM(L_PWM,R_PWM);
}
void stepmoto1_OFF(void) //X步进电机关
{
    L_PWM=0;
    Set_PWM(L_PWM,R_PWM);
}

void stepmotor2_ONUP(void) //Y步进电机开
{
    //L_PWM=Calculate_target(30); //设置电机每分钟120转
    R_PWM=Calculate_target(30);  //设置电机每分钟120转
    Set_PWM(L_PWM,R_PWM);
}
void stepmotor2_ONDOWN(void) //Y步进电机开
{
    //L_PWM=Calculate_target(30); //设置电机每分钟120转
    R_PWM=Calculate_target(-30);  //设置电机每分钟120转
    Set_PWM(L_PWM,R_PWM);
}
void stepmoto2_OFF(void) //Y步进电机关
{
    R_PWM=0;
    Set_PWM(L_PWM,R_PWM);
}

void key_work(void) //按键工作函数
{
    keynum=Key_GetNum();
    if(keynum==1){keycnt++;if(keycnt==3){keycnt=0;}}
    if(keynum==3){keyquan++;if(keyquan>=3){keyquan=0;}}
    if(keynum==2){start_flag=1;}
    // if(keynum==2)keycnt=2;
    // if(keynum==3)keycnt=3; 
    // if(keynum==4)keycnt=4; 
    //if(keycnt>1)keycnt=0;
    // if(keycnt==1)
    // {
    //     stepmotor_ON(); //步进电机开
    // }
    // else
    // {
    //     stepmotor_OFF(); //步进电机关
    // }
    
    // if(keycnt==1)
    // {        
    //     //work();
    //     // Motor.button=1; 
    //     // Motor.run_Lspeed=Motor.run_Rspeed=20;
    // }
    // if(keycnt==0)
    // {
    //     Motor.button=0; 
    //     Motor.run_Lspeed=Motor.run_Rspeed=0;
    // }
}

void Timer_work(void)
{

    if(Motor.button!=0)
    {
        
    }
    else
    {   
        //Car_Move(0,0);
        Motor.right= Motor.right=0;
        EncoderLPid.output=EncoderRPid.output=0;
        jiaoduPid.output=0;
        GxPid.output=0;

    }
    //编码器读数
    if(Tick.encoder_flag==1)
    {
        Encoder.left=Encoder1_Get();
        Encoder.right=Encoder2_Get();
        Tick.encoder_flag=0;
    }

}

void work(void)  //任务函数
{
    if(data==0||data==1||data==2||data==4)
    {
        Motor.button=1;
        jiaoduPid.target_val=0;
        Motor.run_Lspeed=20;
        Motor.run_Rspeed=20;
        work_1=0; 
    }
    if(data==3){
        work_1=1; 
    if(work_1==1)
    {
        
        if(work_flag==0)
        {
            Motor.button=0;
        if(Mpu.yaw<90)
        {
            
            Car_Move(-700,0);
        }
        else
        {
            Car_Move(0,0);            
        }
        }
        if(work_flag==1)
        {
            Motor.button=1;
            jiaoduPid.target_val=90;
            Motor.run_Lspeed=-30;
            Motor.run_Rspeed=-30;
        }
        if(work_flag==2)
        {
            Motor.button=1;
            jiaoduPid.target_val=90;
            Motor.run_Lspeed=Motor.run_Rspeed=0;
        }
        if(work_flag==3)
        {
            Motor.button=1;
            jiaoduPid.target_val=90;
            Motor.run_Lspeed=Motor.run_Rspeed=35;
        }
        if(work_flag==4)
        {
            Motor.button=1;
            jiaoduPid.target_val=90;
            Motor.run_Lspeed=Motor.run_Rspeed=0;
        }
        if(work_flag==5)
        {
            Motor.button=0;
            jiaoduPid.target_val=0;
             Motor.run_Lspeed=Motor.run_Rspeed=0;
            if(Mpu.yaw>0)
        {
            Car_Move(700,0);
        }
        else
        {
            Car_Move(0,0);
        }
        }
        if(work_flag==6)
        {
            Motor.button=1;
            jiaoduPid.target_val=0;
            Motor.run_Lspeed=Motor.run_Rspeed=0;
        }
        if(work_flag==7){
            work_1=0;
            jiaoduPid.target_val=0;
            Motor.button=1;
            data=0;
        }
        }
    }
    }

