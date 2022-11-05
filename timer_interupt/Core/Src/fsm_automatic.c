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
			setTimer4(10);
			status = AUTO_RED_GREEN;
			count_1 = red_time/100;
			count_2 = green_time/100;
			break;
		case AUTO_RED_GREEN:
			if(timer1_flag == 1)//Auto code goes here
			{
				timer1_flag = 0;
				status = AUTO_RED_YELLOW;
				setTimer1(green_time);
				red_display();
				green_1_display();
				count_1 = red_time/100;
				count_2 = green_time/100;
			}
			if(button_flag[0] == 1)//Manual code goes here
			{
				status = MAN_RED;
				clearTimer1();
				setTimer2(25);
				button_flag[0] = 0;
				red_time_buffer = red_time;
				clearTimer4();
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
				count_1 = yellow_time/100;
				count_2 = yellow_time/100;
			}
			if(button_flag[0] == 1)
			{
				status = MAN_RED;
				clearTimer1();
				setTimer2(25);
				button_flag[0] = 0;
				red_time_buffer = red_time;
				clearTimer4();
			}
			break;
		case AUTO_GREEN_RED:
			if(timer1_flag == 1)
			{
				timer1_flag = 0;
				status = AUTO_YELLOW_RED;
				setTimer1(green_time);
				green_display();
				red_1_display();
				count_1 = green_time/100;
				count_2 = red_time/100;
			}
			if(button_flag[0] == 1)
			{
				status = MAN_RED;
				clearTimer1();
				setTimer2(blink_time);
				button_flag[0] = 0;
				red_time_buffer = red_time;
				clearTimer4();
			}
			break;
		case AUTO_YELLOW_RED:
			if(timer1_flag == 1)
			{
				timer1_flag = 0;
				status = AUTO_RED_GREEN;
				setTimer1(yellow_time);
				yellow_display();
				count_1 = yellow_time/100;
				count_2 = yellow_time/100;
			}
			if(button_flag[0] == 1)
			{
				status = MAN_RED;
				clearTimer1();
				setTimer2(25);
				button_flag[0] = 0;
				red_time_buffer = red_time;
				clearTimer4();
			}
			break;
		default:
			break;
		}
}

