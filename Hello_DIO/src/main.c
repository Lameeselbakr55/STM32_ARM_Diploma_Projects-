/*
 * main.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Lamees
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


#define PortA_CRL (*(u32*)0x40010800)
#define PortA_ODR (*(u32*)0x4001080C)

void main (void){
	 RCC_voidInitSysClock() ;
	 RCC_voidEnableClock (RCC_APB2,2);

	 while(1) {

		 PortA_CRL= 0x00000022;
		 PortA_ODR =0x00000011;



    }




}
