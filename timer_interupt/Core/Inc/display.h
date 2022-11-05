/*
 * display.h
 *
 *  Created on: Nov 2, 2022
 *      Author: hatru
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

void red_blink();
void led_reset();
void display7SEG(int numb);
void clock_display();

//external variable using for display
extern int blink_time;

#endif /* INC_DISPLAY_H_ */
