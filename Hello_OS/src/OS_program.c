/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 19 Sep 2020                           */
/* Version    :  V_01                                */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"


#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define 	NULL   (void*)0

// Array of Tasks      "Array of Structure" 
static Task OS_Tasks[NUMBER_OF_TASKS]= { NULL }; 

void OS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Periodicity , void (*ptr)(void) ){
	
	OS_Tasks[Copy_u8ID].periodicity = Copy_u16Periodicity;
	OS_Tasks[Copy_u8ID].FPtr = ptr;
		
}

static void Schedular (void){
	volatile u16 Local_u16TickCounts =0;
	for (u8 i =0 ; i < NUMBER_OF_TASKS ; i++ )
	{
		if  ( (Local_u16TickCounts % OS_Tasks[i].periodicity )==0)
		{
			OS_Tasks[i].FPtr();
			
		}
		
	}
	
	Local_u16TickCounts++;
}
void OS_voidStart(void){

	// initialization
	MSTK_voidInit();
	/* Tick = 1 MSec */
	/* HSE = 8MHZ/8 = 1 MHZ ----->  1 uSec */
	MSTK_voidSetIntervalPeriodic(1000,Schedular);

}
