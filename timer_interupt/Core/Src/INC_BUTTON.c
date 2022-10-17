/*
 * INC_BUTTON.c
 *
 *  Created on: Sep 24, 2022
 *      Author: hatru
 */

#include "INC_BUTTON.h"
#include "main.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;
int button1_flag = 0;

int TimeOutForKeyPress =  100;
void subKeyProcess()
{
	if(KeyReg3 == PRESSED_STATE)
	{
		button1_flag = 1;
	}
}
void getKeyInput(){
  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  KeyReg0 = HAL_GPIO_ReadPin(button_1_GPIO_Port, button_1_Pin);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3){
      KeyReg3 = KeyReg2;

      if (KeyReg3 == PRESSED_STATE){
        TimeOutForKeyPress = 100;
        subKeyProcess();
      }
    }else{
       TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
          KeyReg3 = NORMAL_STATE;
        }
    }
  }
}


