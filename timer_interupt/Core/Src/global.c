/*
 * global.c
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */
#include "global.h"

int red_time;
int yellow_time;
int green_time;
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

