

#ifndef LCD_CFG_H_
#define LCD_CFG_H_


/*	Configure the operation mode,
 * 	options:	1- 	EIGHT_BIT_MODE
 * 				2-	FOUR_BIT_MODE
 **/

#define LCD_OP_MODE		FOUR_BIT_MODE

/*Configure if the RW pin is controlled or not, options: 1- ENABLED
 * 														 2- DISABLED*/
#define LCD_RW_CTRL_EN		DISABLED

#if LCD_RW_CTR_EN == ENABLED
#define LCD_RW_PIN			pin0
#endif

/* Please Choose which port to connect ctrl pins: RS, E
 * options:		1- portA
 * 				2- portB
 * 				3- portC
 * 				4- portD
 */

#define LCD_CTRL_PORT		portB
#define LCD_RS_PIN			pin5
#define LCD_E_PIN			pin6



/*Choosing Data pins*/
#define LCD_DATA_PORT		portD



#if LCD_OP_MODE == FOUR_BIT_MODE

#define LCD_D4_PIN			pin4
#define LCD_D5_PIN			pin5
#define LCD_D6_PIN			pin6
#define LCD_D7_PIN			pin7

#endif



#endif
