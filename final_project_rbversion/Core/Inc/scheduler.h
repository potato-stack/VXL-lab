/*
 * scheduler.h
 *
 *  Created on: Nov 11, 2022
 *      Author: hatru
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include <stdint.h>
#include "global.h"
#include <stdio.h>

typedef struct
{
	void (*pTask)(void);
	uint32_t 	Delay;
	uint32_t 	Period;
	uint8_t 	RunMe;
	uint32_t 	TaskID;
} sTasks;

#define SCH_MAX_TASKS	40
#define TIMER_CYCLE		10

void SCH_Init(void);
void SCH_Add_Task( void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task(const uint8_t TASK_INDEX);

#endif /* INC_SCHEDULER_H_ */
