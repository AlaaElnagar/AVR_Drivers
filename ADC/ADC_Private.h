/*
 * ADC_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
void __vector_16(void) __attribute__((signal));

#define Null   										0


#define ADMUX	*((volatile u8*)  0x27)
#define ADCSRA	*((volatile u8*)  0x26)
#define ADCH	*((volatile u8*)  0x25)
#define ADCL	*((volatile u8*)  0x24)
#define ADC		*((volatile u16*) 0x24)
#define SFIOR	*((volatile u8*)  0x50)
/*ADC converssion complete interrupt */


#endif /* ADC_PRIVATE_H_ */






#define SINGLE								1
#define INTERRUPT							2
#define ANALOG_COMPARATOR					3
#define EXIT0_REQUIST						4
#define TIMR0_COMP_MATCH					5
#define TIMR0_OVER_FLOW						6
#define TIMR1_COMP_MATCH					7
#define TIMR1_OVER_FLOW						8
#define TIMR1_CAPTURE_EVENT					9


















