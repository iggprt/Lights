/*
 * leds.c
 *
 * Created: 9/14/2017 1:55:17 PM
 *  Author: uidn1932
 */ 
#include "fsm.h"
#include "Global.h"
#include "adc.h"

// uint8 LED1(void)
// {
// 	static uint16 count_led1=0;
// 	uint8 led_conf;
// 	if(SME==1)
// 	{
// 		if(NIGHT)
// 			led_conf = LED1_;
// 		else
// 			led_conf = NO_LED_;
// 	}
// 	else
// 	{
// 		if(CL==1)
// 		{
// 			if(NIGHT)
// 			{
// // 				if(count_led1<100)    ///revenit
// // 					led_conf=NO_LED_;
// // 				else
// // 				{
// // 					count_led1=LED1_;
// // 				}
// 				led_conf=LED1_;
// 			}
// 			else
// 			{
// 				led_conf=NO_LED_;
// 			}
// 		}
// 		else
// 		{
// 			if(IGN)
// 			{
// 				led_conf=LED1_;
// 			}
// 			else
// 			{
// 				led_conf=NO_LED_;
// 			}
// 		}
// 	}
// 	if(count_led1<1000)
// 		count_led1++;
// 	else 
// 		count_led1=0;
// 	return led_conf;
// }
uint8 LED1(void)
{
	return LED1_;
}
uint8 LED2(void)
{
	if(NIGHT || HB)
		return LED2_;
	return NO_LED_;
}
uint8 LED3(void)
{
	if(HB || !NIGHT)
		return LED3_;
	return NO_LED_;
}
uint8 LED4(void)
{
	if(B)
		return LED4_;
	return NO_LED_;
}
uint8 LED5()
{
	static uint16 count_led5;
	uint8 led_conf=NO_LED_ ;
	if(TL)
	{
		if(count_led5<400)
			led_conf=LED5_;
		else
			led_conf=NO_LED_;
	}
	count_led5++;
	if(count_led5==1000)
		count_led5=0;
	return led_conf;
}
uint8 LED6()
{
	static uint16 count_led6;
	uint8 led_conf=NO_LED_ ;
	if(TR)
	{
		if(count_led6<400)
			led_conf=LED6_;
		else
			led_conf=NO_LED_;
	}
	count_led6++;
	if(count_led6==1000)
		count_led6=0;
	return led_conf;
}
uint8 LED7(void)
{
	if(FL)
		return LED7_;
	return NO_LED_;
}
uint8 LED8(void)
{
	if(HB)
		return LED8_;
	return NO_LED_;
}
uint8 LEDS()
{
	static uint16 sme_count=0;
	uint16 leds= NO_LED_;
	if(IGN)
	{
		if (SME)
		{
			if(sme_count<1000)
			{
				leds=LED4_+LED5_+LED6_;
				if(NIGHT)
					leds+=LED1()+LED2();
			}
			else 
			{	
				if(NIGHT)
					leds=LED1()+LED2();
				else
					leds=NO_LED_;
			}
			//leds+=LED1();
		}
		else 
		{
			PORTD=0x00;
			DDRD=0xff;
			leds=LED1()+LED2()+LED3()+LED4()+LED5()+LED6()+LED7()+LED8();
		}
		
	}
	else 
	{
		PORTD=0xff;
		leds=NO_LED_;
	}
	//return/* LED1()LED2()+LED3()+LED4()+LED5()+LED6()+LED7()+LED8();
	if(sme_count==2000)
		sme_count=0;
	sme_count++;
	return ~leds;
}


typedef struct 
{
	uint8 state;
	uint8 period;
	uint16 dutycycle;
	uint8 *functions;
	uint16 curentime;
	
}leds_s; 

leds_s leds_array[8] = 
{
	{100,100,100,LED1,100},
	{100,100,100,LED2,100},
	{100,100,100,LED3,100},
	{100,100,100,LED4,100},
	{100,100,100,LED5,100},
	{100,100,100,LED6,100},
	{100,100,100,LED7,100},
	{100,100,100,LED8,100}
};