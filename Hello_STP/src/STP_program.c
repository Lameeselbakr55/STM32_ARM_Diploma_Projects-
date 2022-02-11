/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 14 SEP 2020                          */
/* Version    :  V_01                                */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"


#include "STP_interface.h"
#include "STP_config.h"
#include "STP_private.h"

void HSTP_voidSendSychronous(u8 Copy_u8DataToSend){
	s8 Local_u8Counter=0;
	u8 Local_u8Bit;
	for(Local_u8Counter=7 ; Local_u8Counter >=0 ; Local_u8Counter--)
	{
         /*Send bit by bit starting from MSB*/		
		Local_u8Bit= GET_BIT(Copy_u8DataToSend,Local_u8Counter);
		
		MGPI_voidPinWrite(HSTP_SERIAL_DATA,Local_u8Bit);
		

         /*Send Pulse to shift clock*/			
		MGPI_voidPinWrite(HSTP_SHIFT_CLOCK,HIGH);
	    MSTK_voidSetBusyWait(1);		
		MGPI_voidPinWrite(HSTP_SHIFT_CLOCK,LOW);
	    MSTK_voidSetBusyWait(1);		
	}
         /*Send Pulse to Storage clock*/		
		MGPI_voidPinWrite(HSTP_STOGAGE_CLOCK,HIGH);
	    MSTK_voidSetBusyWait(1);		
		MGPI_voidPinWrite(HSTP_STOGAGE_CLOCK,LOW);
	    MSTK_voidSetBusyWait(1);			
	

}


