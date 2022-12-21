/*
 * SOFTWARE_TIMER.h
 *
 *  Created on: Sep 24, 2022
 *      Author: hatrungquyen
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;
#define TIMER_CYCLE 10;
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
int getTimer1();
int getTimer2();
int getTimer3();
int getTimer4();
void clearTimer1();
void timerRun();
#endif /* INC_SOFTWARE_TIMER_H_ */
