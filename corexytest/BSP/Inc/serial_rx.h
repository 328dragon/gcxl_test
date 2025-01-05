#ifndef __SERIAL__RX_H
#define __SERIAL__RX_H

#include <stdio.h>
#include "main.h"
#include "usart.h"
extern uint8_t USARTData;//数据缓冲
extern uint8_t USARTDataBag[3];//数据存储数组
extern uint8_t RX_Flag;//数据包接受完成标志位
extern int mode;
uint8_t USART_GetFlag(void);//标志位函数

int get_x();
int get_y() ;
int get_size();
void give_x_y(int x,int y,int s);

#endif

