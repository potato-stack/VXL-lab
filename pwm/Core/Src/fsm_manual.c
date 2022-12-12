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
	case MAN_RED:
		if(timer1_flag == 1)
		{
			status = AUTO_GREEN;
			setTimer1(300);
		}
		if(button1_flag == 1)
		{
			clearTimer1();
		    status = MAN_GREEN;
		    setTimer1(1000);
		    button1_flag = 0;
		}
		break;
	case MAN_GREEN:
		if(timer1_flag == 1)
		{
			status = AUTO_YELLOW;
			setTimer1(200);
		}
		if(button1_flag == 1)
		{
			clearTimer1();
		    status = MAN_YELLOW;
		    setTimer1(1000);
		    button1_flag = 0;
		}
		break;
	case MAN_YELLOW:
		if(timer1_flag == 1)
		{
			status = AUTO_RED;
			setTimer1(500);
		}
		if(button1_flag == 1)
		{
			clearTimer1();
		    status = MAN_RED;
		    setTimer1(1000);
		    button1_flag = 0;
		}
		break;
	default:
		break;
	}
}

