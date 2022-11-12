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

void fsm_manual_run()
{
	switch(status)
	{
	case MOD_RED:
		red_blink();
		count_1 = red_time_buffer/100;
		count_2 = 00;
		if(button_flag[0] == 1)
		{
			status = MOD_YELLOW;
			button_flag[0] = 0;
			yellow_time_buffer = yellow_time;
		}
		if(button_flag[1] == 1)
		{
			button_flag[1] = 0;
			if(red_time_buffer >= 99*100)
			{
				red_time_buffer = 0;
			}
			red_time_buffer += 100;
			count_1 = red_time_buffer/100;
		}
		if(button_flag[2] == 1)
		{
			button_flag[2] = 0;
			red_time = red_time_buffer;
			count_1 = 9;
		}
		break;
	case MOD_YELLOW:
			yellow_blink();
			count_1 = yellow_time_buffer/100;
			count_2 = 01;
			if(button_flag[0] == 1)
			{
				status = MOD_GREEN;
				button_flag[0] = 0;
				green_time_buffer = green_time;
			}
			if(button_flag[1] == 1)
			{
				button_flag[1] = 0;
				if(yellow_time_buffer >= 99*100)
				{
					yellow_time_buffer = 0;
				}
				yellow_time_buffer+= 100;
			}
			if(button_flag[2] == 1)
			{
				button_flag[2] = 0;
				yellow_time = yellow_time_buffer;
			}
			break;
	case MOD_GREEN:
		green_blink();
		count_1 = green_time_buffer/100;
		count_2 = 02;
		if(button_flag[0] == 1)
		{
			status = INIT;
			status1 = INIT;
			button_flag[0] = 0;
			clearTimer2();
			setTimer1(10);
			setTimer5(13);
			setTimer4(101);
		}
		if(button_flag[1] == 1)
		{
			button_flag[1] = 0;
			if(green_time_buffer >= 99*100)
			{
				green_time_buffer = 0;
			}
			green_time_buffer+=100;
		}
		if(button_flag[2] == 1)
		{
			button_flag[2] = 0;
			green_time = green_time_buffer;
		}
		break;
	default:
		break;
	}
}

