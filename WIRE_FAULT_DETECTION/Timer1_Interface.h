/*
 * Timer1_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_



void TIMR1_VidInit();

void TMR1_CaptureEvent_VidSetCallBack(void  (*Copy_PVidCallBack)(void));

void TMR1_CompMatch_A_VidSetCallBack(void   (*Copy_PVidCallBack)(void));

void TMR1_CompMatch_B_VidSetCallBack(void   (*Copy_PVidCallBack)(void));

void TMR1_OverFlow_VidSetCallBack   (void   (*Copy_PVidCallBack)(void));


void ACD_VidSendDutyAndWidth(u16 Copy_U16Duty,u16 Copy_U16Width);

u32 TIMr_1_U32ReadTCNT1( void );

void TIMr_1_VidSetTCNT1( u32 Copy_U32Preload );
void TIMER1_VidDisable();
void TIMER1_VidEnable();

#endif /* TIMER1_INTERFACE_H_ */
