/*
 * Timer1_Interface.h
 *
 *  Created on: ??�/??�/????
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

#endif /* TIMER1_INTERFACE_H_ */
