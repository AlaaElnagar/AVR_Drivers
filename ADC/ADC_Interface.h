/*
 * ADC_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_VidSetCallBack(void (*Copy_PVidCallBack)(void));


void ADC_VidInit()                       ;


void ADC_VidEnable()                     ;
void ADC_VidSingleChannelSelect(u8 Copy_U8Channel);
void ADC_VidRefferenceVolt(u8 Copy_u8Refference);
void ADC_VidPrescaller(u8 Copy_u8Refference);
u8 ADC_VidStartConverssion()              ;

u8 ADC_U8PoolConverssion()				 ;

u16 ADC_U8GetData()                       ;

void ADC_VidDisable()					 ;

void ADC_VidFlagIntClr()						;

void ADC_VidConvIntEnable()					;

#endif /* ADC_INTERFACE_H_ */
