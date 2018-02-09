/*
 * Lights_timer.c
 *
 * Created: 9/11/2017 11:12:26 AM
 *  Author: uidn2753
 */ 
#include "Lights_timer.h"
#include "OS.h"

void init_ports(void)
{
	DDRA=0x00;
	PORTA=0xff;
	
	DDRB=0x00;
	PORTB=0xff;
	
	DDRC=0xff;
	PORTC=0xff;
}

void init_timer1(void)
{
	cli();
	TCCR1A|=0x00;
	TCCR1B|=(1<<WGM12)|(1<<CS10);
	TIMSK|=(1<<OCIE1A);
	TIFR|=(1<<OCF1A);
	OCR1A=1600-1;
	sei();
}

ISR(TIMER1_COMPA_vect)
{	
	idle();
}


