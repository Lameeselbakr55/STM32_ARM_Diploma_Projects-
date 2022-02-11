/*
 * main.c
 *
 *  Created on: Sep 13, 2020
 *      Author: Lamees
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"

#include "image.h"

void main (void){
/*RCC Init and Enable*/
RCC_voidInitSysClock();
RCC_voidEnableClock(RCC_APB2,2);
RCC_voidEnableClock(RCC_APB2,12);                // SPI 1 Enable

/*Pin Init*/
MGPI_voidPinMode(GPIOA,1,OUTPUT_2MHZ_PP) ;      // A0
MGPI_voidPinMode(GPIOA,2,OUTPUT_2MHZ_PP) ;     // RST
MGPI_voidPinMode(GPIOA,5,1001);               // CLK
MGPI_voidPinMode(GPIOA,7,1001) ;             // MOSI

/*Systic  init */
MSTK_voidInit();

/*SPI  init */
MSPI1_voidInit();

/*TFT  init */
HTFT_voidInit();


	while(1){
		HTFT_voidDisplayImage(image);

 }
}
