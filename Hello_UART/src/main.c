/*
 * main.c
 *
 *  Created on: Sep 23, 2020
 *      Author: Lamees
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"


#include "UART_interface.h"


void main (void) {
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2 );   // GPIOA
	RCC_voidEnableClock(RCC_APB2,14);   // USART
	/*A9 = TX OUT 50 MHZ*/
    MGPI_voidPinMode(GPIOA,9,OUTPUT_50MHZ_PP);
	/*A10 = RX INPUT Floating 50 MHZ*/
    MGPI_voidPinMode(GPIOA,10,INPUT_FLOATING);
    MGPI_voidPinMode(GPIOA,9,OUTPUT_2MHZ_PP);

	MUART1_voidInit();
	u8 x =0;

	while(1){

		MUART1_voidTransmit("97");
		x = MUART1_u8Recieve();
		if(x=='5'){
		    MGPI_voidPinWrite(GPIOA,0,HIGH);
		}
		else if (x=='R') {
			MGPI_voidPinWrite(GPIOA,0,LOW);

		}

	}
}



