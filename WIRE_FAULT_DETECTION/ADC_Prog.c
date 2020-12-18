#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_Private.h"
#include "ADC_Config.h"






/*channel selection   */
/************************************************************************************************
 [Function Name]    ADC_VidLatch

 [Description]		Function used to Enable and initiate  ADC internal circuit by defining
 	 	 	 	 	 -channel selection
 	 	 	 	 	 -reference voltage
 	 	 	 	 	 -prescaler
 	 	 	 	 	 -LEFT ADJUST OR RIGHT
 	 	 	 	 	 -Enable ADC
 	 	 	 	 	 -setting trigger as single conversion or auto

 [Args]				void

 [in]				void

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/



void ADC_VidInit(){


/*SET AS left ADJUSTMENT */
SET_BIT(ADMUX,5);

#if CONVERSSION == SINGLE
/*if this case intialiezed we will make flag looping  on ADCSRA Bit 4*/
/*Disable  trigger to apply single converssion */
CLEAR_BIT(ADCSRA,5);

#elif CONVERSSION == INTERRUPT
/*Enable  trigger to apply single converssion  free running*/
SET_BIT(ADCSRA,5);
		#if INTERRUPT_SOURCE == FREE_RUNNING
		/*Selection of triggiring source */
							CLEAR_BIT(SFIOR,2);		CLEAR_BIT(SFIOR,1);			CLEAR_BIT(SFIOR,0);

		#elif INTERRUPT_SOURCE == ANALOG_COMPARATOR

							CLEAR_BIT(SFIOR,2);		CLEAR_BIT(SFIOR,1);			   SET_BIT(SFIOR,0);
		#elif INTERRUPT_SOURCE == EXIT0_REQUIST

							CLEAR_BIT(SFIOR,2);		SET_BIT(SFIOR,1);			CLEAR_BIT(SFIOR,0);

		#elif INTERRUPT_SOURCE == TIMR0_COMP_MATCH

							CLEAR_BIT(SF IOR,2);		SET_BIT(SFIOR,1);			 SET_BIT(SFIOR,0);
        #elif INTERRUPT_SOURCE == TIMR0_OVER_FLOW

        					SET_BIT(SFIOR,2);		CLEAR_BIT(SFIOR,1);			CLEAR_BIT(SFIOR,0);
        #elif INTERRUPT_SOURCE == TIMR1_COMP_MATCH

        					SET_BIT(SFIOR,2);		CLEAR_BIT(SFIOR,1);		  	  SET_BIT(SFIOR,0);
        #elif INTERRUPT_SOURCE ==  TIMR1_OVER_FLOW

        					SET_BIT(SFIOR,2);		SET_BIT(SFIOR,1);			CLEAR_BIT(SFIOR,0);
        #elif INTERRUPT_SOURCE ==  TIMR1_CAPTURE_EVENT

        					SET_BIT(SFIOR,2);		SET_BIT(SFIOR,1);			  SET_BIT(SFIOR,0);

		#endif




#endif

}



/************************************************************************************************
 [Function Name]    ADC_Prescaller selection selection

 [Description]		division factor between the XTAL frequency and the input clock to the ADC.
 	 	 	 	 	 -2             Divide by               2
 	 	 	 	 	 -4             Divide by               4
 	 	 	 	 	 -8             Divide by               8
 	 	 	 	 	 -16            Divide by               16
					 -32            Divide by               32
					 -64            Divide by               64
					 -128           Divide by               128
 [Args]				U8

 [in]				void

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/


void ADC_VidPrescaller(u8 Copy_u8Refference){

if (Copy_u8Refference    ==     2   )    {  CLEAR_BIT(ADCSRA,2)   ;	   CLEAR_BIT(ADCSRA,1)   ;     SET_BIT(ADCSRA,0)    ;      }
if (Copy_u8Refference    ==     4   )    {  CLEAR_BIT(ADCSRA,2)   ;	  SET_BIT(ADCSRA,1)      ;   CLEAR_BIT(ADCSRA,0)    ;      }
if (Copy_u8Refference    ==     8   )    {  CLEAR_BIT(ADCSRA,2)   ;	   SET_BIT(ADCSRA,1)     ;     SET_BIT(ADCSRA,0)    ;      }
if (Copy_u8Refference    ==     16  )    {  SET_BIT(ADCSRA,2)     ;	   CLEAR_BIT(ADCSRA,1)   ;   CLEAR_BIT(ADCSRA,0)    ;      }
if (Copy_u8Refference    ==     32  )    {  SET_BIT(ADCSRA,2)     ;	   CLEAR_BIT(ADCSRA,1)   ;     SET_BIT(ADCSRA,0)    ;      }
if (Copy_u8Refference    ==     64  )    {  SET_BIT(ADCSRA,2)     ;	   SET_BIT(ADCSRA,1)     ;   CLEAR_BIT(ADCSRA,0)    ;      }
if (Copy_u8Refference    ==     128 )    {  SET_BIT(ADCSRA,2)     ;	   SET_BIT(ADCSRA,1)     ;     SET_BIT(ADCSRA,0)    ;      }




}




/************************************************************************************************
 [Function Name]    ADC_Vidrefference selection

 [Description]		Function used to Select ADC reference voltage
 	 	 	 	 	 -0 for Turning off 2.56v ref internal circuit
 	 	 	 	 	 -1 for Selecting AVCC with capacitor as external refference
 	 	 	 	 	 -3 for Selecting 2.56v with external cap in vref and avcc
 	 	 	 	 	 -ADC will not switch the to the new refference without finishing the converssion

 [Args]				U8

 [in]				void

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/


void ADC_VidRefferenceVolt(u8 Copy_u8Refference){

if (Copy_u8Refference==0)	{ CLEAR_BIT(ADMUX,7);	CLEAR_BIT(ADMUX,6);}
if (Copy_u8Refference==1)	{ CLEAR_BIT(ADMUX,7);	SET_BIT(ADMUX,6);}
if (Copy_u8Refference==3)	{ SET_BIT(ADMUX,7);	SET_BIT(ADMUX,6);}


}

void ADC_VidSingleChannelSelect(u8 Copy_U8Channel){
if (Copy_U8Channel==0){	CLEAR_BIT(ADMUX,4);	CLEAR_BIT(ADMUX,3);	CLEAR_BIT(ADMUX,2);		CLEAR_BIT(ADMUX,1);		CLEAR_BIT(ADMUX,0);}
if (Copy_U8Channel==1){	CLEAR_BIT(ADMUX,4);	CLEAR_BIT(ADMUX,3);	CLEAR_BIT(ADMUX,2);		CLEAR_BIT(ADMUX,1);		SET_BIT(ADMUX,0)  ;}
if (Copy_U8Channel==2){	CLEAR_BIT(ADMUX,4);	CLEAR_BIT(ADMUX,3);	CLEAR_BIT(ADMUX,2);		SET_BIT(ADMUX,1)  ;		CLEAR_BIT(ADMUX,0);}
if (Copy_U8Channel==3){	CLEAR_BIT(ADMUX,4);	CLEAR_BIT(ADMUX,3);	CLEAR_BIT(ADMUX,2);		SET_BIT(ADMUX,1)  ;		SET_BIT(ADMUX,0)  ;}
if (Copy_U8Channel==4){	CLEAR_BIT(ADMUX,4);	CLEAR_BIT(ADMUX,3);	SET_BIT(ADMUX,2)  ;		CLEAR_BIT(ADMUX,1);		CLEAR_BIT(ADMUX,0);}
if (Copy_U8Channel==5){	CLEAR_BIT(ADMUX,4);	CLEAR_BIT(ADMUX,3);	SET_BIT(ADMUX,2)  ;		CLEAR_BIT(ADMUX,1);		SET_BIT(ADMUX,0)  ;}
if (Copy_U8Channel==6){	CLEAR_BIT(ADMUX,4);	CLEAR_BIT(ADMUX,3);	SET_BIT(ADMUX,2)  ;		SET_BIT(ADMUX,1)  ;		CLEAR_BIT(ADMUX,0);}
if (Copy_U8Channel==7){	CLEAR_BIT(ADMUX,4);	CLEAR_BIT(ADMUX,3);	SET_BIT(ADMUX,2)  ;		SET_BIT(ADMUX,1)  ;		SET_BIT(ADMUX,0)  ;}

}




void ADC_VidEnable(){

	SET_BIT(ADCSRA,7);

}

void ADC_VidDisable(){

	CLEAR_BIT(ADCSRA,7);

}

void ADC_VidStartConverssion(){
	SET_BIT(ADCSRA,6);
							  }

/*ADCSRA Bit 4 is ADC converssion flag =1 by end of converssion and reset by 1*/
u8 ADC_U8PoolConverssion(){
	u8 Local_U8Copy=0;

	Local_U8Copy = GET_BIT(ADCSRA,4);
	if (Local_U8Copy==1){SET_BIT(ADCSRA,4);Local_U8Copy=0;}
	return(Local_U8Copy);
}


u16 ADC_U8GetData(){
static 	volatile u16 Local_U16Copy=0;

	   Local_U16Copy=ADCH;

	   //Converssion of value into mv AND mul by four because of left adjustment
	   //Local_U16Copy =	Local_U16Copy*(5000ul/1023.0)*4;
	   Local_U16Copy =	Local_U16Copy*4;

	   return(Local_U16Copy);

}


void ADC_VidConvIntEnable(){
	SET_BIT(ADCSRA,3);
}

void ADC_VidConvIntDisable(){
	CLEAR_BIT(ADCSRA,3);
}

void ADC_VidFlagIntClr(){
	SET_BIT(ADCSRA,4);
}


static void (*PVidADC_CallBack)(void)=Null;


void ADC_VidSetCallBack(void (*Copy_PVidCallBack)(void)){
	PVidADC_CallBack=Copy_PVidCallBack;

}

/*ADC Converssion complelete*/
void __vector_16(void ){

if (PVidADC_CallBack!=Null){
	PVidADC_CallBack();
}
}

/*
void ADC_enuReadADC(volatile u16 * Copy_Pu16ADC_Value){

	*Copy_Pu16ADC_Value = ADC;



}
*/













