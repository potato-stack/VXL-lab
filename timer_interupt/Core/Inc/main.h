/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define button_1_Pin GPIO_PIN_1
#define button_1_GPIO_Port GPIOA
#define button_2_Pin GPIO_PIN_5
#define button_2_GPIO_Port GPIOA
#define button_3_Pin GPIO_PIN_0
#define button_3_GPIO_Port GPIOB
#define button_p_Pin GPIO_PIN_1
#define button_p_GPIO_Port GPIOB
#define Led_p_1_Pin GPIO_PIN_10
#define Led_p_1_GPIO_Port GPIOB
#define Led_p_2_Pin GPIO_PIN_8
#define Led_p_2_GPIO_Port GPIOA
#define Led_1_Pin GPIO_PIN_10
#define Led_1_GPIO_Port GPIOA
#define Led_4_Pin GPIO_PIN_3
#define Led_4_GPIO_Port GPIOB
#define Led_3_Pin GPIO_PIN_4
#define Led_3_GPIO_Port GPIOB
#define Led_2_Pin GPIO_PIN_5
#define Led_2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
void output_checking();
void output_error();
void output_time(int index, int time);
void change_mode(int index);
void display_time(int time1, int time2);
void sound_loud(int frequency);
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
