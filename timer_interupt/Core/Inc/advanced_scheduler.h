/*
 * advanced_scheduler.h
 *
 *  Created on: Dec 20, 2022
 *      Author: hatru
 */

#ifndef INC_ADVANCED_SCHEDULER_H_
#define INC_ADVANCED_SCHEDULER_H_
#include <stdint.h>
#include "global.h"
#include <stdio.h>
#include <stdlib.h>

#define ADV_SCH_MAX_TASKS	40
#define ADV_TIMER_CYCLE		10

typedef struct advTasks
{
	void (*pTask)(void);
	uint32_t 	Delay;
	uint32_t 	Period;
	uint8_t 	RunMe;
	uint32_t	ID;
	struct advTasks*	next;
} advTasks;

typedef struct adv_SCH_list
{
	uint32_t size;
	advTasks *head;
} adv_SCH_list;


void adv_SCH_Init(void);
void adv_SCH_Add_Task( void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void adv_SCH_Update(void);
void adv_SCH_Dispatch_Tasks(void);
void adv_SCH_Delete_Task(advTasks *task);


#endif /* INC_ADVANCED_SCHEDULER_H_ */
