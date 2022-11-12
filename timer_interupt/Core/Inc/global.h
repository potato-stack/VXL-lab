/*
 * global.h
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 0
#define AUTO_RED_YELLOW 1
#define AUTO_GREEN_RED 2
#define AUTO_YELLOW_RED 3
#define AUTO_RED_GREEN 4

#define MOD_RED 21
#define MOD_YELLOW 22
#define MOD_GREEN 23

#define SAVE_RED 31
#define SAVE_YELLOW 32
#define SAVE_GREEN 33
extern int status;


extern int red_time;
extern int green_time;
extern int yellow_time;

extern int red_time_buffer;
extern int green_time_buffer;
extern int yellow_time_buffer;

void set_red(int time);
void set_green(int time);
void set_yellow(int time);
#endif /* INC_GLOBAL_H_ */
