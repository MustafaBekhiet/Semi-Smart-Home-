/*
 * Buzzer.c
 *
 *  Created on: May 9, 2023
 *      Author: EL CONSUL
 */
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "Buzzer.h"
#include "GPIO.h"
#include "registers.h"


void Buzzer_Init(){
	DioSetPinDirection(portB,pin7,OUTPUT);
}
void Buzzer_ON(){
	DioSetPinValue(portB,pin7,HIGH);
}
void Buzzer_OFF(){
	DioSetPinValue(portB,pin7,LOW);
}

