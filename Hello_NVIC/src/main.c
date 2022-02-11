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
#include "NVIC_interface.h"

void main (void){
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);

	MGPI_voidPinMode(GPIOA,0,OUTPUT_2MHZ_PP);
	MGPI_voidPinMode(GPIOA,1,OUTPUT_2MHZ_PP);
	MGPI_voidPinMode(GPIOA,2,OUTPUT_2MHZ_PP);

	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidEnableInterrupt(7);

	MNVIC_voidSetPriority(6,1,0,GROUP5);
	MNVIC_voidSetPriority(7,0,3,GROUP5);

	MNVIC_voidSetPendingFlag(6);


	while(1){
	}
}

void EXTI0_IRQHandler(void){
	MGPI_voidPinWrite(GPIOA,2,HIGH);
	MNVIC_voidSetPendingFlag(7);
	MGPI_voidPinWrite(GPIOA,1,HIGH);
}

void EXTI1_IRQHandler(void){
	MGPI_voidPinWrite(GPIOA,0,HIGH);

}
