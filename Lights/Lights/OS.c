/*
 * OS.c
 *
 * Created: 9/11/2017 11:06:28 AM
 *  Author: uidn2753
 */ 
#include "OS.h"
#include "adc.h"
#include "Global.h"
#include "fsm.h"

task_s tablou_tasks[NUM_TASKS]=
{
	 {0,10,task_1ms,WAIT,0},
	 {1,50,task_5ms,WAIT,0},
	 {2,100,task_10ms,WAIT,0},
	 {3,200,task_20ms,WAIT,0},
	 {4,500,task_50ms,WAIT,0},
	 {5,1000,task_100ms,WAIT,0},
};

uint8_t i;
void init(void)
{
	
	for(i=0;i<NUM_TASKS;i++)
	{
		tablou_tasks[i].current_time=tablou_tasks[i].delay;
	}
	
}
void idle(void)
{
	
	for(i=0;i<NUM_TASKS;i++)
	{
		if((tablou_tasks[i].state!=READY)&&(tablou_tasks[i].current_time>0))
		{
			tablou_tasks[i].current_time--;
		}
		if(tablou_tasks[i].current_time==0)
		{
			tablou_tasks[i].state=READY;
			tablou_tasks[i].current_time=tablou_tasks[i].cycletime;
		}
	}
	
}
void scheduler(void)
{
	while(1)
	{
		for(i=0;i<NUM_TASKS;i++)
		{
			if(tablou_tasks[i].state==READY)
			{
				tablou_tasks[i].state=ACTIVE;
				tablou_tasks[i].task_pointer();
				tablou_tasks[i].state=WAIT;
			}
		}
	}
}
uint16 count;
void task_1ms(void)
{
	char local_states= states;
	debounce_D(&PINB);
	processEvents();
	if((local_states&1)!=CL)
	{
		PORTC=0x00;
	}
	else
	PORTC= LEDS();
	
	adc_cyclic(0);
}
void task_5ms(void)
{
	
}
void task_10ms(void)
{
	
}
void task_20ms(void)
{
	
}
void task_50ms(void)
{
	
}
void task_100ms(void)
{
	
}
