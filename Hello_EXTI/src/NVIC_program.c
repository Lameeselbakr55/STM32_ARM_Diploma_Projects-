/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 2 Sep 2020                           */
/* Version    :  V_01                                */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntNumber){           // Function to Enable Interrupt
	if(Copy_u8IntNumber<=31)
	{
		NVIC_ISER0=(1<<Copy_u8IntNumber);    //This instruction = SET_BIT(NVIC_ISER0,Copy_u8IntNumber);   as 0 has no effect
	}
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -=32;               
		NVIC_ISER1=(1<<Copy_u8IntNumber); 	
	}
	else 
	{
		// Return Error
	}
	
}

void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntNumber){         // Function to Disable Interrupt
	if(Copy_u8IntNumber<=31)
	{
		NVIC_ICER0=(1<<Copy_u8IntNumber);   
	}
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -=32;               
		NVIC_ICER1=(1<<Copy_u8IntNumber); 	
	}
	else 
	{
		// Return Error
	}
	
}


void MNVIC_VoidSetPendingFlag(u8 Copy_u8IntNumber){           // Function to Set Pending Flag
	if(Copy_u8IntNumber<=31)
	{
		NVIC_ISPR0=(1<<Copy_u8IntNumber);    //This instruction = SET_BIT(NVIC_ISPR0,Copy_u8IntNumber);   as 0 has no effect
	}
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -=32;               
		NVIC_ISPR1=(1<<Copy_u8IntNumber); 	
	}
	else 
	{
		// Return Error
	}
}

	
void MNVIC_VoidClearPendingFlag(u8 Copy_u8IntNumber){           // Function to Clear Pending Flag
	if(Copy_u8IntNumber<=31)
	{
		NVIC_ICPR0=(1<<Copy_u8IntNumber);    //This instruction = SET_BIT(NVIC_ISPR0,Copy_u8IntNumber);   as 0 has no effect
	}
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -=32;               
		NVIC_ICPR1=(1<<Copy_u8IntNumber); 	
	}
	else 
	{
		// Return Error
	}	
}



u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber){                // Function to Get Active Flag Status
	
	u8 Local_u8Result ;
	
	if(Copy_u8IntNumber<=31)
	{
		Local_u8Result= GET_BIT(NVIC_IABR0,Copy_u8IntNumber);    
	}
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -=32;               
		Local_u8Result= GET_BIT(NVIC_IABR1,Copy_u8IntNumber);    	
	}
	else 
	{
		// Return Error
	}
	return Local_u8Result;
}




void MNVIC_VoidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority ,u32 Copy_u32Group){           // Function to set pririty

// value assigned to IPR
u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority<< ((Copy_u32Group - 0x05fa0300)/256));

// core prephiral 



// External Prephiral 
if (Copy_s8IntID >= 0){
	NVIC_IPR[Copy_s8IntID]=Local_u8Priority<<4;   // AS we want to write in IPR MSB
}
SCB_AIRCR=Copy_u32Group; 

}
