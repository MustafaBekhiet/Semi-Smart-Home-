/*
 * Global_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: EL CONSUL
 */

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "Global_Interface.h"
void GLobalInterruptEnable()
{
	SET_BIT(SREG,GLOBAL_BIT);

}
void GLobalInterruptDisable()
{
	CLR_BIT(SREG,GLOBAL_BIT);
}
