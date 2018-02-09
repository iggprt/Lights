
/*
 * fsm.h
 *
 * Created: 9/13/2017 2:15:48 PM
 *  Author: uidn1932
 */ 

#ifndef FSM_H_
#define FSM_H_


#include "Global.h"
#include <avr/io.h>


uint8 states;

#define SME  ((states>>7)&1)
#define FL ((states>>6)&1)
#define HB  ((states>>5)&1)
#define B  ((states>>4)&1)
#define TR   ((states>>3)&1)
#define TL  ((states>>2)&1)
#define IGN  ((states>>1)&1)
#define CL    (states&1)

// #define SET_CL_OFF  states&=~(1<<7)
// #define SET_IGN_OFF states&=~(1<<6)
// #define SET_TL_OFF  states&=~(1<<5)
// #define SET_TR_OFF  states&=~(1<<4)
// #define SET_B_OFF   states&=~(1<<3)
// #define SET_HB_OFF  states&=~(1<<2)
// #define SET_FL_OFF  states&=~(1<<1)
// #define SET_SME_OFF states&=~1
// 
// #define SET_CL_ON  states|=1<<7
// #define SET_IGN_ON states|=1<<6
// #define SET_TL_ON  states|=1<<5
// #define SET_TR_ON  states|=1<<4
// #define SET_B_ON   states|=1<<3
// #define SET_HB_ON  states|=1<<2
// #define SET_FL_ON  states|=1<<1
// #define SET_SME_ON states|=1

#define LED1_ 0x01
#define LED2_ 0x02
#define LED3_ 0x04
#define LED4_ 0x08
#define LED5_ 0x10
#define LED6_ 0x20
#define LED7_ 0x40
#define LED8_ 0x80
#define NO_LED_ ~0xff




extern void CL_func(void);
extern void IGN_func(void);
extern void TL_func(void);
extern void TR_func(void);
extern void B_func(void);
extern void HB_func(void);
extern void FL_func(void);
extern void SME_func(void);

 typedef (*func_point)(void);
 extern func_point f_leds[8];


#endif  /* FSM_H_ */