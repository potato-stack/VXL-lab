/*
 * fsm_tunning.c
 *
 *  Created on: Dec 14, 2022
 *      Author: Tam Thanh Tin
 */
#include "global.h"
#include "SOFTWARE_TIMER.h"
#include "input_reading.h"
#include "fsm_tunning.h"
#include "display_control.h"


void fsm_tunning_run(){
	switch (status1){
	case TUNNING_GREEN:
		Green_On();
		Green1_On();
		if(button_flag[0]==1)
		{
			button_flag[0]=0;
			status1=TUNNING_YELLOW;
		}
		if(button_flag[1]==1)
		{
			button_flag[1]=0;
			output_time(0,green_time+1000);
			set_green_time(green_time+1000);
		}
		if(button_flag[2]==1)
		{
			button_flag[2]=0;
			if(green_time > 1000)
			{
				output_time(0,green_time-1000);
				set_green_time(green_time-1000);
			}
			else
			{
				output_error();
			}
		}
	break;
	case TUNNING_YELLOW :
		Yellow_On();
		Yellow1_On();
		if(button_flag[0]==1){
			button_flag[0]=0;
			change_mode(0);
			status1=INIT;
		}
		if(button_flag[1]==1)
		{
			button_flag[1]=0;
			output_time(1,yellow_time+1000);
			set_yellow_time(yellow_time+1000);
		}
		if(button_flag[2]==1)
		{
			button_flag[2]=0;
			if(yellow_time > 1000)
			{
				output_time(1,yellow_time-1000);
				set_yellow_time(yellow_time-1000);
			}
			else
			{
				output_error();
			}

		}
		break;

	}
}
