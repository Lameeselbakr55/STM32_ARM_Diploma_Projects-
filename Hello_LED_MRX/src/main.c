/*
 * main.c
 *
 *  Created on: Sep 13, 2020
 *      Author: Lamees
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"


#include "LED_MRX_interface.h"

u8 DataArray[8]={0, 126, 2, 126, 2, 126, 0, 0};

void main (void){
/*RCC Init and Enable*/
RCC_voidInitSysClock();
RCC_voidEnableClock(RCC_APB2,2);
RCC_voidEnableClock(RCC_APB2,3);


/*Systic  init */
MSTK_voidInit();
HLEDMRX_voidInit();

	while(1){

		HLEDMRX_voidDisplay(DataArray);

	}



}
