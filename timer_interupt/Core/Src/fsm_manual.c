/*
 * fsm_manual.h
 *
 *  Created on: Oct 7, 2022
 *      Author: hatru
 */
#include "fsm_manual.h"
#include "input_reading.h"
#include "display_control.h"

void fsm_manual_run()
{
	switch(status1)
	{
	case MAN_RED_GREEN:
		Green1_On();
		if(timer1_flag == 1)
		{
			change_mode(0);
			status1 = AUTO_RED_GREEN;
			set_road1_time(red_time);
			set_road2_time(green_time);
			setTimer1(green_time);
		}
		if(button_flag[1] == 1)
		{
			button_flag[1]=0;
			status1 = MAN_RED_YELLOW;
			status2 = MAN_RED_YELLOW;
			//Set timer3 here to turn off pedestrian led after exit manual mode
			setTimer3(timeout_duration);
			//Set timer1 here to exit manual mode when time out
			setTimer1(timeout_duration);
		}
		break;
	case MAN_RED_YELLOW:
		Red_On();
		Yellow1_On();
		if(timer1_flag == 1)
		{
			change_mode(0);
			status1 = AUTO_RED_YELLOW;
			set_road1_time(yellow_time);
			set_road2_time(yellow_time);
			setTimer1(yellow_time);
		}
		if(button_flag[1]  == 1)
		{
			button_flag[1]=0;
			status1=MAN_GREEN_RED;
			status2=MAN_GREEN_RED;
			//Set timer3 here to turn off pedestrian led after exit manual mode
			setTimer3(timeout_duration);
			setTimer1(timeout_duration);
		}
		break;
	case MAN_GREEN_RED:
		Red1_On();
		Green_On();
		if(timer1_flag == 1)
		{
			change_mode(0);
			status1=AUTO_GREEN_RED;
			set_road1_time(green_time);
			set_road2_time(red_time);
			setTimer1(green_time);
		}
		if(button_flag[1] == 1)
		{
			button_flag[1]=0;
			status1=MAN_YELLOW_RED;
			status2=MAN_YELLOW_RED;
			//Set timer3 here to turn off pedestrian led after exit manual mode
			setTimer3(timeout_duration);
			setTimer1(timeout_duration);
		}
		break;
	case MAN_YELLOW_RED:
		Red1_On();
		Yellow_On();
		if(timer1_flag == 1)
		{
			change_mode(0);
			status1=AUTO_YELLOW_RED;
			set_road1_time(yellow_time);
			set_road2_time(yellow_time);
			setTimer1(yellow_time);
		}
		if(button_flag[1]  == 1)
		{
			button_flag[1]=0;
			status1=MAN_RED_GREEN;
			status2=MAN_RED_GREEN;
			//Set timer3 here to turn off pedestrian led after exit manual mode
			setTimer3(timeout_duration);
			setTimer1(timeout_duration);
		}
		break;
	default:
		break;
	}
}

