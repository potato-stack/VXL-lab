/*
 * fsm_pedestrian.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Thinh Dang
 */
#include "fsm_pedestrian.h"
#include "display_control.h"
int buzz_state = 0;

void fsm_pedestrian()
{
	if(checking == 1)
	{
		if(status2 != status1)
		{
			sound_loud(OFF);
		}
		status2 = status1;
	}
	switch(status2)
	{
	case AUTO_RED_GREEN :
		if(timer3_flag == 1)
		{
			sound_loud(OFF);
			Reset_p();
			status2 = WAITING;
			checking = 0;
			setTimer4(0);
		}
		else Redp_On();
		break;
	case AUTO_RED_YELLOW:
		if(timer3_flag == 1)
		{
			sound_loud(OFF);
			Reset_p();
			status2 = WAITING;
			setTimer4(0);
		}
		else Redp_On();
		break;
	case AUTO_GREEN_RED:
		if(count2 <= 5 && timer4_flag == 1)
		{
				if(buzz_state == 1)
				{
					sound_loud(ON);
					buzz_state = 0;
				}
				else
				{
					sound_loud(OFF);
					buzz_state = 1;
				}
				setTimer4(count2*50 + 10);
		}
		if(timer3_flag == 1)
		{
			sound_loud(OFF);
			Reset_p();
			status2 = WAITING;
			checking = 0;
			setTimer4(0);
		}
		else Greenp_On();
		break;
	case AUTO_YELLOW_RED:
		if(count2<= 5 && timer4_flag == 1)
		{
				if(buzz_state == 1)
				{
					sound_loud(ON);
					buzz_state = 0;
				}
				else
				{
					sound_loud(OFF);
					buzz_state = 1;
				}
				setTimer4(count2*50 + 10);
		}
		if(timer3_flag == 1)
		{
			sound_loud(OFF);
			Reset_p();
			status2 = WAITING;
			checking = 0;
			setTimer4(0);
		}
		else Greenp_On();
		break;
	case MAN_RED_GREEN:
		Redp_On();
		if(timer3_flag == 1)
		{
			sound_loud(OFF);
			Reset_p();
			status2 = WAITING;
			setTimer4(0);
		}
		break;
	case MAN_RED_YELLOW:
		Redp_On();
		if(timer3_flag == 1)
		{
			sound_loud(OFF);
			Reset_p();
			status2 = WAITING;
			checking = 0;
			setTimer4(0);
		}
		break;
	case MAN_GREEN_RED:
		Greenp_On();
		if(timer3_flag == 1)
		{
			sound_loud(OFF);
			Reset_p();
			status2 = WAITING;
			setTimer4(0);
		}
		break;
	case MAN_YELLOW_RED:
		Greenp_On();
		if(timer3_flag == 1)
		{
			sound_loud(OFF);
			Reset_p();
			status2 = WAITING;
			checking = 0;
			setTimer4(0);
		}
		break;

	default: break;
}
}
