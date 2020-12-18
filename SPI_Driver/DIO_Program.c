/*
 * DIO_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: alaqsa
 */

#include  "STD_TYPES.h"
#include "DIO_Private.h"
#include  "DIO_Configure.h"
#include  "BIT_MATH.h"





void DIO_VidSetPortDirection( u8 Copy_U8Port, u8 Copy_U8Direction){

	if (Copy_U8Direction==OUTPUT){

		switch(Copy_U8Port){

		case PORTA_NUM :		DDRA=0xff;	break;
		case PORTB_NUM :		DDRB=0xff;  break;
		case PORTC_NUM :		DDRC=0xff;; break;
		case PORTD_NUM :		DDRD=0xff;  break;

		}


	}


	else if  (Copy_U8Direction==INPUT){


		switch(Copy_U8Port){
		case PORTA_NUM :		DDRA=0x00; break;
		case PORTB_NUM :		DDRB=0x00; break;
		case PORTC_NUM :		DDRC=0x00; break;
		case PORTD_NUM :		DDRD=0x00; break;
	}

	}



}


void DIO_VidSetPortValue(u8 Copy_U8Port,u8 Copy_U8Value){

	switch(Copy_U8Port){

		case PORTA_NUM :		PORTA=Copy_U8Value;				break;
		case PORTB_NUM :		PORTB=Copy_U8Value; 		    break;
		case PORTC_NUM :		PORTC=Copy_U8Value;			    break;
		case PORTD_NUM :		PORTD=Copy_U8Value;			    break;

		}



}


void DIO_VidSetPinDirection(u8 Copy_U8Port,u8 Copy_U8PinNum,u8 Copy_U8Direction){

	if (Copy_U8Direction==OUTPUT){

		switch(Copy_U8Port){

		case PORTA_NUM :		SET_BIT(DDRA,Copy_U8PinNum);	break;
		case PORTB_NUM :		SET_BIT(DDRB,Copy_U8PinNum);	break;
		case PORTC_NUM :		SET_BIT(DDRC,Copy_U8PinNum);	break;
		case PORTD_NUM :		SET_BIT(DDRD,Copy_U8PinNum);	break;

		}


	}


	else if  (Copy_U8Direction==INPUT){


		switch(Copy_U8Port){
		case PORTA_NUM :		CLEAR_BIT(DDRA,Copy_U8PinNum);	break;
		case PORTB_NUM :		CLEAR_BIT(DDRB,Copy_U8PinNum);	break;
		case PORTC_NUM :		CLEAR_BIT(DDRC,Copy_U8PinNum);	break;
		case PORTD_NUM :		CLEAR_BIT(DDRD,Copy_U8PinNum);	break;
		}

	}

}



void DIO_VidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8PinValue){
if (Copy_U8PinValue == HIGH){
	switch(Copy_U8Port){

		case PORTA_NUM :		SET_BIT(PORTA,Copy_U8Pin);	        	break;
		case PORTB_NUM :		SET_BIT(PORTB,Copy_U8Pin); 		        break;
		case PORTC_NUM :		SET_BIT(PORTC,Copy_U8Pin);			    break;
		case PORTD_NUM :		SET_BIT(PORTD,Copy_U8Pin);			    break;

		}
}

else if  (Copy_U8PinValue == LOW){
	switch(Copy_U8Port){

		case PORTA_NUM :		CLEAR_BIT(PORTA,Copy_U8Pin);	        break;
		case PORTB_NUM :		CLEAR_BIT(PORTB,Copy_U8Pin); 		    break;
		case PORTC_NUM :		CLEAR_BIT(PORTC,Copy_U8Pin);			break;
		case PORTD_NUM :		CLEAR_BIT(PORTD,Copy_U8Pin);			break;

		}
}
}







u8 DIO_VidGetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin){
u8 Lcal_U8PinResult=0;
	switch(Copy_U8Port){

			case PORTA_NUM :		Lcal_U8PinResult=GET_BIT(PINA,Copy_U8Pin);	        break;
			case PORTB_NUM :		Lcal_U8PinResult=GET_BIT(PINB,Copy_U8Pin); 		    break;
			case PORTC_NUM :		Lcal_U8PinResult=GET_BIT(PINC,Copy_U8Pin);			break;
			case PORTD_NUM :		Lcal_U8PinResult=GET_BIT(PIND,Copy_U8Pin);			break;

			}


return(Lcal_U8PinResult);


}


void DIO_VidTogglePin(u8 Copy_U8Port,u8 Copy_U8Pin){

	switch(Copy_U8Port){

		case PORTA_NUM :		TOGGLE_BIT(PORTA,Copy_U8Pin)	;			break;
		case PORTB_NUM :		TOGGLE_BIT(PORTA,Copy_U8Pin) 	;	    break;
		case PORTC_NUM :		TOGGLE_BIT(PORTA,Copy_U8Pin)	;	    break;
		case PORTD_NUM :		TOGGLE_BIT(PORTA,Copy_U8Pin)	;	    break;

		}



}


