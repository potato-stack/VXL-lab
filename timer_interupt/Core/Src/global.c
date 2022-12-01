/*
 * global.c
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */
#include "global.h"

int global_time = 0;
int status = 0;

void update_time()
{
	global_time +=10;
}
int get_time()
{
	return global_time;
}
