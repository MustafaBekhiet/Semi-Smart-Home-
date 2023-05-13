
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_voidSendCmd(u8 Copy_u8Cmd);

void LCD_voidSendData(u8 Copy_u8Data);

void LCD_voidInit(void);

void LCD_SendString(const char* Copy_chString);

void LCD_voidSendNumber(s32 Copy_s32Number);

void LCD_voidSendBinary(s32 Copy_s32DecimalNumber);

void LCD_voidSendHex(s32 Copy_s32DecimalNumber);

void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8yPos);

void LCD_voidSendSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);




#endif
