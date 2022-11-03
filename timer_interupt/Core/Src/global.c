/*
 * global.c
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */
#include "global.h"

int red_time = 0;
int yellow_time = 0;
int green_time = 0;

int red_time_buffer = 0;
int green_time_buffer = 0;
int yellow_time_buffer = 0;
int t1 = 0;
int status = 0;
void set_red(int time)
{
	red_time = time;
}
void set_yellow(int time)
{
	yellow_time = time;
}
void set_green(int time)
{
	green_time = time;
}

