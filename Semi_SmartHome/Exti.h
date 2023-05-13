#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define EXTI_INT0			0
#define EXTI_INT1			1
#define EXTI_INT2			2


#define EXTI_LOW_LEVEL		1
#define EXTI_ON_CHANGE		2
#define EXTI_FALLING_EDGE		3
#define EXTI_RISING_EDGE		4


void EXTI_voidInitInt0(void);
void EXTI_voidInitInt1(void);
void EXTI_voidInitInt2(void);

u8 EXTI_SetSenseCtrl(u8 Copy_u8IntNum, u8 Copy_u8SenseType);

u8 EXTI_Enable(u8 Copy_u8IntNum);

u8 EXTI_Disable(u8 Copy_u8IntNum);

u8 EXTI_SetCallBack(u8 Copy_u8IntNum, void (*Copy_pfFuncPtr)(void));


#endif
