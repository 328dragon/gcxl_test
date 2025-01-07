#include "task.h"


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

void task2()
{
 x_des=x_data;
y_des=y_data;
rubbish_kind=rb_kd;	
move_xy(x_des,y_des);
classif(rubbish_kind);
}
