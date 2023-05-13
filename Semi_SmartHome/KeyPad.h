#ifndef KEYPAD_H_
#define KEYPAD_H_


void keyPad_Init(void);
u8 KeyPadGetPressedKey(void);

/*This to determine how many switches in the keypad, in terms of rows & columns*/
#define KPD_u8COL_NUM			4
#define KPD_u8ROW_NUM			4


/*hardware connection on Kit of rows*/
#define KPD_u8ROW_PORT			portC
#define KPD_u8ROW1_PIN			pin0
#define KPD_u8ROW2_PIN			pin1
#define KPD_u8ROW3_PIN			pin2
#define KPD_u8ROW4_PIN			pin3



/*hardware connection on Kit of columns*/
#define KPD_u8COL_PORT			portC
#define KPD_u8COL1_PIN			pin4
#define KPD_u8COL2_PIN			pin5
#define KPD_u8COL3_PIN			pin6
#define KPD_u8COL4_PIN			pin7

/*The corresponding values of the keys*/
#define KPD_u8BUTTON_ARR		{{'7','8','9','-'}, {'4','5','6','*'}, {'1','2','3','/'}, {'R','0','=','+'}}



#define KPD_u8NO_PRESSED_KEY_VAL		0xff

#endif
