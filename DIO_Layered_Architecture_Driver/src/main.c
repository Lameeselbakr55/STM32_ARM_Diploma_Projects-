/*
 * main.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Lamees
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "DIO_interface.h"


void main (void){

	 RCC_voidInitSysClock() ;

	 RCC_voidEnableClock (RCC_APB2,2);
	 RCC_voidEnableClock (RCC_APB2,3);
	 RCC_voidEnableClock (RCC_APB2,4);

	 MGPI_voidPinMode(GPIOA , 0, OUTPUT_2MHZ_PP );
	 MGPI_voidPinMode(GPIOA , 1, OUTPUT_2MHZ_PP );
	 MGPI_voidPinMode(GPIOA , 2, OUTPUT_2MHZ_PP );
	 MGPI_voidPinMode(GPIOA , 3, OUTPUT_2MHZ_PP );
	 MGPI_voidPinMode(GPIOA , 4, OUTPUT_2MHZ_PP );
	 MGPI_voidPinMode(GPIOA , 5, OUTPUT_2MHZ_PP );
	 MGPI_voidPinMode(GPIOA , 6, OUTPUT_2MHZ_PP );
	 MGPI_voidPinMode(GPIOA , 7, OUTPUT_2MHZ_PP );
	 MGPI_voidPinMode(GPIOA , 8, OUTPUT_2MHZ_PP );


	 int w = 600;
	 while(1) {

	    MGPI_voidPinWrite(GPIOA  , 0 , HIGH );
	    MGPI_voidPinWrite(GPIOA  , 1 , HIGH );
	    MGPI_voidPinWrite(GPIOA  , 2 , HIGH );
	    MGPI_voidPinWrite(GPIOA  , 3 , HIGH );
	    MGPI_voidPinWrite(GPIOA  , 4 , HIGH );
	    MGPI_voidPinWrite(GPIOA  , 5 , HIGH );
	    MGPI_voidPinWrite(GPIOA  , 6 , HIGH );
	    MGPI_voidPinWrite(GPIOA  , 7 , HIGH );
	    MGPI_voidPinWrite(GPIOA  , 8 , HIGH );
		for(int i = 0 ; i < w ; i++ )
		{
			for(int i = 0 ; i < w ; i++ )
			{
			asm("NOP");
			}
		}


	    MGPI_voidPinWrite(GPIOA  ,0 , LOW );
	    MGPI_voidPinWrite(GPIOA  ,1 , LOW );
	    MGPI_voidPinWrite(GPIOA  ,2 , LOW );
	    MGPI_voidPinWrite(GPIOA  ,3 , LOW );
	    MGPI_voidPinWrite(GPIOA  ,4 , LOW );
	    MGPI_voidPinWrite(GPIOA  ,5 , LOW );
	    MGPI_voidPinWrite(GPIOA  ,6 , LOW );
	    MGPI_voidPinWrite(GPIOA  ,7 , LOW );
	    MGPI_voidPinWrite(GPIOA  ,8 , LOW );

	    for(int i = 0 ; i < w ; i++ )
	    {
	    	for(int i = 0 ; i < w ; i++ )
	    		{
	    		  asm("NOP");
	    		}
	    }
    }

}











