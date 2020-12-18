/*
 * SPI_Private.h
 *
 *  Created on: Dec 17, 2020
 *      Author: Alaa Elnagar
 */


/*
 * SOI_Private.h
 *
 *  Created on: Dec 17, 2020
 *      Author: PC
 */
void __vector_12(void) __attribute__((signal));



#ifndef SOI_PRIVATE_H_
#define SOI_PRIVATE_H_

#define SPI_ENABLE						1
#define SPI_DISABLE						0

#define ENABLE							1
#define DISABLE							0
#define PRESCALLER_BY_2             4
#define PRESCALLER_BY_4             0
#define PRESCALLER_BY_8             5
#define PRESCALLER_BY_16            1
#define PRESCALLER_BY_32            6
#define PRESCALLER_BY_64            2
#define PRESCALLER_BY_128           3


#define CPHA_READ_THEN_WRITE 		    0
#define CPHA_WRITE_THEN_READ  			1


#define CPOL_RISING_LEADING_EDGE			    	0
#define CPOL_FALLING_LEADING_EDGE  			     	1

#define  MASTER					1
#define  SLAVE					0



#define FRAME_FORMATE_MSB		    	0
#define FRAME_FORMATE_LSB			    1


#define SPCR *((volatile u8* )0x2D )
#define SPSR *((volatile u8* )0x2E )
#define SPDR *((volatile u8* )0x2F)







#endif /* SOI_PRIVATE_H_ */
