
/*
 * fsm.c
 *
 * Created: 9/13/2017 2:15:39 PM
 *  Author: uidn1932
 */ 
#include "fsm.h"

func_point f_leds[8]={ CL_func, IGN_func, TL_func, TR_func, B_func, HB_func, FL_func, SME_func };


void processEvents(void)
{
	uint8 i=0;
	uint16 ev=getEvent();
	while (ev)
	{
		if (ev & 1)
		{
			if (i==8)
			{
				states ^=(1<<4);
			}
			else
			{
				states ^=(1<<i);
			}
			if (i==3 && (1&(states>>3)))
			{
				states &=~(1<<2);
			}
			if(i==2 && (1&(states>>2)))
			{
				states &=~(1<<3);
			}
			resetEvent(i);
		}
		i++;
		ev>>=1;
	}
	//PORTC=~states;
}



void processStates()
{

}

void TL_func(void)
{
	//PORTC^=LED5;
}
void TR_func(void)
{
	//PORTC^=LED6;
}
void B_func(void)
{
	
}
void HB_func(void)
{
	
}
void FL_func(void)
{
	
}
void SME_func(void)
{
	
}

void nothing()
{
	
}