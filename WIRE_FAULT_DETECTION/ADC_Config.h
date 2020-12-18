/*
 * ADC_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*

1-          SINGLE								1
2-          INTERRUPT							2




3-          ANALOG_COMPARATOR					3
4-          EXIT0_REQUIST						4
5-          TIMR0_COMP_MATCH					5
6-          TIMR0_OVER_FLOW						6
7-          TIMR1_COMP_MATCH					7
8-          TIMR1_OVER_FLOW						8
9-          TIMR1_CAPTURE_EVENT					9

*/





/*CONVERSSION FINISHING SELECTION SINGLE (SUPER LOOP) OR INTERRUPT*/
#define	 CONVERSSION				SINGLE

				/**/
#define  INTERRUPT_SOURCE           TIMR1_COMP_MATCH





#endif /* ADC_CONFIG_H_ */
