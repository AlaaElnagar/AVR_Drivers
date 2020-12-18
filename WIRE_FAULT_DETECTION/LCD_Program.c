/*
 * LCD_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa Elnagar
 */

#include "STD_TYPES.h"
#include "DIO_reference.h"
#include "DIO_Configure.h"

#include "LCD_Configaration.h"
#include "LCD_interface.h"
#include <util/delay.h>


//static u8 LCD_U8GlobalCursorLocation=0;

/************************************************************************************************
 [Function Name]    LCD_VidLatch

 [Description]		Function used to Enable LCD internal circuit to
 	 	 	 	 	 -receive data by setting RS pin to High rising  edge
 	 	 	 	 	 -write   data by setting RS pin to Low  falling edge

 [Args]				void

 [in]				void

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/


void LCD_VidLatch(void){

/*Set EN pin to change from high to low to as falling edge to allow lcd recive data */

DIO_VidSetPinDirection(LCD_E_PORT,LCD_E_PIN,OUTPUT);

/*Set EN PIN to ONE as instruction READ operation */

DIO_VidSetPinValue(LCD_E_PORT, LCD_E_PIN,ONE);
_delay_ms(1);
/*Set EN PIN to ZERRO as instruction WRITE operation */
DIO_VidSetPinValue(LCD_E_PORT, LCD_E_PIN,ZERO);
_delay_ms(1);


}


/************************************************************************************************
 [Function Name]    LCD_VidSendCommand

 [Description]		Function used to send command to lcd internal circuit
 	 	 	 	 	 -
 	 	 	 	 	 -

 [Args]				Copy_U8Command

 [in]				Copy_U8Command : a char which hold lcd command

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/

void LCD_VidSendCommand(u8 Copy_U8Command){
	/*Set RS pin as output */
DIO_VidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
/*Set RW pin as output */
DIO_VidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);

/*Set RS to zerro as instruction write operation */
DIO_VidSetPinValue(LCD_RS_PORT , LCD_RS_PIN,ZERO);
/*Set RW to zerro as instruction write operation */
DIO_VidSetPinValue(LCD_RW_PORT , LCD_RW_PIN,ZERO);


/*Setup of lcd pins directions as output*/

DIO_VidSetPinDirection(LCD_D0_PIN_PORT,LCD_D0_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D1_PIN_PORT,LCD_D1_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D2_PIN_PORT,LCD_D2_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D3_PIN_PORT,LCD_D3_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D4_PIN_PORT,LCD_D4_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D5_PIN_PORT,LCD_D5_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D6_PIN_PORT,LCD_D6_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D7_PIN_PORT,LCD_D7_PIN,OUTPUT);

/*Sending the command to the Pins*/

DIO_VidSetPinValue( LCD_D0_PIN_PORT   ,  LCD_D0_PIN ,    ( Copy_U8Command>>ZERO ) &ONE     );
DIO_VidSetPinValue( LCD_D1_PIN_PORT   ,  LCD_D1_PIN ,    ( Copy_U8Command>>ONE  ) &ONE	   );
DIO_VidSetPinValue( LCD_D2_PIN_PORT   ,  LCD_D2_PIN ,    ( Copy_U8Command>>TWO  ) &ONE	   );
DIO_VidSetPinValue( LCD_D3_PIN_PORT   ,  LCD_D3_PIN ,    ( Copy_U8Command>>THREE) &ONE	   );
DIO_VidSetPinValue( LCD_D4_PIN_PORT   ,  LCD_D4_PIN ,    ( Copy_U8Command>>FOUR ) &ONE	   );
DIO_VidSetPinValue( LCD_D5_PIN_PORT   ,  LCD_D5_PIN ,    ( Copy_U8Command>>FIVE ) &ONE	   );
DIO_VidSetPinValue( LCD_D6_PIN_PORT   ,  LCD_D6_PIN ,    ( Copy_U8Command>>SIX  ) &ONE	   );
DIO_VidSetPinValue( LCD_D7_PIN_PORT   ,  LCD_D7_PIN ,    ( Copy_U8Command>>SEVEN) &ONE	   );
/*Enable lcd to recive command*/
LCD_VidLatch();
}


/*Reading busy flag and finding its contents     */



u8  LCD_U8dReadBusyFlag(){


	//RS low for busy flag read and enable low
	        //RD pin low (for enable circuit)

	// WR connected to read/write pin - high for read

	//LCD PORT  input

	// enable high
	        // short delay



	//asm volatile ("nop");
		//asm volatile ("nop");



	//while E is high, get data from LCD




	/*Set RS pin as output */
DIO_VidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
/*Set RW pin as output */
DIO_VidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
//ENABLE CIRCUIT
DIO_VidSetPinDirection(LCD_E_PORT,LCD_E_PIN,OUTPUT);


//RS low for busy flag read and enable low
DIO_VidSetPinValue(LCD_RS_PORT , LCD_RS_PIN,ZERO);

DIO_VidSetPinValue(LCD_E_PORT, LCD_E_PIN,ZERO);
_delay_ms(1);

/*Set RW to ONE as instruction READ operation */
DIO_VidSetPinValue(LCD_RW_PORT , LCD_RW_PIN,ONE);





/*setting D0 TO D6 AS INPUT TO READ THE BUSY FLAG
 *
 */

DIO_VidSetPinDirection(LCD_D0_PIN_PORT,LCD_D0_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D1_PIN_PORT,LCD_D1_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D2_PIN_PORT,LCD_D2_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D3_PIN_PORT,LCD_D3_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D4_PIN_PORT,LCD_D4_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D5_PIN_PORT,LCD_D5_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D6_PIN_PORT,LCD_D6_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D7_PIN_PORT,LCD_D7_PIN,INPUT);

DIO_VidSetPinValue(LCD_E_PORT, LCD_E_PIN,HIGH);
asm volatile ("nop");
asm volatile ("nop");

//_delay_ms(50);

//LCD_VidLatch();
 u8 Local_U8BusyFlagVal=0;
 //while enable is high  get the reading of DDRAM addresses

Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D0_PIN_PORT,LCD_D0_PIN)<<0;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D1_PIN_PORT,LCD_D1_PIN)<<1;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D2_PIN_PORT,LCD_D2_PIN)<<2;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D3_PIN_PORT,LCD_D3_PIN)<<3;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D4_PIN_PORT,LCD_D4_PIN)<<4;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D5_PIN_PORT,LCD_D5_PIN)<<5;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D6_PIN_PORT,LCD_D6_PIN)<<6;

DIO_VidSetPinValue(LCD_E_PORT, LCD_E_PIN,LOW);

//	// restore other settings

//LCD_VidLatch();

return(Local_U8BusyFlagVal);


}




u8  LCD_U8dReadDDRAM(){


	//RS low for busy flag read and enable low
	        //RD pin low (for enable circuit)

	// WR connected to read/write pin - high for read

	//LCD PORT  input

	// enable high
	        // short delay



	//asm volatile ("nop");
		//asm volatile ("nop");



	//while E is high, get data from LCD




	/*Set RS pin as output */
DIO_VidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
/*Set RW pin as output */
DIO_VidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
//ENABLE CIRCUIT
DIO_VidSetPinDirection(LCD_E_PORT,LCD_E_PIN,OUTPUT);


DIO_VidSetPinValue(LCD_E_PORT, LCD_E_PIN,LOW);
_delay_ms(1);

/*Set RS to ONE as instruction READ operation */
DIO_VidSetPinValue(LCD_RS_PORT , LCD_RS_PIN,HIGH);

DIO_VidSetPinValue(LCD_RW_PORT , LCD_RW_PIN,LOW);




/*setting D0 TO D6 AS INPUT TO READ THE BUSY FLAG
 *
 */

DIO_VidSetPinDirection(LCD_D0_PIN_PORT,LCD_D0_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D1_PIN_PORT,LCD_D1_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D2_PIN_PORT,LCD_D2_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D3_PIN_PORT,LCD_D3_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D4_PIN_PORT,LCD_D4_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D5_PIN_PORT,LCD_D5_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D6_PIN_PORT,LCD_D6_PIN,INPUT);
DIO_VidSetPinDirection(LCD_D7_PIN_PORT,LCD_D7_PIN,INPUT);

DIO_VidSetPinValue(LCD_E_PORT, LCD_E_PIN,HIGH);
asm volatile ("nop");
asm volatile ("nop");

//_delay_ms(50);

//LCD_VidLatch();
 u8 Local_U8BusyFlagVal=0;
 //while enable is high  get the reading of DDRAM addresses

Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D0_PIN_PORT,LCD_D0_PIN)<<0;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D1_PIN_PORT,LCD_D1_PIN)<<1;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D2_PIN_PORT,LCD_D2_PIN)<<2;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D3_PIN_PORT,LCD_D3_PIN)<<3;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D4_PIN_PORT,LCD_D4_PIN)<<4;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D5_PIN_PORT,LCD_D5_PIN)<<5;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D6_PIN_PORT,LCD_D6_PIN)<<6;
Local_U8BusyFlagVal |= DIO_VidGetPinValue(LCD_D6_PIN_PORT,LCD_D6_PIN)<<7;


DIO_VidSetPinValue(LCD_E_PORT, LCD_E_PIN,LOW);

//	// restore other settings

//LCD_VidLatch();

return(Local_U8BusyFlagVal);


}



/************************************************************************************************
 [Function Name]    LCD_VidGoto

 [Description]		Function used to mov to any where in the LCD



 [Args]				Copy_U8Row    Copy_U8Column

 [in]				-Copy_U8Row  zerro for selction of first row
 	 	 	 	 				 one  for selection of second row
 	 	 	 	 	-Copy_U8Column 0 start at first column
 	 	 	 	 				   16 mov to last LCD column


 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/

void LCD_VidGoto(u8 Copy_U8Row,u8 Copy_U8Column){
	//start address for the first line is $80 to $8F and for the second line $C0 to $CF

	/*(Set DDRAM address)      1  AC6 AC5 AC4 AC3 AC2 AC1 AC0
	 *
	 *AC is the address counter which looks at DDRAM
	 *
	 *
	 * */
	u8 Local_Copy_u8ACC=Copy_U8Column;

	if (Copy_U8Row==0){

	LCD_VidSendCommand(0b10000000+Local_Copy_u8ACC);
	}
	else if (Copy_U8Row==1){
	LCD_VidSendCommand(0b10000000+64+Local_Copy_u8ACC);

	}


}



/*right shifting of the whole screen*/
/*			; This is very cool command let screen shift to left  */

/*		This is very cool command let screen shift to right */

void LCD_VidRightScreenShifting(){
	LCD_VidSendCommand(	0b00000101);
}

void LCD_VidLeftScreenShifting(){

	LCD_VidSendCommand(	0b00000111);
}



/************************************************************************************************
 [Function Name]    LCD_VidSendData

 [Description]		Function used to send Data to lcd internal circuit
 	 	 	 	 	 -send the command to all of lcd pins
 	 	 	 	 	 -feature of  to insertion lcd pins at any ports
 	 	 	 	 	 -FEATURE OF CALLING READ BUSY FLAG FUNCTION

 [Args]				Copy_U8Data

 [in]				Copy_U8Data : a char which hold lcd Data

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/






void LCD_VidSendData(s64 Copy_s64Data){



/********************************This section under construction **************/

	//to make sure that u are write in the lcd line one and line two only without writing in the additional rddram memory

	if (LCD_U8dReadBusyFlag()==16){LCD_VidGoto(1,0);}

	else if ( ( LCD_U8dReadBusyFlag()==(64+16) ) ){LCD_VidGoto(0,0);LCD_CLEAR();}

/***********************************************************************/
	/*Set RS pin as output */
DIO_VidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
/*Set RW pin as output */

DIO_VidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);

/*Set RS to ONE as DATA write operation */
DIO_VidSetPinValue(LCD_RS_PORT , LCD_RS_PIN,ONE);
/*Set RW to ZERRO as DATA write operation */
DIO_VidSetPinValue(LCD_RW_PORT , LCD_RW_PIN,ZERO);

/*Setup of lcd pins directions as output*/

DIO_VidSetPinDirection(LCD_D0_PIN_PORT,LCD_D0_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D1_PIN_PORT,LCD_D1_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D2_PIN_PORT,LCD_D2_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D3_PIN_PORT,LCD_D3_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D4_PIN_PORT,LCD_D4_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D5_PIN_PORT,LCD_D5_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D6_PIN_PORT,LCD_D6_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D7_PIN_PORT,LCD_D7_PIN,OUTPUT);

/*Sending the command to the Pins*/


DIO_VidSetPinValue(  LCD_D0_PIN_PORT  ,   LCD_D0_PIN ,    ( Copy_s64Data>>ZERO )   &ONE     );
DIO_VidSetPinValue(  LCD_D1_PIN_PORT  ,   LCD_D1_PIN ,    ( Copy_s64Data>>ONE  )   &ONE	   );
DIO_VidSetPinValue(  LCD_D2_PIN_PORT  ,   LCD_D2_PIN ,    ( Copy_s64Data>>TWO  )   &ONE	   );
DIO_VidSetPinValue(  LCD_D3_PIN_PORT  ,   LCD_D3_PIN ,    ( Copy_s64Data>>THREE)   &ONE	   );
DIO_VidSetPinValue(  LCD_D4_PIN_PORT  ,   LCD_D4_PIN ,    ( Copy_s64Data>>FOUR )   &ONE	   );
DIO_VidSetPinValue(  LCD_D5_PIN_PORT  ,   LCD_D5_PIN ,    ( Copy_s64Data>>FIVE )   &ONE	   );
DIO_VidSetPinValue(  LCD_D6_PIN_PORT  ,   LCD_D6_PIN ,    ( Copy_s64Data>>SIX  )   &ONE	   );
DIO_VidSetPinValue(  LCD_D7_PIN_PORT  ,   LCD_D7_PIN ,    ( Copy_s64Data>>SEVEN)   &ONE	   );
/*Enable LCD to receive Data*/
LCD_VidLatch();


}


/************************************************************************************************
 [Function Name]    LCD_VidInit

 [Description]		Function used to intialize internal circuit and make LCD ready
 	 	 	 	 	 -feature of 8BIT mode
 	 	 	 	 	 -feature of 4BIT mode

 [Args]				None

 [in]				None

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/


void LCD_VidInit(void){

_delay_ms(50);

/*set the function set  0  0  1  DL  N  F  X  X
 * 		DL-->> Data line 						1 for 8bit Mode   		0 for 4 bit Mode
 * 		N -->>Number of display lines			1 for 2 line			0 for 1 line
 * 		F -->>Font 								1 for 5*11 dots         0 for 5*8 dots
 */

LCD_VidSendCommand(0b00111000);

_delay_ms(1);

/*set Display on off control   0  0  0  0  1  D  C  B
 * 		D-->> Set on off entire display 		1 for Display on   		0 for Display off
 * 		C-->>Set cursor on off  display			1 for cursor  on		0 for cursor off
 * 		B-->>blinking of cursor position 		1 for Blinking          0 for None
 */

LCD_VidSendCommand(0b00001100);
_delay_ms(1);

/*Clear display*/
LCD_VidSendCommand(0b00000001);

_delay_ms(2);

/*Entry Mode Set   0  0  0  0  0  1  I/D  SH
 * 	I/D-->> allow movement through DDRAM addresses when character code is written or read
 * 						1 for address increase
 * 								The cursor blink mov to right I/D 1
 * 						0 for address decrease
 * 								The cursor blink mov to left  I/D 0
 *
 * 	SH-->>shift display
 *
 * 						1 for <<Screen>>  shift to the right
 * 						0 for <<Screen>> shift to the left
 *
 */

LCD_VidSendCommand(0b00000110);


}





void LCD_CLEAR(){

	LCD_VidSendCommand(0b00000001);


}

/************************************************************************************************
 [Function Name]    LCD_VidSendString

 [Description]		Function used to print string  in the LCD



 [Args]				Copy_U8String

 [in]				-Copy_U8String is a pointer to char which points to array to access it



 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/

/*
void LCD_VidSendString(u16 *Copy_U8String){
u16 *Ptr_U8String=Copy_U8String;
while (*Ptr_U8String){

	LCD_VidSendData(*Ptr_U8String);
	Ptr_U8String++;
}


}
*/



void LCD_String (char *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_VidSendData(str[i]);
	}
}


/************************************************************************************************
 [Function Name]    LCD_VidSendString

 [Description]		Function used to print string  in the LCD



 [Args]				Copy_U8String

 [in]				-Copy_U8String is a pointer to char which points to array to access it



 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/



void LCD_VidNewPattern(){

	u8 Custom_Char[] = {
			0b01110,0b10000,0b10000,0b11111,0b11011,0b11011,0b11111,0b00000 // Code for CGRAM memory space 5

	};

	u8 Custom_Char_2[] = {
			0x06,
			  0x09,
			  0x09,
			  0x06,
			  0x00,
			  0x00,
			  0x00,
			  0x00
	};



	/* Set CGRAM address to move Acc address pointer from DDRAM TO CGRAM  */


	/*(Set CGRAMaddress)      0  1 AC5 AC4 AC3 AC2 AC1 AC0
	 *
	 *AC is the address counter which  NOW WILL looks at CGRAM
	 *
	 *
	 * */

	u8 Local_CopyU8ACC=0;   /*point to first address in CGRAM*/
	LCD_VidSendCommand(0b01000000+Local_CopyU8ACC);

	/*Write your data to CGRAM start with first row        */

for (u8 i=0 ; i<8 ; i++){
	LCD_VidSendData(Custom_Char_2[i]);

}



	/*Set Entry mode set to allow CGRAM Address to be increased automatically    */

	/*Entry Mode Set   0  0  0  0  0  1  I/D  SH
	 * 	I/D-->> allow movement through DDRAM addresses when character code is written or read
	 * 						1 for address increase
	 * 								The cursor blink mov to right I/D 1
	 * 						0 for address decrease
	 * 								The cursor blink mov to left  I/D 0
	 *
	 * 	SH-->>shift display
	 *
	 * 						1 for <<Screen>>  shift to the right
	 * 						0 for <<Screen>> shift to the left
	 *
	 */

	LCD_VidSendCommand(0b00000110);

	/*Set DDRAM ACC to select place to write = GOTO FNCTION   */
  LCD_VidGoto(0,5);


	/*write the pattern address u want to show --->>pattern address start from zerro to 7*/
	/*for (u8 i=0 ; i<8 ; i++){
	LCD_VidSendData(i);
	}
	*/
	LCD_VidSendData(0);



}










void LCD_VidSendInt(s64 Copy_s64Integer){

	//1234
	//65535
	if (!Copy_s64Integer){ LCD_VidSendData('0') ;}

	else{

		s64 Local_Copy_s64Divisor=10000;
		s64 Local_Copy_s64DivResult;
if (Copy_s64Integer<0){LCD_VidSendData('-');Copy_s64Integer*=-1;}

while(Copy_s64Integer){


			while (Copy_s64Integer<Local_Copy_s64Divisor){

				Local_Copy_s64Divisor/=10;
			}

			Local_Copy_s64DivResult=Copy_s64Integer/Local_Copy_s64Divisor;
			LCD_VidSendData('0'+Local_Copy_s64DivResult);
			Copy_s64Integer%=Local_Copy_s64Divisor;
		}
	}
}


/*for reading from keyboard */



void LCD_VidVBackSpace(u16 Copy_U16KeyBoardPress){
/*127 is backspace asci */
	if (Copy_U16KeyBoardPress==127){

	if (LCD_U8dReadBusyFlag()>=7 && LCD_U8dReadBusyFlag()<16){
		/*For left shifting for*/
		LCD_VidSendCommand(	0b00000100);
		//LocalEneredElementsArr[LCD_U8dReadBusyFlag()]=0;
		LCD_VidGoto(0,LCD_U8dReadBusyFlag());
		/*   LCD_VidGoto(0,LCD_U8dRedBusyFlag());*/
		LCD_VidSendData(' ');
		/*back to left shifting for*/
		LCD_VidSendCommand(	0b00000110);
	}

	else if (LCD_U8dReadBusyFlag()>=70 ){
		/*For left shifting for*/
		LCD_VidSendCommand(	0b00000100);
	//	LocalEneredElementsArr[LCD_U8dReadBusyFlag()]=0;
		LCD_VidGoto(0,LCD_U8dReadBusyFlag());

		/*  LCD_VidGoto(0,LCD_U8dReadBusyFlag());*/
		LCD_VidSendData(' ');
		/*back to left shifting for*/
		LCD_VidSendCommand(	0b00000110);
	}

	else if (LCD_U8dReadBusyFlag()==69){
		/*For left shifting for*/
		LCD_VidSendCommand(	0b00000100);
	//	LocalEneredElementsArr[LCD_U8dReadBusyFlag()]=0;
		LCD_VidGoto(0,16);

		/*  LCD_VidGoto(0,LCD_U8dReadBusyFlag());*/
		LCD_VidSendData(' ');
		/*back to left shifting for*/
		LCD_VidSendCommand(	0b00000110);
	}


}


}








void LCD_VidSendDataFromKeyboard(s64 Copy_s64Data){

	if (LCD_U8dReadBusyFlag()>16){
		Copy_s64Data='*';
	}

/********************************This section under construction **************/

	//to make sure that u are write in the lcd line one and line two only without writing in the additional rddram memory

	if ((LCD_U8dReadBusyFlag()==0) || ( LCD_U8dReadBusyFlag()==(64+16) )){LCD_VidGoto(0,6);}


	else if (LCD_U8dReadBusyFlag()==16){LCD_VidGoto(1,6);}

	//else if ( ( LCD_U8dReadBusyFlag()==(64+16) ) ){LCD_VidGoto(0,6);}



/***********************************************************************/
	/*Set RS pin as output */
DIO_VidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
/*Set RW pin as output */

DIO_VidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);

/*Set RS to ONE as DATA write operation */
DIO_VidSetPinValue(LCD_RS_PORT , LCD_RS_PIN,ONE);
/*Set RW to ZERRO as DATA write operation */
DIO_VidSetPinValue(LCD_RW_PORT , LCD_RW_PIN,ZERO);

/*Setup of lcd pins directions as output*/

DIO_VidSetPinDirection(LCD_D0_PIN_PORT,LCD_D0_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D1_PIN_PORT,LCD_D1_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D2_PIN_PORT,LCD_D2_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D3_PIN_PORT,LCD_D3_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D4_PIN_PORT,LCD_D4_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D5_PIN_PORT,LCD_D5_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D6_PIN_PORT,LCD_D6_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D7_PIN_PORT,LCD_D7_PIN,OUTPUT);

/*Sending the command to the Pins*/




//to mask the password  by writing * to lcd

DIO_VidSetPinValue(  LCD_D0_PIN_PORT  ,   LCD_D0_PIN ,    ( Copy_s64Data>>ZERO )   &ONE     );
DIO_VidSetPinValue(  LCD_D1_PIN_PORT  ,   LCD_D1_PIN ,    ( Copy_s64Data>>ONE  )   &ONE	   );
DIO_VidSetPinValue(  LCD_D2_PIN_PORT  ,   LCD_D2_PIN ,    ( Copy_s64Data>>TWO  )   &ONE	   );
DIO_VidSetPinValue(  LCD_D3_PIN_PORT  ,   LCD_D3_PIN ,    ( Copy_s64Data>>THREE)   &ONE	   );
DIO_VidSetPinValue(  LCD_D4_PIN_PORT  ,   LCD_D4_PIN ,    ( Copy_s64Data>>FOUR )   &ONE	   );
DIO_VidSetPinValue(  LCD_D5_PIN_PORT  ,   LCD_D5_PIN ,    ( Copy_s64Data>>FIVE )   &ONE	   );
DIO_VidSetPinValue(  LCD_D6_PIN_PORT  ,   LCD_D6_PIN ,    ( Copy_s64Data>>SIX  )   &ONE	   );
DIO_VidSetPinValue(  LCD_D7_PIN_PORT  ,   LCD_D7_PIN ,    ( Copy_s64Data>>SEVEN)   &ONE	   );
/*Enable LCD to receive Data*/
LCD_VidLatch();


}

void LCD_KeyBoradNewline(s64 Copy_s64Data){

if(Copy_s64Data==13){
	if (LCD_U8dReadBusyFlag()<17) {
		LCD_VidGoto(1,6);
	}
	else {
		LCD_CLEAR();
		LCD_VidGoto(0,6);


	}


}

}

u8 LocalEneredElementsArr[100]={0};
u8 Local_1_PssWordAllert=48;
u8 Local_U8While_Activator=0;
u8 count1=0;
u8 count2=0;
u8 ToggleEnter=0;
u8 i=6;

u16 LCD_U16keyBoardPassword(u16 Copy_s16Data){

	if (Copy_s16Data!=127  ){
	if ( Copy_s16Data!=13  ){
	LocalEneredElementsArr[LCD_U8dReadBusyFlag()]=Copy_s16Data;

	}
}

	/*LCD_CLEAR();
	LCD_VidGoto(1,0);
	for (u8 i =70 ; i<=75 ; i++){
	LCD_VidSendData(LocalEneredElementsArr[i]);

	}
	LCD_VidGoto(0,0);
	for (u8 i =6 ; i<=9 ; i++){
		LCD_VidSendData(LocalEneredElementsArr[i]);

		}
		*/




	u8 user_array[100]={0};
		user_array[6]='a';
		user_array[7]='a';
		user_array[8]='a';
		user_array[9]='a';

		user_array[71]='a';
		user_array[72]='b';
		user_array[73]='c';
		user_array[74]='d';
		user_array[75]='e';
		user_array[76]='f';

		/*check user with each enter hting*/
if (Copy_s16Data==13){

	ToggleEnter+=1;


	if (ToggleEnter==1){
		for (u8 i =6 ; i<=9 ; i++){

			if (LocalEneredElementsArr[i]==user_array[i])

				count1+=1;
			else{

				break;
			}
		}


	}
		/*check Global_1_PssWordAllert*/

	else if (ToggleEnter==2){

		if (count1==4){

			//LCD_VidGoto(0,6);
			for (u8 i =71 ; i<=76 ; i++){

				if (LocalEneredElementsArr[i]!=user_array[i]){
					 Local_1_PssWordAllert+=1;

					break;
				}

				else{
					count2+=1;
				}
			}
		}
		/*alarm*/



		ToggleEnter=0;

	if (	 Local_1_PssWordAllert>=51){
		 Local_1_PssWordAllert=48;

		//return('f');
	}


	}
		if (count1 ==4 && count2 ==6 ){		count1=0;  count2=0;
		//LCD_VidGoto(0,5);
		/*to clear the password  */

		LCD_VidGoto(0,0);
		LCD_CLEAR();
		LCD_String("welcome To Your");
		LCD_VidGoto(1,5);
		LCD_String(" Home");
		Local_U8While_Activator=0;
		Local_1_PssWordAllert=48;

_delay_ms(1000);

		return('o');




		}



}




	}
























/*Reading busy flag and finding its contents     */

/*READ BUSY FLAG SET   0  0  0  0  0  1  I/D  SH
 * 	BF: IF 1 INDICATES THAT INTERNAL OPERATION IN PROGRESS AND NEXT OPERATION WILL NOT BE ACCEPTED
 * 						1 for address increase
 * 								The cursor blink mov to right I/D 1
 * 						0 for address decrease
 * 								The cursor blink mov to left  I/D 0
 *
 * 	SH-->>shift display
 *
 * 						1 for <<Screen>>  shift to the right
 * 						0 for <<Screen>> shift to the left
 *
 */


/*

void LCD_busy()
{

     LCD_D7   = 1;           //Make D7th bit of LCD as i/p
     LCD_en   = 1;           //Make port pin as o/p
     LCD_rs   = 0;           //Selected command register
     LCD_rw   = 1;           //We are reading

     while(LCD_D7){          //read busy flag again and again till it becomes 0
           LCD_en   = 0;     //Enable H->
L
           LCD_en   = 1;
     }

}





*/








/*

void LCD_VidDisplayShifting(){
	// 0x18 for left scroll or 0xC0 for right scroll:It just like move the whole addresses block left or right “under” the display screen.
	//To get back, we can use the cursor home instruction 0x02 to go back to address 0x00
	//
}

*/





































//RS low for busy flag read and enable low
        //RD pin low (for enable circuit)

// WR connected to read/write pin - high for read

//LCD PORT  input

// enable high
        // short delay



//asm volatile ("nop");
	//asm volatile ("nop");



//while E is high, get data from LCD



// E low (for strobe)
// restore other settings
	//PORTD |= (1<<LCD_RD);   // RD pin high (for enable circuit)
//	PORTD &= ~(1<<LCD_WR);   // WR read/write goes low for write
	//DDRA = 0xFF; //back to output
	//return address and busy flag
	//return address;

















