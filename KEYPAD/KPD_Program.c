/*
 * KPD_Program.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: Alaa elnagar
 *
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_reference.h"
#include "KPD_Configration.h"
#include "LCD_Configaration.h"
#include "DIO_Configure.h"
#include <util/delay.h>
#include "LCD_interface.h"
#include "USART_Interface.h"

u8 KPD_VidSetKey(void){


	LCD_CLEAR();
		LCD_VidGoto(1,0);
		LCD_String ("Pass:");
		LCD_VidGoto(0,0);
		LCD_String ("USER:");

	u8 Local_1_PssWordAllert=48;

/*Define kpd elements */


	// Setting kEYPAD COLUMNS AS OUTPUT
DIO_VidSetPinDirection(  KPD_Column0_PIN_PORT  ,  KPD_Column0_PIN  ,  OUTPUT  );
DIO_VidSetPinDirection(  KPD_Column1_PIN_PORT  ,  KPD_Column1_PIN  ,  OUTPUT  );
DIO_VidSetPinDirection(  KPD_Column2_PIN_PORT  ,  KPD_Column2_PIN  ,  OUTPUT  );
DIO_VidSetPinDirection(  KPD_Column3_PIN_PORT  ,  KPD_Column3_PIN  ,  OUTPUT  );

// Setting kEYPAD ROWS AS INPUT

DIO_VidSetPinDirection(  KPD_Row0_PIN_PORT  ,  KPD_Row0_PIN  ,  INPUT   );
DIO_VidSetPinDirection(  KPD_Row1_PIN_PORT  ,  KPD_Row1_PIN  ,  INPUT   );
DIO_VidSetPinDirection(  KPD_Row2_PIN_PORT  ,  KPD_Row2_PIN  ,  INPUT   );
DIO_VidSetPinDirection(  KPD_Row3_PIN_PORT  ,  KPD_Row3_PIN  ,  INPUT   );

// Setting kEYPAD ROWS AS INPUT PULL UP

DIO_VidSetPinValue   (  KPD_Row0_PIN_PORT  ,  KPD_Row0_PIN  ,  HIGH  );
DIO_VidSetPinValue   (  KPD_Row1_PIN_PORT  ,  KPD_Row1_PIN  ,  HIGH  );
DIO_VidSetPinValue   (  KPD_Row2_PIN_PORT  ,  KPD_Row2_PIN  ,  HIGH  );
DIO_VidSetPinValue   (  KPD_Row3_PIN_PORT  ,  KPD_Row3_PIN  ,  HIGH  );

// Setting kEYPAD COLUMNS  AS HIGH
DIO_VidSetPinValue   (  KPD_Column0_PIN_PORT  ,  KPD_Column0_PIN  ,   HIGH  );
DIO_VidSetPinValue   (  KPD_Column1_PIN_PORT  ,  KPD_Column1_PIN  ,   HIGH  );
DIO_VidSetPinValue   (  KPD_Column2_PIN_PORT  ,  KPD_Column2_PIN  ,   HIGH  );
DIO_VidSetPinValue   (  KPD_Column3_PIN_PORT  ,  KPD_Column3_PIN  ,   HIGH  );

u8 LOCAL_U8CharGen='a'-1;   /*First char before letter a*/
u8 Local_Musk_Flag=0;
u8 LocalEneredElementsArr[100]={0};
u8 Local_U8While_Activator=1;
//Set Column0 as LOW
while (Local_U8While_Activator){



	for (u8 i=0; i<4 ; i++){
		DIO_VidSetPinValue(  KPD_Column0_PIN_PORT  ,  i  ,  LOW  );

		for (u8 j=0; j<4 ; j++)
		{

			/***Uart calling ***/

			u16 x=USART_U16Recive();
				USART_VidTransmit(x);
				/*make sure that x not backspace or enter hit button */
			if (x!=127  ){
				if (x!=13  ){
				{LCD_VidSendDataFromKeyboard(x);}
				}
			}

			LCD_KeyBoradNewline(x);
			LCD_VidVBackSpace(x);
			u8 z=LCD_U16keyBoardPassword(x);

		if (z=='o'){
			Local_U8While_Activator=0;
				return('o');
		}
			/****/


			if (!DIO_VidGetPinValue(KPD_Row0_PIN_PORT  ,  j+4 )){





while (!DIO_VidGetPinValue(KPD_Row0_PIN_PORT  , j+4 )){

					_delay_ms(20);
				}


/***************************************************/
				/*WHEN STARTING WITH USER ENTERY AND PRESSING 1 TO ENTER CHARACTERS*/
if (Local_U8KpdArr [i][j]=='1' && Local_Musk_Flag==0 &&LCD_U8dReadBusyFlag()<15){

	if (LOCAL_U8CharGen==('z'+1)){LOCAL_U8CharGen=('a'-1);}
	LCD_VidSendData( LOCAL_U8CharGen+=1);
	/*Encoding screen elements into array*/
	LocalEneredElementsArr[LCD_U8dReadBusyFlag()]= LOCAL_U8CharGen;
}
/*Password writting */
else if (Local_U8KpdArr [i][j]=='1' && Local_Musk_Flag==1 && LCD_U8dReadBusyFlag()<76){
	/*reseting char generator */
	if (LOCAL_U8CharGen==('z'+1)){LOCAL_U8CharGen=('a'-1);}
	LocalEneredElementsArr[LCD_U8dReadBusyFlag()]= ++LOCAL_U8CharGen;
	LCD_VidSendData('*');
	/*encoding password into array*/
/*to delete element */																		}
else if (Local_U8KpdArr [i][j]=='2'){
	if (LCD_U8dReadBusyFlag()>=6 && LCD_U8dReadBusyFlag()<16){
		/*For left shifting for*/
		LCD_VidSendCommand(	0b00000100);
		LocalEneredElementsArr[LCD_U8dReadBusyFlag()]=0;
		LCD_VidGoto(0,LCD_U8dReadBusyFlag());
		/*   LCD_VidGoto(0,LCD_U8dReadBusyFlag());*/
		LCD_VidSendData(' ');
		/*back to left shifting for*/
		LCD_VidSendCommand(	0b00000110);
	}

	else if (LCD_U8dReadBusyFlag()>=69){
		/*For left shifting for*/
		LCD_VidSendCommand(	0b00000100);
		LocalEneredElementsArr[LCD_U8dReadBusyFlag()]=0;
		LCD_VidGoto(0,LCD_U8dReadBusyFlag());

		/*  LCD_VidGoto(0,LCD_U8dReadBusyFlag());*/
		LCD_VidSendData(' ');
		/*back to left shifting for*/
		LCD_VidSendCommand(	0b00000110);
	}
}

/*Sending to second line */
else if (Local_U8KpdArr [i][j]=='3' && Local_Musk_Flag==0){
	LCD_VidGoto(1,5);
	/*to clear the user name */
	for (u8 i=0 ; i<10 ; i++){
		LCD_VidSendData(' ');
	}
	LCD_VidGoto(1,5);
	Local_Musk_Flag=1;
	/*RESET THE LETTERS*/
	LOCAL_U8CharGen='a'-2;
}
/*up to user */
else if (Local_U8KpdArr [i][j]=='3' && Local_Musk_Flag==1){
	/*to clear the password  */
	LCD_VidGoto(0,5);
	for (u8 i=0 ; i<10 ; i++){
		LCD_VidSendData(' ');
	}

	LCD_VidGoto(1,5);
	/*to clear the password  */
	for (u8 i=0 ; i<10 ; i++){

		LCD_VidSendData(' ');
	}

	LCD_VidGoto(0,5);

	Local_Musk_Flag=0;
	/*RESET THE LETTERS*/
	LOCAL_U8CharGen='a'-1;

	/*comparing the user of first line */
	u8 user_array[100]={0};
	user_array[6]='a';
	user_array[7]='a';
	user_array[8]='a';
	user_array[9]='a';

	user_array[70]='a';
	user_array[71]='b';
	user_array[72]='c';
	user_array[73]='d';
	user_array[74]='e';
	user_array[75]='f';
	u8 count1=0;
	u8 count2=0;


	for (u8 i =6 ; i<=9 ; i++){

		if (LocalEneredElementsArr[i]==user_array[i])

			count1+=1;
		else{
			 Local_1_PssWordAllert+=1;
			 LCD_VidGoto(0,14);
						 LCD_VidSendData(Local_1_PssWordAllert);
						 LCD_VidGoto(0,5);
			break;
		}
	}


	/*check Global_1_PssWordAllert*/


	if (count1==4){
		LCD_VidGoto(0,6);
		for (u8 i =70 ; i<=75 ; i++){

			LCD_VidSendData(LocalEneredElementsArr[i]);
			if (LocalEneredElementsArr[i]!=user_array[i]){
				 Local_1_PssWordAllert+=1;
				 LCD_VidGoto(0,14);
				 LCD_VidSendData(Local_1_PssWordAllert);
				 LCD_VidGoto(0,5);

				break;
			}

			else{
				count2+=1;
			}
		}
	}
	/*alarm*/





	if (count1 ==4 && count2 ==5 ){		count1=0;  count2=0;
	LCD_VidGoto(0,5);
	/*to clear the password  */
	for (u8 i=0 ; i<10 ; i++){

		LCD_VidSendData(' ');
	}
	LCD_VidGoto(0,0);
	LCD_CLEAR();
	LCD_String("welcome To Your");
	LCD_VidGoto(1,5);
	LCD_String(" Home");
	Local_U8While_Activator=0;
	Local_1_PssWordAllert=0;
	}




}
/*reset a*/
else if (Local_U8KpdArr [i][j]=='4'){LOCAL_U8CharGen='a'-1;}


//recording password


/***************************************************/




			}
		}
		DIO_VidSetPinValue(KPD_Column0_PIN_PORT  ,  i  ,  HIGH);
	}

	if (Local_1_PssWordAllert>51){
		Local_U8While_Activator=0;

		LCD_CLEAR();
	}
}

if (Local_1_PssWordAllert>(51)){
	return('f');
}
else{
	return('o');
}

}






























u8 KPD_VidSendOrder(void){


	// Setting kEYPAD COLUMNS AS OUTPUT
DIO_VidSetPinDirection(  KPD_Column0_PIN_PORT  ,  KPD_Column0_PIN  ,  OUTPUT  );
DIO_VidSetPinDirection(  KPD_Column1_PIN_PORT  ,  KPD_Column1_PIN  ,  OUTPUT  );
DIO_VidSetPinDirection(  KPD_Column2_PIN_PORT  ,  KPD_Column2_PIN  ,  OUTPUT  );
DIO_VidSetPinDirection(  KPD_Column3_PIN_PORT  ,  KPD_Column3_PIN  ,  OUTPUT  );

// Setting kEYPAD ROWS AS INPUT

DIO_VidSetPinDirection(  KPD_Row0_PIN_PORT  ,  KPD_Row0_PIN  ,  INPUT   );
DIO_VidSetPinDirection(  KPD_Row1_PIN_PORT  ,  KPD_Row1_PIN  ,  INPUT   );
DIO_VidSetPinDirection(  KPD_Row2_PIN_PORT  ,  KPD_Row2_PIN  ,  INPUT   );
DIO_VidSetPinDirection(  KPD_Row3_PIN_PORT  ,  KPD_Row3_PIN  ,  INPUT   );

// Setting kEYPAD ROWS AS INPUT PULL UP

DIO_VidSetPinValue   (  KPD_Row0_PIN_PORT  ,  KPD_Row0_PIN  ,  HIGH  );
DIO_VidSetPinValue   (  KPD_Row1_PIN_PORT  ,  KPD_Row1_PIN  ,  HIGH  );
DIO_VidSetPinValue   (  KPD_Row2_PIN_PORT  ,  KPD_Row2_PIN  ,  HIGH  );
DIO_VidSetPinValue   (  KPD_Row3_PIN_PORT  ,  KPD_Row3_PIN  ,  HIGH  );

// Setting kEYPAD COLUMNS  AS HIGH
DIO_VidSetPinValue   (  KPD_Column0_PIN_PORT  ,  KPD_Column0_PIN  ,   HIGH  );
DIO_VidSetPinValue   (  KPD_Column1_PIN_PORT  ,  KPD_Column1_PIN  ,   HIGH  );
DIO_VidSetPinValue   (  KPD_Column2_PIN_PORT  ,  KPD_Column2_PIN  ,   HIGH  );
DIO_VidSetPinValue   (  KPD_Column3_PIN_PORT  ,  KPD_Column3_PIN  ,   HIGH  );



	u8 Local_U8Return='a';

	//Set Column0 as LOW

		for ( u8 i=0; i<4 ; i++){
			DIO_VidSetPinValue(  KPD_Column0_PIN_PORT  ,  i  ,  LOW  );

			for ( u8 j=0; j<4 ; j++)
			{
				if (!DIO_VidGetPinValue(KPD_Row0_PIN_PORT  ,  j+4 )){

					Local_U8Return=Local_U8KpdArr_1 [j][i];

					while (!DIO_VidGetPinValue(KPD_Row0_PIN_PORT  , j+4 )){

						_delay_ms(20);
					}

				}
			}
			DIO_VidSetPinValue(KPD_Column0_PIN_PORT  ,  i  ,  HIGH);

		}

		return( Local_U8Return);


	}




