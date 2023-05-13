
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*for channel selection*/
#define ADC_SINGLE_ENDED_CH0	   0
#define ADC_SINGLE_ENDED_CH1	   1
#define ADC_SINGLE_ENDED_CH2	   2
#define ADC_SINGLE_ENDED_CH3	   3
#define ADC_SINGLE_ENDED_CH4	   4
#define ADC_SINGLE_ENDED_CH5	   5
#define ADC_SINGLE_ENDED_CH6	   6
#define ADC_SINGLE_ENDED_CH7	   7


void ADC_voidInit(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u16* Copy_pu16Result);

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu16Result, void(*Copy_pvNotificationFunc)(void));




#endif
