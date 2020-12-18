/*
 * LCD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_VidLatch(void);
void LCD_VidSendCommand(u8 Copy_U8Command);
void LCD_VidRightScreenShifting();

void LCD_VidLeftScreenShifting();

void LCD_VidInit(void);
void LCD_VidSendData(s64 Copy_s64Data);
//void LCD_VidSendString(u16 *Copy_U8String[]);
void LCD_String (char *str);
//void LCD_VidSendInt(s64 Copy_U8Int);
void LCD_VidSendFloat(u16 Copy_U8Float);

void LCD_VidGoto(u8 Copy_U8Row,u8 Copy_U8Column);

void LCD_VidNewPattern();

void LCD_CLEAR();
void LCD_VidSendInt(s64 Copy_s64Integer);
u8  LCD_U8dReadBusyFlag();

u8 LCD_U8dReadDDRAM();

void LCD_VidVBackSpace(u16 Copy_U16KeyBoardPress);

void LCD_VidSendDataFromKeyboard(s64 Copy_s64Data);

void LCD_KeyBoradNewline(s64 Copy_s64Data);


u16 LCD_U16keyBoardPassword(u16 Copy_s16Data);







#endif /* LCD_INTERFACE_H_ */
