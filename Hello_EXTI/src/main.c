/*****************************************/
/* Author  :  Lamees Elbakr              */
/* Version :  V01                        */
/* Date    : 30 Sep 2020                 */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "AFIO_interface.h"

void ahmed (void);

void main (void) {
	/*RCC Initialization  */
	RCC_voidInitSysClock();

	/*Enable GPIOA , AFIO   */
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,0);

    MEXTI_voidSetCallBack(ahmed);

	/* GPIO PINS Direction   */	
	/* A0 ------> INPUT with PULL UP Resistor*/
	MGPI_voidPinMode(GPIOA,0,INPUT_PULL);
	MGPI_voidPinWrite(GPIOA,0,HIGH);
	
	/* OUTPUT PUSH PUll*/
	MGPI_voidPinMode(GPIOA,2,OUTPUT_2MHZ_PP);
 
	/* EXTI0 Initialization */
	 MEXTI_voidInit();                            
//	 MEXTI_voidSetSignalLatch(0,FALLING);

	/*NVIC EXTI0 Enable*/
	MNVIC_VoidEnableInterrupt(6);
	 /* 2 bits for group & 2 bits for sub */
    MNVIC_VoidSetPriority(6,1,0,GROUP5);

    /*Select Interrupt Pin as A0*/
    MAFIO_voidSetEXTIPin(0 , PA);
	


     while(1){
		
	}
	
	
}


void ahmed (void){

	MGPI_voidPinWrite(GPIOA,2,HIGH);
}



