/*
 * Timer1_Prog.c

 *
 *  Created on: 12/11/2020
 *      Author: ALAA ELNAGAR
 *      MOBILE:+201019793647
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO_Configure.h"
#include "DIO_reference.h"
#include "Timr1_Private.h"
#include "Timer1_Config.h"
#include <util/delay.h>


void TIMR1_VidInit(){



										/*COMPARE OUTPUT MODE NON PWM BLOCK*/
#if COMPARE_OUTPUT_MODE == NON_PWM_MODE
	/*NORMAL_OPERATION*/
   #if (NON_PWM_MODE_SELECTOR == NORMAL_OPERATION) && (SELECT_CHANEEL == CHANEL_A)
   	CLEAR_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	/*normal selection from waveform generation mode bit description table*/
 CLEAR_BIT(TCCR1B,WGM13_BIT_TCCR1B);  CLEAR_BIT(TCCR1B,WGM12_BIT_TCCR1B);  CLEAR_BIT(TCCR1A,WGM11_BIT_TCCR1A); CLEAR_BIT(TCCR1A,WGM10_BIT_TCCR1A);
   	/*enable overflow  interrupt  � Bit 2 � TOIE1: Timer/Counter1, Overflow Interrupt Enable*/
	SET_BIT(TIMSK,TOIE1_BIT_TIMSK);

   #elif (NON_PWM_MODE_SELECTOR == NORMAL_OPERATION) && (SELECT_CHANEEL == CHANEL_B)
   	CLEAR_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1B0_BIT_TCCR1A);

   #elif (NON_PWM_MODE_SELECTOR == NORMAL_OPERATION) && (SELECT_CHANEEL == CHANEL_A_AND_B)
   	CLEAR_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	CLEAR_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1B0_BIT_TCCR1A);

	#endif

   	/*TOGGLE_ON_COMPARE_MATCH*/
   	   #if (NON_PWM_MODE_SELECTOR == TOGGLE_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_A)
   	   	CLEAR_BIT(TCCR1A,COM1A1_BIT_TCCR1A);  SET_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	   	/*intiailze ocr1a for compare match toggling */
   	   	OCR1AL = OCR1AL__intiailze;
   	   	/*Enable the Compare match interrupt */
   	   	SET_BIT(TIMSK,OCIE1A_BIT_TIMSK);


   	   #elif (NON_PWM_MODE_SELECTOR == TOGGLE_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_B)
   	   	CLEAR_BIT(TCCR1A,COM1B1_BIT_TCCR1A);  SET_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
   	   	/*intiailze ocr1b for compare match toggling */

   	   	OCR1BL = OCR1BL__intiailze;

   	   	/*Enable the Compare match interrupt */
   	   	SET_BIT(TIMSK,OCIE1B_BIT_TIMSK);

   	   #elif (NON_PWM_MODE_SELECTOR == TOGGLE_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_A_AND_B)
   	   	CLEAR_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   SET_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	   	CLEAR_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   SET_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
   	   	/*intiailze ocr1a for compare match toggling */

   	   	OCR1BL = OCR1BL__intiailze;									OCR1AL = OCR1AL__intiailze;
  	   	/*Enable the Compare match interrupt */						 /*Enable the Compare match interrupt */
   	   	SET_BIT(TIMSK,OCIE1B_BIT_TIMSK);						   SET_BIT(TIMSK,OCIE1A_BIT_TIMSK);


    #endif

   	   	/*CLEAR_ON_COMPARE_MATCH*/
   	   	   #if (NON_PWM_MODE_SELECTOR == CLEAR_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_A)
   	   	   	SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);  CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	   	   	OCR1AL = OCR1AL__intiailze;

   	   	   #elif (NON_PWM_MODE_SELECTOR == CLEAR_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_B)
   	     	SET_BIT(TCCR1A,COM1B1_BIT_TCCR1A);  CLEAR_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
   	   	   	OCR1BL = OCR1BL__intiailze;

   	   	   #elif (NON_PWM_MODE_SELECTOR == CLEAR_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_A_AND_B)
   	         SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	         SET_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
   	   	   	OCR1BL = OCR1BL__intiailze;
   	   	   	OCR1AL = OCR1AL__intiailze;


   	    #endif


   	    	/*SET_ON_COMPARE_MATCH*/
   	    	   #if (NON_PWM_MODE_SELECTOR == SET_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_A)
   	   	   		SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);  SET_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	            /*intialize OCR1AL to allow toggle in  compare mode*/
   	             OCR1AL =OCR1AL__intiailze;

   	        // OCR1BL

   	    	   #elif (NON_PWM_MODE_SELECTOR == SET_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_B)
   	            SET_BIT(TCCR1A,COM1B1_BIT_TCCR1A);  SET_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
   	            OCR1BL =OCR1BL__intiailze;
   	    	   #elif (NON_PWM_MODE_SELECTOR == NORMAL_OPERATION) && (SELECT_CHANEEL == CHANEL_A_AND_B)
            	SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   SET_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	            SET_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   SET_BIT(TCCR1A,COM1B0_BIT_TCCR1A);

   	            OCR1AL =OCR1AL__intiailze;
   	            OCR1BL =OCR1BL__intiailze;
   	     #endif

 /************S******************************************************************************************************/
   	            										/*COMPARE OUTPUT MODE FAST PWM BLOCK*/
/*******************************************************************************************************************/
#elif COMPARE_OUTPUT_MODE == FAST_PWM_MODE
	/* 1 NORMAL_OPERATION*/
	   #if (FAST_PWM_MODE_SELECTOR == NORMAL_OPERATION) && (SELECT_CHANEEL == CHANEL_A)
		CLEAR_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);


	   #elif (FAST_PWM_MODE_SELECTOR  ==  NORMAL_OPERATION) && (SELECT_CHANEEL == CHANEL_B)
		CLEAR_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1B0_BIT_TCCR1A);

	   #elif (FAST_PWM_MODE_SELECTOR == NORMAL_OPERATION) && (SELECT_CHANEEL == CHANEL_A_AND_B)
		CLEAR_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
		CLEAR_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1B0_BIT_TCCR1A);

		#endif

   	/*  TOGGLE_ON_COMPARE_MATCH   OC1A ONLEY  OCQB ON NORMAL POET OPERATION */

   	   #if (FAST_PWM_MODE_SELECTOR == TOGGLE_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_A)
   	   	CLEAR_BIT(TCCR1A,COM1A1_BIT_TCCR1A);  SET_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	   	/*selecting mode 15 FAST PWM*/

   	   	SET_BIT(TCCR1B,WGM13_BIT_TCCR1B);  SET_BIT(TCCR1B,WGM12_BIT_TCCR1B);  SET_BIT(TCCR1A,WGM11_BIT_TCCR1A); SET_BIT(TCCR1A,WGM10_BIT_TCCR1A);
           OCR1AL =OCR1AL__intiailze;


	   #endif

   	   	/*3 CLEAR_ON_COMPARE_MATCH*/
   	   	   #if (FAST_PWM_MODE_SELECTOR == CLEAR_ON_COMPARE_MATCH	) && (SELECT_CHANEEL == CHANEL_A)
   	   	   	SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);  CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	   	   	SET_BIT(TCCR1B,WGM13_BIT_TCCR1B);  SET_BIT(TCCR1B,WGM12_BIT_TCCR1B);  SET_BIT(TCCR1A,WGM11_BIT_TCCR1A); CLEAR_BIT(TCCR1A,WGM10_BIT_TCCR1A);
   	   	   	ICR1L=ICR1L__intiailze;
   	   	   	OCR1AL =OCR1AL__intiailze;


   	   	   #elif (FAST_PWM_MODE_SELECTOR == CLEAR_ON_COMPARE_MATCH	) && (SELECT_CHANEEL == CHANEL_B)
   	     	SET_BIT(TCCR1A,COM1B1_BIT_TCCR1A);  CLEAR_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
   	   	   	SET_BIT(TCCR1B,WGM13_BIT_TCCR1B);  SET_BIT(TCCR1B,WGM12_BIT_TCCR1B);  SET_BIT(TCCR1A,WGM11_BIT_TCCR1A); CLEAR_BIT(TCCR1A,WGM10_BIT_TCCR1A);
   	   	   	ICR1L=ICR1L__intiailze;
   	     	OCR1BL =OCR1BL__intiailze;

   	   	   #elif (FAST_PWM_MODE_SELECTOR == CLEAR_ON_COMPARE_MATCH	) && (SELECT_CHANEEL == CHANEL_A_AND_B)
   	         SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	         SET_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
    	   	   	SET_BIT(TCCR1B,WGM13_BIT_TCCR1B);  SET_BIT(TCCR1B,WGM12_BIT_TCCR1B);  SET_BIT(TCCR1A,WGM11_BIT_TCCR1A); CLEAR_BIT(TCCR1A,WGM10_BIT_TCCR1A);
    	   	 ICR1L=ICR1L__intiailze;
             OCR1AL =OCR1AL__intiailze;
             OCR1BL =OCR1BL__intiailze;

   	    #endif


   	    	/*4   SET_ON_COMPARE_MATCH*/
   	    	   #if (FAST_PWM_MODE_SELECTOR == SET_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_A)
   	            SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);  SET_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
    	   	   	SET_BIT(TCCR1B,WGM13_BIT_TCCR1B);  SET_BIT(TCCR1B,WGM12_BIT_TCCR1B);  SET_BIT(TCCR1A,WGM11_BIT_TCCR1A); CLEAR_BIT(TCCR1A,WGM10_BIT_TCCR1A);
    	   	 ICR1L=ICR1L__intiailze;
             OCR1AL =OCR1AL__intiailze;

   	    	   #elif (FAST_PWM_MODE_SELECTOR == SET_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_B)
   	            SET_BIT(TCCR1A,COM1B1_BIT_TCCR1A);  SET_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
    	   	   	SET_BIT(TCCR1B,WGM13_BIT_TCCR1B);  SET_BIT(TCCR1B,WGM12_BIT_TCCR1B);  SET_BIT(TCCR1A,WGM11_BIT_TCCR1A); CLEAR_BIT(TCCR1A,WGM10_BIT_TCCR1A);
    	   	 ICR1L=ICR1L__intiailze;
             OCR1BL =OCR1BL__intiailze;

   	    	   #elif (FAST_PWM_MODE_SELECTOR == SET_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_A_AND_B)
            	SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   SET_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	            SET_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   SET_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
    	   	   	SET_BIT(TCCR1B,WGM13_BIT_TCCR1B);  SET_BIT(TCCR1B,WGM12_BIT_TCCR1B);  SET_BIT(TCCR1A,WGM11_BIT_TCCR1A); CLEAR_BIT(TCCR1A,WGM10_BIT_TCCR1A);
    	   	 ICR1L=ICR1L__intiailze;
             OCR1AL =OCR1AL__intiailze;
             OCR1BL =OCR1BL__intiailze;
   	     #endif



   	         /******************************************************************************************************************/
   	           	            /*COMPARE OUTPUT MODE phase correct and frequancy correct BLOCK*/
   	        /*******************************************************************************************************************/
  #elif COMPARE_OUTPUT_MODE ==  PHASE_CORRECT_MODE
   	        	/* 1 NORMAL_OPERATION*/
   	           #if (PHASE_CORRECT_SELECTOR == NORMAL_OPERATION) && (SELECT_CHANEEL == CHANEL_A)
   	           	CLEAR_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);

   	           #elif (FAST_PWM_MODE_SELECTOR  ==  NORMAL_OPERATION) && (SELECT_CHANEEL == CHANEL_B)
   	           	CLEAR_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1B0_BIT_TCCR1A);

   	           #elif (FAST_PWM_MODE_SELECTOR == NORMAL_OPERATION) && (SELECT_CHANEEL == CHANEL_A_AND_B)
   	           	CLEAR_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	           	CLEAR_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1B0_BIT_TCCR1A);

   	        	#endif

   	           	/*  TOGGLE_ON_COMPARE_MATCH   OC1A ONLEY  OC1B ON NORMAL PORET OPERATION */

   	           	   #if (PHASE_CORRECT_SELECTOR == TOGGLE_ON_COMPARE_MATCH_OCR1A) && (SELECT_CHANEEL == CHANEL_A)
   	           	   	CLEAR_BIT(TCCR1A,COM1A1_BIT_TCCR1A);  SET_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	           	   	/*selecting mode 9  */
   	           	   		/*mode 9 PWM, Phase and Frequency Correct OCR1A */
   	           	   	SET_BIT(TCCR1B,WGM13_BIT_TCCR1B);  CLEAR_BIT(TCCR1B,WGM12_BIT_TCCR1B);  CLEAR_BIT(TCCR1A,WGM11_BIT_TCCR1A); SET_BIT(TCCR1A,WGM10_BIT_TCCR1A);
   	           	   	OCR1AL  = OCR1AL__intiailze;
   	           	   	/*mode 14 PWM, Fast PWM ICR1 BOTTOM */
   	           	   	//SET_BIT(TCCR1B,WGM13_BIT_TCCR1B);  SET_BIT(TCCR1B,WGM12_BIT_TCCR1B);  SET_BIT(TCCR1A,WGM11_BIT_TCCR1A); CLEAR_BIT(TCCR1A,WGM10_BIT_TCCR1A);
   	           	  // 	ICR1=ICR1L__intiailze ;

/***************************************??????????????????????????????*/
				   #elif (PHASE_CORRECT_SELECTOR == TOGGLE_ON_COMPARE_MATCH_ICR1L) && (SELECT_CHANEEL == CHANEL_A)
					CLEAR_BIT(TCCR1A,COM1A1_BIT_TCCR1A);  SET_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
					/*  or 14 FAST PWM*/
					SET_BIT(TCCR1B,WGM13_BIT_TCCR1B);  SET_BIT(TCCR1B,WGM12_BIT_TCCR1B);  SET_BIT(TCCR1A,WGM11_BIT_TCCR1A); CLEAR_BIT(TCCR1A,WGM10_BIT_TCCR1A);
					/*mode 14 PWM, Fast PWM ICR1 BOTTOM */
					OCR1AL  = OCR1AL__intiailze;

					ICR1L=ICR1L__intiailze ;






   	        	   #endif

   	           	   	/*3 CLEAR_ON_COMPARE_MATCH*/
   	           	   	   #if (PHASE_CORRECT_SELECTOR == CLEAR_ON_COMPARE_MATCH	) && (SELECT_CHANEEL == CHANEL_A)
   	           	   	   	SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);  CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   						SET_BIT(TCCR1B,WGM13_BIT_TCCR1B);  CLEAR_BIT(TCCR1B,WGM12_BIT_TCCR1B);  CLEAR_BIT(TCCR1A,WGM11_BIT_TCCR1A); SET_BIT(TCCR1A,WGM10_BIT_TCCR1A);

   	           	   	   	OCR1AL  = OCR1AL__intiailze;

   	           	   	   #elif (PHASE_CORRECT_SELECTOR == CLEAR_ON_COMPARE_MATCH	) && (SELECT_CHANEEL == CHANEL_B)
   	           	     	SET_BIT(TCCR1A,COM1B1_BIT_TCCR1A);  CLEAR_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
   	           	     	OCR1BL  = OCR1BL__intiailze;
   	           	   	   #elif (PHASE_CORRECT_SELECTOR == CLEAR_ON_COMPARE_MATCH	) && (SELECT_CHANEEL == CHANEL_A_AND_B)
   	           	         SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	           	         SET_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   CLEAR_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
   	           	         OCR1AL  = OCR1AL__intiailze;
   	           	         OCR1BL  = OCR1BL__intiailze;

   	           	         #endif


   	           	    	/*4   SET_ON_COMPARE_MATCH*/
   	           	    	   #if (PHASE_CORRECT_SELECTOR == SET_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_A)
   	           	            SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);  SET_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
      	           	         OCR1AL  = OCR1AL__intiailze;

   	           	    	   #elif (PHASE_CORRECT_SELECTOR == SET_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_B)
   	           	            SET_BIT(TCCR1A,COM1B1_BIT_TCCR1A);  SET_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
      	           	         OCR1BL  = OCR1BL__intiailze;

   	           	    	   #elif (FPHASE_CORRECT_SELECTOR == SET_ON_COMPARE_MATCH) && (SELECT_CHANEEL == CHANEL_A_AND_B)
   	                    	SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);   SET_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
   	           	            SET_BIT(TCCR1A,COM1B1_BIT_TCCR1A);   SET_BIT(TCCR1A,COM1B0_BIT_TCCR1A);
      	           	         OCR1AL  = OCR1AL__intiailze;
       	           	         OCR1BL  = OCR1BL__intiailze;

   	           	            #endif




#endif






}



/*use this function icase of PWM MODE AND ICR MODE  3 CLEAR_ON_COMPARE_MATCH*/
void ACD_VidSendDutyAndWidth(u16 Copy_U16Duty,u16 Copy_U16Width){
	SET_BIT(TCCR1A,COM1A1_BIT_TCCR1A);  CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);
	SET_BIT(TCCR1B,WGM13_BIT_TCCR1B);  SET_BIT(TCCR1B,WGM12_BIT_TCCR1B);  SET_BIT(TCCR1A,WGM11_BIT_TCCR1A); CLEAR_BIT(TCCR1A,WGM10_BIT_TCCR1A);
	OCR1AL=Copy_U16Duty;
	ICR1L=Copy_U16Width;

}



void TIMr_1_VidSetTCNT1( u32 Copy_U32Preload )
{
	/*STOP THE INTERRUPT*/
	CLEAR_BIT(TIMSK,TOIE1_BIT_TIMSK);
	/*FETCH TIMER VALUE*/
	TCNT1L = Copy_U32Preload;
	/*ENABLE INTERRUPT */
	SET_BIT(TIMSK,TOIE1_BIT_TIMSK);

}



u32 TIMr_1_U32ReadTCNT1( void )
{
	/*STOP THE INTERRUPT*/
	CLEAR_BIT(TIMSK,TOIE1_BIT_TIMSK);
	/*FETCH TIMER VALUE*/
	u32 TCNT1L_HELP =TCNT1L;
	/*ENABLE INTERRUPT */
	SET_BIT(TIMSK,TOIE1_BIT_TIMSK);
	return TCNT1L_HELP;
}


void TIMER1_VidEnable(){

	/*PRESCALLER WHICH WORKS LIKE ENABLING */

	#if 	SELECT_CLOCK==NO_CLOCK_SOURCE
			CLEAR_BIT(TCCR1B,CS12_BIT_TCCR1B); 	CLEAR_BIT(TCCR1B,CS11_BIT_TCCR1B);    CLEAR_BIT(TCCR1B,CS10_BIT_TCCR1B);

	#elif 	SELECT_CLOCK==NO_PRESCALING
			CLEAR_BIT(TCCR1B,CS12_BIT_TCCR1B); 	CLEAR_BIT(TCCR1B,CS11_BIT_TCCR1B);    SET_BIT(TCCR1B,CS10_BIT_TCCR1B);

#elif 	SELECT_CLOCK==DIVIDE_BY_8_PRESCALING
			CLEAR_BIT(TCCR1B,CS12_BIT_TCCR1B); 	SET_BIT(TCCR1B,CS11_BIT_TCCR1B);    CLEAR_BIT(TCCR1B,CS10_BIT_TCCR1B);

	#elif 	SELECT_CLOCK==DIVIDE_BY_64_PRESCALING
			CLEAR_BIT(TCCR1B,CS12_BIT_TCCR1B); 	SET_BIT(TCCR1B,CS11_BIT_TCCR1B);    SET_BIT(TCCR1B,CS10_BIT_TCCR1B);

	#elif 	SELECT_CLOCK==DIVIDE_BY_256_PRESCALING

			SET_BIT(TCCR1B,CS12_BIT_TCCR1B); 	CLEAR_BIT(TCCR1B,CS11_BIT_TCCR1B);    CLEAR_BIT(TCCR1B,CS10_BIT_TCCR1B);

	#elif 	SELECT_CLOCK==DIVIDE_BY_1024_PRESCALING
			SET_BIT(TCCR1B,CS12_BIT_TCCR1B); 	CLEAR_BIT(TCCR1B,CS11_BIT_TCCR1B);    SET_BIT(TCCR1B,CS10_BIT_TCCR1B);

	#elif 	SELECT_CLOCK== EXTERNAL_FALLING_EDGE
			SET_BIT(TCCR1B,CS12_BIT_TCCR1B); 	SET_BIT(TCCR1B,CS11_BIT_TCCR1B);    CLEAR_BIT(TCCR1B,CS10_BIT_TCCR1B);

	#elif SELECT_CLOCK==EXTERNAL_RISING_EDGE
			SET_BIT(TCCR1B,CS12_BIT_TCCR1B); 	SET_BIT(TCCR1B,CS11_BIT_TCCR1B);    SET_BIT(TCCR1B,CS10_BIT_TCCR1B);

	#endif


}
void TIMER1_VidDisable(){

	/*PRESCALLER WHICH WORKS LIKE ENABLING */

		CLEAR_BIT(TCCR1B,CS12_BIT_TCCR1B); 	CLEAR_BIT(TCCR1B,CS11_BIT_TCCR1B);    CLEAR_BIT(TCCR1B,CS10_BIT_TCCR1B);



}













/*capture event callback function */
static void (*PVidCall_6_Back)(void)=0;
/*compare match A call back*/
static void (*PVidCall_7_Back)(void)=0;
/*COMPARE MATCH B CALL BACK*/
static void (*PVidCall_8_Back)(void)=0;
/*OVERFLOW CLALL FUNCTIO */
static void (*PVidCall_9_Back)(void)=0;



void TMR1_CaptureEvent_VidSetCallBack(void (*Copy_PVidCallBack)(void)){
	PVidCall_6_Back=Copy_PVidCallBack;

}


void TMR1_CompMatch_A_VidSetCallBack(void (*Copy_PVidCallBack)(void)){
	PVidCall_7_Back=Copy_PVidCallBack;

}

void TMR1_CompMatch_B_VidSetCallBack(void (*Copy_PVidCallBack)(void)){
	PVidCall_8_Back=Copy_PVidCallBack;

}

void TMR1_OverFlow_VidSetCallBack(void (*Copy_PVidCallBack)(void)){
	PVidCall_9_Back=Copy_PVidCallBack;

}


/*capture event callback function */

void __vector_6(void ){

	if (PVidCall_6_Back!=0){
		PVidCall_6_Back();
		}

}
/*compare match A call back*/

void __vector_7(void ){

	if (PVidCall_7_Back!=0){
		PVidCall_7_Back();
		}

}

/*COMPARE MATCH B CALL BACK*/

void __vector_8(void ){

	if (PVidCall_8_Back!=0){
		PVidCall_8_Back();
		}

}
/*OVERFLOW CLALL FUNCTIO */


void __vector_9(void ){

	if (PVidCall_9_Back!=0){
		PVidCall_9_Back();
		}

}















/*
	DIO_VidSetPinDirection(PORTA_NUM,7,1);

	CLEAR_BIT(TCCR1A,WGM10_BIT_TCCR1A);
	CLEAR_BIT(TCCR1A,WGM11_BIT_TCCR1A);
	CLEAR_BIT(TCCR1B,WGM12_BIT_TCCR1B);
	CLEAR_BIT(TCCR1B,WGM13_BIT_TCCR1B);





CLEAR_BIT(TCCR1A,COM1A1_BIT_TCCR1A);
CLEAR_BIT(TCCR1A,COM1A0_BIT_TCCR1A);


TCNT1L = 16834 ;

	SET_BIT(TCCR1B,CS10_BIT_TCCR1B);
	CLEAR_BIT(TCCR1B,CS11_BIT_TCCR1B);
	SET_BIT(TCCR1B,CS12_BIT_TCCR1B);
u8 count=0;
//TCNT1L = 16834 ;


while(1){

//	TOGGLE_BIT(PORTA,7);
while (!GET_BIT(TIFR,TOV1_BIT_TIFR)){	 asm ("NOP");}

TOGGLE_BIT(PORTA,7);

count+=1;
SET_BIT(TIFR,TOV1_BIT_TIFR);

TCNT1L =16834 ;


*/
