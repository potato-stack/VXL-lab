/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void clearAllClock()
{
	HAL_GPIO_WritePin(pin_1_GPIO_Port, pin_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(pin_2_GPIO_Port, pin_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(pin_3_GPIO_Port, pin_3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(pin_4_GPIO_Port, pin_4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(pin_5_GPIO_Port, pin_5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(pin_6_GPIO_Port, pin_6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(pin_7_GPIO_Port, pin_7_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(pin_8_GPIO_Port, pin_8_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(pin_9_GPIO_Port, pin_9_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(pin_10_GPIO_Port, pin_10_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(pin_11_GPIO_Port, pin_11_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(pin_12_GPIO_Port, pin_12_Pin, GPIO_PIN_SET);
}
void setNumberOnClock(int numb)
{
	if(numb == 0) HAL_GPIO_WritePin(pin_1_GPIO_Port, pin_1_Pin, GPIO_PIN_RESET);
	if(numb == 1) HAL_GPIO_WritePin(pin_2_GPIO_Port, pin_2_Pin, GPIO_PIN_RESET);
	if(numb == 2) HAL_GPIO_WritePin(pin_3_GPIO_Port, pin_3_Pin, GPIO_PIN_RESET);
	if(numb == 3)	HAL_GPIO_WritePin(pin_4_GPIO_Port, pin_4_Pin, GPIO_PIN_RESET);
	if(numb == 4)	HAL_GPIO_WritePin(pin_5_GPIO_Port, pin_5_Pin, GPIO_PIN_RESET);
	if(numb == 5)	HAL_GPIO_WritePin(pin_6_GPIO_Port, pin_6_Pin, GPIO_PIN_RESET);
	if(numb == 6)	HAL_GPIO_WritePin(pin_7_GPIO_Port, pin_7_Pin, GPIO_PIN_RESET);
	if(numb == 7)	HAL_GPIO_WritePin(pin_8_GPIO_Port, pin_8_Pin, GPIO_PIN_RESET);
	if(numb == 8)	HAL_GPIO_WritePin(pin_9_GPIO_Port, pin_9_Pin, GPIO_PIN_RESET);
	if(numb == 9)	HAL_GPIO_WritePin(pin_10_GPIO_Port, pin_10_Pin, GPIO_PIN_RESET);
	if(numb == 10)	HAL_GPIO_WritePin(pin_11_GPIO_Port, pin_11_Pin, GPIO_PIN_RESET);
	if(numb == 11)	HAL_GPIO_WritePin(pin_12_GPIO_Port, pin_12_Pin, GPIO_PIN_RESET);
}
void clearNumberOnClock(int numb)
{
	if(numb == 0) HAL_GPIO_WritePin(pin_1_GPIO_Port, pin_1_Pin, GPIO_PIN_SET);
	if(numb == 1) HAL_GPIO_WritePin(pin_2_GPIO_Port, pin_2_Pin, GPIO_PIN_SET);
	if(numb == 2) HAL_GPIO_WritePin(pin_3_GPIO_Port, pin_3_Pin, GPIO_PIN_SET);
	if(numb == 3)	HAL_GPIO_WritePin(pin_4_GPIO_Port, pin_4_Pin, GPIO_PIN_SET);
	if(numb == 4)	HAL_GPIO_WritePin(pin_5_GPIO_Port, pin_5_Pin, GPIO_PIN_SET);
	if(numb == 5)	HAL_GPIO_WritePin(pin_6_GPIO_Port, pin_6_Pin, GPIO_PIN_SET);
	if(numb == 6)	HAL_GPIO_WritePin(pin_7_GPIO_Port, pin_7_Pin, GPIO_PIN_SET);
	if(numb == 7)	HAL_GPIO_WritePin(pin_8_GPIO_Port, pin_8_Pin, GPIO_PIN_SET);
	if(numb == 8)	HAL_GPIO_WritePin(pin_9_GPIO_Port, pin_9_Pin, GPIO_PIN_SET);
	if(numb == 9)	HAL_GPIO_WritePin(pin_10_GPIO_Port, pin_10_Pin, GPIO_PIN_SET);
	if(numb == 10)	HAL_GPIO_WritePin(pin_11_GPIO_Port, pin_11_Pin, GPIO_PIN_SET);
	if(numb == 11)	HAL_GPIO_WritePin(pin_12_GPIO_Port, pin_12_Pin, GPIO_PIN_SET);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int second = 0;
  int minute = 0;
  int hour = 0;
  int prev_second = 0;
  int prev_minute =0;
  int prev_hour = 0;
  while (1)
  {

	  if(second == 0 && minute == 0 && hour == 0)
	  {
	  		  clearAllClock();
	  		  setNumberOnClock(0);
	  }
	  else
	  {
		  	  if(second == 60)
		  	  {
		  		  second = 0;
		  		  prev_minute = minute;
		  		  prev_second = 59;
		  		  minute++;
		  	  }
		  	  if(minute == 60)
		  	  {
		  		  minute = 0;
		  		  prev_hour = hour;
		  		  prev_minute = 59;
		  		  hour++;
		  	  }
		  	  if(hour == 12)
		  	  {
		  		  prev_hour = 11;
		  		  hour = 0;
		  	  }
		  	  /* change the minute and hour if need */
		  	  if(prev_second != minute && prev_second != hour*5)
		  	  {
		  		   clearNumberOnClock(prev_second/5);
		  	  }
		  	  if(prev_minute != second && prev_minute != hour*5)
		  	  {
		  		  clearNumberOnClock(prev_minute/5);
		  	  }
		  	  if(prev_hour != second/5 && prev_hour != minute/5)
		  	  {
		  		  clearNumberOnClock(prev_hour);
		  	  }
		  	  setNumberOnClock(second/5);
		  	  setNumberOnClock(minute/5);
		  	  setNumberOnClock(hour);
	  }
	  prev_second = second;
	  second++;
	  HAL_Delay(1000);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, pin_1_Pin|pin_2_Pin|pin_3_Pin|pin_4_Pin
                          |pin_5_Pin|pin_6_Pin|pin_7_Pin|pin_8_Pin
                          |pin_9_Pin|pin_10_Pin|pin_11_Pin|pin_12_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : pin_1_Pin pin_2_Pin pin_3_Pin pin_4_Pin
                           pin_5_Pin pin_6_Pin pin_7_Pin pin_8_Pin
                           pin_9_Pin pin_10_Pin pin_11_Pin pin_12_Pin */
  GPIO_InitStruct.Pin = pin_1_Pin|pin_2_Pin|pin_3_Pin|pin_4_Pin
                          |pin_5_Pin|pin_6_Pin|pin_7_Pin|pin_8_Pin
                          |pin_9_Pin|pin_10_Pin|pin_11_Pin|pin_12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
