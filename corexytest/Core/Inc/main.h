/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "motor.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EMS1_Pin GPIO_PIN_13
#define EMS1_GPIO_Port GPIOC
#define EMS2_Pin GPIO_PIN_14
#define EMS2_GPIO_Port GPIOC
#define ESTEP_Pin GPIO_PIN_15
#define ESTEP_GPIO_Port GPIOC
#define EDIR_Pin GPIO_PIN_0
#define EDIR_GPIO_Port GPIOC
#define LMS1_Pin GPIO_PIN_15
#define LMS1_GPIO_Port GPIOA
#define LMS2_Pin GPIO_PIN_10
#define LMS2_GPIO_Port GPIOC
#define LSTEP_Pin GPIO_PIN_11
#define LSTEP_GPIO_Port GPIOC
#define LDIR_Pin GPIO_PIN_3
#define LDIR_GPIO_Port GPIOB
#define RMS1_Pin GPIO_PIN_4
#define RMS1_GPIO_Port GPIOB
#define RMS2_Pin GPIO_PIN_5
#define RMS2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
