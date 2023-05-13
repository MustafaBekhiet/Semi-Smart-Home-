
#ifndef GPIO_H_
#define GPIO_H_

#define  portA 		0
#define  portB 		1
#define  portC		2
#define  portD		3



#define  pin0 			0
#define  pin1 			1
#define  pin2			2
#define  pin3			3
#define  pin4 			4
#define  pin5 			5
#define  pin6			6
#define  pin7			7


#define  INPUT		0
#define  OUTPUT	    1


#define  HIGH		1
#define  LOW		0


void DioSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
void DioSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
void DioGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value);
void DioTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin);
void DioSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
void DioSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);


#endif
