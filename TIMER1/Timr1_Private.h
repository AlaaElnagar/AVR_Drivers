/*
 * Timr1_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#ifndef TIMR1_PRIVATE_H_
#define TIMR1_PRIVATE_H_


/*Timer/Counter1Control Register B –>>>>>>>>>TCCR1B*/
#define TCCR1A  *((volatile u8*)  0X4F)
#define TCCR1B  *((volatile u8*)  0X4E)


/*Timer/Counter1Control Register A –CCR1A*/
#define OCR1AL                                  *((volatile u16*)  0X4A)

#define OCR1AH                                  *((volatile u8* )  0X4B)

#define OCR1BL                                  *((volatile u16*)  0X48)
#define OCR1BH                                  *((volatile u8* )  0X49)


#define ICR1L                                   *((volatile u16*)  0X46)
#define ICR1H                                   *((volatile u8* )  0X47)

#define TCNT1L                                  *((volatile u16*)  0x4C)

#define TCNT1H                                  *((volatile u8* )  0x4D)
	/*Timer/Counter1Interrupt Mask  Register –( –>>>>>>>>> TIMSK)*/
#define TIMSK                                   *((volatile u8* )  0x59)
   /*Timer/Counter1Interrupt Flag Register –( –>>>>>>>>> TIFR)*/

#define TIFR                                    *((volatile u8* )  0x58)

#define Null							0


/*capture event */
void __vector_6(void) __attribute__((signal));
/*Capture match*/
void __vector_7(void) __attribute__((signal));
/*compare match*/
void __vector_8(void) __attribute__((signal));
/*over flow */
void __vector_9(void) __attribute__((signal));


/*------------------------------------------------------------------------*/


							/*Timer/Counter1Control Register A –>>>>>>>>>TCCR1A*/

/*• Bit 7:6 – COM1A1:0: Compare Output Mode for Compare unit A*/
#define  COM1A1_BIT_TCCR1A																	    7
#define  COM1A0_BIT_TCCR1A																		6
/*Bit 5:4 – COM1B1:0: Compare Output Mode for Compare unit B*/
#define  COM1B1_BIT_TCCR1A																	    5
#define  COM1B0_BIT_TCCR1A																		4
/*• Bit 3 – FOC1A: Force Output Compare for Compare unit A*/
#define  FOC1A_BIT_TCCR1A																		3
/*• Bit 2 – FOC1B: Force Output Compare for Compare unit B*/
#define  FOC1B_BIT_TCCR1A																		2
/*• Bit 1:0 – WGM11:0: Waveform Generation Mode*/
#define  WGM11_BIT_TCCR1A	                                                                    1
#define  WGM10_BIT_TCCR1A                                                                        0




							/*Timer/Counter1Control Register B –>>>>>>>>>TCCR1B*/

/*• Bit 7 – ICNC1: Input Capture Noise Canceler*/
#define  ICNC1_BIT_TCCR1B																		7
/*• Bit 6 – ICES1: Input Capture Edge Select*/
#define  ICES1_BIT_TCCR1B																		6
/*Bit 5:4 – COM1B1:0: Compare Output Mode for Compare unit B*/
/*bit five is resrved bit */
/*• Bit 4:3 – WGM13:2: Waveform Generation Mode*/
#define  WGM13_BIT_TCCR1B																		4
/*• Bit 3 – FOC1A: Force Output Compare for Compare unit A*/
#define  WGM12_BIT_TCCR1B																		3
/*• Bit 2:0 – CS12:0: Clock Select*/
#define  CS12_BIT_TCCR1B																		2
#define  CS11_BIT_TCCR1B	                                                                    1
#define  CS10_BIT_TCCR1B                                                                        0



						/*Timer/Counter1Interrupt Mask  Register –( –>>>>>>>>> TIMSK)*/


/*• Bit 5 – TICIE1: Timer/Counter1, Input Capture Interrupt Enable*/
#define  TICIE1_BIT_TIMSK																		5
/*• Bit 4 – OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable*/
#define  OCIE1A_BIT_TIMSK																		4
/*• Bit 3 – OCIE1B: Timer/Counter1, Output Compare B Match Interrupt Enable*/
#define  OCIE1B_BIT_TIMSK																		3
/*•  Bit 2 – TOIE1: Timer/Counter1, Overflow Interrupt Enable*/
#define  TOIE1_BIT_TIMSK																		2



					/*Timer/Counter1Interrupt Flag Register –( –>>>>>>>>> TIFR)*/

/*• Bit 5 – ICF1: Timer/Counter1, Input Capture Flag*/
#define  ICF1_BIT_TIFR																       		5
/*• Bit 4 – OCF1A: Timer/Counter1, Output Compare A Match Flag*/
#define  OCF1A_BIT_TIFR																		    4
/*• Bit 3 – OCF1B: Timer/Counter1, Output Compare B Match Flag*/
#define  OCF1B_BIT_TIFR																		    3
/*• Bit 2 – TOV1: Timer/Counter1, Overflow Flag*/
#define  TOV1_BIT_TIFR															    		    2


/*SELECT_CLOCK >>SELECT ONE OF THE FOLLOWING */

#define NO_CLOCK_SOURCE														0
#define NO_PRESCALING														11
#define DIVIDE_BY_8_PRESCALING												12
#define DIVIDE_BY_64_PRESCALING												13
#define DIVIDE_BY_256_PRESCALING											14
#define DIVIDE_BY_1024_PRESCALING											15
#define EXTERNAL_FALLING_EDGE												16
#define EXTERNAL_RISING_EDGE												17


/***********************************/
#define NON_PWM_MODE	          				18
#define FAST_PWM_MODE	          				19
#define PHASE_CORRECT_MODE	      			20
/*********************************/


#define   NORMAL_OPERATION     	  						21
#define   TOGGLE_ON_COMPARE_MATCH                       22
#define  TOGGLE_ON_COMPARE_MATCH_ICR1L					25
#define   CLEAR_ON_COMPARE_MATCH	                    23
#define   SET_ON_COMPARE_MATCH                          24



#define CHANEL_A  				25
#define CHANEL_B                26
#define CHANEL_A_AND_B          27

























































#endif /* TIMR1_PRIVATE_H_ */
