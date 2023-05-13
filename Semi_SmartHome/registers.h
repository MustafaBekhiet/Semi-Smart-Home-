
#ifndef REGISTERS_H_
#define REGISTERS_H_


/* GPIO Registers */
 #define PORTA	*((volatile u8 *) 0x3B)
 #define DDRA 	*((volatile u8 *) 0x3A)
 #define PINA 	*((volatile u8 *) 0x39)
 #define PORTB 	*((volatile u8 *) 0x38)
 #define DDRB 	*((volatile u8 *) 0x37)
 #define PINB 	*((volatile u8 *) 0x36)
 #define PORTC 	*((volatile u8 *) 0x35)
 #define DDRC 	*((volatile u8 *) 0x34)
 #define PINC 	*((volatile u8 *) 0x33)
 #define PORTD 	*((volatile u8 *) 0x32)
 #define DDRD 	*((volatile u8 *) 0x31)
 #define PIND 	*((volatile u8 *) 0x30)
/* End of GPIO registers */


/* External Interrupt Registers */
#define GICR			*((volatile u8 *) 0x5B)			/*@brief General Interrupt control register*/
#define GICR_INT1		7									/*@brief INT0	control bit*/
#define GICR_INT0		6                                 /*@brief INT1	control bit*/
#define GICR_INT2		5                                  /*@brief INT2	control bit*/


#define MCUCR			*((volatile u8 *) 0x55)		  /*@brief MCU control Register*/
#define MCUCR_ISC00		0                                /*@brief Interrupt sense control 0 bit 0*/
#define MCUCR_ISC01		1                                /*@brief Interrupt sense control 0 bit 1*/
#define MCUCR_ISC10		2                                /*@brief Interrupt sense control 1 bit 0*/
#define MCUCR_ISC11		3                               /*@brief Interrupt sense control 1 bit 1*/


#define MCUCSR			*((volatile u8 *) 0x54)			/*@brief MCU control Status Register*/
#define MCUCSR_ISC2		6									/*@brief Interrupt sense control 2*/


/* End of External Interrupt Registers */

/* ADC Registers */

#define ACSR				*((volatile u8 *) 0x28)

#define ADMUX				*((volatile u8 *) 0x27)
#define ADMUX_MUX0			0			/*@brief from ADMUX_MUX0 to MUX4 are the channel selection bits */
#define ADMUX_MUX1			1
#define ADMUX_MUX2			2
#define ADMUX_MUX3			3
#define ADMUX_MUX4			4
#define ADMUX_ADLAR			5			/*Left/Right Adjustment bit*/
#define ADMUX_REFS0			6			/*@brief REFS0 is the bit0 of the reference voltage select*/
#define ADMUX_REFS1			7			/*@brief REFS1 is the bit1 of the reference voltage select*/


#define ADCSRA				*((volatile u8 *) 0x26)
#define ADCSRA_ADPS0		0			/*@brief ADPS0,1,2 are the prescaler bits*/
#define ADCSRA_ADPS1		1
#define ADCSRA_ADPS2		2
#define ADCSRA_ADIE			3			/*@brief is the ADC interrupt enable bit*/
#define ADCSRA_ADIF			4			/*@brief is the ADC interrupt flag bit*/
#define ADCSRA_ADATE		5			/*@brief is the Auto trigger enable bit*/
#define ADCSRA_ADSC			6			/*@brief is the ADC Start conversion bit*/
#define ADCSRA_ADEN			7			/*@brief is the ADC enable bit*/


#define ADCH			*((volatile u8 *) 0x25)
#define ADCL			*((volatile u8 *) 0x24)
#define ADC				*((volatile u16 *) 0x24)		/*ADC Data register*/


#define SFIOR			*((volatile u8 *) 0x50)
#define ADTS0			5			/*those three bits selects the mood of operation of the ADC*/
#define ADTS1			6
#define ADTS2			7

/* End of ADC registers*/

/* Timers register */

#define TCNT0  (*(volatile u8*)0x52)
#define OCR0   (*(volatile u8*)0x5C)
#define TCCR0  (*(volatile u8*)0x53)

#define TIMSK  (*(volatile u8*)0x59)

/* End of Timer registers*/

#endif
