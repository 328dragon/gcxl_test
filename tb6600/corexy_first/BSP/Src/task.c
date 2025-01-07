#include "task.h"

int x=0;
int y=0;
int z=0;
int x_data_last=0;
int y_data_last=0;
//需要测试，改参数等
void classif(int s)
{
switch (s)//1
{
case 1:
{open();
move_z(1);
close();
HAL_Delay(50);
move_z(0);
move_xy(25,25);
open();
  break;
}

case 2:
{open();
move_z(1);
close();
HAL_Delay(50);
move_z(0);
move_xy(25,50);
open();
break;
}

case 3:
{open();
move_z(1);
close();
HAL_Delay(50);
move_z(0);
move_xy(50,25);
open();
break;
}

case 4:
{open();
move_z(1);
close();
HAL_Delay(50);
move_z(0);
move_xy(50,50);
open();
break;
}

default:
  break;
}


}

void task1()
{

       for (int i=1;i<5;i++)
      {
        printf("start");     
      }
       mode=2;
HAL_UART_Receive_IT(&huart1,&USARTData,1);
      while (1)
      {
      if(USART_GetFlag() == 1)
        {
             x=get_x();
             y=get_y();
             z=get_size();
            if((x!=x_data_last)||(y!=y_data_last))
            {
           for (int i=1;i<5;i++)
            {
              printf("stop");     
            }
             move_xy(x,y);
             classif(z);//分类
             printf("%d,%d,%d",x,y,z);
             printf("\n");   
            x_data_last=x;
            y_data_last=y;
               break;  
            }
        }
mode=2;
      }

}