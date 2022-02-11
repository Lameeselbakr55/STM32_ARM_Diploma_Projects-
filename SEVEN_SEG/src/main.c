/*
 * main.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Lamees
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Delay.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SEV_SEG_interface.h"



void main (void){

	 RCC_voidInitSysClock() ;

	 RCC_voidEnableClock (RCC_APB2,2);
	 RCC_voidEnableClock (RCC_APB2,3);
	 RCC_voidEnableClock (RCC_APB2,4);

	 while(1) {
       for (int i=0 ; i<=9 ; i++){
    	   SEV_SEG_voidDisplay (Cathode, i);
    	   	 Delay ();
                   }
              }
 }













