/*
 * main.c
 *
 *  Created on: Dec 17, 2020
 *      Author: Alaa Elnagar
 */


#include "STD_Types.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "util/delay.h"
#include "DIO_reference.h"

#define MASTER  1
#define SLAVE   0



/*Global recive data incase of sync or async*/
u8 Global = 0 ;

/*reciving function in case of asynch */
void MSPI_VidSendReciveData(u8 Data){
	Global = Data ;

}




/****************************CODE SWITCHING **********************************/
/*
		1 - MASTER
		2 - SLAVE
 */

//dont forget to stup the configration as master or slave

#define CODE_FLASH_MODE			SLAVE




/*****************************************************************************/


#if CODE_FLASH_MODE ==MASTER


int  main (void){


	SPI_voidMSInit(MASTER) ;



	while (1){
		//    MSPI1_voidSendReceiveAsynch ( 5 ,MSPI_VidSendReciveData(10));

		 MSPI1_voidSendReceiveSynch  (5, &Global ) ;
		 _delay_ms(1000);
		 MSPI1_voidSendReceiveSynch  (7, &Global ) ;
		 _delay_ms(1000);


	}

return 0;


}


#elif CODE_FLASH_MODE ==SLAVE


void main (void){

DIO_VidSetPinDirection(PORTA_NUM,PIN7_NUM,OUTPUT);

	SPI_voidMSInit(SLAVE) ;



	while (1){
		//    MSPI1_voidSendReceiveAsynch ( 5 ,MSPI_VidSendReciveData(10));

		 MSPI1_voidSendReceiveSynch  (20, &Global ) ;
if (Global == 12){

DIO_VidSetPinValue(PORTA_NUM,PIN7_NUM,HIGH);

	}

else if(Global == 17){

	DIO_VidSetPinValue(PORTA_NUM,PIN7_NUM,LOW);

}


}


}

#endif






