/*
 * main.c
 *
 *  Created on: Sep 20, 2020
 *      Author: Lamees
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STk_interface.h"

#include "OS_interface.h"


void LED1 (void);
void LED2 (void);
void LED3 (void);



void main (){
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);

	MGPI_voidPinMode(GPIOA ,0 ,OUTPUT_2MHZ_PP);
	MGPI_voidPinMode(GPIOA ,5 ,OUTPUT_2MHZ_PP);
	MGPI_voidPinMode(GPIOA ,6 ,OUTPUT_2MHZ_PP);


	OS_voidCreateTask(0 , 1000 , LED1);
	OS_voidCreateTask(0 , 2000 , LED2);
	OS_voidCreateTask(0 , 4000 , LED3);


	 OS_voidStart();


	while(1){

	}


}

void LED1 (void){

	static u8 Local_u8Pin0 = 0 ;
	TOG_BIT(Local_u8Pin0,0);
	MGPI_voidPinWrite(GPIOA ,0 ,Local_u8Pin0);

}

void LED2 (void){

	static u8 Local_u8Pin1 = 0 ;
	TOG_BIT(Local_u8Pin1,0);
	MGPI_voidPinWrite(GPIOA ,5 ,Local_u8Pin1);

}

void LED3 (void){

	static u8 Local_u8Pin2 = 0 ;
	TOG_BIT(Local_u8Pin2,0);
	MGPI_voidPinWrite(GPIOA ,6 ,Local_u8Pin2);

}
