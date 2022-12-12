/*
 * global.h
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 0
#define AUTO_RED 1
#define AUTO_GREEN 2
#define AUTO_YELLOW 3

#define MAN_RED 11
#define MAN_YELLOW 12
#define MAN_GREEN 13
extern int status;

extern int red_time;
extern int green_time;
extern int yellow_time;

void set_red(int time);
void set_green(int time);
void set_yellow(int time);
#endif /* INC_GLOBAL_H_ */
