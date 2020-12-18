/*
 * DIO_reference.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */
#ifndef DIO_REFERENCE_H_
#define DIO_REFERENCE_H_


#define OUTPUT 								1
#define INPUT 								0
#define HIGH								1
#define LOW									0

#define PIN0_NUM							0
#define PIN1_NUM							1
#define PIN2_NUM							2
#define PIN3_NUM							3
#define PIN4_NUM							4
#define PIN5_NUM							5
#define PIN6_NUM							6
#define PIN7_NUM							7

#define PORTA_NUM							0
#define PORTB_NUM							1
#define PORTC_NUM							2
#define PORTD_NUM							3


#define ZERO								0
#define ONE									1
#define TWO									2
#define THREE								3
#define FOUR								4
#define FIVE								5
#define SIX									6
#define SEVEN								7
#define EIGHT								8
#define NINE								9
#define Null								0





void DIO_VidSetPortDirection   (u8 Copy_U8Port, u8 Copy_U8Direction);
void DIO_VidSetPortValue       (u8 Copy_U8Port,u8 Copy_U8Value);
void DIO_VidSetPinDirection    (u8 Copy_U8Port,u8 Copy_U8PinNum,u8 Copy_U8Direction);
void DIO_VidSetPinValue        (u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8PinValue);
u8 DIO_VidGetPinValue          (u8 Copy_U8Port,u8 Copy_U8Pin);


void DIO_VidTogglePin(u8 Copy_U8Port,u8 Copy_U8Pin);

#endif /* DIO_REFERENCE_H_ */
