/*
 * adc.c
 *
 * Created: 9/14/2017 2:11:37 PM
 *  Author: uidn1932
 */ 
#include "avr/io.h"
#include "Global.h"
#include "avr/interrupt.h"
uint16 result_ADC;
void adc_init()
{
	cli();
	
	ADMUX=0x40;

	ADCSRA|=1<<ADIE;
	ADCSRA|=6; //prscaler =64
	ADCSRA|=1<<ADEN;
	
	sei();
	
}
uint16 get_result_ADC(void)
{
	return result_ADC;
}
void adc_cyclic(uint8 channel)
{
 	ADMUX |= channel;
 	ADCSRA |= 1<<ADSC;
}


ISR(ADC_vect)
{
	result_ADC=ADC;
}