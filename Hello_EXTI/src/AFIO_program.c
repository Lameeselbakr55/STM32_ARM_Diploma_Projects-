/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 9 Sep 2020                           */
/* Version    :  V_01                                */
/*****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"




void MAFIO_voidSetEXTIPin(u8 Copy_u8Line , u8 Copy_u8PortMap){
	
	u8 Local_u8RegIndx=0;
	
	if(Copy_u8Line<=3){
		Local_u8RegIndx=0;
	}
	else if(Copy_u8Line <=7)
    {
		Local_u8RegIndx=1;
	}	
	else if(Copy_u8Line <=7)
    {
		Local_u8RegIndx=1;
		Copy_u8Line-=4;
	}
	else if(Copy_u8Line <=11)
    {
		Local_u8RegIndx=2;
		Copy_u8Line-=8;
	}	
	else if(Copy_u8Line <=15)
    {
		Local_u8RegIndx=3;
		Copy_u8Line-=12;
	}
	
	AFIO->EXTICR[Local_u8RegIndx] &= ~((0b1111) << (Copy_u8Line*4));                 //Reset
	AFIO->EXTICR[Local_u8RegIndx]  |=((Copy_u8PortMap) << (Copy_u8Line*4));         

}       

