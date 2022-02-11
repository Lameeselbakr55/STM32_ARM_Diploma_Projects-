/*
 * main.c
 *
 *  Created on: Sep 14, 2020
 *      Author: Lamees
 */



#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "STP_interface.h"



void main (void) {
	RCC_voidInitSysClock();
 RCC_voidEnableClock(RCC_APB2,2);


 MGPI_voidPinMode(GPIOA,0,OUTPUT_2MHZ_PP);
 MGPI_voidPinMode(GPIOA,1,OUTPUT_2MHZ_PP);
 MGPI_voidPinMode(GPIOA,2,OUTPUT_2MHZ_PP);


 MSTK_voidInit();

 u8 i=0;

	while(1){

		for(i=0;i<8;i++){
		 HSTP_voidSendSychronous(1<<i);
         MSTK_voidSetBusyWait(300000);
		}
	}

}
