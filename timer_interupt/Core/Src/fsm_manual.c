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
		//save the time for counting down
		//set timer2 for counting down
		//timer 4 using for time out, we clear it since we dont using it in auto.
		setTime();
		setTimer2(10);
		clearTimer4();
		status = AUTO;
	case AUTO:
		if(timer2_flag ==  1)
		{
			setTimer2(CNT_DOWN_TIME);
			display7SEG(count_1);
			if(count_1 > 0) count_1--;
		}
		if(button_flag[0] == 1)
		{
			button_flag[0] = 0;
			status = Reset;
			time = 0;
			setTime();
			setTimer4(TIME_OUT);
		}
		if(button_flag[1] == 1 || button_flag[2] == 1)
		{
			button_flag[1] = 0;
			button_flag[2] = 0;
			clearTimer2();
			status = MOD;
		}
		break;
	case MOD:
		display7SEG(time);
		if(button_flag[0] == 1)
		{
			button_flag[0] = 0;
			status = Reset;
			time = 0;
			//save the time for counting down
			setTime();
			//set up timer4 for time out
			setTimer4(TIME_OUT);
		}
		if(button_flag[1] == 1)
		{
			button_flag[1] = 0;
			if(time >= 9) time = 0;
			else time++;
			setTime();
			setTimer4(TIME_OUT);
		}
		if(button_flag[2] == 1)
		{
			button_flag[2] = 0;
			if(time <= 0) time = 9;
			else time--;
			setTime();
			setTimer4(TIME_OUT);
		}
		if(timer4_flag == 1)
		{
			status = AUTO;
			setTimer2(10);
			clearTimer4();
		}
		break;
	case Reset:
	{
		display7SEG(0);
		if(button_flag[1] == 1)
		{
			status = MOD;
			button_flag[1] = 0;
			setTimer4(TIME_OUT);
		}
		if(button_flag[2] == 1)
		{
			status = MOD;
			button_flag[2] = 0;
			setTimer4(TIME_OUT);
		}
	}
	default:
		break;
	}
}

