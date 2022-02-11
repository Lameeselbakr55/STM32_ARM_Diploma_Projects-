/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 8 Aug 2020                           */
/* Version    :  V_01                                */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"

#include "LED_MRX_interface.h"
#include "LED_MRX_config.h"
#include "LED_MRX_private.h"



void HLEDMRX_voidInit(void)  {
 MGPI_voidPinMode(LED_MRX_ROW0_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_ROW1_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_ROW2_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_ROW3_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_ROW4_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_ROW5_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_ROW6_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_ROW7_PIN, OUTPUT_2MHZ_PP );


 MGPI_voidPinMode(LED_MRX_COL0_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_COL1_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_COL2_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_COL3_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_COL4_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_COL5_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_COL6_PIN, OUTPUT_2MHZ_PP );
 MGPI_voidPinMode(LED_MRX_COL7_PIN, OUTPUT_2MHZ_PP ); 
}

void HLEDMRX_voidDisplay(u8 *copy_u8_Data){
	
    /* Column0  */
	DisableAllCols();
	SetRowsValues(copy_u8_Data[0]);
	MGPI_voidPinWrite(LED_MRX_COL0_PIN, LOW);
	MSTK_voidSetBusyWait(2500);    //2.5MSEC
	
    /* Column1  */
	DisableAllCols();
	SetRowsValues(copy_u8_Data[1]);
	MGPI_voidPinWrite(LED_MRX_COL1_PIN, LOW);
	MSTK_voidSetBusyWait(2500);    //2.5MSEC
		
	/* Column2  */
	DisableAllCols();
	SetRowsValues(copy_u8_Data[2]);
	MGPI_voidPinWrite(LED_MRX_COL2_PIN, LOW);
	MSTK_voidSetBusyWait(2500);    //2.5MSEC
	
	 /* Column3  */
	DisableAllCols();
	SetRowsValues(copy_u8_Data[3]);
	MGPI_voidPinWrite(LED_MRX_COL3_PIN, LOW);
	MSTK_voidSetBusyWait(2500);    //2.5MSEC
	
     /* Column4  */
	DisableAllCols();
	SetRowsValues(copy_u8_Data[4]);
	MGPI_voidPinWrite(LED_MRX_COL4_PIN, LOW);
	MSTK_voidSetBusyWait(2500);    //2.5MSEC
	
	/* Column5  */
	DisableAllCols();
	SetRowsValues(copy_u8_Data[5]);
	MGPI_voidPinWrite(LED_MRX_COL5_PIN, LOW);
	MSTK_voidSetBusyWait(2500);    //2.5MSEC
	
	
	 /* Column6  */
	DisableAllCols();
	SetRowsValues(copy_u8_Data[6]);
	MGPI_voidPinWrite(LED_MRX_COL6_PIN, LOW);
	MSTK_voidSetBusyWait(2500);    //2.5MSEC
	
     /* Column7  */
	DisableAllCols();
	SetRowsValues(copy_u8_Data[7]);
	MGPI_voidPinWrite(LED_MRX_COL7_PIN, LOW);
	MSTK_voidSetBusyWait(2500);    //2.5MSEC
	
	}
	
static void DisableAllCols(void){

  MGPI_voidPinWrite(LED_MRX_COL0_PIN, HIGH);
  MGPI_voidPinWrite(LED_MRX_COL1_PIN, HIGH);
  MGPI_voidPinWrite(LED_MRX_COL2_PIN, HIGH);
  MGPI_voidPinWrite(LED_MRX_COL3_PIN, HIGH);
  MGPI_voidPinWrite(LED_MRX_COL4_PIN, HIGH);
  MGPI_voidPinWrite(LED_MRX_COL5_PIN, HIGH);
  MGPI_voidPinWrite(LED_MRX_COL6_PIN, HIGH); 
  MGPI_voidPinWrite(LED_MRX_COL7_PIN, HIGH);
}

static void SetRowsValues(u8 Copy_u8Value){

 u8 Local_u8BIT;

  Local_u8BIT=GET_BIT(Copy_u8Value,0);
  MGPI_voidPinWrite(LED_MRX_ROW0_PIN, Local_u8BIT);
 
  Local_u8BIT=GET_BIT(Copy_u8Value,1);
  MGPI_voidPinWrite(LED_MRX_ROW1_PIN, Local_u8BIT);

  Local_u8BIT=GET_BIT(Copy_u8Value,2);
  MGPI_voidPinWrite(LED_MRX_ROW2_PIN, Local_u8BIT);

  Local_u8BIT=GET_BIT(Copy_u8Value,3);
  MGPI_voidPinWrite(LED_MRX_ROW3_PIN, Local_u8BIT);

  Local_u8BIT=GET_BIT(Copy_u8Value,4);
  MGPI_voidPinWrite(LED_MRX_ROW4_PIN, Local_u8BIT);

  Local_u8BIT=GET_BIT(Copy_u8Value,5);
  MGPI_voidPinWrite(LED_MRX_ROW5_PIN, Local_u8BIT);

  Local_u8BIT=GET_BIT(Copy_u8Value,6);
  MGPI_voidPinWrite(LED_MRX_ROW6_PIN, Local_u8BIT); 

  Local_u8BIT=GET_BIT(Copy_u8Value,7);
  MGPI_voidPinWrite(LED_MRX_ROW7_PIN, Local_u8BIT);
	
}
