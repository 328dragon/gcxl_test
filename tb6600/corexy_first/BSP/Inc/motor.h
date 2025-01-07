#ifndef __MOTOR_H
#define __MOTOR_H
//方向
#define lmotor_front HAL_GPIO_WritePin(LDIR_GPIO_Port,LDIR_Pin,1);
#define lmotor_back HAL_GPIO_WritePin(LDIR_GPIO_Port,LDIR_Pin,0);
#define rmotor_front HAL_GPIO_WritePin(RDIR_GPIO_Port,RDIR_Pin,1);
#define rmotor_back HAL_GPIO_WritePin(RDIR_GPIO_Port,RDIR_Pin,0);
#define emotor_front HAL_GPIO_WritePin(EDIR_GPIO_Port,EDIR_Pin,1);
#define emotor_back HAL_GPIO_WritePin(EDIR_GPIO_Port,EDIR_Pin,0);
//脉冲
#define lmotor_step_on HAL_GPIO_WritePin(LSTEP_GPIO_Port,LSTEP_Pin,1);
#define lmotor_step_off HAL_GPIO_WritePin(LSTEP_GPIO_Port,LSTEP_Pin,0);
#define rmotor_step_on HAL_GPIO_WritePin(RSTEP_GPIO_Port,RSTEP_Pin,1);
#define rmotor_step_off HAL_GPIO_WritePin(RSTEP_GPIO_Port,RSTEP_Pin,0);
#define Emotor_step_on HAL_GPIO_WritePin(ESTEP_GPIO_Port,ESTEP_Pin,1);
#define Emotor_step_off HAL_GPIO_WritePin(ESTEP_GPIO_Port,ESTEP_Pin,0);
//速度
extern  int motor_speed;
extern int x_now;
extern int y_now;
#include "main.h"
#include "tim.h"
#include "stm32f4xx_hal.h"
void delay_us(uint32_t us);
void motor_initial();
int cal_dir(int cur_x,int des_x,int cur_y,int des_y,int m_flag);
int cal_step(int cur_x,int des_x,int cur_y,int des_y,int n_flag);
void move_step(int step_l,int step_r );
void move_xy(int x,int y);
void move_motor(int x);
void open();
void close();
void motor_stop();
void motor_start();
void move_z(int z);

// void move_motor(int x);

#endif
