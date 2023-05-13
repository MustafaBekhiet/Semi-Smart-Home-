/*
 * KeyPad.c
 *
 *  Created on: May 9, 2023
 *      Author: EL CONSUL
 */




#include "STD_Types.h"

#include "GPIO.h"

#include "KeyPad.h"

void keyPad_Init(void)
{
	DioSetPortDirection(portC,0xF0);
	DioSetPortValue(portC,0b00001111);
}

/*required: All row pins are input pulled-up, and all columns pins are output high*/
u8 KeyPadGetPressedKey(void)
{
	u8 Local_u8PressedKey = KPD_u8NO_PRESSED_KEY_VAL;
	u8 Local_u8RowCounter;
	u8 Local_u8ColCounter;
	u8 Local_u8KeyState;
	static u8 Local_u8ColArr[KPD_u8COL_NUM] = {KPD_u8COL1_PIN, KPD_u8COL2_PIN, KPD_u8COL3_PIN, KPD_u8COL4_PIN};
	static u8 Local_u8RowArr[KPD_u8ROW_NUM] = {KPD_u8ROW1_PIN, KPD_u8ROW2_PIN, KPD_u8ROW3_PIN, KPD_u8ROW4_PIN};
	static u8 Local_uKPDArr[KPD_u8ROW_NUM][KPD_u8COL_NUM] = KPD_u8BUTTON_ARR; /*static is used here to save stack memory, as it will be saved one time in .bss memory not the stack*/

	/*Activate column pins, and read the rows*/
	for (Local_u8ColCounter = 0; Local_u8ColCounter < KPD_u8COL_NUM; Local_u8ColCounter++)
	{
		/*Activate the current column*/
		DioSetPinValue(KPD_u8COL_PORT, Local_u8ColArr[Local_u8ColCounter],  LOW);

		for (Local_u8RowCounter = 0; Local_u8RowCounter < KPD_u8ROW_NUM; Local_u8RowCounter++)
		{
			/*Read the current row*/

			DioGetPinValue(KPD_u8ROW_PORT, Local_u8RowArr[Local_u8RowCounter], &Local_u8KeyState);

			/*if current row is low, button is pressed*/
			if (Local_u8KeyState ==  LOW)
			{
				Local_u8PressedKey = Local_uKPDArr[Local_u8RowCounter][Local_u8ColCounter];

				/*wait until key, is released*/
				while(Local_u8KeyState ==  LOW)
				{
					DioGetPinValue(KPD_u8ROW_PORT, Local_u8RowArr[Local_u8RowCounter], &Local_u8KeyState);
				}

				return Local_u8PressedKey;
			}
		}

		/*Deactivating the current column before activating the next*/
		DioSetPinValue(KPD_u8COL_PORT, Local_u8ColArr[Local_u8ColCounter], HIGH);
	}



	return Local_u8PressedKey;
}





