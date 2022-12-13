/*
 * display_control.h
 *
 *  Created on: Dec 12, 2022
 *      Author: hatru
 */

#ifndef INC_DISPLAY_CONTROL_H_
#define INC_DISPLAY_CONTROL_H_
#include "main.h"
//===============LEDS DISPLAY FUNCTION PART==========================================================================================================
//led control on two main roads.--------------------------------------------------------------------------------------------------------
void Red_On();
void Green_On();
void Yellow_On();
void Red1_On();
void Green1_On();
void Yellow1_On();

//led control for crossing the road--------------------------------------------------------------------------------------------------------
void Redp_On();
void Greenp_On();

//Reset leds on two main roads.--------------------------------------------------------------------------------------------------------
void Reset();
//Reset leds for crossing the road--------------------------------------------------------------------------------------------------------
void Reset_p();
#endif /* INC_DISPLAY_CONTROL_H_ */
