/*
 * com_reiceive.c
 *
 *  Created on: Dec 24, 2022
 *      Author: hatru
 */

#include "com_reiceive.h"
#include "SOFTWARE_TIMER.h"

int cmd_status = 0;
int cmd_type = 0;
int cmd_flag = 0;
char curr_char;
int curr_par;

char start_mess_cap[30] = "RST#";
char start_mess_nocap[30] = "rst#";
#define start_mess_length 4

char end_mess_cap[30] = "OK#";
char end_mess_nocap[30] = "ok#";
#define end_mess_length 4

void cmd_init()
{
	cmd_status = INIT;
	cmd_type = UNDEFINE;
	cmd_flag = 0;
	curr_par = 0;
}

void cmd_parser_fsm()
{
	curr_char = buffer[index_buffer-1];
	switch (cmd_status) {
		case INIT:
			cmd_type = UNDEFINE;
			curr_par = 0;
			if(curr_char == '!')
			{
				cmd_status = START_STATE;
			}
			break;
		case START_STATE:
			if(curr_char == start_mess_cap[0] || curr_char == start_mess_nocap[0])
			{
				curr_par++;
				cmd_status = ASK;
			}
			else if(curr_char == end_mess_cap[0] || curr_char == end_mess_nocap[0])
			{
				curr_par++;
				cmd_status = STOP;
			}
			else cmd_status = INIT;
			break;
		case ASK:
			if(curr_char == start_mess_cap[curr_par] || curr_char == start_mess_nocap[curr_par])
			{
				if(curr_char == '#')
				{
					cmd_status = INIT;
					cmd_type = ASK;
					curr_par = 0;
				}
				else curr_par++;
			}
			else
			{
				cmd_status = INIT;
				curr_par = 0;
			}
			break;
		case STOP:
			if(curr_char == end_mess_cap[curr_par] || curr_char == end_mess_nocap[curr_par])
			{

				if(curr_char == '#')
				{
					cmd_status = INIT;
					cmd_type = STOP;
				}
				else curr_par++;
			}
			else
			{
				cmd_status = INIT;
				curr_par = 0;
			}
			break;
		default:
			break;
	}
}
