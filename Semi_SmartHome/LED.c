/*
 * LED.c
 *
 *  Created on: May 9, 2023
 *      Author: EL CONSUL
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "GPIO.h"
#include "registers.h"
#include "defines.h"

#include "LED.h"

/* leds from A2 to A7 and PB4 PB0 */
void LED_Init(void){
	// 0xFC = 0b11111100
	DioSetPortDirection(portA,0xFC);
	DioSetPinDirection(portB,pin0,OUTPUT);
	DioSetPinDirection(portB,pin4,OUTPUT);
}
void LED_ON(u8 n_LEDs){
	switch(n_LEDs)
	{
	case 1: DioSetPortValue(portA,0x4); break;
	case 2: DioSetPortValue(portA,0x0C); break;
	case 3: DioSetPortValue(portA,0x1C); break;
	case 4: DioSetPortValue(portA,0x3C); break;
	case 5: DioSetPortValue(portA,0x7C); break;
	case 6:  DioSetPortValue(portA,0xFC); break;
	case 7: DioSetPortValue(portA,0xFC);
	DioSetPinValue(portB,pin0,HIGH);
	break;
	case 8: DioSetPortValue(portA,0xFC);
	DioSetPinValue(portB,pin0,HIGH);
	DioSetPinValue(portB,pin4,HIGH);
	break;
	default :  DioSetPortValue(portA,0);
	DioSetPinValue(portB,pin0,LOW);
	DioSetPinValue(portB,pin4,LOW);
	break;
	}
}
void LED_OFF(){
	DioSetPortValue(portA,0);
	DioSetPinValue(portB,pin0,LOW);
	DioSetPinValue(portB,pin4,LOW);
}
