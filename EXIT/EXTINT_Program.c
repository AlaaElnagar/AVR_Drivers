/*
 * EXTINT_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_reference.h"
#include "EXTINT_Private.h"




#define FALLING 0
#define RISING  1
#define OCH 	2
#define LOW_LEVEL  3

#define ISC FALLING



/**********************************************************************************************
 *  Set mcucr
 *
 *
 *
 *
 *
 *
 *
 * *********************************************************************************************/




void EXIT_SENSEcontroll(){
// chose interrupt firing mode
#if ISC==FALLING
SET_BIT(MCUCR,1);
SET_BIT(MCUCR,0);
#elif ISC==RISING
SET_BIT(MCUCR,1);
SET_BIT(MCUCR,0);

#endif


}

void EXIT_Enable(){

	SET_BIT(GICR,6);   //because we are in interrupt zerro

}


void EXIT_Disable(){

	CLEAR_BIT(GICR,6);   //because we are in interrupt zerro

}



//__vector_id(void)SPACE__attribute__()
//please take care with id=id-1 in data sheet

/*USING ISR FUNCTION
 * THIS FUNCTION IS CALLED BY THE INTURREPT
 * USE ATTRIBUTE to inform the intrrupt not to delete un called function
 * use signal to infrom the compiler that this is an interrupt
 *
 */

/*
void __vector_1(void) __attribute__((signal)); // this prototype is constant to all of the vectors

void __vector_1(void) __attribute__((signal))
{

DIO_TOGGLEEPIN(0,0);

}

*/






