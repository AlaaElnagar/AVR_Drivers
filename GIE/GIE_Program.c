/*
 *
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_reference.h"
#include "GIE_Private.h"
#include "GIE_Config.h"







/**********************************************************************************************
 * ****************************** SETTING SREG REGISTER ****************************************
 *
 *SREG:STATOUS REGISTER :This register contains information about the most excuited arithmatic instruction
 *The Status Register is not automatically stored when entering an interrupt routine and restored
 *when returning from an interrupt. This must be handled by software.
 * SENSE CONTROLL INT2
 *Bit 			7		 6		 5		 4		 3 		2		 1		 0
 *				I 		 T		 H		 S		 V	    N		 Z		 C
 *	Bit 7 – I: Global Interrupt Enable
 *
 * *********************************************************************************************/


void GIE_VidEnable(){

	SET_BIT(SREG, GIE_PIN);
}

void GIE_VidDisable(){

	CLEAR_BIT(SREG, GIE_PIN);

}


/*
 * in the main file
 *
 *
 *void main(void){
 *
 *EXIT_VidInit();
 *EXIT_VidEnable();
 *GIE_VidEnable();
 *
 *}
 *
 *
 *
 *
 */








