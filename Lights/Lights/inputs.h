
/*
 * inputs.h
 *
 * Created: 9/12/2017 10:22:54 AM
 *  Author: uidn1932
 */ 


#include <avr/io.h>

#ifndef DEBOUNCE_H_
#define DEBOUNCE_H_

// #define RC  0x80
// #define IGN 0x40
// #define TL  0x20
// #define TR  0x10
// #define B   0x08
// #define HB  0x04
// #define FL  0x02
// #define SME 0x01


typedef enum event_type
{
	ev1_CL=0,
	ev2_IGN,
	ev3_TL,
	ev4_TR,
	ev5_B_rising,
	ev6_HB,
	ev7_FL,
	ev8_SME,
	ev9_B_falling,
	
}event_e;

typedef enum sw_state
{
	Bt_unpressed=0,
	Bt_pos_edge,
	Bt_pressed,
	Bt_neg_edge

}sw_state_e;

extern void debounce_D(volatile uint8_t *port_button);
extern char button_read(void);

extern char press_history, restrict_flag, switches_state;

#endif
