/*
 * USART_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_VidInit();

void USART_VidTransmit(u16 Copy_U8Data);

u16 USART_U16Recive();
/*Multiple MICRO PROCESSOR STUFF*/
void USART_VidSendDataMPCM(u16 Copy_U16Data);
u16 USART_VidReciveMPCM();
void USART_VidSendAdressMPCM(u16 Copy_U16Adress);





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



#endif /* USART_INTERFACE_H_ */
