/*
 * global.c
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */
#include "global.h"
//Initial value of variable in the header
int global_time = 0;
int status1 = 0;
int status2 = 0;
int green_time = 0;
int yellow_time = 0;
int red_time = 0;
int timeout_duration = 0;
int count1 = 0;
int count2 = 0;

//Function for setting led time
void set_green_time(int time)
{
	green_time = time;
}
void set_yellow_time(int time)
{
	yellow_time = time;
}
void set_red_time()
{
	red_time = green_time + yellow_time;
}
void set_timeout_duration(int time)
{
	timeout_duration = time;
}
//Function for setting display time
void set_road1_time(int time)
{
	count1 = time;
}
void set_road2_time(int time)
{
	count2 = time;
}
//global time function - not use
void update_time()
{
	global_time +=10;
}
int get_time()
{
	return global_time;
}
