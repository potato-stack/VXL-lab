/*
 * global.h
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 0
#define RUNNING 1
#define WAITING 2

#define TIME_OUT 1000
extern int status;
extern int time;
extern int count_1;

void setTime();
#endif /* INC_GLOBAL_H_ */
