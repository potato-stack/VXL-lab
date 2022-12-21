/*
 * advanced_scheduler.c
 *
 *  Created on: Dec 20, 2022
 *      Author: hatru
 */
#include "advanced_scheduler.h"

adv_SCH_list S;

advTasks* new_task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD)
{
	advTasks *temp = malloc(sizeof(advTasks));
	temp->pTask = pFunction;
	temp->Delay = DELAY/ADV_TIMER_CYCLE;
	temp->Period = PERIOD/ADV_TIMER_CYCLE;
	temp->RunMe = 0;
	temp->next = NULL;
	temp->ID   = DELAY;
	return temp;
}

void adv_SCH_Init(void)
{
	S.head = NULL;
	S.size = 0;
}

void adv_SCH_push(advTasks *task)
{
	if(S.size == ADV_SCH_MAX_TASKS) return;
	//if this is the first task to add
	if(S.head == NULL)
	{
		S.head = task;
		S.size++;
		return;
	}
	//if this task is neither the first task or have to add to the head of list
	//we search for it positoin
	advTasks *temp = S.head;
	advTasks *prev = NULL;

	while(temp != NULL)
	{
		//output_error(temp->Delay);
		if(task->Delay >= temp->Delay)
		{
			task->Delay -= temp->Delay;
		}
		else
			break;
		prev = temp;
		temp = temp->next;
	}

	if(prev == NULL)//The first task at head is bigger
	{
		S.head->Delay -= task->Delay;
		task->next = S.head;
		S.head = task;
		S.size++;
	}
	else if(temp == NULL)//Even the last task is smaller
	{
		prev->next = task;
		S.size++;
	}
	else//the task position is somewhere in the list
	{
		task->next = temp;
		temp->Delay -= task->Delay;
		prev->next = task;
		S.size++;
	}
	return;
}

advTasks* adv_SCH_pop()
{
	if(S.head != NULL)
	{
		advTasks* temp = S.head;
		S.head = S.head->next;
		temp->next = NULL;
		S.size--;
		return temp;
	}
	return NULL;
}

void adv_SCH_Add_Task( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD)
{
	if(S.size == ADV_SCH_MAX_TASKS) return;

	//if this is the first task to add
	advTasks *temp = new_task(pFunction, DELAY, PERIOD);
	adv_SCH_push(temp);
}


void adv_SCH_Update(void)
{
	if(S.head != NULL)
	{
		if(S.head->Delay > 0)
		{
			S.head->Delay--;
		}
		if(S.head->Delay == 0)
		{
			S.head->RunMe++;
		}
	}
}

void adv_SCH_Dispatch_Tasks(void)
{
	if(S.head->RunMe > 0)
	{
		(*S.head->pTask)();
		S.head->RunMe--;
		advTasks* currTask = adv_SCH_pop();
		if(currTask->Period)
		{
			currTask->Delay = currTask->Period;
			adv_SCH_push(currTask);
			if(S.head->Delay == 0)
			{
				S.head->RunMe++;
			}
		}
		else
		{
			adv_SCH_Delete_Task(currTask);
		}
	}
}

void adv_SCH_Delete_Task(advTasks *task)
{
	if(task != NULL)
		free(task);
}


