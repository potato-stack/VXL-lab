/*
 * display.c
 *
 *  Created on: Nov 2, 2022
 *      Author: hatru
 */
#include "display.h"
#include "main.h"
#include "SOFTWARE_TIMER.h"
#include "global.h"
#define LED7PORT GPIOB

void display7SEG(int numb)
{
	switch (numb) {
		case 0:
		    HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
		    HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
		    HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
		    HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
		    HAL_GPIO_WritePin(LED7PORT, S5_Pin, RESET);
		    HAL_GPIO_WritePin(LED7PORT, S6_Pin, RESET);
		    HAL_GPIO_WritePin(LED7PORT, S7_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		default:
			break;
	}
}
void setTime()
{
	count_1 = time;
}
void red_blink()
{
	if(timer1_flag == 1)
	{
		setTimer1(50);
		HAL_GPIO_TogglePin(GPIOA, Led_red_Pin);
	}
}

void led_reset()
{
	HAL_GPIO_WritePin(GPIOA, Led_red_Pin, SET);
}

