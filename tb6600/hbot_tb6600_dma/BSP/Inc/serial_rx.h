#ifndef __SERIAL__RX_H
#define __SERIAL__RX_H

#include <stdio.h>
#include "main.h"
#include "usart.h"
#define  BUFF_SIZE  30
extern uint8_t rx_buf[BUFF_SIZE];

extern uint8_t USARTData;//数据缓冲
extern uint8_t USARTDataBag[3];//数据存储数组
extern uint8_t RX_Flag;//数据包接受完成标志位
extern int mode;
void new_data();
uint8_t USART_GetFlag(void);//标志位函数
void print_data();


#endif

