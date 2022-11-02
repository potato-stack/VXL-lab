/*
 * fsm_automatic.h
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */

#include "fsm_automatic.h"
#include "SOFTWARE_TIMER.h"
#include "input_reading.h"
#include "display.h"
#include "global.h"

//#include "INC_BUTTON.h"
void fsm_automatic_run()
{
	switch(status)
		{
		case INIT:
			status = AUTO_RED_GREEN;
			break;
		case AUTO_RED_GREEN:
			if(timer1_flag == 1)
			{
				timer1_flag = 0;
				status = AUTO_RED_YELLOW;
				setTimer1(green_time);
				red_display();
				green_1_display();
			}
			if(button_flag[0] == 1)
			{
				status = MAN_RED;
				clearTimer1();
				setTimer2(25);
				button_flag[0] = 0;
			}
			break;
		case AUTO_RED_YELLOW:
			if(timer1_flag == 1)
			{
				timer1_flag = 0;
				status = AUTO_GREEN_RED;
				setTimer1(yellow_time);
				red_display();
				yellow_1_display();
			}
			if(button_flag[0] == 1)
			{
				status = MAN_RED;
				clearTimer1();
				setTimer2(25);
				button_flag[0] = 0;
			}
			break;
		case AUTO_GREEN_RED:
			if(timer1_flag == 1)
			{
				timer1_flag = 0;
				status = AUTO_YELLOW_RED;
				setTimer1(25);
				green_display();
				red_1_display();
			}
			if(button_flag[0] == 1)
			{
				status = MAN_RED;
				clearTimer1();
				setTimer2(blink_time);
				button_flag[0] = 0;
			}
			break;
		case AUTO_YELLOW_RED:
			if(timer1_flag == 1)
			{
				timer1_flag = 0;
				status = AUTO_RED_GREEN;
				setTimer1(yellow_time);
				yellow_display();
			}
			if(button_flag[0] == 1)
			{
				status = MAN_RED;
				clearTimer1();
				setTimer2(25);
				button_flag[0] = 0;
			}
			break;
		default:
			break;
		}
}

