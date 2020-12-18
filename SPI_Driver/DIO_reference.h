/*
 * DIO_reference.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: alaqsa
 */
#ifndef DIO_REFERENCE_H_
#define DIO_REFERENCE_H_







void DIO_VidSetPortDirection   (u8 Copy_U8Port, u8 Copy_U8Direction);
void DIO_VidSetPortValue       (u8 Copy_U8Port,u8 Copy_U8Value);
void DIO_VidSetPinDirection    (u8 Copy_U8Port,u8 Copy_U8PinNum,u8 Copy_U8Direction);
void DIO_VidSetPinValue        (u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8PinValue);
u8 DIO_VidGetPinValue          (u8 Copy_U8Port,u8 Copy_U8Pin);


void DIO_VidTogglePin(u8 Copy_U8Port,u8 Copy_U8Pin);

#endif /* DIO_REFERENCE_H_ */
