#ifndef __WORK_H__
#define __WORK_H__
#include "alldata.h"

void oled_show(void);  //oled显示函数
void uart_work(void); //串口函数
void ccd_work(void); //ccd
void key_work(void); //按键工作函数
void work(void);  //任务函数
void Timer_work(void); 
void stepmotor1_ONUP(void);     //X步进电机开
void stepmotor1_ONDOWN(void); //X步进电机开
void stepmoto1_OFF(void);    //X步进电机关
void stepmotor2_ONUP(void);   //Y步进电机开
void stepmotor2_ONDOWN(void);   //Y步进电机开
void stepmoto2_OFF(void);   //Y步进电机关

#endif