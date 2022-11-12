/*
 * display.h
 *
 *  Created on: Nov 2, 2022
 *      Author: hatru
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

void red_display();
void green_display();
void yellow_display();
void red_1_display();
void green_1_display();
void yellow_1_display();
void red_blink();
void green_blink();
void yellow_blink();
void led_reset();
void scan7SEG();
void clock_update();
extern int blink_time;
extern int led_buffer[4];
extern int count_1;
extern int count_2;

#endif /* INC_DISPLAY_H_ */
