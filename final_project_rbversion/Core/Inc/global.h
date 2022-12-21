/*
 * global.h
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
//===============DEFINE PART============================================================================================================
//--------------------------------------------------all the state of finate state machine------------------------------------------------
//Note: assume that red time always = green time + yellow time
#define INIT 0
#define AUTO_RED_GREEN 			1			//Red on first road, green on the second
#define AUTO_RED_YELLOW 		2			//Red on first road, yellow on the second
#define AUTO_GREEN_RED			3			//Green on first road, red on the second
#define AUTO_YELLOW_RED			4			//Yellow on first road, red on the second

#define MAN_RED_GREEN 			11			//Red on first road, green on the second
#define MAN_RED_YELLOW 			12			//Red on first road, yellow on the second
#define MAN_GREEN_RED			13			//Green on first road, red on the second
#define MAN_YELLOW_RED			14			//Yellow on first road, red on the second


#define TUNNING_GREEN 			15
#define TUNNING_YELLOW 			16

#define WAITING					-1
//define the value to convert from milisec to sec when displaying or output in terminal
#define CYCLE 					1000
//===============VARIABLES PART==========================================================================================================
//-------------------------------------------------status of finate state machine--------------------------------------------------------
extern int status1;
extern int status2;
//extern int status3;
//extern int status4;
//extern int sound;
//extern int sound_flag;
//-------------------------------------------------leds' time variables--------------------------------------------------------------------
extern int green_time;
extern int red_time;
extern int yellow_time;

extern int timeout_duration;
extern int pedestrian_duration;
extern int checking;
//-------------------------------------------------UART time display variables--------------------------------------------------------------------
extern int count1;
extern int count2;
//===============TIME RELATED FUNCTION PART==========================================================================================================
//-----------------------------------------------set time function----------------------------------------------------------------------
//Note: since red = green + yellow, only need to set time for green and yellow
void set_green_time(int time);
void set_yellow_time(int time);
void set_timeout_duration(int time);
void set_pedestrian_duration(int time);
void set_road1_time(int time);
void set_road2_time(int time);
void count_down_show();
//------------------------------------this part is use for displaying interval time - not use----------------------------------------------


extern int global_time;
void update_time();
int get_time();

#endif /* INC_GLOBAL_H_ */
