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

extern int global_time;
void update_time();
int get_time();
#endif /* INC_GLOBAL_H_ */
