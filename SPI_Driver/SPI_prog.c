/*
 * SPI_prog.c
 *
 *  Created on: 29/9/2018
 *      Author: Abdullah Abdelhakeem
 */


#include"STD_Types.h"
#include "BIT_MATH.h"
#include "SPI_Private.h"
#include "SPI_interface.h"
#include "SPI_Config.h"
#include "DIO_reference.h"

static void (*MSPI_CallBack)(u8 Data);

/*With master slave select*/
void SPI_voidMSInit(u8 Copy_U8MS_Select)
{
#if SPI_CASE == SPI_ENABLE


	/*Clear register*/
	SPCR = 0;
	/*****************************CLK Phase***********************************/

	SPCR |= (MSPI_CPHA_SELECT<<2) ;

	/*****************************CLK Polarity***********************************/

	SPCR |= (MSPI_CPOL_SELECT<<3) ;
	/****************************Data Order ************************************/

	SPCR |= (MSPI_FRAME_SELECT<<5) ;



/*****************************Master slave select ***********************************/

if  (Copy_U8MS_Select == MASTER ){

	/****************************MASTER SELECT ************************************/
	SPCR |= (MASTER<<4) ;



	/****************************MASTER PINS CONFIGARTION ************************************/


	/*SS  PIN  Config.*/
	DIO_VidSetPinDirection( PORTB_NUM,PIN4_NUM, OUTPUT) ;
	/*MOSI  PIN  Config.*/
	DIO_VidSetPinDirection( PORTB_NUM,PIN5_NUM, OUTPUT) ;
	/*MISO  PIN  Config.*/
	DIO_VidSetPinDirection( PORTB_NUM,PIN6_NUM, INPUT) ;
	/*SCK  PIN  Config.*/
	DIO_VidSetPinDirection( PORTB_NUM,PIN7_NUM, OUTPUT) ;


	/***************************** interrupt case ***********************************/
	SPCR |= (MSPI_INTERRUPT_CASE<<7)  ;
	/*****************************Enable SPI ***********************************/


	/*************************** CLK Rate Selection **********************/


	/*Set CLK bit0 and bit 1*/
	SPCR |= (0b011&MSPI_CLK_RATE_SELECT)  ;

	/*Clear bit 0 IN SPSR*/
	SPSR &= 0   ;

	/*Set CLK bit2 in bit 0 of SPSR*/
	SPSR |= (MSPI_CLK_RATE_SELECT>>2)  ;




	SET_BIT(SPCR,6) ;




}

else if (   Copy_U8MS_Select == SLAVE )
{
	/****************************SLAVE SELECT ************************************/

	SPCR |= (SLAVE<<4) ;
	/****************************SLAVE PINS CONFIGARTION ************************************/

	/*SS  PIN  Config.*/
	DIO_VidSetPinDirection( PORTB_NUM,PIN4_NUM, INPUT) ;
	/*MOSI  PIN  Config.*/
	DIO_VidSetPinDirection( PORTB_NUM,PIN5_NUM, INPUT) ;
	/*MISO  PIN  Config.*/
	DIO_VidSetPinDirection( PORTB_NUM,PIN6_NUM, OUTPUT) ;
	/*SCK  PIN  Config.*/
	DIO_VidSetPinDirection( PORTB_NUM,PIN7_NUM, INPUT) ;


	/***************************** interrupt case ***********************************/
	SPCR |= (MSPI_INTERRUPT_CASE<<7)  ;
	/*****************************Enable SPI ***********************************/
	SET_BIT(SPCR,6) ;

}




#elif  SPI_CASE == SPI_DISABLE
/*****************************Disable SPI ***********************************/
					CLEAR_BIT(SPCR,6)  ;

#else
#warning "SPI is undefined "


#endif



}



void SPI_voidSlaveSelect(void)
{

	DIO_VidSetPinValue(PORTB_NUM,PIN4_NUM,LOW);

}

void SPI_voidSlaveRelease(void)
{

	DIO_VidSetPinValue(PORTB_NUM,PIN4_NUM,HIGH);


}



void MSPI_VidEnable ()
{
	/*****************************Enable SPI ***********************************/
				SET_BIT(SPCR,6) ;


}


void MSPI_VidDisable ()
{

	/*****************************Disable SPI ***********************************/
									CLEAR_BIT(SPCR,6)  ;
}





void MSPI_VidInterruptEnable ()
{

	SET_BIT(SPCR,7) ;
}


void MSPI_VidInterruptDisable ()
{

	CLEAR_BIT(SPCR,7) ;
}




/*i have idea by sending struct with slave number in app where slave number is struct contains slave port and pin to be selected by master  */

void MSPI1_voidSendReceiveSynch  ( u8 Copy_u8Data , u8 * Copy_ptrDataToReceive )
{

	/* Disable All Interrupts */

	//MSPI_VidInterruptDisable();

	//SPI_voidSlaveSelect();
	SPDR = Copy_u8Data ;
/*SPIF looping */
   while(GET_BIT(SPSR,7)==0);

	*Copy_ptrDataToReceive= SPDR ;




	//MGPIO_voidSetPinValue(MSPI1_SLAVE_SELECT_PORT, MSPI1_SLAVE_SELECT_PIN , MGPIO_HIGH );

	//SPI_voidSlaveRelease();
}




void MSPI1_voidSendReceiveAsynch ( u8 Copy_u8Data , void (*Copy_CallBack)(u8 Data) )

{

	SPDR = Copy_u8Data ;

	MSPI_CallBack = Copy_CallBack ;


}


void __vector_12(void )

{

	if (MSPI_CallBack!=0){
		MSPI_CallBack(SPDR);
		}

}









