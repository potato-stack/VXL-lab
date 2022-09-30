/*
 * fsm_automatic.h
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */

#include "fsm_automatic.h"
#include "SOFTWARE_TIMER.h"
#include "main.h"

void fsm_automatic_run()
{
	switch(status)
	{
	case INIT:
		status = AUTO_RED;
		setTimer1(50);
		break;
	case AUTO_RED:
		if(timer1_flag == 1)
		{
			HAL_GPIO_WritePin(Led_red_GPIO_Port, Led_red_Pin, SET);
			HAL_GPIO_WritePin(Led_green_GPIO_Port, Led_green_Pin, RESET);
			status = AUTO_YELLOW;
			setTimer1(yellow_time);
		}
		break;
	case AUTO_YELLOW:
		if(timer1_flag == 1)
		{
			status = AUTO_GREEN;
			setTimer1(green_time);
			HAL_GPIO_WritePin(Led_red_GPIO_Port, Led_red_Pin, SET);
			HAL_GPIO_WritePin(Led_green_GPIO_Port, Led_green_Pin, SET);
		}
		break;
	case AUTO_GREEN:
		if(timer1_flag == 1)
		{
			status = AUTO_RED;
			setTimer1(red_time);
			HAL_GPIO_WritePin(Led_red_GPIO_Port, Led_red_Pin, RESET);
			HAL_GPIO_WritePin(Led_green_GPIO_Port, Led_green_Pin, SET);
		}
		break;
	default:
		break;
	}
}
