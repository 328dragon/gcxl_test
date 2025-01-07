#include "serial_rx.h"
//数据帧0xff x位置 y位置 s种类 0xfe

uint8_t USARTData;//数据缓冲
uint8_t USARTDataBag[3];//数据存储数组

uint8_t RX_Flag;//数据包接受完成标志位

int mode=0;//处理模式,2才为数据处理模式

uint8_t USART_GetFlag(void)//标志位函数
{
  if(RX_Flag == 1)
  {
    return 1;
    RX_Flag = 0;
  }else
  {
    return 0 ;
  }
}

int get_x()
{
	int re_x;
	re_x=(int)USARTDataBag[0];
	return re_x;
}
	
int get_y()
{
	int re_y;
	re_y=(int)USARTDataBag[1];
	return re_y;
}

int get_size()
{
int re_z=(int)USARTDataBag[2];
return re_z;
}

//s表示类别，1为有害垃圾，2为可回收垃圾，3为厨余垃圾,4为其他垃圾
void give_x_y(int x,int y,int s)
{

uint8_t dj[5]={0xFF,0X00,0x05,0x06,0xFE};

memcpy(&dj[1],&x,1);	
memcpy(&dj[2],&y,1);	
memcpy(&dj[3],&s,1);	
HAL_UART_Transmit (&huart1,dj,5,0xfff);
// printf("0xFF0xFE",x1,x2,x3,y1,y2,y3);

}
