/*
 * fsm_save.c
 *
 *  Created on: Nov 3, 2022
 *      Author: hatru
 */

#include "fsm_save.h"
#include "global.h"

void fsm_save()
{
	switch(status)
	{
	case SAVE_RED:
		set_red(red_time_buffer);
		if(button_flag[0] == 1)
		{
			status = MOD_GREEN;
			button_flag[0] = 0;
		}
		break;
	case SAVE_GREEN:
		set_green(green_time_buffer);
		if(button_flag[0] == 1)
		{
			status = MOD_YELLOW;
			button_flag[0] = 0;
		}
	break;
	case SAVE_YELLOW:
		set_yellow(yellow_time_buffer);
		if(button_flag[0] == 1)
		{
			status = AUTO_RED_GREEN;
			button_flag[0] = 0;
		}
		break;
	default:
		break;
	}
}
