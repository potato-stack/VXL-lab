/*
 * display.c
 *
 *  Created on: Nov 2, 2022
 *      Author: hatru
 */
#include "display.h"
#include "main.h"
#include "SOFTWARE_TIMER.h"

#define LED7PORT GPIOB
int blink_time = 25;

const int MAX_LEDS = 4;
int led_buffer[4] = {0,0,0,0};
void display7SEG(int numb)
{
	switch (numb) {
		case 0:
		    HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
		    HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
		    HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
		    HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
		    HAL_GPIO_WritePin(LED7PORT, S5_Pin, RESET);
		    HAL_GPIO_WritePin(LED7PORT, S6_Pin, RESET);
		    HAL_GPIO_WritePin(LED7PORT, S7_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(LED7PORT, S1_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S2_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S3_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S4_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S5_Pin, SET);
			HAL_GPIO_WritePin(LED7PORT, S6_Pin, RESET);
			HAL_GPIO_WritePin(LED7PORT, S7_Pin, RESET);
			break;
		default:
			break;
	}
}
void update7SEG(int index)
{
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(S8_GPIO_Port, S8_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(S9_GPIO_Port, S9_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(S10_GPIO_Port, S10_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(S11_GPIO_Port, S11_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(S8_GPIO_Port, S8_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(S9_GPIO_Port, S9_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(S10_GPIO_Port, S10_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(S11_GPIO_Port, S11_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(S8_GPIO_Port, S8_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(S9_GPIO_Port, S9_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(S10_GPIO_Port, S10_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(S11_GPIO_Port, S11_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(S8_GPIO_Port, S8_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(S9_GPIO_Port, S9_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(S10_GPIO_Port, S10_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(S11_GPIO_Port, S11_Pin, GPIO_PIN_RESET);
			display7SEG(led_buffer[3]);
			break;
		default:
			break;
	}
}
int count_1 = 0;
int count_2 = 0;
void updateLedBuffer()
{
	led_buffer[0] = count_1/10;
	led_buffer[1] = count_1%10;
	led_buffer[2] = count_2/10;
	led_buffer[3] = count_2%10;
}
int led_index = 0;
void scan7SEG()
{
	updateLedBuffer();
	if(timer3_flag == 1)
	{
		setTimer3(5);
		if(led_index >= MAX_LEDS)
		{
			led_index = 0;
		}
		else led_index++;
		update7SEG(led_index);
	}
}
void clock_display()
{
	if(timer4_flag == 1)
	{
		setTimer4(100);
		count_1--;
		count_2--;
	}
}
void red_display()
{
	HAL_GPIO_WritePin(GPIOA, Led_red_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, Led_green_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_yellow_Pin, SET);
}
void green_display()
{
	HAL_GPIO_WritePin(GPIOA, Led_red_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_green_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, Led_yellow_Pin, SET);
}
void yellow_display()
{
	HAL_GPIO_WritePin(GPIOA, Led_red_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_green_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_yellow_Pin, RESET);
}
void red_1_display()
{
	HAL_GPIO_WritePin(GPIOA, Led_red_1_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, Led_green_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_yellow_1_Pin, SET);
}
void green_1_display()
{
	HAL_GPIO_WritePin(GPIOA, Led_red_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_green_1_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, Led_yellow_1_Pin, SET);
}
void yellow_1_display()
{
	HAL_GPIO_WritePin(GPIOA, Led_red_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_green_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_yellow_1_Pin, RESET);
}
int st = 0;
void red_blink()
{
	if(timer2_flag == 1)
	{
		led_reset();
		setTimer2(blink_time);
		if(st == 0)
		{
		HAL_GPIO_WritePin(GPIOA, Led_red_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Led_red_1_Pin, SET);
		st = 1;
		}
		else
		{
		HAL_GPIO_WritePin(GPIOA, Led_red_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, Led_red_1_Pin, RESET);
		st = 0;
		}
	}
}
void green_blink()
{
	if(timer2_flag == 1)
	{
		led_reset();
		setTimer2(blink_time);
		if(st == 0)
		{
		HAL_GPIO_WritePin(GPIOA, Led_green_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Led_green_1_Pin, SET);
		st = 1;
		}
		else
		{
		HAL_GPIO_WritePin(GPIOA, Led_green_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, Led_green_1_Pin, RESET);
		st = 0;
		}
	}
}
void yellow_blink()
{
	if(timer2_flag == 1)
	{
		led_reset();
		setTimer2(blink_time);
		if(st == 0)
		{
		HAL_GPIO_WritePin(GPIOA, Led_yellow_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Led_yellow_1_Pin, SET);
		st = 1;
		}
		else
		{
		HAL_GPIO_WritePin(GPIOA, Led_yellow_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, Led_yellow_1_Pin, RESET);
		st = 0;
		}
	}
}
void led_reset()
{
	HAL_GPIO_WritePin(GPIOA, Led_red_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_green_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_yellow_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_red_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_green_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, Led_yellow_Pin, SET);
}

