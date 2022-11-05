/*
 * fsm_manual.h
 *
 *  Created on: Oct 7, 2022
 *      Author: hatru
 */
#include "fsm_manual.h"
#include "INC_BUTTON.h"
#include "input_reading.h"
#include "global.h"
#include "display.h"

void fsm_simple_buttons_run()
{
	switch(status)
	{
	case INIT:
		setTime();
		clearTimer4();
		status = RUNNING;
	case RUNNING:
		if(button_flag[0] == 1)
		{
			status = WAITING;
			button_flag[0] = 0;
			setTimer4(TIME_OUT);
			time = 0;
			setTime();
		}
		if(button_flag[1] == 1)
		{
			display7SEG(time);
			clearTimer2();
			status = WAITING;
			button_flag[1] = 0;
		}
		if(button_flag[2] == 1)
		{
			display7SEG(time);
			status = WAITING;
			clearTimer2();
			button_flag[2] = 0;
		}
		break;

	case WAITING:
		display7SEG(time);
		if(button_flag[0] == 1)
		{
			button_flag[0] = 0;
			setTimer4(TIME_OUT);
			time = 0;
			setTime();
		}
		if(button_flag[1] == 1)
		{
			button_flag[1] = 0;
			setTimer4(TIME_OUT);
			if(time >= 9) time = 0;
			else time++;
			setTime();
		}
		if(button_flag[2] == 1)
		{
			button_flag[2] = 0;
			setTimer4(TIME_OUT);
			if(time <= 0) time = 9;
			else time--;
			setTime();
		}
		if(timer4_flag == 1)
		{
			status = RUNNING;
			setTimer2(10);
			clearTimer4();
		}
		break;
	default:
		break;
	}
}

