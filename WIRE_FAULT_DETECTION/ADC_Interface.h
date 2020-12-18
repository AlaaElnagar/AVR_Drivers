/*
 * ADC_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*CHANNEL SELECTION*/
#define CHANNEL_0_SELECT				0
#define CHANNEL_1_SELECT				1
#define CHANNEL_2_SELECT				2
#define CHANNEL_3_SELECT				3
#define CHANNEL_4_SELECT				4
#define CHANNEL_5_SELECT				5
#define CHANNEL_6_SELECT				6
#define CHANNEL_7_SELECT				7


/*REFFERNECE VOLTAGE */

#define VREF_2_5V_INTERNAL				0
#define VREF_AVCC_EXTERNAL			    1
#define vREF_2_5V_EXTERNAL_CAP			3

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
