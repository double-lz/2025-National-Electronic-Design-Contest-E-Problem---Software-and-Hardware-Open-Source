#ifndef _CCD_H
#define _CCD_H
#include "main.h"
int adc_getValue(void);
extern uint8_t CCD_Zhongzhi;
extern uint16_t ADV[128];
extern unsigned int adc_value ;
extern unsigned int voltage_value;
extern volatile bool gCheckADC;        //ADC采集成功标志位
void CCD_Mode(void);
extern float CCD_KP,CCD_KI,CCD_Vel;
void TSL_CLK(int state);  // 0=低电平, 1=高电平
void TSL_SI(int state);   // 0=低电平, 1=高电平
void RD_TSL(void);
void  Find_CCD_Median (void); 
#endif