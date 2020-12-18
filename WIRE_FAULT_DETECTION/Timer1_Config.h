/*
 * Timer1_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_



/*CHANEL_A    CHANEL_B    CHANEL_A_AND_B*/
#define SELECT_CHANEEL     CHANEL_A


/*

 NO_CLOCK_SOURCE			NO_PRESCALING				DIVIDE_BY_8_PRESCALING		DIVIDE_BY_64_PRESCALING
 DIVIDE_BY_256_PRESCALING	 DIVIDE_BY_1024_PRESCALING	 EXTERNAL_FALLING_EDGE		EXTERNAL_RISING_EDGE
 CLOCK_SELECT
*/
#define SELECT_CLOCK			  DIVIDE_BY_1024_PRESCALING


/*	SELECT ONE OF >>     NON_PWM_MODE  		      FAST_PWM_MODE	     	 PHASE_CORRECT_MODE*/

#define COMPARE_OUTPUT_MODE 		  NON_PWM_MODE


/*	NORMAL_OPERATION                    >>        (OC1A/OC1B disconnected.)
 *  TOGGLE_ON_COMPARE_MATCH             >>        (Toggle OC1A/OC1B on compare match)
 *  CLEAR_ON_COMPARE_MATCH	            >>        (Clear OC1A/OC1B on compare match (Set output to low level))
 *  SET_ON_COMPARE_MATCH                >>        (Set OC1A/OC1B on compare match (Set output to LOW level))*/
#define NON_PWM_MODE_SELECTOR       NORMAL_OPERATION


/*	NORMAL_OPERATION                    >>        (OC1A/OC1B disconnected.)
 *  TOGGLE_ON_COMPARE_MATCH             >>        Toggle OC1A on Compare Match, OC1B disconnected (normal port operation) dont forget to intialize OCR1AH and OCR1AL
 *  CLEAR_ON_COMPARE_MATCH	            >>        Clear OC1A/OC1B on compare match, set OC1A/OC1B at BOTTOM, (non-inverting mode)
 *  SET_ON_COMPARE_MATCH                >>       Set OC1A/OC1B on compare match, clear OC1A/OC1B at BOTTOM,(inverting mode)*/

#define FAST_PWM_MODE_SELECTOR         Null


/*	NORMAL_OPERATION                    >>        (OC1A/OC1B disconnected.)
 *  TOGGLE_ON_COMPARE_MATCH_OCR1A             >>       Toggle OC1A on Compare Match, OC1B disconnected (normal port operation)
 *  TOGGLE_ON_COMPARE_MATCH_ICR1			  >>       Fast PWM  Toggle OC1A on Compare Match, OC1B disconnected (normal port operation)
 *  CLEAR_ON_COMPARE_MATCH	            >>        Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare match when downcounting.
 *  SET_ON_COMPARE_MATCH                >>        Set OC1A/OC1B on compare match when upcounting. Clear OC1A/OC1B on compare match when downcounting.*/

#define PHASE_CORRECT_SELECTOR       Null




#define TIMER_INTIAL_VALUE    0


/*incase of compare mde according to your selected channels A OR B OR BOTH   */
/*on compare change */
/*OCR duty cycle selction incase of pwm mode */
#define OCR1AL__intiailze 5000
#define OCR1BL__intiailze 5000
/*ICR THE TOP value that  counter can reach to for pwm  >>define signal width   */
#define ICR1L__intiailze   10000









#endif /* TIMER1_CONFIG_H_ */
