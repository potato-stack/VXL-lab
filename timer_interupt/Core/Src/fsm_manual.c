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
	case MAN_RED:
		red_time_buffer = red_time;
		red_blink();
		if(button_flag[0] == 1)
		{
			status = MAN_YELLOW;
			button_flag[0] = 0;
		}
		if(button_flag[1] == 1)
		{
			button_flag[1] = 0;
			if(red_time_buffer >= 99)
			{
				red_time_buffer = 0;
			}
			red_time_buffer++;
		}
		break;
	case MAN_GREEN:
		green_time_buffer = green_time;
		green_blink();
		if(button_flag[0] == 1)
		{
			status = INIT;
			button_flag[0] = 0;
			clearTimer2();
			setTimer1(10);
		}
		if(button_flag[1] == 1)
		{
			button_flag[1] = 0;
			if(green_time_buffer >= 99)
			{
				green_time_buffer = 0;
			}
			green_time_buffer++;
		}
		break;
	case MAN_YELLOW:
		yellow_time_buffer = yellow_time;
		yellow_blink();
		if(button_flag[0] == 1)
		{
			status = MAN_GREEN;
			button_flag[0] = 0;
		}
		if(button_flag[1] == 1)
		{
			button_flag[1] = 0;
			if(yellow_time_buffer >= 99)
			{
				yellow_time_buffer = 0;
			}
			yellow_time_buffer++;
		}
		break;
	default:
		break;
	}
}

