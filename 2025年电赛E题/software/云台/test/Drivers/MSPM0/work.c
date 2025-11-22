#include "main.h"
#include "work.h"
#include "alldata.h"


void oled_show(void)  //oled显示函数
{
    if(Tick.mpu_flag==1)
    {
       
        if(Tick.mpu_flag==1&&clear_flag==0){OLED_Clear();clear_flag=1;}
        // OLED_ShowString(15*6,0,(uint8_t *)"M:",8);
        // OLED_ShowString(15*6,2,(uint8_t *)"K:",8);
        // OLED_ShowString(15*6,4,(uint8_t *)"F:",8);
        //OLED_ShowString(0,6,(uint8_t *)"Keynum",16);   
        OLED_ShowString(0,0,(uint8_t *)"xwucha",8);
        OLED_ShowString(0,2,(uint8_t *)"xout",8);
        OLED_ShowString(0,4,(uint8_t *)"ywucha",8);
        OLED_ShowString(0,6,(uint8_t *)"yout",8);
        sprintf((char *)oled_buffer, "%2d", Motor.button);
        OLED_ShowString(7*15,4,oled_buffer,16);
        sprintf((char *)oled_buffer, "%4d", x_site);
        OLED_ShowString(15*3,0,oled_buffer,16);
        sprintf((char *)oled_buffer, "%4.2f", x_stepPid.output);
        OLED_ShowString(15*3,2,oled_buffer,8);
        sprintf((char *)oled_buffer, "%4d", y_site);
        OLED_ShowString(15*3,4,oled_buffer,16);
        sprintf((char *)oled_buffer, "%4.2f",y_stepPid.output);
        OLED_ShowString(15*3,6,oled_buffer,8);
        sprintf((char *)oled_buffer, "%2d", mode);
        OLED_ShowString(7*15,0,oled_buffer,16);
        sprintf((char *)oled_buffer, "%2d", keycnt);
        OLED_ShowString(7*15,2,oled_buffer,16);


        // sprintf((char *)oled_buffer, "%3d", Tick.encoder);
        // OLED_ShowString(5*15,6,oled_buffer,16);
        
        //按键值
        // sprintf((char *)oled_buffer, "%3d", keycnt);
        // OLED_ShowString(0,6,oled_buffer,16);
        // sprintf((char *)oled_buffer, "%4d", jiaodu);
        // OLED_ShowString(15*5,6,oled_buffer,16);
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
    }
    else
    {
        
        OLED_ShowString(0,0,(uint8_t *)"MPU6050Init....",16);
        OLED_ShowString(0,4,(uint8_t *)"Time:",16);
        sprintf((char *)oled_buffer, "%5d", Tick.mpu);
        OLED_ShowString(15*3,4,oled_buffer,16);
    }
}

// Coords parse_coords(const char* data) {
//     Coords res = {0, 0, 0};
//     if (strlen(data) != 8) return res;  // 4位 x + 4位 y = 8位

//     // 拆分 x 和 y 的子串
//     char x_str[5] = {0};
//     char y_str[5] = {0};
//     strncpy(x_str, data, 4);  // x_str = "-123"
//     strncpy(y_str, data + 4, 4);  // y_str = "+045"

//     // 转为整数
//     res.x = atoi(x_str);
//     res.y = atoi(y_str);
//     res.valid = 1;
//     return res;
// }



int uart_work(void) //串口函数
{
    if (Serial_RxFlag == 1) {
        // 处理接收到的数据
        if (strlen(Serial_RxPacket) != 8) 
        {
            printf("数据长度错误！\n");
            Serial_RxFlag = 0;
            return -1;
        }
        else
        {
            // 提取前4位（x坐标）
            char x_str[5] = {0};
            strncpy(x_str, Serial_RxPacket, 4);
    
            // 提取后4位（y坐标）
            char y_str[5] = {0};
            strncpy(y_str, Serial_RxPacket + 4, 4);
    
            // 转换为整数
            x_site = atoi(x_str);
            y_site = atoi(y_str);
           // printf("解析结果: x=%d, y=%d\n", x_site, y_site);  // 输出: x=-110, y=120
            //LED1_ON();LED2_ON();
            // 重置标志位以接收下一个包
            Serial_RxFlag = 0;
            return 0;
        }       
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
    if(keynum==1)mode++;
    if(keynum==2)mode--;
    if(keynum==3)keycnt=3; 
    if(keynum==4)keycnt=4; 
}

void Timer_work(void)
{
    // if(Motor.button!=0)
    // {

    // }   
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

