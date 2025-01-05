#include "motor.h"

int motor_speed=10;//13最快，越高越慢
int x_now=0;
int y_now=0;

void delay_us(uint32_t us)
{
    uint32_t delay = (HAL_RCC_GetHCLKFreq() / 4000000 * us);
    while (delay--)
    {
        __NOP(); // 防止编译器优化
    }
}

void motor_initial()
{
// 16细分
HAL_GPIO_WritePin(LMS1_GPIO_Port,LMS1_Pin,1);
HAL_GPIO_WritePin(LMS2_GPIO_Port,LMS2_Pin,1);
HAL_GPIO_WritePin(RMS1_GPIO_Port,RMS2_Pin,1);
HAL_GPIO_WritePin(RMS2_GPIO_Port,RMS2_Pin,1);
// HAL_GPIO_WritePin(MS3_GPIO_Port,MS3_Pin,1);

}

void move_xy(int x,int y)
{
int x_step;
int y_step;

}

void move_motor(int x)
{
	// int step = (4*(x))/0.1575;
    if(x>0)
  {
lmotor_front;
 for (uint32_t i = 0; i < x; i++)
    {

           lmotor_step_on;
           delay_us(motor_speed);
      //   HAL_Delay(2);
           lmotor_step_off;
           delay_us(motor_speed);
      //   HAL_Delay(2);
   }
  }
    if(x<0)
   {
lmotor_back;
 for (uint32_t i = 0; i <  -x; i++)
    {
           lmotor_step_on;
           delay_us(motor_speed);
         //  HAL_Delay(2);
           lmotor_step_off;
           delay_us(motor_speed);
         //  HAL_Delay(2);

    }
   } 
}

// void move_motor(int x)
// {
// 	// int step = (4*(x))/0.1575;
//     if(x>0)
//   {
// motor_front;
//  for (uint32_t i = 0; i < x; i++)
//     {
//            motor_step_on;
//            delay_us(motor_speed);
//       //   HAL_Delay(2);
//            motor_step_off;
//            delay_us(motor_speed);
//       //   HAL_Delay(2);
//    }
//   }
//     if(x<0)
//    {
// motor_back;
//  for (uint32_t i = 0; i <  -x; i++)
//     {
//            motor_step_on;
//            delay_us(motor_speed);
//          //  HAL_Delay(2);
//            motor_step_off;
//            delay_us(motor_speed);
//          //  HAL_Delay(2);
//     }
//    } 
// }

