/*
 * DC_Moto.c
 *
 *  Created on: May 10, 2023
 *      Author: EL CONSUL
 */

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "registers.h"
#include "GPIO.h"
#include "DC_Motor.h"

static void timer_Init(void){
	// Fast PWM
	//Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)
	// prescaler -> /8
	TCCR0 = (1<<6)| (1<<3) | (1<<5) | (1<<1);// | (1<<4);
	TCNT0 = 0;
	OCR0 = 255;

}

void DC_MotorInit(void){
	DioSetPinDirection(portB,pin1,OUTPUT);
	DioSetPinDirection(portB,pin2,OUTPUT);

	// OC0 pin
	DioSetPinDirection(portB,pin3,OUTPUT);
	timer_Init();
	DioSetPinValue(portB,pin1,LOW);
	DioSetPinValue(portB,pin2,LOW);
}

void DC_MotorRotate(u8 Copy_u8DutyCycle){
	OCR0= (u8)(((u16)(Copy_u8DutyCycle*255))/(100));
	//OCR0 = (Copy_u8DutyCycle/100) * 255 ;
	DioSetPinValue(portB,pin1,HIGH);
	DioSetPinValue(portB,pin2,LOW);
}
void DC_MotorOff(void){

	DioSetPinValue(portB,pin1,LOW);
	DioSetPinValue(portB,pin2,LOW);
}
