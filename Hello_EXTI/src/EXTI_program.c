/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 9 Sep 2020                           */
/* Version    :  V_01                                */
/*****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#define 	NULL   (void*)0
static void (*EXTT0_Callback) (void) = NULL;


void MEXTI_voidInit()  {          // line and mode initialization 
    #if EXTI_MODE == RISING
        SET_BIT(EXTI->RTSR , EXTI_LINE);
		
	#elif EXTI_MODE == FALLING
        SET_BIT(EXTI->FTSR , EXTI_LINE);
		
	#elif EXTI_MODE == ON_CHANGE	
        SET_BIT(EXTI->RTSR , EXTI_LINE);   
        SET_BIT(EXTI->FTSR , EXTI_LINE);
		
	#else
		#error "Wrong Mode and Line Choice"
    #endif
	
	// Enable External Interrupt
	SET_BIT(EXTI->IMR , EXTI_LINE);
}




void MEXTI_voidEnableEXTI(u8 Copy_u8Line) {     // Enable External Interrupt
    SET_BIT(EXTI->IMR , Copy_u8Line);

}

void MEXTI_voidDisableEXTI(u8 Copy_u8Line){    // Disable External Interrupt
    CLR_BIT(EXTI->IMR , Copy_u8Line);

}


void MEXTI_voidSwTrigger(u8 Copy_u8Line){      // sw trigger for INT
    SET_BIT(EXTI->SWIER , Copy_u8Line);

 }
 
 
 void MEXTI_voidSetSignalLatch(u8 Copy_u8Line ,u8 Copy_u8SenseMode )  {          // line and mode in runtime
    switch(Copy_u8SenseMode) {
	case RISING    :  SET_BIT(EXTI->RTSR , Copy_u8Line);            break;
	case FALLING   :  SET_BIT(EXTI->FTSR , Copy_u8Line);            break;
    case ON_CHANGE :  SET_BIT(EXTI->RTSR , Copy_u8Line);   
                      SET_BIT(EXTI->FTSR , Copy_u8Line);            break;
    }
	SET_BIT(EXTI->IMR , Copy_u8Line);

 }
 
  
 void MEXTI_voidSetCallBack(void (*ptr) (void) )  {
	EXTT0_Callback=ptr;
 }
 
 
 void EXTI0_IRQHandler (void){
	EXTT0_Callback(); 
	 // clear pending bit
	SET_BIT(EXTI->PR , 0);
	 
 }
