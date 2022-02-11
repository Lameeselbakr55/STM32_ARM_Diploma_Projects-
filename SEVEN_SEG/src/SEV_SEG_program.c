/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 8 Aug 2020                           */
/* Version    :  V_01                                */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SEV_SEG_interface.h"
#include "SEV_SEG_config.h"
#include "SEV_SEG_private.h"


void SEV_SEG_voidInit (void){ 

 MGPI_voidPinMode(SEV_SEG_PIN_A, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(SEV_SEG_PIN_B, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(SEV_SEG_PIN_C, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(SEV_SEG_PIN_D, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(SEV_SEG_PIN_E, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(SEV_SEG_PIN_F, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(SEV_SEG_PIN_G, OUTPUT_2MHZ_PP ); 
 MGPI_voidPinMode(SEV_SEG_PIN_H, OUTPUT_2MHZ_PP ); 

}
  


void SEV_SEG_voidDisplay (u8 Copy_u8ComType, u8 Copy_u8Number)
{
u8 Local_u8BIT;
SEV_SEG_voidInit();
switch(Copy_u8ComType) {

case  Cathode :        // write 1 to pins
  switch(Copy_u8Number){

  case 0 :
	  for(int i =0 ; i<=7 ; i++){
	   Local_u8BIT=GET_BIT(Numbers_ARR[0],i);
       MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	  }
   break;
   
   case 1 :   
	 for(int i =0 ; i<=7 ; i++){
	    Local_u8BIT=GET_BIT(Numbers_ARR[1],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	 }
   break;
   
   case 2 :   
	for(int i =0 ; i<=7 ; i++){
		Local_u8BIT=GET_BIT(Numbers_ARR[2],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	 }
   break;
   
   case 3 :   
	for(int i =0 ; i<=7 ; i++){
		Local_u8BIT=GET_BIT(Numbers_ARR[3],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	 }
   break;
   
   case 4 :   
	for(int i =0 ; i<=7 ; i++){
		Local_u8BIT=GET_BIT(Numbers_ARR[4],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	 }
   break;
   
    case 5 :   
    for(int i =0 ; i<=7 ; i++){
    	Local_u8BIT=GET_BIT(Numbers_ARR[5],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
     }
   break;
   
   case 6 :   
	for(int i =0 ; i<=7 ; i++){
		Local_u8BIT=GET_BIT(Numbers_ARR[6],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	 }
   break;
   
    case 7 :   
    for(int i =0 ; i<=7 ; i++){
    	Local_u8BIT=GET_BIT(Numbers_ARR[7],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
   	 }
   break;
   
    case 8 :   
    for(int i =0 ; i<=7 ; i++){
    	Local_u8BIT=GET_BIT(Numbers_ARR[8],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
    	}
   break;
   
   case 9 :   
	for(int i =0 ; i<=7 ; i++){
		Local_u8BIT=GET_BIT(Numbers_ARR[9],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	 }
   break;
   
   default : break;
  }
break;

case Anode :        // write 0 to pins

  switch(Copy_u8Number){

 case 0 :
	  for(int i =0 ; i<=7 ; i++){
	   Local_u8BIT=GET_BIT(Numbers_ARR[0],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],~Local_u8BIT);
	  }
   break;
   
   case 1 :   
	 for(int i =0 ; i<=7 ; i++){
	    Local_u8BIT=GET_BIT(Numbers_ARR[1],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	 }
   break;
   
   case 2 :   
	for(int i =0 ; i<=7 ; i++){
		Local_u8BIT=GET_BIT(Numbers_ARR[2],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	 }
   break;
   
   case 3 :   
	for(int i =0 ; i<=7 ; i++){
		Local_u8BIT=GET_BIT(Numbers_ARR[3],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	 }
   break;
   
   case 4 :   
	for(int i =0 ; i<=7 ; i++){
		Local_u8BIT=GET_BIT(Numbers_ARR[4],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	 }
   break;
   
    case 5 :   
    for(int i =0 ; i<=7 ; i++){
    	Local_u8BIT=GET_BIT(Numbers_ARR[5],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
     }
   break;
   
   case 6 :   
	for(int i =0 ; i<=7 ; i++){
		Local_u8BIT=GET_BIT(Numbers_ARR[6],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	 }
   break;
   
    case 7 :   
    for(int i =0 ; i<=7 ; i++){
    	Local_u8BIT=GET_BIT(Numbers_ARR[7],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
   	 }
   break;
   
    case 8 :   
    for(int i =0 ; i<=7 ; i++){
    	Local_u8BIT=GET_BIT(Numbers_ARR[8],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
    	}
   break;
   
   case 9 :   
	for(int i =0 ; i<=7 ; i++){
		Local_u8BIT=GET_BIT(Numbers_ARR[9],i);
	    MGPI_voidPinWrite(PINS_ARR[i],PINS_ARR[i+1],Local_u8BIT);
	 }
   break;
   
   default : break;
  }
break;

default: break;
}
}
