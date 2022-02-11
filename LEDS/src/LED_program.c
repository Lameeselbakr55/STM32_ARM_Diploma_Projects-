/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 9 Sep 2020                           */
/* Version    :  V_01                                */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

#include "Delay.h"


void HLED_voidON (u8 Copy_u8Port , u8 Copy_u8Pin){
	MGPI_voidPinMode( Copy_u8Port, Copy_u8Pin  , OUTPUT_2MHZ_PP);
	MGPI_voidPinWrite( Copy_u8Port, Copy_u8Pin  , HIGH);

	}
   
void HLED_voidOFF (u8 Copy_u8Port , u8 Copy_u8Pin){
	MGPI_voidPinMode( Copy_u8Port, Copy_u8Pin  , OUTPUT_2MHZ_PP);
	MGPI_voidPinWrite( Copy_u8Port, Copy_u8Pin  , LOW);
	}
   

void HLED_voidTOGGLE (u8 Copy_u8Port , u8 Copy_u8Pin){
	MGPI_voidPinMode( Copy_u8Port, Copy_u8Pin  , OUTPUT_2MHZ_PP);
	MGPI_voidPinWrite( Copy_u8Port, Copy_u8Pin  , HIGH);
    Delay();
    MGPI_voidPinWrite( Copy_u8Port, Copy_u8Pin  , LOW);
    Delay();
	}
   

