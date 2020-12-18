/*
 * SPI_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fly labs
 */


#define MASTER   1

#define SLAVE   0


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
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





void SPI_voidMSInit(u8 Copy_U8MS_Select)  ;



void SPI_voidSlaveSelect(void);



void SPI_voidSlaveRelease(void);


void MSPI_VidEnable ();

void MSPI_VidDisable ();

void MSPI_VidInterruptEnable ();

void MSPI_VidInterruptDisable ();

void MSPI1_voidSendReceiveSynch  ( u8 Copy_u8Data , u8 * Copy_ptrDataToReceive );

void MSPI1_voidSendReceiveAsynch ( u8 Copy_u8Data , void (*Copy_CallBack)(u8 Data) );



#endif /* SPI_INTERFACE_H_ */
