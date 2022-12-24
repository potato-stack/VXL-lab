/*
 * comm_fsm.c
 *
 *  Created on: Dec 24, 2022
 *      Author: hatru
 */

#include "com_reiceive.h"
#include "main.h"
int comm_status = 0;
int ack = 0;
void uart_communiction_innit()
{
	comm_status = STOP;
}

void uart_communication_fsm()
{
	switch (comm_status)
	{
	case STOP:
		if(cmd_type == ASK)
		{
			comm_status = ASK;
			timer1_flag = 1;
			ack = 1;
			cmd_type = UNDEFINE;
		}
		break;
	case ASK:
		if(timer1_flag == 1)
		{
			Send_value();
			setTimer1(time_out);
			ack = 0;
		}
		if(cmd_type == STOP)
		{
			comm_status = STOP;
			setTimer1(0);
			ack = 1;
			cmd_type = UNDEFINE;
		}
	default:
		break;
	}
}
