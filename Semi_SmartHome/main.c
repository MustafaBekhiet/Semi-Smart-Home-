/*
 * main.c
 *
 *  Created on: May 9, 2023
 *      Author: EL CONSUL
 */
#include "STD_Types.h"
#include "LCD.h"
#include "KeyPad.h"
#include "LED.h"
#include "Buzzer.h"
#include "DC_Motor.h"
#include "temperature.h"
#include "ADC.h"
#include "Exti.h"

#include <util/delay.h>

#include "Global_Interface.h"


/******************************/

#define CLR_SCREEN   1

/*****************************/

const u8  g_ID[5] = "1234";
const u8 g_pass[5] = "4321";
/****************************/
#define ALL_LED   8
static u8 g_led =0;
u8 g_temperature ;
void welcome_ms(void);
void Fan(void);
void home_login(void);
void home_screen(void);
void LED(void);

int main()
{
	LCD_voidInit();
	keyPad_Init();
	ADC_voidInit();
	DC_MotorInit();
	Buzzer_Init();
	LED_Init();
	welcome_ms();

	home_login();
	while(1)
	{
		LED();
		Fan();
	}
	return 0;
}
void welcome_ms(void){
	LCD_voidGoToXY(0,2);
	LCD_SendString("Welcome Home");
	_delay_ms(1500);
	LCD_voidSendCmd(CLR_SCREEN);

}
void Fan(void){
	g_temperature = Get_temperature();
	LCD_voidGoToXY(6,0);
	LCD_voidSendNumber(g_temperature);
	if(g_temperature >= 45)
	{
		DC_MotorRotate(95);
		LCD_voidSendCmd(CLR_SCREEN);
		LCD_SendString("ALarm Fire");
		Buzzer_ON();
		_delay_ms(100);
		Buzzer_OFF();
		_delay_ms(100);

	}
	else if (g_temperature < 45  && g_temperature >= 35 ){
		DC_MotorRotate(80);

	}
	else if (g_temperature < 35 && g_temperature >= 25)
	{
		DC_MotorRotate(60);

	}
	else if (g_temperature < 25  && g_temperature >= 20){
		DC_MotorRotate(30);
	}
	else
	{
		DC_MotorOff();
	}
}
void home_login(void){
	u8 local_ID[5]; u8 i =0;
	u8 local_pass[5];
	u8 pressedKey = 0xff;

	LCD_SendString("Enter ID :  ");
	LCD_voidGoToXY(0,1);
	for(i=0;i<4;i++)
	{
		while(pressedKey == 0xff)
		{
			pressedKey = KeyPadGetPressedKey();
		}
		local_ID[i] = pressedKey;
		LCD_voidSendData(pressedKey);
		pressedKey = 0xff;
	}
	if(local_ID[0] == g_ID[0] && local_ID[1] == g_ID[1]
													 && local_ID[2] == g_ID[2] && local_ID[3] == g_ID[3])
	{
		LCD_voidSendCmd(CLR_SCREEN);
		LCD_SendString("Enter Password :  ");
		LCD_voidGoToXY(0,1);
		for(i=0;i<4;i++)
		{
			while(pressedKey == 0xff)
			{
				pressedKey = KeyPadGetPressedKey();
			}
			local_pass[i] = pressedKey;
			LCD_voidSendData(pressedKey);
			_delay_ms(100);
			LCD_voidGoToXY(i,1);
			LCD_voidSendData('*');
			pressedKey = 0xff;
		}
		LCD_voidSendCmd(CLR_SCREEN);
		if(local_pass[0] == g_pass[0] && local_pass[1] == g_pass[1]
																 && local_pass[2] == g_pass[2] && local_pass[3] == g_pass[3])
		{
			LCD_SendString("Welcome");
			home_screen();
		}
		else
		{
			LCD_SendString("Wrong pass/ID");
			_delay_ms(1000);
			LCD_voidSendCmd(CLR_SCREEN);
			home_login();
		}
	}
	else
	{
		LCD_voidSendCmd(CLR_SCREEN);
		LCD_SendString("Wrong pass/ID");
		_delay_ms(1000);
		LCD_voidSendCmd(CLR_SCREEN);
		home_login();
	}


}
void home_screen(void){
	LCD_voidSendCmd(CLR_SCREEN);
	LCD_SendString("Temp:  'C");

	LCD_voidGoToXY(0,1);

	LCD_SendString("LEDs: ");
}
void LED(void)
{
	u8 Digital;
	ADC_u8StartConversionSynch(ADC_SINGLE_ENDED_CH1,(u16*)&Digital);


	if (Digital <= 20)
		{

		g_led = 8;
		LED_OFF();

		}

		else if((Digital > 20) && (Digital <= 40))
		{

			g_led = 7;
			LED_OFF();

		}

		else if((Digital > 40) && (Digital <= 60))
		{

			g_led = 6;
			LED_OFF();

		}

		else if((Digital > 60) && (Digital <= 70))
		{

			g_led = 5;
			LED_OFF();

		}

		else if((Digital > 70) && (Digital <= 80))
		{

			g_led = 4;
			LED_OFF();
		}

		else if((Digital > 80) && (Digital <= 90))
		{

			g_led = 3;
			LED_OFF();
		}

		else if (Digital > 90)
		{

			g_led = 2;
			LED_OFF();

		}
	    LED_ON(g_led);
		LCD_voidGoToXY(6,1);
		LCD_voidSendNumber(g_led);
}

