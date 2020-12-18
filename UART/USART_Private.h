/*
 * USART_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define UDR 	*((volatile  u8*)  0X2C  )
#define UCSRA   *((volatile  u8*)  0X2B  )
#define UCSRB   *((volatile  u8*)  0X2A  )
#define UCSRC   *((volatile  u8*)  0X40  )
#define UBRRL   *((volatile  u8*)  0X29  )   /*U16*/
#define UBRRH   *((volatile  u8*)  0X40  )


/*USART Control and status registerA>> UCSRA*/

/* RX_COMPLETE_BIT 		    */
#define 						 RXC_BIT						7
/*TX_COMPLETE_BIT */
#define						     TXC_BIT		  				6
/*DATA_REGISTER_EMPTY_BIT*/
#define						     UDRE_BIT                       5
/* FRAME_ERROR*/
#define  						 FE_BIT                         4
/* DATA_OVERRUN*/
#define						 	 DOR_BIT                        3
/*PARITY_ERROR*/
#define 						 PE_BIT                        2
/*DOUBLE_TRANSMISSION_SPEED*/
#define							 U2X_BIT                        1
/*MULTI_PROCESSOR_COMUNICATION_MODE */
#define						     MPCM_BIT	                    0




/*USART Control and status registerB>> UCSRB*/

/* RX Complete Interrupt Enable 		    */
#define 						 RXCIE_BIT						7
/*TX Complete Interrupt Enable */
#define						     TXCIE_BIT		  				6
/*UDRIE: USART Data Register Empty Interrupt Enable*/
#define						     UDRIE_BIT                      5
/* RXEN: Receiver Enable*/
#define  					   	 RXEN_BIT                       4
/* TXEN: Transmitter Enable*/
#define						     TXEN_BIT                       3
/*UCSZ2: Character Size*/
#define 						 UCSZ2_BIT                      2
/*RXB8: Receive Data Bit 8*/
#define							 RXB8_BIT                       1
/*TXB8: Transmit Data Bit 8 */
#define						     TXB8_BIT	                    0



/*USART Control and status registerC>> UCSRC*/

/* • Bit 7 – URSEL: Register Select		    */
#define 						 URSEL_BIT						7
/*• Bit 6 – UMSEL: USART Mode Select */
#define						     UMSEL_BIT		  				6
/*• Bit 5:4 – UPM1:0: Parity Mode*/
#define						     UPM1_BIT                       5
/*• Bit 5:4 – UPM1:0: Parity Mode*/
#define  					   	 UPM0_BIT                       4
/*• Bit 3 – USBS: Stop Bit Select*/
#define						     USBS_BIT                       3
/*• Bit 2:1 – UCSZ1:0: Character Size*/
#define 						 UCSZ1_BIT                      2
/*• Bit 2:1 – UCSZ1:0: Character Size*/
#define							 UCSZ0_BIT                      1
/*• Bit 0 – UCPOL: Clock Polarity */
#define						     UCPOL_BIT	                    0







#define DOUBLE  1
#define SINGLE  0

#define FIVE_BIT				5
#define SIX_BIT					6
#define SEVEN_BIT				7
#define EIGHT_BIT				8
#define NINE_BIT				9

#define ASYNCHRONOUS            0
#define SYNCHRONOUS				1

#define  DISABLED 				0
#define  ENABLE_EVEN			2
#define  ENABLE_ODD 			1

#define ONE_BIT_STOP			0
#define TWO_BIT_STOP			1

#define FALLING_TRANSMITTED_EDGE    0
#define RISING_TRANSMITTED_EDGE     1


#define MCU1STARTADDRESS						1
#define MCU2STARTADDRESS						2
#define MCU3STARTADDRESS						3
#define MCU4STARTADDRESS						4
#define MCU5STARTADDRESS						5
#define MCU6STARTADDRESS						6
#define MCU7STARTADDRESS						7
#define MCU8STARTADDRESS						8
#define MCU9STARTADDRESS					    9
#define MCU10STARTADDRESS					    10


#define MCU1STOPADDRESS						11
#define MCU2STOPADDRESS						12
#define MCU3STOPADDRESS						13
#define MCU4STOPADDRESS						14
#define MCU5STOPADDRESS						15
#define MCU6STOPADDRESS						16
#define MCU7STOPADDRESS						17
#define MCU8STOPADDRESS						18
#define MCU9STOPADDRESS					    19
#define MCU10STOPADDRESS					20








#endif /* USART_PRIVATE_H_ */
