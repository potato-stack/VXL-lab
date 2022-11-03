#include "input_reading.h"

#define DURATION_FOR_AUTO_DECREASING 	100
#define BUTTON_IS_PRESSED				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED				GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer0[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
int button_flag[NO_OF_BUTTONS];
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];

unsigned char is_button_pressed(unsigned char index)
{
	if(index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

//unsigned char is_button_pressed_1s()


void subkeyProcess(unsigned char i)
{
	button_flag[i] = 1;
}
void button_reading()
{
	for(unsigned char i = 0; i < NO_OF_BUTTONS; i++)
	{
		debounceButtonBuffer0[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = debounceButtonBuffer2[i];
		switch (i)
		{
			case 0:
				debounceButtonBuffer2[i] = HAL_GPIO_ReadPin(button_1_GPIO_Port, button_1_Pin);
				break;
			case 1:
				debounceButtonBuffer2[i] = HAL_GPIO_ReadPin(button_2_GPIO_Port, button_2_Pin);
				break;
			case 2:
				debounceButtonBuffer2[i] = HAL_GPIO_ReadPin(button_3_GPIO_Port, button_3_Pin);
				break;
			default:
				debounceButtonBuffer2[i] = BUTTON_IS_RELEASED;
				break;
		}
		if((debounceButtonBuffer0[i] == debounceButtonBuffer1[i]) && (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]))
		{
			if(buttonBuffer[i] != debounceButtonBuffer2[i])
			{
				buttonBuffer[i] = debounceButtonBuffer2[i];
				if(buttonBuffer[i] == BUTTON_IS_PRESSED)
				{
					counterForButtonPress1s[i] = DURATION_FOR_AUTO_DECREASING;
					subkeyProcess(i);
				}
			}
			else
			{
				counterForButtonPress1s[i]--;
				if(counterForButtonPress1s[i] == 0)
				{
					if(buttonBuffer[i] == BUTTON_IS_PRESSED)
					{
						counterForButtonPress1s[i] = DURATION_FOR_AUTO_DECREASING;
						subkeyProcess(i);
					}

				}
			}
		}
	}
}

