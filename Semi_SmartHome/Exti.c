

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "registers.h"
#include "defines.h"
#include "Exti.h"
#include "Exti_config.h"


static void (*EXTI_pfINTFunctionPtr[3])(void) = {NULL}; /*Array of ptrs to functions to hold ISR callbacks */



void EXTI_voidInitInt0(void)
{
	/*implement INT0 sense control configuration*/
#if INT0_SENSE_CTRL == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC01);

#elif INT0_SENSE_CTRL == EXTI_ON_CHANGE
	SET_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC01);

#elif INT0_SENSE_CTRL == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);


#elif INT0_SENSE_CTRL == EXTI_RISING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);


#else
#error Wrong INT0_SENSE_CTRL Configuration Option

#endif

	/*implement INT0 Initial state configuration*/
#if INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR, GICR_INT0);
#elif INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR, GICR_INT0);
#else
#error Wrong INT0 Initial State Configuration Option
#endif
}

void EXTI_voidInitInt1(void)
{
	/*implement INT1 sense control configuration*/
#if INT1_SENSE_CTRL == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR, MCUCR_ISC10);
	CLR_BIT(MCUCR, MCUCR_ISC11);

#elif INT1_SENSE_CTRL == EXTI_ON_CHANGE
	  SET_BIT(MCUCR, MCUCR_ISC10);
	  CLR_BIT(MCUCR, MCUCR_ISC11);

#elif INT1_SENSE_CTRL == EXTI_FALLING_EDGE
	  CLR_BIT(MCUCR, MCUCR_ISC10);
	  SET_BIT(MCUCR, MCUCR_ISC11);

#elif INT1_SENSE_CTRL == EXTI_RISING_EDGE
	  SET_BIT(MCUCR, MCUCR_ISC10);
	  SET_BIT(MCUCR, MCUCR_ISC11);

#else
#error Wrong INT1_SENSE_CTRL Configuration Option
#endif

	/*implement INT1 Initial state configuration*/
#if INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR, GICR_INT1);
#elif INT1_INITIAL_STATE == ENABLED
SET_BIT(GICR, GICR_INT1);
#else
#error Wrong INT1 Initial State Configuration Option
#endif

}


void EXTI_voidInitInt2(void)
{
	/*implement INT2 sense control configuration*/
#if INT2_SENSE_CTRL == EXTI_FALLING_EDGE
	  CLR_BIT(MCUCSR, MCUCSR_ISC2);

#elif INT2_SENSE_CTRL == EXTI_RISING_EDGE
	  SET_BIT(MCUCSR, MCUCSR_ISC2);

#else
#error Wrong INT2_SENSE_CTRL Configuration Option
#endif

	/*implement INT2 Initial state configuration*/
#if INT2_INITIAL_STATE == DISABLED
	CLR_BIT(GICR, GICR_INT2);
#elif INT2_INITIAL_STATE == ENABLED
SET_BIT(GICR, GICR_INT2);
#else
#error Wrong INT2 Initial State Configuration Option
#endif
}



u8 EXTI_SetSenseCtrl(u8 Copy_u8IntNum, u8 Copy_u8SenseType)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8IntNum)
	{
	case EXTI_INT0:
		switch(Copy_u8SenseType)
		{
		case EXTI_LOW_LEVEL: CLR_BIT(MCUCR, MCUCR_ISC00); CLR_BIT(MCUCR, MCUCR_ISC01); break;
		case EXTI_ON_CHANGE: SET_BIT(MCUCR, MCUCR_ISC00); CLR_BIT(MCUCR, MCUCR_ISC01); break;
		case EXTI_FALLING_EDGE: CLR_BIT(MCUCR, MCUCR_ISC00); SET_BIT(MCUCR, MCUCR_ISC01); break;
		case EXTI_RISING_EDGE: SET_BIT(MCUCR, MCUCR_ISC00); SET_BIT(MCUCR, MCUCR_ISC01); break;
		default: Local_u8ErrorState = NOK;
		} break;

	case EXTI_INT1:
		switch(Copy_u8SenseType)
		{
		case EXTI_LOW_LEVEL: CLR_BIT(MCUCR, MCUCR_ISC10); CLR_BIT(MCUCR, MCUCR_ISC11); break;
		case EXTI_ON_CHANGE: SET_BIT(MCUCR, MCUCR_ISC10); CLR_BIT(MCUCR, MCUCR_ISC11); break;
		case EXTI_FALLING_EDGE: CLR_BIT(MCUCR, MCUCR_ISC10); SET_BIT(MCUCR, MCUCR_ISC11); break;
		case EXTI_RISING_EDGE: SET_BIT(MCUCR, MCUCR_ISC10); SET_BIT(MCUCR, MCUCR_ISC11); break;
		default: Local_u8ErrorState = NOK;
		} break;

	case EXTI_INT2:
		switch(Copy_u8SenseType)
		{
		case EXTI_LOW_LEVEL: CLR_BIT(MCUCSR, MCUCSR_ISC2);break;
		case EXTI_ON_CHANGE: SET_BIT(MCUCSR, MCUCSR_ISC2);break;
		default: Local_u8ErrorState = NOK;
		} break;

	}


	return Local_u8ErrorState;
}

u8 EXTI_Enable(u8 Copy_u8IntNum)
{
	u8 Local_u8ErrorState = OK;

	switch (Copy_u8IntNum)
	{
	case EXTI_INT0: SET_BIT(GICR, GICR_INT0); break;
	case EXTI_INT1: SET_BIT(GICR, GICR_INT1); break;
	case EXTI_INT2: SET_BIT(GICR, GICR_INT2); break;
	default: Local_u8ErrorState = NOK;

	}

	return Local_u8ErrorState;
}

u8 EXTI_Disable(u8 Copy_u8IntNum)
{
	u8 Local_u8ErrorState = OK;

	switch (Copy_u8IntNum)
	{
	case EXTI_INT0: CLR_BIT(GICR, GICR_INT0); break;
	case EXTI_INT1: CLR_BIT(GICR, GICR_INT1); break;
	case EXTI_INT2: CLR_BIT(GICR, GICR_INT2); break;
	default: Local_u8ErrorState = NOK;

	}

	return Local_u8ErrorState;
}


u8 EXTI_SetCallBack(u8 Copy_u8IntNum, void (*Copy_pfFuncPtr)(void))
{

	u8 Local_u8ErrorState = OK;
	if (Copy_pfFuncPtr != NULL)
	{
		EXTI_pfINTFunctionPtr[Copy_u8IntNum] = Copy_pfFuncPtr;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}



/**
 * @brief INT0 ISR
 */
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (EXTI_pfINTFunctionPtr[EXTI_INT0] != NULL)
	{
		EXTI_pfINTFunctionPtr[EXTI_INT0]();
	}
}


/**
 * @brief INT1 ISR
 */
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if (EXTI_pfINTFunctionPtr[EXTI_INT1] != NULL)
	{
		EXTI_pfINTFunctionPtr[EXTI_INT1]();
	}
}



/**
 * @brief INT2 ISR
 */
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (EXTI_pfINTFunctionPtr[EXTI_INT2] != NULL)
	{
		EXTI_pfINTFunctionPtr[EXTI_INT2]();
	}
}

