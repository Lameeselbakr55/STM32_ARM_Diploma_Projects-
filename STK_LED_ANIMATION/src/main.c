/*
 * main.c
 *
 *  Created on: Sep 30, 2020
 *      Author: Lamees
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"


void main (void){
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);   /* Enable GPIOA */

	MGPI_voidPinMode(GPIOA,0,OUTPUT_2MHZ_PP);
	MGPI_voidPinMode(GPIOA,1,OUTPUT_2MHZ_PP);
	MGPI_voidPinMode(GPIOA,2,OUTPUT_2MHZ_PP);
	MGPI_voidPinMode(GPIOA,3,OUTPUT_2MHZ_PP);
	MGPI_voidPinMode(GPIOA,4,OUTPUT_2MHZ_PP);
	MGPI_voidPinMode(GPIOA,5,OUTPUT_2MHZ_PP);
	MGPI_voidPinMode(GPIOA,6,OUTPUT_2MHZ_PP);
	MGPI_voidPinMode(GPIOA,7,OUTPUT_2MHZ_PP);

	MSTK_voidInit();


	while(1){

		/*Ping Pong Animation with 200 msec Led To Led & Total 4 times Senario */
		for (u8 i=0 ; i<4 ; i++){
			for (u8 j=0 ; j<8 ; j++){
				MGPI_voidPinWrite(GPIOA,j,HIGH);
				MSTK_voidSetBusyWait(200000);             /*delay 200 msec*/
			}
			for (s8 j=7 ; j>=0 ; j--){
				MGPI_voidPinWrite(GPIOA,j,LOW);
				MSTK_voidSetBusyWait(200000);             /*delay 200 msec*/
			}
		}

	    /*FAT7E Ya Warda Animation with 200 msec Led To Led & Total 4 times Senario */
     for (u8 i=0 ; i<4 ; i++){
    	 for (u8 j=0  ; j<4   ; j++ ){
    		 u8 k=0 , s=0;
    		 k=j+4;
    		 s=3-j;
		    MGPI_voidPinWrite(GPIOA,s,HIGH);
		    MGPI_voidPinWrite(GPIOA,k,HIGH);
		    MSTK_voidSetBusyWait(1000000);             /*delay 200 msec*/
	      }


	 for (s8 j=7,s=0 ; j>=4,s<=3 ;s++, j--){
	    MGPI_voidPinWrite(GPIOA,s,LOW);
	    MGPI_voidPinWrite(GPIOA,j,LOW);
	    MSTK_voidSetBusyWait(200000);             /*delay 200 msec*/
      }

     }

     for (u8 i=0 ; i<8 ; i++){
 	    MGPI_voidPinWrite(GPIOA,0,HIGH);
 	    MGPI_voidPinWrite(GPIOA,1,HIGH);
 	    MGPI_voidPinWrite(GPIOA,2,HIGH);
 	    MGPI_voidPinWrite(GPIOA,3,HIGH);
 	    MGPI_voidPinWrite(GPIOA,4,HIGH);
 	    MGPI_voidPinWrite(GPIOA,5,HIGH);
 	    MGPI_voidPinWrite(GPIOA,6,HIGH);
 	    MGPI_voidPinWrite(GPIOA,7,HIGH);
	    MSTK_voidSetBusyWait(500000);             /*delay 500 msec*/
 	    MGPI_voidPinWrite(GPIOA,0,LOW);
 	    MGPI_voidPinWrite(GPIOA,1,LOW);
 	    MGPI_voidPinWrite(GPIOA,2,LOW);
 	    MGPI_voidPinWrite(GPIOA,3,LOW);
 	    MGPI_voidPinWrite(GPIOA,4,LOW);
 	    MGPI_voidPinWrite(GPIOA,5,LOW);
 	    MGPI_voidPinWrite(GPIOA,6,LOW);
 	    MGPI_voidPinWrite(GPIOA,7,LOW);
	    MSTK_voidSetBusyWait(500000);             /*delay 500 msec*/
     }

	}

}





