/*
 * main.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Lamees Elbakr
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "EXTI0_interface.h"

#include "NVIC_interface.h"
#include "STK_interface.h"

volatile u8 u8StartFlag=0;
volatile u32 u32FrameData[50]={0};
volatile u8 u8EdgeCounter=0;
volatile u8 u8Data=0;

void voidPlay(void){

	switch (u8Data){
	case 4 :  MGPIO_VidSetPinValue(GPIOA,1,HIGH);    break;
	default :  MGPIO_VidSetPinValue(GPIOA,1,LOW);     break;
	}

}


void voidTakeAction(void){
	u8 i=0;
	u8Data=0;
	if( (u32FrameData[0]>=10000) && (u32FrameData[0]<=14000) ) {
		for(i=0;i<8;i++){
			if( (u32FrameData[17+i] >= 2000 ) && (u32FrameData[17+i] <= 2300) ){
				SET_BIT(u8Data,i);
			}
			else {

				CLR_BIT(u8Data,i);
			}
		}
		voidPlay();

	}

	else {
		// invalid frame
	}

	u8StartFlag=0;
	u32FrameData[0]=0;
	u8EdgeCounter=0;
}

void voidGetFrame(void) {

	if(u8StartFlag==0){        // 1ST Falling edge or not
		//Start Timer
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8StartFlag=1;
	}
	else {
		u32FrameData[u8EdgeCounter]=MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8EdgeCounter++;
	}



}

void main (void) {
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);

	//IO PINS Init
	MGPIO_VidSetPinDirection(GPIOA,0,INPUT_FLOATING);    // A0 input floating
	MGPIO_VidSetPinDirection(GPIOA,1,OUTPUT_SPEED_2MHZ_PP);   //A1 Output PP "RED"
	MGPIO_VidSetPinDirection(GPIOA,2,OUTPUT_SPEED_2MHZ_PP);   //A2 Output PP "GREEN"
	MGPIO_VidSetPinDirection(GPIOA,3,OUTPUT_SPEED_2MHZ_PP);

	// EXTI INIT
	MEXTI_voidSetCallBack(voidGetFrame);
	MEXTI_voidInit();    // A0 EXTI0 Enabled Falling Edge

	// enable EXTI0 from NVIC
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6);    // EXTI0

	//systick init
	MSTK_voidInit();    // Enable systick AHB/8 = 1MHz

	while(1){


	}
}
