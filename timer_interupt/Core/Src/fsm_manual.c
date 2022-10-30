/*
 * fsm_manual.h
 *
 *  Created on: Oct 7, 2022
 *      Author: hatru
 */
#include "fsm_manual.h"
#include "INC_BUTTON.h"
void fsm_manual_run()
{
	switch(status)
	{
	case INIT:
		HAL_GPIO_WritePin(GPIOA, Led_red_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Led_green_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Led_yellow_Pin, SET);
		status = MAN_RED;
	case MAN_RED:
		/*if(timer1_flag == 1)
		{
			status = AUTO_GREEN;
			setTimer1(300);
		}*/
		HAL_GPIO_WritePin(GPIOA, Led_red_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, Led_green_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Led_yellow_Pin, SET);
		if(button1_flag == 1)
		{
			//clearTimer1();
		    status = MAN_GREEN;
		    //setTimer1(1000);
		    button1_flag = 0;
		}
		if(button2_flag == 1)
		{
			status = MAN_YELLOW;
			button2_flag = 0;
		}
		break;
	case MAN_GREEN:
		/*if(timer1_flag == 1)
		{
			status = AUTO_YELLOW;
			setTimer1(200);
		}*/
		HAL_GPIO_WritePin(GPIOA, Led_red_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Led_green_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, Led_yellow_Pin, SET);
		if(button1_flag == 1)
		{
			//clearTimer1();
		    status = MAN_YELLOW;
		    //setTimer1(1000);
		    button1_flag = 0;
		}
		if(button2_flag == 1)
		{
			status = MAN_RED;
			button2_flag = 0;
		}
		break;
	case MAN_YELLOW:
		/*if(timer1_flag == 1)
		{
			status = AUTO_RED;
			setTimer1(500);
		}*/
		HAL_GPIO_WritePin(GPIOA, Led_red_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Led_green_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Led_yellow_Pin, RESET);
		if(button1_flag == 1)
		{
			//clearTimer1();
		    status = MAN_RED;
		    //setTimer1(1000);
		    button1_flag = 0;
		}
		if(button2_flag == 1)
		{
			status = MAN_GREEN;
			button2_flag = 0;
		}
		break;
	default:
		break;
	}
}

