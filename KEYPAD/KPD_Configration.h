/*
 * KPD_Configration.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#ifndef KPD_CONFIGRATION_H_
#define KPD_CONFIGRATION_H_



#define KPD_Column0_PIN            ZERO
#define KPD_Column1_PIN            ONE
#define KPD_Column2_PIN           TWO
#define KPD_Column3_PIN            THREE

#define KPD_Row0_PIN            FOUR
#define KPD_Row1_PIN            FIVE
#define KPD_Row2_PIN            SIX
#define KPD_Row3_PIN            SEVEN

#define KPD_Row0_PIN_PORT       PORTB_NUM
#define KPD_Row1_PIN_PORT       PORTB_NUM
#define KPD_Row2_PIN_PORT       PORTB_NUM
#define KPD_Row3_PIN_PORT       PORTB_NUM


#define KPD_Column0_PIN_PORT       PORTB_NUM
#define KPD_Column1_PIN_PORT       PORTB_NUM
#define KPD_Column2_PIN_PORT       PORTB_NUM
#define KPD_Column3_PIN_PORT       PORTB_NUM




u8 Local_U8KpdArr[4][4] ={


                                       		{'4','3','2','1'},
	                 	          	        {'3','7','6','5'},
	                 	          	        {'2','+','=','9'},
	                 	          	        {'1','C','-','%'}

						};

u8 Local_U8KpdArr_1[4][4] ={


                                       		{'d','c','b','e'},
	                 	          	        {'8','7','o','f'},
	                 	          	        {'/','+','=','9'},
	                 	          	        {'*','C','-','E'}

						};






#endif /* KPD_CONFIGRATION_H_ */
