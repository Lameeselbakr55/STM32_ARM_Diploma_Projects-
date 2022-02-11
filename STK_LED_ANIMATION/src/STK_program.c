/*****************************************/
/* Author  :  Lamees Elbakr              */
/* Version :  V01                        */
/* Date    : 10 Sep 2020                 */
/*****************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

static void (*Callback) (void) ;                // Pointer To Function

static u8 STK_u8ModeOfInterval;            /* Define Variable for interval mode */



void MSTK_voidInit(){
	// Disable SysTick 
    CLR_BIT(STK_CTRL,0);
	
	//Disable Interrupt		
    CLR_BIT(STK_CTRL,1);	
		
	// Apply user clock choice
	#if STK_Clock_Source == AHB
    SET_BIT(STK_CTRL,2);
    #elif STK_Clock_Source == AHB_DIV_BY_8
    CLR_BIT(STK_CTRL,2); 
    #endif
	
		
}



void MSTK_voidSetBusyWait(u32 Copy_u32Ticks){
	u8 Local_u8FlagCounter=0;
	// Put Ticks in Load Register 
	STK_LOAD=Copy_u32Ticks;
	
	//Disable Interrupt
    CLR_BIT(STK_CTRL,1);

	// Enable SysTick (Start Timer) 
    SET_BIT(STK_CTRL,0);


	/* Wait till flag is raised */
	while( (GET_BIT(STK_CTRL,16)) == 0){
		asm("NOP");
	}
	
	/* Stop Timer */
	CLR_BIT(STK_CTRL, 0);
	STK_LOAD = 0;
	STK_VAL  = 0;
}



void MSTK_voidSetIntervalSingle( u32 Copy_u32Ticks, void(*ptr)(void) ){
	
	// Put Ticks in Load Register 	
	STK_LOAD = Copy_u32Ticks;
	
	// Enable SysTick  ( Start Timer )
    SET_BIT(STK_CTRL,0);
	
	//Enable Interrupt		
    SET_BIT(STK_CTRL,1);
	
	// call callback fuction 
	Callback=ptr;

	/* Set Mode to Single */
	STK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	
}







void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void(*ptr)(void) ){
	// Put Ticks in Load Register 	
	STK_LOAD = Copy_u32Ticks;
	
	// Enable SysTick 
    SET_BIT(STK_CTRL,0);
	
	//Enable Interrupt		
    SET_BIT(STK_CTRL,1);
	
	// call callback fuction 
	Callback=ptr;
	
    /* Set Mode to Periodic */
	STK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	
}



void MSTK_voidStopInterval(void){
	STK_LOAD=0;
	STK_VAL = 0;
	/*Disable Timer*/
	CLR_BIT(STK_CTRL, 0);
	/* Disable STK Interrupt */
	CLR_BIT(STK_CTRL, 1);
}

u32  MSTK_u32GetElapsedTime(void){
	return STK_LOAD- STK_VAL;
	
	}
u32  MSTK_u32GetRemainingTime(void){
	return STK_VAL;	
	
	}
	



	
void SysTick_Handler(void){
	volatile u8 Local_u8Temporary;
if (STK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK_CTRL, 1);
	
		/* Stop Timer */
		CLR_BIT(STK_CTRL, 0);
		STK_LOAD = 0;
		STK_VAL  = 0;
	}	
		/* Callback notification */
	Callback();	
	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK_CTRL,16);
}
	


