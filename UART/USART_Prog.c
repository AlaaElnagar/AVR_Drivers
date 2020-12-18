/*
 * USART_Prog.h
 *
 *  Created on: 12/11/2020
 *      Author: ALAA ELNAGAR
 *      PHONE :+201019793647
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Configure.h"
#include "DIO_reference.h"
#include "USART_Private.h"
#include "USART_Config.h"

 u8 static UCSRB_Help;
 u8 static UCSRc_Help;

/************************************************************************************************
 [Function Name]     USART_VidInit()

 [Description]		Function used to Enable USART internal circuit to
 	 	 	 	 	 -setting RX and TX pins of atmega
 	 	 	 	 	 -receive  send
 	 	 	 	 	 -setting boad rate
 	 	 	 	 	 -setting charater or data size from five to nine bit
 	 	 	 	 	 -setting working operation synchronous or asynchronous
 	 	 	 	 	 -setting transmitting and recieving edge incase of synchronous
 	 	 	 	 	 -incase of Asynchronous setting transmition speed single or dubled
 	 	 	 	 	 -setting stop bit one or two
 	 	 	 	 	 -setting parity CHECKER mode DISABLED,ENABLED_EVEN,ENABLED_ODD
					 -

 [Args]				void

 [in]				void

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/

void USART_VidInit(){
	/*setting rx and tx pins */
	DIO_VidSetPinDirection(PORTD_NUM,0,0);
	DIO_VidSetPinDirection(PORTD_NUM,1,1);
	/*setting boad rate*/
	/*This bit selects between accessing the UBRRH or the UCSRC Register. It is read as zero when
	reading UBRRH. The URSEL must be zero when writing the UBRRH.*/
	UBRRL=(0<<URSEL_BIT);
	UBRRL = BOADRATE_L_REG;

	/*SETTING A*/
	UBRRH = BOADRATE_M_REG;
/*It's very important to write the word on one shot */

/*character size selection  size */
#if CHARACTER_SIZE == FIVE_BIT
	UCSRB_Help |=  (0<<UCSZ2_BIT);       UCSRc_Help |=  (0<<UCSZ1_BIT) |  (0<<UCSZ0_BIT)   ;
#elif CHARACTER_SIZE == SIX_BIT
	UCSRB_Help |=  (0<<UCSZ2_BIT);       UCSRc_Help |=  (0<<UCSZ1_BIT) |  (1<<UCSZ0_BIT)   ;
#elif CHARACTER_SIZE == SEVEN_BIT
	UCSRB_Help |=  (0<<UCSZ2_BIT);       UCSRc_Help |=  (1<<UCSZ1_BIT) |  (0<<UCSZ0_BIT)   ;
#elif CHARACTER_SIZE == EIGHT_BIT
	UCSRB_Help |=  (0<<UCSZ2_BIT);       UCSRc_Help |=  (1<<UCSZ1_BIT) |  (1<<UCSZ0_BIT)   ;
#elif CHARACTER_SIZE == NINE_BIT
	UCSRB_Help |=  (1<<UCSZ2_BIT);       UCSRc_Help |=  (1<<UCSZ1_BIT) |  (0<<UCSZ0_BIT)   ;
	/*OPEN THE NINES BIT IN */
	#define    NINE_BIT_FLAG      5


#endif

#if  (OPERATION ==SYNCHRONOUS) &&(CLOCK_POLARITY == RISING_TRANSMITTED_EDGE)

    					UCSRc_Help |= (1<<UMSEL_BIT);		UCSRc_Help |= (0<<UPOL_BIT);   UCSRc_Help |= (0<<U2X_BIT);

#elif  (OPERATION ==SYNCHRONOUS) &&(CLOCK_POLARITY == FALLINGG_TRANSMITTED_EDGE)

    					UCSRc_Help |= (1<<UMSEL_BIT);		UCSRc_Help |= (1<<UPOL_BIT);    UCSRc_Help |= (0<<U2X_BIT);



#elif  (OPERATION ==ASYNCHRONOUS) &&(TRANSMISSION_SPEED==SINGLE)

 						UCSRc_Help |= (0<<UMSEL_BIT) ;							UCSRc_Help |= (0<<U2X_BIT);
#elif  (OPERATION ==ASYNCHRONOUS) &&(TRANSMISSION_SPEED==DOUBLE)

 						UCSRc_Help |= (0<<UMSEL_BIT) ;							UCSRc_Help |= (1<<U2X_BIT);

#endif

#if PARIT_MODE == DISABLED
 						UCSRB_Help |= (0<<UPM1_BIT) | (0<<UPM0_BIT) ;
#elif PARIT_MODE == ENABLE_EVEN
 						UCSRB_Help |= (1<<UPM1_BIT) | (0<<UPM0_BIT) ;
#elif PARIT_MODE == ENABLE_ODD
 						UCSRB_Help |= (1<<UPM1_BIT) | (1<<UPM0_BIT) ;

#endif


#if STOP_BIT_SELECT == ONE_BIT_STOP

 						UCSRB_Help |= (0<<USBS_BIT)  ;
#elif STOP_BIT_SELECT == TWO_BIT_STOP

 						UCSRB_Help |= (1<<USBS_BIT)  ;
#endif

 					/*MANUFACTURURE INSTRUCTION DONT WITE IN UCSRB OR UCSRC BIT BY BIT */

/*ENABLE RECIEV AND TRANSMITTER 4,3*/
UCSRB_Help |= (1<<RXEN_BIT) | (1<<TXEN_BIT) ;

UCSRB=UCSRB_Help;
/*The URSEL must be one  when writing the UCSRC.*/
UCSRc_Help |= (1<<URSEL_BIT);
UCSRC =  UCSRc_Help ;
//UCSRB = 0b00011000;

//UCSRC = 0b10000110;


}


/************************************************************************************************
 [Function Name]    USART_VidTransmit

 [Description]		Function used to Transmitting data
 	 	 	 	 	 -checking the if UDRE register which contains recived value  FLAG is empty and start transmition



 [Args]				u8 Copy_U8Data

 [in]				Copy_U8Data

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/



void USART_VidTransmit(u16 Copy_U16Data){

#ifdef NINE_BIT_FLAG
	while (!GET_BIT(UCSRA,UDRE_BIT) );
/*The nine's bit must be encodded first */
	UCSRB |=  (	GET_BIT	(Copy_U16Data,8)<<0		);
	UDR =  (u8)Copy_U16Data;


#else
	while (!GET_BIT(UCSRA,UDRE_BIT) );

	u8 Copy_U8Data = (u8)Copy_U16Data   ;

	UDR = Copy_U8Data;
#endif

}


/************************************************************************************************
 [Function Name]    USART_VidRecive()

 [Description]		Function used to reciving data
 	 	 	 	 	 -checking the if recive complete  FLAG is empty and start transmition
					 -supporting 9 bit mode


 [Args]				void

 [in]				void

 [out]				None

 [in/out]			None


 [Returns]			UDR

 * ********************************************************************************************/

u16 USART_U16Recive(){

#ifdef  NINE_BIT_FLAG
	while (!GET_BIT(UCSRA,RXCIE_BIT) );

u16 UDR_U16Copy =0;
UDR_U16Copy |= ( GET_BIT(UCSRB,RXB8_BIT)<< 8) |(UDR)  ;

return (UDR_U16Copy);

#else
	while (!GET_BIT(UCSRA,RXCIE_BIT) );

return(	UDR ) ;

#endif

}





/*Sending address incase of MPCM INCASE OF 9 BIT MODE MASTER MODE  */
void USART_VidSendAdressMPCM(u16 Copy_U16Adress){
#if 	CHARACTER_SIZE 	==  NINE_BIT
	SET_BIT(UCSRB,TXB8_BIT);
#endif
	/*traying to use 5:8 bit but ask in this point?????????????*/

	USART_VidTransmit(Copy_U16Adress);

}
/*sending data to another MCUS*/





void USART_VidSendDataMPCM(u16 Copy_U16Data){
#if 	CHARACTER_SIZE 	==  NINE_BIT
	CLEAR_BIT(UCSRB,TXB8_BIT);
/*#ELIF 	/*traying to use 5:8 bit but ask in this point?????????????*/
#endif
	USART_VidTransmit(Copy_U16Data);
}

/*ReCIVING DATA From other MCUS */
u8 Global_U8SwitchingFlag=0;







u16 USART_VidReciveMPCM(){
	/**BACK IN  multi processor reciving mode If the stop address recived*/
	if (USART_U16Recive() == MCU1STOPADDRESS){ Global_U8SwitchingFlag = 0;SET_BIT(UCSRA,MPCM_BIT);return (0); }

	/**enable multi processor reciving mode if the start address recived */
	else if (	(USART_U16Recive()==MCU1STARTADDRESS) | (Global_U8SwitchingFlag ==1 )){
	/*start recive all the time */
		CLEAR_BIT(UCSRA,MPCM_BIT);
		Global_U8SwitchingFlag =1;
		/*excute specific task based on USART_VidRecive()*/
		return (USART_U16Recive());

	}
	/*wait as slave until your address come */
	else{
		SET_BIT(UCSRA,MPCM_BIT);
		return (0);
	}

}



