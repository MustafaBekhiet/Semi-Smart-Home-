/*
 * GPIO.c
 *
 *  Created on: May 9, 2023
 *      Author: EL CONSUL
 */


#include "STD_Types.h"
#include "BIT_MATH.h"
#include "defines.h"
#include "GPIO.h"
#include "registers.h"


 void DioSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
 {


	 if (Copy_u8Pin <= pin7)
	 {

		 if (Copy_u8Direction == INPUT)
		 {
			 switch (Copy_u8Port)
			 {
			 	 case portA: CLR_BIT(DDRA, Copy_u8Pin); break;
			 	 case portB: CLR_BIT(DDRB, Copy_u8Pin); break;
			 	 case portC: CLR_BIT(DDRC, Copy_u8Pin); break;
			 	 case portD: CLR_BIT(DDRD, Copy_u8Pin); break;
			 	 default:  break;

			 }
		 }

		 else if (Copy_u8Direction == OUTPUT)
		 {
			 switch(Copy_u8Port)
			 {
				 case portA: SET_BIT(DDRA, Copy_u8Pin); break;
			 	 case portB: SET_BIT(DDRB, Copy_u8Pin); break;
			 	 case portC: SET_BIT(DDRC, Copy_u8Pin); break;
			 	 case portD: SET_BIT(DDRD, Copy_u8Pin); break;
			 	 default: 	break;
			 }
		 }



		 else
		 {

		 }


	 }

	 else
	 {

	 }

 }

 void DioSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
 {


	 	 if (Copy_u8Pin <= pin7)
	 	 {

	 		 if (Copy_u8Value == HIGH)
	 		 {
	 			 switch (Copy_u8Port)
	 			 {
	 			 	 case portA: SET_BIT(PORTA, Copy_u8Pin); break;
	 			 	 case portB: SET_BIT(PORTB, Copy_u8Pin); break;
	 			 	 case portC: SET_BIT(PORTC, Copy_u8Pin); break;
	 			 	 case portD: SET_BIT(PORTD, Copy_u8Pin); break;
	 			 	 default:  break;

	 			 }
	 		 }

	 		 else if (Copy_u8Value == LOW)
	 		 {
	 			 switch(Copy_u8Port)
	 			 {
	 				 case portA: CLR_BIT(PORTA, Copy_u8Pin); break;
	 			 	 case portB: CLR_BIT(PORTB, Copy_u8Pin); break;
	 			 	 case portC: CLR_BIT(PORTC, Copy_u8Pin); break;
	 			 	 case portD: CLR_BIT(PORTD, Copy_u8Pin); break;
	 			 	 default: break;
	 			 }
	 		 }



	 		 else
	 		 {

	 		 }


	 	 }

	 	 else
	 	 {

	 	 }

 }

 void DioGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value)

 {


	 if (Copy_pu8Value != NULL)
	 {

		 if (Copy_u8Pin <= pin7)
		 {
			 switch (Copy_u8Port)
			 {
			 	 case portA:  *Copy_pu8Value = GET_BIT(PINA, Copy_u8Pin); break;
			 	 case portB:  *Copy_pu8Value = GET_BIT(PINB, Copy_u8Pin); break;
			 	 case portC:  *Copy_pu8Value = GET_BIT(PINC, Copy_u8Pin); break;
			 	 case portD:  *Copy_pu8Value = GET_BIT(PIND, Copy_u8Pin); break;
			 	 default:  break;
			 }
		 }


		 else
		 {

		 }
	 }

	 else
	 {

	 }

 }

 void DioSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
 {

	 switch (Copy_u8Port)
	 {
	 	 case portA: DDRA = Copy_u8Direction; break;
	 	 case portB: DDRB = Copy_u8Direction; break;
	 	 case portC: DDRC = Copy_u8Direction; break;
	 	 case portD: DDRD = Copy_u8Direction; break;
	 	 default:  break;

	 }

 }

void DioSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
 {


	 switch (Copy_u8Port)
	 {
	 	 case portA: PORTA = Copy_u8Value; break;
	 	 case portB: PORTB = Copy_u8Value; break;
	 	 case portC: PORTC = Copy_u8Value; break;
	  	 case portD: PORTD = Copy_u8Value; break;
	 	 default:  break;

	 }

 }

void DioTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{



	 	 if (Copy_u8Pin <= pin7)
	 	 {

	 		 switch (Copy_u8Port)
	 		 {
			 	 case portA: TOG_BIT(PORTA, Copy_u8Pin); break;
			 	 case portB: TOG_BIT(PORTB, Copy_u8Pin); break;
			 	 case portC: TOG_BIT(PORTC, Copy_u8Pin); break;
			 	 case portD: TOG_BIT(PORTD, Copy_u8Pin); break;
			 	 default:  break;

			 }

	 	 }

	 	 else
	 	 {

	 	 }
}
