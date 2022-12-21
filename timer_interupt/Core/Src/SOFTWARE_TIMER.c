/*
 * SOFTWARE_TIMER.C
 *
 *  Created on: Sep 24, 2022
 *      Author: hatru
 */
#include "SOFTWARE_TIMER.h"
#include "global.h"
int timer1_flag = 0;
int timer1_counter = 0;
int timer2_flag = 0;
int timer2_counter = 0;
int timer3_flag = 0;
int timer3_counter = 0;
int timer4_flag = 0;
int timer4_counter = 0;

void setTimer1( int duration)
{
	timer1_counter = duration/TIMER_CYCLE;
	timer1_flag = 0;
}

void setTimer2( int duration)
{
	timer2_counter = duration/TIMER_CYCLE;
	timer2_flag = 0;
}
void setTimer3( int duration)
{
	timer3_counter = duration/TIMER_CYCLE;
	timer3_flag = 0;
}
void setTimer4( int duration)
{
	timer4_counter = duration/TIMER_CYCLE;
	timer4_flag = 0;
}

int getTimer1()
{
	return timer1_counter*TIMER_CYCLE;
}
int getTimer2()
{
	return timer2_counter*TIMER_CYCLE;
}
int getTimer3()
{
	return timer3_counter*TIMER_CYCLE;
}
int getTimer4()
{
	return timer4_counter*TIMER_CYCLE;
}

void timerRun()
{
	if(timer1_counter > 0)
	{
		timer1_counter--;
		if(timer1_counter <= 0)
		{
			timer1_flag = 1;
		}
	}
	if(timer2_counter > 0)
	{
		timer2_counter--;
		if(timer2_counter <= 0)
		{
			timer2_flag = 1;
		}
	}
	if(timer3_counter > 0)
	{
			timer3_counter--;
			if(timer3_counter <= 0)
			{
				timer3_flag = 1;
			}
	}
	if(timer4_counter > 0)
	{
			timer4_counter--;
			if(timer4_counter <= 0)
			{
				timer4_flag = 1;
			}
	}
}
