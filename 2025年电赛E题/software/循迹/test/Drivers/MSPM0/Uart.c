#include "Uart.h"
#include "stdio.h"
#include "stdarg.h"
#include "string.h"
#include <stdlib.h>
#include <math.h>

char Serial_RxPacket[100]; //printf�ض�����Ҫ��ѡtarget��Use MicroLIB				
uint8_t Serial_RxFlag;

int fputc(int c,FILE* stream)
{
	DL_UART_Main_transmitDataBlocking(UART_0_INST, c);
	return c;
}

int fputs(const char* restrict s,FILE* restrict stream)
{
	uint16_t i,len;
	len = strlen(s);
	for(i=0;i<len;i++)
	{
		DL_UART_Main_transmitDataBlocking(UART_0_INST, s[i]);
	}
	return len;
}

int puts(const char* _ptr)
{
	int count =fputs(_ptr,stdout);
	count += fputs("\n",stdout);
	return count;
}

int16_t Rxdata(char *str)
{
	char *loc,*token;
	int a;
	
	loc = strstr((char*)Serial_RxPacket,str);
	token = strtok(loc,str); 
	a = atoi((char*)token); 
	
	return a;
}

void UART_0_INST_IRQHandler(void)
{
	static uint8_t RxState = 0;
	static uint8_t pRxPacket = 0;
	uint8_t RxData;
	
    switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)) {
        case DL_UART_MAIN_IIDX_RX:
            RxData = DL_UART_Main_receiveData(UART_0_INST);

			if (RxState == 0)
			{
				if (RxData == '[' && Serial_RxFlag == 0)
				{
					RxState = 1;
					pRxPacket = 0;
				}
			}
			else if (RxState == 1)
			{
				if (RxData == '*')
				{
					RxState = 2;
				}
				else
				{
					Serial_RxPacket[pRxPacket] = RxData;
					pRxPacket ++;
				}
			}
			else if (RxState == 2)
			{
				if (RxData == ']')
				{
					RxState = 0;
					Serial_RxPacket[pRxPacket] = '\0';
					Serial_RxFlag = 1;
				}
			}
		
            break;
        default:
            break;
    }
}
void UART_1_INST_IRQHandler(void)
{
	static uint8_t RxState = 0;
	static uint8_t pRxPacket = 0;
	uint8_t RxData;
	
    switch (DL_UART_Main_getPendingInterrupt(UART_1_INST)) {
        case DL_UART_MAIN_IIDX_RX:
            RxData = DL_UART_Main_receiveData(UART_1_INST);

			if (RxState == 0)
			{
				if (RxData == '[' && Serial_RxFlag == 0)
				{
					RxState = 1;
					pRxPacket = 0;
				}
			}
			else if (RxState == 1)
			{
				if (RxData == '*')
				{
					RxState = 2;
				}
				else
				{
					Serial_RxPacket[pRxPacket] = RxData;
					pRxPacket ++;
				}
			}
			else if (RxState == 2)
			{
				if (RxData == ']')
				{
					RxState = 0;
					Serial_RxPacket[pRxPacket] = '\0';
					Serial_RxFlag = 1;
				}
			}
		
            break;
        default:
            break;
    }
}
