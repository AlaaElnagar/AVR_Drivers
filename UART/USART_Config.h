/*
 * USART_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


/*SELECT OPERATION  ASYNCHRONOUS OR SYNCHRONOUS */
#define OPERATION 				ASYNCHRONOUS
/*SELECT CLOCK POLARITY INCASE OF SYNCHRONOUS MODE  FALLINGG_TRANSMITTED_EDGE OR RISSING_TRANSMITTED_EDGE*/
#define CLOCK_POLARITY        FALLING_TRANSMITTED_EDGE

/*SELECT SPEED DUOBLE OR SINGLE  NOTE: DOUBLE TRANSMISSION_SPEED WORKS ONLY WITH SYNCHRONOUS MODE  */
#define TRANSMISSION_SPEED     SINGLE


/*9600 boad rate at 8mhz */
#define BOADRATE_L_REG    51 //103  //
#define BOADRATE_M_REG    0

/*CHARACTER_SIZE :EIGHT_BIT OR NINE ,SEVEN,SIX,FIVE*/

#define CHARACTER_SIZE 							   NINE_BIT
/*DISABLED OR ENABLE_EVEN OR ENABLE_ODD*/
#define PARIT_MODE   								DISABLED
/*ONE_BIT_STOP or Two_BIT_STOP  it must be Two incase of MPCM (multi processor comunication  mode because first stop bit will define the frame is  address or data)*/
#define STOP_BIT_SELECT 						 TWO_BIT_STOP






#endif /* USART_CONFIG_H_ */
