/*
 * adc.h
 *
 * Created: 9/14/2017 2:27:19 PM
 *  Author: uidn1932
 */ 
#include "Global.h"

extern uint16 get_result_ADC();
extern void adc_cyclic(uint8);

#define NIGHT (get_result_ADC()>615?0:1)