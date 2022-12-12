/*
 * fsm_automatic.h
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */

#include "fsm_automatic.h"
#include "SOFTWARE_TIMER.h"
#include "main.h"
#include "INC_BUTTON.h"

void fsm_automatic_run()
{
	switch(status)
	{
	case INIT:
		status = AUTO_RED;
		break;
	case AUTO_RED:
		if(timer1_flag == 1)
		{
			HAL_GPIO_WritePin(GPIOA, Led_red_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, Led_green_Pin, SET);
			status = AUTO_GREEN;
			setTimer1(300);
		}
		if(button1_flag == 1)
		{
			button1_flag = 0;
			status = MAN_RED;
			setTimer1(1000);
		}
		break;
	case AUTO_YELLOW:
		if(timer1_flag == 1)
		{
			status = AUTO_RED;
			setTimer1(200);
		    HAL_GPIO_WritePin(Led_red_GPIO_Port, Led_red_Pin, SET);
			HAL_GPIO_WritePin(Led_green_GPIO_Port, Led_green_Pin, SET);
		}
		if(button1_flag == 1)
		{
			button1_flag = 0;
			status = MAN_YELLOW;
			setTimer1(1000);
		}
		break;
	case AUTO_GREEN:
		if(timer1_flag == 1)
		{
			status = AUTO_YELLOW;
			HAL_GPIO_WritePin(GPIOA, Led_red_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, Led_green_Pin, SET);
			setTimer1(500);
		}
		if(button1_flag == 1)
		{
			button1_flag = 0;
			status = MAN_RED;
			setTimer1(100);
		}
		break;
	default:
		break;
	}
}
