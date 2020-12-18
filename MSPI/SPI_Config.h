/*
 * SPI_Config.h
 *
 *  Created on: Dec 17, 2020
 *      Author: Alaa Elnagar
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_




/*
		1 - SPI_ENABLE
		2 - SPI_DISABLE
 */

#define SPI_CASE     SPI_ENABLE

/*
  1-  PRESCALLER_BY_2
  2-  PRESCALLER_BY_4
  3-  PRESCALLER_BY_8
  4-  PRESCALLER_BY_16
  5-  PRESCALLER_BY_32
  6-  PRESCALLER_BY_64
  7-  PRESCALLER_BY_128

*/

#define MSPI_CLK_RATE_SELECT    PRESCALLER_BY_64

		//Clk phase selection
/*
		1 -  CPHA_READ_THEN_WRITE
		2 -  CPHA_WRITE_THEN_READ
 */

#define MSPI_CPHA_SELECT    CPHA_WRITE_THEN_READ


//Clk polarity selection
/*
   1  -   CPOL_RISING_LEADING_EDGE
   2  -   CPOL_FALLING_LEADING_EDGE
*/
#define MSPI_CPOL_SELECT   CPOL_RISING_LEADING_EDGE



//Data order
/*
   1  -  FRAME_FORMATE_MSB
   2  -  FRAME_FORMATE_LSB
*/
#define MSPI_FRAME_SELECT  FRAME_FORMATE_LSB


#define MSPI_INTERRUPT_CASE     DISABLE









#endif /* SPI_CONFIG_H_ */
