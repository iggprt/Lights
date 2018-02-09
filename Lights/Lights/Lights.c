/*
 * Lights.c
 *
 * Created: 9/11/2017 11:06:09 AM
 *  Author: uidn2753
 */ 

#include "OS.h"
#include "Lights_timer.h"
#include "avr/io.h"
#include "avr/io.h"
#include "avr/delay.h"
#include "inputs.h"

int main(void)
{
	adc_init();
	init_ports();
	init();
	init_timer1();
	
	scheduler();

}