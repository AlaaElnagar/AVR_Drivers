/*
 * main.c
 *  Created on: Dec 12, 2020
 *      Author: Alaa Elnagar
 *      Mobile:+201019793647
 */


/*  Capacitance Measurement
* Theory   A capacitor will charge, through a resistor, in one time constant, defined as T seconds where
 *    TC = R * C
 *    TC = time constant period in seconds
 *    R = resistance in ohms
 *    C = capacitance in farads (1 microfarad (ufd) = .0000001 farad = 10^-6 farads)
 *
 *    The capacitor's voltage at one time constant is defined as 63.2% of the charging voltage.
*/


/*
Set discharge pin to INPUT (so it can’t discharge the capacitor)
Set charge pin to OUTPUT and make it HIGH
Record the start time with millis()
Check the voltage repeatedly in a loop until it gets to 63.2% of total voltage.
After the cap is charged, subtract the current time from the start time to find out how long the capacitor took to charge.
Divide the Time in seconds by the charging Resistance in ohms to find the Capacitance.
Report the value with print on Serial monitor.
Discharge the capacitor. To do this:
Set the charge pin to Input
Set the discharge pin to OUTPUT and make it LOW
Read the voltage to make sure the capacitor is fully discharged
Loop and do it again
Capacitance Mea

 * */





#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_reference.h"
#include <util/delay.h>
#include "GIE_Interface.h"
#include "Timer1_Interface.h"
#include "LCD_interface.h"
#include "ADC_Interface.h"
#include "VERTICAL_FILE.h"

u32 GLOBAL_F32MicroFarads;
u32 GLOBAL_F32NanoFarads;
u32 Global_U32TimerOverflow;
u32 Global_U32ConstantTime ;

void ADC_VidISR(){
//	LCD_VidGoto(ZERO,ZERO);
//LCD_String("i'M HERE ");
//	LCD_VidGoto(ONE,ZERO);
//	LCD_VidSendInt(ADC_U8GetData());
}

void CompareMatchISR_A_VidFunc (void){

}

void OverFlowISR_VidFunc (void){

	//DIO_VidTogglePin(PORTC_NUM,PIN0_NUM);
	Global_U32TimerOverflow+=1;
}





int main (){
	TMR1_OverFlow_VidSetCallBack(&OverFlowISR_VidFunc);
	/*setting the pins */
	DIO_VidSetPinDirection(CHARGE_PORT,CHARGE_PIN,OUTPUT);
	DIO_VidSetPinDirection( CAPACITANCE_READ_PORT,CAPACITANCE_READ_PIN,INPUT);

	TMR1_OverFlow_VidSetCallBack(&OverFlowISR_VidFunc);

	TIMR1_VidInit();
	LCD_VidInit();

	ADC_VidInit();
	ADC_VidRefferenceVolt( VREF_AVCC_EXTERNAL);
	ADC_VidEnable();
	ADC_VidSingleChannelSelect(CHANNEL_6_SELECT);
	ADC_VidConvIntEnable();
	ADC_VidPrescaller(128);

	ADC_VidSetCallBack(&ADC_VidISR);


	DIO_VidSetPinDirection(PORTC_NUM,PIN0_NUM,OUTPUT);

	GIE_VidEnable();

	while(1){

/*Start charging */
DIO_VidSetPinValue(CHARGE_PORT,CHARGE_PIN,HIGH);
/*Record time */
TIMER1_VidEnable();
TIMr_1_VidSetTCNT1( 0);
/*check the wire capacitance */
// 647 is 63.2% of 1023, which corresponds to full-scale voltage
ADC_VidStartConverssion();

while( ADC_U8GetData() < 648){
	ADC_VidStartConverssion();
	ADC_U8PoolConverssion();
	//LCD_VidGoto(ONE,SEVEN);
	//LCD_String("LOAD...");

	//LCD_VidGoto(ZERO,SEVEN);
	//LCD_VidSendInt(ADC_U8GetData() );


}
/*stop time and get the elapsed time*/
u32 LOCAL_U32TCNT1_VAL=TIMr_1_U32ReadTCNT1();

TIMER1_VidDisable();
f32 Local_F32ElapsedTime=0;
/*one over flow equal 8 sec  AND One Tick  =  .1 us */
Local_F32ElapsedTime=(Global_U32TimerOverflow*8)+(LOCAL_U32TCNT1_VAL * (1.28/10000));
/*Get the capacitance */
Global_U32TimerOverflow=0;
//  and Farads to microFarads ( 10^6 )
f32 LOCAL_F32MicroFarads = (   Local_F32ElapsedTime / DISCHARGE_RESISTOR_VALUE ) *1000000 ;
if (LOCAL_F32MicroFarads>1){
LCD_CLEAR();
LCD_VidGoto(ZERO,ZERO);
LCD_String("Cap:");
LCD_VidSendInt(LOCAL_F32MicroFarads);
LCD_String(" MicroFarad");


}

else {
    // if value is smaller than one microFarad, convert to nanoFarads (10^-9 Farad).
	  // multiply by 1000 to convert to nanoFarads (10^-9 Farads)
	f32 LOCAL_F32NanoFarads = LOCAL_F32MicroFarads * 1000.0;
	LCD_CLEAR();
	LCD_VidGoto(ZERO,ZERO);
	LCD_String("Cap:");
	LCD_VidSendInt(LOCAL_F32NanoFarads);
	LCD_String(" NanoFarad");

}
/* dicharge the capacitor  */

/* set charge pin to  LOW */
DIO_VidSetPinDirection(DISCHARGE_PORT,DISCHARGE_PIN,OUTPUT);

DIO_VidSetPinValue(CHARGE_PORT,CHARGE_PIN,LOW);

/*set discharge pin LOW*/

DIO_VidSetPinValue(DISCHARGE_PORT,DISCHARGE_PIN,LOW);

/* wait until capacitor is completely discharged*/
while(ADC_U8GetData() > 0){
	ADC_VidStartConverssion();
		ADC_U8PoolConverssion();
	LCD_VidGoto(ONE,ZERO);
	LCD_String("Cap:");
	LCD_VidSendInt(ADC_U8GetData());
	_delay_ms(500);

}
_delay_ms(5000);


// set discharge pin back to input
DIO_VidSetPinDirection(DISCHARGE_PORT,DISCHARGE_PIN,INPUT);



	}




}



//TMR1_CompMatch_A_VidSetCallBack(&CompareMatchISR_A_VidFunc);
//TMR1_OverFlow_VidSetCallBack(&OverFlowISR_VidFunc);
//ADC_VidSetCallBack(&ADC_VidISR);
