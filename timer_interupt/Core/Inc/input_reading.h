/*
 * input_reading.h
 *
 *  Created on: Nov 1, 2022
 *      Author: hatru
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_
#include "main.h"

#define NO_OF_BUTTONS		3
extern int button_flag[NO_OF_BUTTONS];
void button_reading();
int if_keys_is_realease();


//unsigned char is_button_pressed_1s(unsigned char index);
#endif /* INC_INPUT_READING_H_ */
