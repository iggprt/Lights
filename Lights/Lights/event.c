
/*
 * event.c
 *
 * Created: 9/13/2017 2:12:31 PM
 *  Author: uidn1932
 */ 
#include "Global.h"
uint16 events;
void setEvent(uint8 ev)
{
	events |=1<<ev;
}

void resetEvent(uint8 ev)
{
	events &=~(1<<ev);
}

uint16 getEvent(void)
{
	return events;
}