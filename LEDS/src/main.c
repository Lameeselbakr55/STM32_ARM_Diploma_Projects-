/*
 * main.c
 *
 *  Created on: Sep 9, 2020
 *      Author: Lamees
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

#include "Delay.h"

void main (void){
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);


	MGPI_voidPinMode(GPIOA,1,OUTPUT_2MHZ_PP);
//	MGPI_voidPinWrite(GPIOA,1,HIGH);       // SW PULL  UP

	//u8 GLB_u8SW;
	while(1){
	/*	GLB_u8SW= MGPI_u8PinRead(GPIOA,1);
        if(GLB_u8SW==0)
		HLED_voidON(GPIOA,0);
        else
		HLED_voidOFF(GPIOA,0);
		*/
		MGPI_voidPinWrite(GPIOA,1,HIGH);       // SW PULL  UP
		Delay();
		MGPI_voidPinWrite(GPIOA,1,LOW);       // SW PULL  UP
		Delay();
	}

}

