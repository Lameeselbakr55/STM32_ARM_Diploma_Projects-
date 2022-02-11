/*****************************************/
/* Author  :  Lamees Elbakr              */
/* Version :  V01                        */
/* Date    : 22 Sep 2020                 */
/*****************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void MUART1_voidInit(void){
	
	/*9600   baud rate  BRR=0X341 */
	MUART1 -> BRR = 0x341;
	/*
	1- Enable Rx 
	2- Enable Tx
	3- Enable UART 
	*/
    SET_BIT(MUART1 -> CR1, 2 );	
    SET_BIT(MUART1 -> CR1, 3 );	
    SET_BIT(MUART1 -> CR1, 13);		

	/*Clear Status Register */
    MUART1 -> SR=0;
}
void MUART1_voidTransmit(u8 Copy_u8Arr[]){
	u8 i =0;
	while(Copy_u8Arr[i] != '\0'){
		MUART1 -> DR = Copy_u8Arr[i];
		/* Wait till transmission complete */
		while(GET_BIT(MUART1 -> SR,6)==0);
		/* while(((UART1 -> SR) & 0x40 )==0);*/
	    i++;
	} 
}		 
	

u8   MUART1_u8Recieve(void){
	
	while(GET_BIT(MUART1 -> SR,5)==0);
	return (0xFF & (MUART1 -> DR)) ;       // MASKING WITH 0xFF TO GET 8 BIT DATA ONLY
	
}

