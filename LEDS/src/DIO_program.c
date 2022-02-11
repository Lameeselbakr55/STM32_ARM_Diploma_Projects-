/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 28 Sep 2020                          */
/* Version    :  V_02                                */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void MGPI_voidPinMode(u8 copy_u8_port , u8 copy_u8_pin, u8 copy_u8_mode ){
	switch(copy_u8_port){
		case GPIOA :
		      if(copy_u8_pin<=7){
				  GPIOA_CRL &=  ~((0b1111)     << (copy_u8_pin*4));
				  GPIOA_CRL |= ((copy_u8_mode) << (copy_u8_pin*4));
			  }
		      else if(copy_u8_pin<=15){
				  copy_u8_pin=copy_u8_pin-8;
			      GPIOA_CRH &=  ~((0b1111)     << (copy_u8_pin*4));
			      GPIOA_CRH |= ((copy_u8_mode) << (copy_u8_pin*4));
		      }
			  break;		
		
		case GPIOB :
		      if(copy_u8_pin<=7){
			      GPIOB_CRL &=  ~((0b1111)     << (copy_u8_pin*4));
			      GPIOB_CRL |= ((copy_u8_mode) << (copy_u8_pin*4));
		      }
		      else if(copy_u8_pin<=15){
			      copy_u8_pin=copy_u8_pin-8;
			      GPIOB_CRH &=  ~((0b1111)     << (copy_u8_pin*4));
			      GPIOB_CRH |= ((copy_u8_mode) << (copy_u8_pin*4));
		      }
		      break;
		      				
		case GPIOC :
		      if(copy_u8_pin<=7){
			      GPIOC_CRL &=  ~((0b1111)     << (copy_u8_pin*4));
			      GPIOC_CRL |= ((copy_u8_mode) << (copy_u8_pin*4));
		      }
		      else if(copy_u8_pin<=15){
			      copy_u8_pin=copy_u8_pin-8;
			      GPIOC_CRH &=  ~((0b1111)     << (copy_u8_pin*4));
			      GPIOC_CRH |= ((copy_u8_mode) << (copy_u8_pin*4));
		      }
		      break;
		  default :  break;
		      		
		
	}
	
	
}

void MGPI_voidPinWrite(u8 copy_u8_port , u8 copy_u8_pin, u8 copy_u8_value ){
	switch(copy_u8_port){
		case GPIOA :
		 if(copy_u8_value==HIGH){
			 GPIOA_BSRR=(1<<copy_u8_pin );
		 }
		 else if(copy_u8_value==LOW){
			 GPIOA_BRR=(1<<copy_u8_pin );
		 }
		break;
		
		case GPIOB :
		 if(copy_u8_value==HIGH){
			 GPIOB_BSRR=(1<<copy_u8_pin );
		 }
		 else if(copy_u8_value==LOW){
			 GPIOB_BRR=(1<<copy_u8_pin );
		 }		
		break;
		
		case GPIOC :
		 if(copy_u8_value==HIGH){
			 GPIOC_BSRR=(1<<copy_u8_pin );
		 }
		 else if(copy_u8_value==LOW){
			 GPIOC_BRR=(1<<copy_u8_pin );
		 }
		break;
		
		default :  break;
		
	}	
}

u8 MGPI_u8PinRead(u8 copy_u8_port , u8 copy_u8_pin){
	u8 LOC_U8Result=0;
	switch(copy_u8_port){
		case GPIOA :
		LOC_U8Result=GET_BIT(GPIOA_IDR , copy_u8_pin );
		break;
		
		case GPIOB :
		LOC_U8Result=GET_BIT(GPIOB_IDR , copy_u8_pin );
		break;
		
		case GPIOC :
		LOC_U8Result=GET_BIT(GPIOC_IDR , copy_u8_pin );
		break;
		
		default :  break;
		
	}
	return LOC_U8Result;
}
