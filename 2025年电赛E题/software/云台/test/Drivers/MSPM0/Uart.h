#ifndef UART_H
#define UART_H

#include "ti_msp_dl_config.h"

void UART_0_INST_IRQHandler(void) ;
int16_t Rxdata(char *str);

extern char Serial_RxPacket[];
extern uint8_t Serial_RxFlag;

#endif