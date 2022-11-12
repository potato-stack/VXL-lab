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


void fsm_automatic_1_run()
{
	switch(status)
		{
		case INIT:
			setTimer4(10);//start counting down
			status = AUTO_RED;
			count_1 = red_time/100;
			break;
		case AUTO_RED:
			if(timer1_flag == 1)
			{
				status = AUTO_GREEN;
				setTimer1(red_time);
				red_display();
				count_1 = red_time/100;
			}
			if(button_flag[0] == 1)
			{
				status = MOD_RED;
				clearTimer1();//stop changing autostate
				clearTimer4();//stop counting down
				setTimer2(blink_time);//start to blink
				button_flag[0] = 0;
				red_time_buffer = red_time;//set time into buffer for modifying
			}
			break;
		case AUTO_GREEN:
			if(timer1_flag == 1)
			{
				status = AUTO_YELLOW;
				setTimer1(green_time);
				green_display();
				count_1 = green_time/100;
			}
			if(button_flag[0] == 1)
			{
				status = MOD_RED;
				clearTimer1();
				clearTimer4();
				setTimer2(blink_time);
				button_flag[0] = 0;
				red_time_buffer = red_time;
			}
			break;
		case AUTO_YELLOW:
			if(timer1_flag == 1)
			{
				status = AUTO_RED;
				setTimer1(yellow_time);
				yellow_display();
				count_1 = yellow_time/100;
			}
			if(button_flag[0] == 1)
			{
				status = MOD_RED;
				clearTimer1();
				clearTimer4();
				setTimer2(blink_time);
				button_flag[0] = 0;
				red_time_buffer = red_time;
			}
			break;
		default:
			break;
		}
}

void fsm_automatic_2_run()
{
	switch(status1)
		{
		case INIT:
			status1 = AUTO_GREEN_1;
			count_2 = green_time/100;
			break;
		case AUTO_RED_1:
			if(timer5_flag == 1)
			{
				status1 = AUTO_GREEN_1;
				setTimer5(red_time);
				red_1_display();
				count_2 = red_time/100;
			}
			if(button_flag[0] == 1)
			{
				status1 = NULL_STATE;
				clearTimer5();
				button_flag[0] = 0;
			}
			break;
		case AUTO_GREEN_1:
			if(timer5_flag == 1)
			{
				status1 = AUTO_YELLOW_1;
				setTimer5(green_time);
				green_1_display();
				count_2 = green_time/100;
			}
			if(button_flag[0] == 1)
			{
				status1 = NULL_STATE;
				clearTimer5();
				button_flag[0] = 0;
			}
			break;
		case AUTO_YELLOW_1:
			if(timer5_flag == 1)
			{
				status1 = AUTO_RED_1;
				setTimer5(yellow_time);
				yellow_1_display();
				count_2 = yellow_time/100;
			}
			if(button_flag[0] == 1)
			{
				status1 = NULL_STATE;
				clearTimer5();
				button_flag[0] = 0;
			}
			break;
		default:
			break;
		}
}
