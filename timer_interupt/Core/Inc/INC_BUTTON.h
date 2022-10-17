/*
 * INC_BUTTON.h
 *
 *  Created on: Sep 24, 2022
 *      Author: hatru
 */

#ifndef INC_INC_BUTTON_H_
#define INC_INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag;
void getKeyInput();

#endif /* INC_INC_BUTTON_H_ */
