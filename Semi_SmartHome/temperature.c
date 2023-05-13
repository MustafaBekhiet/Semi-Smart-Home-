/*
 * temperature.c
 *
 *  Created on: May 10, 2023
 *      Author: EL CONSUL
 */

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "ADC.h"
#include "registers.h"


u8 Get_temperature(void){

	u8 temperature_;
	u16 digitalResult;
	ADC_u8StartConversionSynch(ADC_SINGLE_ENDED_CH0,(u16 *)&digitalResult);
	temperature_ = ((u8)(((u32)digitalResult * 500UL) / 256UL));
	return temperature_ ;
}
