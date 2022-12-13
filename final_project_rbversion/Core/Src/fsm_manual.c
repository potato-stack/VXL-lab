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
	switch(status1)
	{
	case MAN_RED_GREEN:
		if(timer2_flag == 1)
		{

		}
		if(button1_flag == 1)
		{

		}
		break;
	case MAN_RED_YELLOW:
		if(timer2_flag == 1)
		{

		}
		if(button1_flag == 1)
		{

		}
		break;
	case MAN_GREEN_RED:
		if(timer2_flag == 1)
		{
			status1 = AUTO_GREEN_RED;
		}
		if(button1_flag == 1)
		{

		}
		break;
	case MAN_YELLOW_RED:
		if(timer2_flag == 1)
		{

		}
		if(button1_flag == 1)
		{

		}
		break;
	default:
		break;
	}
}

