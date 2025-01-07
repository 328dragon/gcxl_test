#include "serial_rx.h"
//数据帧0xff x位置 y位置 s种类 0xfe


int mode=0;//处理模式,2才为数据处理模式
uint8_t rx_buf[BUFF_SIZE];


void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
if(huart==&huart1)
{
	HAL_UART_DMAStop(&huart1);
    new_data();
		HAL_UARTEx_ReceiveToIdle_DMA(&huart1,rx_buf,BUFF_SIZE);	
}

}

void new_data()
{
if(rx_buf[0]==0xA5)
{
memcpy(&x_data,&rx_buf[6],1);
memcpy(&y_data,&rx_buf[7],1);
memcpy(&rb_kd,&rx_buf[8],1);
}  
}

void print_data()
{  
	

	printf("%d,%d,%d\r\n",x_data,y_data,rb_kd);

}

