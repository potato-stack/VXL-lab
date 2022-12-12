/*
 * display_control.c
 *
 *  Created on: Dec 12, 2022
 *      Author: hatru
 */
#include "display_control.h"
#include "main.h"
//First road leds' functions--------------------------------------------------------------------------------------------------------
void Red_On()
{
	HAL_GPIO_WritePin(GPIOA,Led_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Led_2_Pin, GPIO_PIN_SET);
}

void Green_On()
{
	HAL_GPIO_WritePin(GPIOA,Led_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Led_2_Pin, GPIO_PIN_RESET);
}

void Yellow_On()
{
	HAL_GPIO_WritePin(GPIOA,Led_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Led_2_Pin, GPIO_PIN_RESET);
}

//Second road leds functions--------------------------------------------------------------------------------------------------------
void Red1_On()
{
	HAL_GPIO_WritePin(GPIOB,Led_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Led_4_Pin, GPIO_PIN_SET);
}

void Green1_On()
{
	HAL_GPIO_WritePin(GPIOB,Led_3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Led_4_Pin, GPIO_PIN_RESET);
}

void Yellow1_On()
{
	HAL_GPIO_WritePin(GPIOB,Led_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Led_4_Pin, GPIO_PIN_RESET);
}

//Leds function for crossing road--------------------------------------------------------------------------------------------------------
void Redp_On()
{
	HAL_GPIO_WritePin(GPIOB,Led_p_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,Led_p_2_Pin, GPIO_PIN_SET);
}
void Greenp_On()
{
	HAL_GPIO_WritePin(GPIOB,Led_p_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,Led_p_2_Pin, GPIO_PIN_RESET);
}

//Led reset functions---------------------------------------------------------------------------------------------------------------
void Reset()
{
	HAL_GPIO_WritePin(GPIOA,Led_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Led_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,Led_3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Led_4_Pin, GPIO_PIN_SET);
}

void Reset_p()
{
	HAL_GPIO_WritePin(GPIOB,Led_p_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,Led_p_2_Pin, GPIO_PIN_SET);
}
