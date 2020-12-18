
/*
 * VERTICAL_FILE.h
 *
 *  Created on: Dec 13, 2020
 *      Author: Alaa Elnagar
 */

#ifndef VERTICAL_FILE_H_
#define VERTICAL_FILE_H_



#define ARM_CONTROLLER				1
#define AVR_CONTROLLER 				0

#define CONTROLLER_SELECT		AVR_CONTROLLER

#if  CONTROLLER_SELECT	==	AVR_CONTROLLER

/*defining the pins */
#define CHARGE_PIN					SEVEN
#define DISCHARGE_PIN				FIVE
#define CAPACITANCE_READ_PIN			SIX


/*the selected ports */

#define CHARGE_PORT						 PORTC_NUM
#define DISCHARGE_PORT					 PORTC_NUM
#define  CAPACITANCE_READ_PORT			 PORTA_NUM

#define DISCHARGE_RESISTOR_VALUE	     10000.0F



#elif CONTROLLER_SELECT	==	 ARM_CONTROLLER

#endif





#endif /* VERTICAL_FILE_H_ */
