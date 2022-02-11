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

#include "LED_MRX_interface.h"

u8 DataArray0[8]={0, 0, 0, 0, 126, 64, 64, 64 };  // L
u8 DataArray1[8]={0, 0, 0, 126, 64, 64, 64, 0 };
u8 DataArray2[8]={0, 0, 126, 64, 64, 64, 0, 0 };
u8 DataArray3[8]={0, 126, 64, 64, 64, 0, 0, 0 };
u8 DataArray4[8]={0, 126, 64, 64, 64, 0, 0, 0 };

u8 DataArray5[8]={0, 0, 0, 120, 20, 18, 20, 120};  // A
u8 DataArray6[8]={0, 0, 120, 20, 18, 20, 120, 0};
u8 DataArray7[8]={0, 120, 20, 18, 20, 120, 0, 0};
u8 DataArray8[8]={120, 20, 18, 20, 120, 0, 0, 0};


u8 DataArray9 [8]={0, 0, 0, 126, 4, 124, 4, 124};  // M
u8 DataArray10[8]={0, 0, 126, 4, 124, 4, 124, 0};
u8 DataArray11[8]={0, 126, 4, 124, 4, 124, 0, 0};
u8 DataArray12[8]={126, 4, 124, 4, 124, 0, 0, 0};

u8 DataArray13 [8]={0, 0, 0, 0, 126, 82, 82, 82};  // E
u8 DataArray14 [8]={0, 0, 0, 126, 82, 82, 82, 0};
u8 DataArray15 [8]={0, 0, 126, 82, 82, 82, 0, 0};
u8 DataArray16 [8]={0, 126, 82, 82, 82, 0, 0, 0};
u8 DataArray17 [8]={126, 82, 82, 82, 0, 0, 0, 0};

u8 DataArray18 [8]={0, 0, 0, 0, 126, 82, 82, 82};  // E
u8 DataArray19 [8]={0, 0, 0, 126, 82, 82, 82, 0};
u8 DataArray20 [8]={0, 0, 126, 82, 82, 82, 0, 0};
u8 DataArray21 [8]={0, 126, 82, 82, 82, 0, 0, 0};
u8 DataArray22 [8]={126, 82, 82, 82, 0, 0, 0, 0};

u8 DataArray23 [8]={0, 0, 0, 0, 78, 74, 74, 122};  // S
u8 DataArray24 [8]={0, 0, 0, 78, 74, 74, 122, 0};
u8 DataArray25 [8]={0, 0, 78, 74, 74, 122, 0, 0};
u8 DataArray26 [8]={0, 78, 74, 74, 122, 0, 0, 0};
u8 DataArray27 [8]={78, 74, 74, 122, 0, 0, 0, 0};

u8* SendDataArray [28] ={DataArray0,DataArray1,DataArray2,DataArray3,DataArray4,
DataArray5,DataArray6,DataArray7,DataArray8,DataArray9,DataArray10,DataArray11,
DataArray12,DataArray13,DataArray14,DataArray15,DataArray16,DataArray17,DataArray18,
DataArray19,DataArray20,DataArray21,DataArray22,DataArray23,DataArray24,DataArray25,
DataArray26,DataArray27 };


#define SCROLL_SPEED      100000

void main (void){
/*RCC Init and Enable*/
RCC_voidInitSysClock();
RCC_voidEnableClock(RCC_APB2,2);
RCC_voidEnableClock(RCC_APB2,3);

/*Systic  init */
MSTK_voidInit();
HLEDMRX_voidInit();

	while(1){

		for (u8 i =0 ; i< 27 ; i++){
		  HLEDMRX_voidDisplay(SendDataArray [i]);
		  MSTK_voidSetBusyWait(SCROLL_SPEED);
		}

	}
}
