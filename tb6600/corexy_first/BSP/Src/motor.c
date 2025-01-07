#include "motor.h"

int motor_speed=9;//5最快，9开始再小就丢步了，
int x_now=0;
int y_now=0;
float prop=2;

void open()
{
__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,250);

}
void close()
{
__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,1250);

}
void move_z(int z)
{
if(z==1)
{
  __HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,250);
}else if(z==0)
{
  __HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,1250);
}
}

void motor_start(){
HAL_GPIO_WritePin(L_EN_GPIO_Port,L_EN_Pin,1);
HAL_GPIO_WritePin(R_EN_GPIO_Port,R_EN_Pin,1);
}
void motor_stop()
{
  HAL_GPIO_WritePin(L_EN_GPIO_Port,L_EN_Pin,0);
HAL_GPIO_WritePin(R_EN_GPIO_Port,R_EN_Pin,0);
}

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


}



//逆时针为正，顺时针为负,m_flag表示是左边的电机还是右边的电机，0为左，1为右
int cal_dir(int cur_x,int des_x,int cur_y,int des_y,int m_flag)
{
int delta_x=des_x-cur_x;
int delta_y=des_y-cur_y;
int delta_l=delta_x+delta_y;
int delta_r=delta_x-delta_y;
if(m_flag==0)
{
  return (delta_l>0)?1:-1;
}else if(m_flag==1)
{
return (delta_r>0)?1:-1;
}
else return 0;
}
//m_flag表示是左边的电机还是右边的电机，0为左，1为右
int cal_step(int cur_x,int des_x,int cur_y,int des_y,int n_flag)
{
int delta_x=des_x-cur_x;
int delta_y=des_y-cur_y;
int delta_l=delta_x+delta_y;
int delta_r=delta_x-delta_y;
int true_l;
int true_r;
//实际距离换算成具体脉冲数
true_l=delta_l*prop;
true_r=delta_r*prop;

if(n_flag==0)
{
	return (true_l>0)?true_l:-true_l;
}
if(n_flag==1)
{
	return (true_r>0)?true_r:-true_r;
}

}

void move_step(int step_l,int step_r )
{
if(step_l<=step_r){
 for (uint32_t i = 0; i < step_r; i++)
    {
        if(i<=step_l)
        {
            lmotor_step_on;
            rmotor_step_on;           
            delay_us(motor_speed);
            lmotor_step_off;
            rmotor_step_off;
            delay_us(motor_speed);
     }else 
		{
         rmotor_step_on;
            delay_us(motor_speed);
        rmotor_step_off;
            delay_us(motor_speed);
		}
    }
	}else {
 for (uint32_t i = 0; i < step_l; i++)
    {
        if(i<=step_r)
        {
            lmotor_step_on;
            rmotor_step_on;           
            delay_us(motor_speed);
            lmotor_step_off;
            rmotor_step_off;
            delay_us(motor_speed);
     }else 
		{
         lmotor_step_on;
            delay_us(motor_speed);
        lmotor_step_off;
            delay_us(motor_speed);
		}
    }
	}


}

void move_xy(int x,int y)
{
motor_start();
int l_dir=cal_dir(x_now,x,y_now,y,0);
int r_dir=cal_dir(x_now,x,y_now,y,1);
if(l_dir==1)
{
lmotor_front;
}else if(l_dir==-1){
lmotor_back;
}
if(r_dir==1)
{
rmotor_front;
}else if(l_dir==-1){
rmotor_back;
}
int l_pulse =cal_step(x_now,x,y_now,y,0);
int r_pulse =cal_step(x_now,x,y_now,y,1);
move_step(l_pulse,r_pulse);
motor_stop();
x_now=x;
y_now=y;

}

//测试单个能不能驱动,默认用左电机
void move_motor(int x)
{
  motor_start();
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
   motor_stop();
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

// void move_step(int X_step,int Y_step )
// {
// 	if(X_step<=Y_step){
//  for (uint32_t i = 0; i < Y_step; i++)
//     {
//         if(i<=X_step)
//         {
//             X1_STEP_ON;
//             X2_STEP_ON;
//             Y_STEP_ON;
//             delay_us(x_motor_speed);
//             X1_STEP_OFF;
//             X2_STEP_OFF;
//             Y_STEP_OFF;
//             delay_us(x_motor_speed);
//      }else 
// 		{
//          Y_STEP_ON;
//             delay_us(y_motor_speed);
//         Y_STEP_OFF;
//             delay_us(y_motor_speed);
// 		}
//     }
// 	}else {
// 		for (uint32_t i = 0; i < X_step; i++)
//     {
//         if(i<=Y_step)
//         {
//             X1_STEP_ON;
//             X2_STEP_ON;
//             Y_STEP_ON;
//             delay_us(y_motor_speed);
//             X1_STEP_OFF;
//             X2_STEP_OFF;
//             Y_STEP_OFF;
//             delay_us(y_motor_speed);
//      }else 
// 		{
//         X1_STEP_ON;
//             X2_STEP_ON;
//             delay_us(x_motor_speed);
//        X1_STEP_OFF;
//             X2_STEP_OFF;
//             delay_us(x_motor_speed);
// 		}
//     }
// 	}
// }
