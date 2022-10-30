/*
 * INC_BUTTON.c
 *
 *  Created on: Sep 24, 2022
 *      Author: hatru
 */

#include "INC_BUTTON.h"
#include "main.h"

int KeyReg0_a = NORMAL_STATE;
int KeyReg1_a = NORMAL_STATE;
int KeyReg2_a = NORMAL_STATE;
int KeyReg3_a = NORMAL_STATE;
int button1_flag = 0;

int KeyReg0_b = NORMAL_STATE;
int KeyReg1_b = NORMAL_STATE;
int KeyReg2_b = NORMAL_STATE;
int KeyReg3_b = NORMAL_STATE;
int button2_flag = 0;

int TimeOutForKeyPress1 = 100;
int TimeOutForKeyPress2 = 100;

void subKeyProcess1()
{
	if(KeyReg3_a == PRESSED_STATE)
	{
		button1_flag = 1;
	}
}

void subKeyProcess2()
{
	if(KeyReg3_b == PRESSED_STATE)
	{
		button2_flag = 1;
	}
}

void getKeyInput1(){
  KeyReg2_a = KeyReg1_a;
  KeyReg1_a = KeyReg0_a;
  KeyReg0_a = HAL_GPIO_ReadPin(button_1_GPIO_Port, button_1_Pin);
  if ((KeyReg1_a == KeyReg0_a) && (KeyReg1_a == KeyReg2_a))
  {
    if (KeyReg2_a != KeyReg3_a)
    {
      KeyReg3_a = KeyReg2_a;
      if (KeyReg3_a == PRESSED_STATE)
      {
        TimeOutForKeyPress1 = 100;
        subKeyProcess1();
      }
    }
    else
    {
       TimeOutForKeyPress1 --;
       if (TimeOutForKeyPress1 == 0)
       {
          KeyReg3_a = NORMAL_STATE;
       }
    }
  }
}

void getKeyInput2(){
  KeyReg2_b = KeyReg1_b;
  KeyReg1_b = KeyReg0_b;
  KeyReg0_b = HAL_GPIO_ReadPin(button_2_GPIO_Port, button_2_Pin);
  if ((KeyReg1_b == KeyReg0_b) && (KeyReg1_b == KeyReg2_b))
  {
    if (KeyReg2_b != KeyReg3_b)
    {
      KeyReg3_b = KeyReg2_b;
      if (KeyReg3_b == PRESSED_STATE)
      {
        TimeOutForKeyPress2 = 100;
        subKeyProcess2();
      }
    }
    else
    {
       TimeOutForKeyPress2 --;
       if (TimeOutForKeyPress2 == 0)
       {
          KeyReg3_b = NORMAL_STATE;
       }
    }
  }
}
