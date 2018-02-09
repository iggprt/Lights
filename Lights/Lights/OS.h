/*
 * OS.h
 *
 * Created: 9/11/2017 11:06:38 AM
 *  Author: uidn2753
 */ 
#include <avr/io.h>

#ifndef OS_H_
#define OS_H_
#define NUM_TASKS 6

typedef enum task_state
{
	WAIT,
	READY,
	ACTIVE,
}task_state_e;
 
 typedef void(*function_pointer)(void);
 
 typedef struct task
 {
	 const uint16_t delay;
	 const uint16_t cycletime;
	 function_pointer task_pointer;
	 task_state_e state;
	 uint16_t current_time;
 }task_s;



extern void init(void);
 
extern void idle(void);
extern void scheduler(void);

extern void task_1ms(void);
extern void task_5ms(void);
extern void task_10ms(void);
extern void task_20ms(void);
extern void task_50ms(void);
extern void task_100ms(void);



#endif /* OS_H_ */