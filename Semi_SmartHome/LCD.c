/*
 * LCD.c
 *
 *  Created on: May 9, 2023
 *      Author: EL CONSUL
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "registers.h"
#include <util/delay.h>
#include "defines.h"
#include "GPIO.h"
#include "LCD.h"
#include "LCD_private.h"
#include "LCD_config.h"

static void voidSendEnablePulse(void)
{
	/*Send enable pulse*/
	DioSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, HIGH);
	_delay_ms(2);
	DioSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, LOW);
}


static void voidSetLCDHalfDataPort(u8 Copy_u8Nipple)
{
	DioSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_u8Nipple,0));
	DioSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_u8Nipple,1));
	DioSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_u8Nipple,2));
	DioSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_u8Nipple,3));
}

void LCD_voidInit(void)
{
	DioSetPinDirection(portD,pin4,OUTPUT);
	DioSetPinDirection(portD,pin5,OUTPUT);
	DioSetPinDirection(portD,pin6,OUTPUT);
	DioSetPinDirection(portD,pin7,OUTPUT);

	DioSetPinDirection(portB,pin5,OUTPUT);
	DioSetPinDirection(portB,pin6,OUTPUT);
	/*wait for more than 30ms after power is on*/
	_delay_ms(40);
	DioSetPinDirection(portD,pin4,OUTPUT);
	/*Function Set command: 2 lines, 5*7 font size*/
#if LCD_OP_MODE == EIGHT_BIT_MODE
	LCD_voidSendCmd(0b00111000);

#elif LCD_OP_MODE == FOUR_BIT_MODE
	voidSetLCDHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLCDHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLCDHalfDataPort(0b1000);
	voidSendEnablePulse();

#endif
	/*we don't need to make another delay, as LCD_voidSendCmd have 2ms delay*/

	/*Display ON/OFF control: Display enable, Cursor and blink disable*/
	LCD_voidSendCmd(0b00001100);

	/*Clearing The Display*/
	LCD_voidSendCmd(1);
}
void LCD_voidSendCmd(u8 Copy_u8Cmd){
	/*Set RS pin to low for command mode*/
	DioSetPinValue(portB, LCD_RS_PIN, LOW);

#if LCD_RW_CTRL_EN == ENABLED
	/*Set RW pin to LOW for write mode*/
	DioSetPinValue(portB, LCD_RW_PIN, LOW);
#endif

#if LCD_OP_MODE == EIGHT_BIT_MODE
	/*Send The command on data pins*/
	DioSetPortValue(LCD_DATA_PORT, Copy_u8Cmd);
	LCD_voidSendEnablePulse();

#elif LCD_OP_MODE == FOUR_BIT_MODE
	voidSetLCDHalfDataPort(Copy_u8Cmd >> 4); /*Send the 4 most bits to the LCD*/
	voidSendEnablePulse();

	voidSetLCDHalfDataPort(Copy_u8Cmd);		/*Send the 4 least bits to the LCD*/
	voidSendEnablePulse();

#endif
}

void LCD_voidSendData(u8 Copy_u8Data){
	/*Set RS pin to HIGH for data mode*/
	DioSetPinValue(portB, LCD_RS_PIN,HIGH);

	#if LCD_RW_CTRL_EN == ENABLED
	/*Set RW pin to LOW for write mode*/
	DioSetPinValue(portB, LCD_RW_PIN,  LOW);
	#endif

#if LCD_OP_MODE == EIGHT_BIT_MODE
	/*Send The Data on data pins*/
	DioSetPortValue(LCD_DATA_PORT, Copy_u8Data);
	LCD_voidSendEnablePulse();

#elif LCD_OP_MODE == FOUR_BIT_MODE
	voidSetLCDHalfDataPort(Copy_u8Data >> 4);
	voidSendEnablePulse();

	voidSetLCDHalfDataPort(Copy_u8Data);
	voidSendEnablePulse();

#endif
}

void LCD_SendString(const char* Copy_chString){

	if (Copy_chString != NULL)
	{
		u8 Local_u8Itterator = 0u;
		while (Copy_chString[Local_u8Itterator] != '\0')
		{
			LCD_voidSendData(Copy_chString[Local_u8Itterator]);
			Local_u8Itterator++;
		}
	}

	else
	{

	}


}

void LCD_voidSendNumber(s32 Copy_s32Number){
	 char Local_chNumberArr[10];
		    u8 Local_u8RightDigit;
		    u8 Local_u8Counter1 = 0;
		    s8 Local_s8Counter2;

		    if (Copy_s32Number == 0)
		    {
		    	LCD_voidSendData('0');
		    	return;
		    }

		    else if (Copy_s32Number < 0)
		    {
		    	LCD_voidSendData('-');
		    	Copy_s32Number *= -1;
		    }

		    while (Copy_s32Number != 0)
		    {
		    	Local_u8RightDigit = Copy_s32Number % 10;		//Extracts the right most digit
		    	Copy_s32Number /= 10;
		    	Local_chNumberArr[Local_u8Counter1] = Local_u8RightDigit + '0';		//Store that dig in array
		    	Local_u8Counter1++;
		    }

		    for (Local_s8Counter2 = Local_u8Counter1 - 1; Local_s8Counter2 >= 0; Local_s8Counter2--)
		    {
		    	LCD_voidSendData(Local_chNumberArr[Local_s8Counter2]);
		    }
}

void LCD_voidSendBinary(s32 Copy_s32DecimalNumber){
	u8 Local_u8DigitsArr[14];
	s8 Local_s8DigitIndex;

	for (Local_s8DigitIndex = 0; Local_s8DigitIndex < 14; Local_s8DigitIndex++)
	{
		Local_u8DigitsArr[Local_s8DigitIndex] = GET_BIT(Copy_s32DecimalNumber, Local_s8DigitIndex);
	}

	LCD_voidSendNumber(Copy_s32DecimalNumber);
	LCD_SendString(" to Binary:");
	LCD_voidGoToXY(0,1);
	LCD_SendString("0b");

	for (Local_s8DigitIndex = 13; Local_s8DigitIndex >= 0; Local_s8DigitIndex--)
	{
		LCD_voidSendNumber(Local_u8DigitsArr[Local_s8DigitIndex]);
	}

}

void LCD_voidSendHex(s32 Copy_s32DecimalNumber){
	u8 Local_u8DigitsArr[14];
	s8 Local_s8DigitIndex;
	s32 Local_s8Holder = Copy_s32DecimalNumber;

	for (Local_s8DigitIndex = 13; Local_s8DigitIndex >= 0;)
	{





		if (Copy_s32DecimalNumber % 16 == Copy_s32DecimalNumber)
		{
			Local_u8DigitsArr[Local_s8DigitIndex] = 0;
			Local_s8DigitIndex--;
			Copy_s32DecimalNumber /= 16;
		}

		if ((Copy_s32DecimalNumber / 16) < 16)
		{
			Local_u8DigitsArr[Local_s8DigitIndex] = Copy_s32DecimalNumber % 16;
			Local_u8DigitsArr[Local_s8DigitIndex - 1] = Copy_s32DecimalNumber / 16;
			Local_s8DigitIndex-= 2;
			Copy_s32DecimalNumber /= 16;
		}

		else if ((Copy_s32DecimalNumber / 16) > 16)
		{
			Local_u8DigitsArr[Local_s8DigitIndex] = Copy_s32DecimalNumber % 16;
			Copy_s32DecimalNumber /= 16;
			Local_s8DigitIndex--;
		}
	}

	LCD_voidSendNumber(Local_s8Holder);
	LCD_SendString(" to Hex:");
	LCD_voidGoToXY(0,1);
	LCD_SendString("0x");

	for (Local_s8DigitIndex = 0; Local_s8DigitIndex < 14; Local_s8DigitIndex++)
	{
		if (Local_u8DigitsArr[Local_s8DigitIndex] < 10)
		{
			LCD_voidSendNumber(Local_u8DigitsArr[Local_s8DigitIndex]);
		}

		else
		{
			switch (Local_u8DigitsArr[Local_s8DigitIndex])
			{
				case 10: LCD_voidSendData('A');	break;
				case 11: LCD_voidSendData('B');	break;
				case 12: LCD_voidSendData('C');	break;
				case 13: LCD_voidSendData('D');	break;
				case 14: LCD_voidSendData('E');	break;
				case 15: LCD_voidSendData('F');	break;
			}
		}
	}


}

void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8yPos){
	u8 Local_u8DDRamAdd;

		if (Copy_u8yPos == 0)
		{
			Local_u8DDRamAdd = Copy_u8XPos;
		}

		else if (Copy_u8yPos == 1)
		{
			Local_u8DDRamAdd = 0x40 + Copy_u8XPos;
		}

		/*Set bit 7, for setting DDRAM address command*/
		SET_BIT(Local_u8DDRamAdd, 7);

		LCD_voidSendCmd(Local_u8DDRamAdd);
}

void LCD_voidSendSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos){
	u8 Local_u8CGRAMAdrs = Copy_u8PatternNumber * 8u;
		u8 Local_u8LoopCounter;

		/*Set bit number6, for Set_Address of CG command from datasheet*/
		SET_BIT(Local_u8CGRAMAdrs, 6);

		/*select the address in CGRAM*/
		LCD_voidSendCmd(Local_u8CGRAMAdrs);

		/*Write the patter into CGRAM*/
		for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8u; Local_u8LoopCounter++)
		{
			LCD_voidSendData(Copy_u8Pattern[Local_u8LoopCounter]);
		}

		/*back to DDRAM, to display the patterns*/
		LCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);

		/*Display the pattern written inside the CGRAM*/
		LCD_voidSendData(Copy_u8PatternNumber);
}


