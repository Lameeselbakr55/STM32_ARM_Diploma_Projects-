/*
 * main.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Lamees
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"


#include"RCC_interface.h"
#include"DIO_interface.h"

#include"STK_interface.h"
#include"file.h"

#include "DIO_private.h"
volatile u16 i=0;

void voidSetDac(void){
GPIOA_ODR=hakayat_raw[i];
i++;
if(i==32136){
	i=0;
}

}

void main(void){
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2,2);

	 MGPIO_VidSetPinDirection  (GPIOA,0, OUTPUT_SPEED_2MHZ_PP  );
	 MGPIO_VidSetPinDirection  (GPIOA,1, OUTPUT_SPEED_2MHZ_PP  );
	 MGPIO_VidSetPinDirection  (GPIOA,2, OUTPUT_SPEED_2MHZ_PP  );
	 MGPIO_VidSetPinDirection  (GPIOA,3, OUTPUT_SPEED_2MHZ_PP  );
	 MGPIO_VidSetPinDirection  (GPIOA,4, OUTPUT_SPEED_2MHZ_PP  );
	 MGPIO_VidSetPinDirection  (GPIOA,5, OUTPUT_SPEED_2MHZ_PP  );
	 MGPIO_VidSetPinDirection  (GPIOA,6, OUTPUT_SPEED_2MHZ_PP  );
	 MGPIO_VidSetPinDirection  (GPIOA,7, OUTPUT_SPEED_2MHZ_PP  );


	 MSTK_voidInit();
	 MSTK_voidSetIntervalPeriodic(125,voidSetDac);

}

