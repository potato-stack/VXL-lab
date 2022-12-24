/*
 * com_reiceive.h
 *
 *  Created on: Dec 24, 2022
 *      Author: hatru
 */

#ifndef INC_COM_REICEIVE_H_
#define INC_COM_REICEIVE_H_
#include "main.h"
#include "SOFTWARE_TIMER.h"

#define INIT	0
#define START_STATE		10

#define ASK				21
#define STOP			22
#define UNDEFINE		-1

#define MAX_BUFFER_SIZE 30

#define time_out  3000
extern int comm_status;
extern int cmd_status;		//command char status
extern int cmd_type;		//message type
extern int cmd_flag;
extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern int ack;
void cmd_init();
void cmd_parser_fsm();

void uart_communiction_innit();
void uart_communication_fsm();
#endif /* INC_COM_REICEIVE_H_ */
