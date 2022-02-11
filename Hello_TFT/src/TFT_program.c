/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 21 Sep 2020                           */
/* Version    :  V_01                                */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"


#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"




void HTFT_voidInit(void) {
	/*Reset Pulse*/
    MGPI_voidPinWrite(TFT_RST_PIN,HIGH);    	
	MSTK_voidSetBusyWait(100);
    MGPI_voidPinWrite(TFT_RST_PIN,LOW);    	
	MSTK_voidSetBusyWait(1);
	MGPI_voidPinWrite(TFT_RST_PIN,HIGH);    	
	MSTK_voidSetBusyWait(100);
	MGPI_voidPinWrite(TFT_RST_PIN,LOW);    	
	MSTK_voidSetBusyWait(100);		
	MGPI_voidPinWrite(TFT_RST_PIN,HIGH);    	
	MSTK_voidSetBusyWait(120000);	
	

	/* Sleep OUT Command */
	voidWriteCommand(0x11);
	
	/* Wait 150 msec */
	MSTK_voidSetBusyWait(150000);		
	
	/* Color Mode Command */
	voidWriteCommand(0x3A);
    voidWriteData   (0x05);

	/* Dispay ON Command */
	voidWriteCommand(0x29);	
}
void HTFT_voidDisplayImage(const u16 *copy_u8_Image){
	u16 Counter =0 ;
	/*Set X address*/
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	/*Set Y address*/
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);
	
	/*RAM Write*/
	voidWriteCommand(0x2C);
     for (Counter=0 ;Counter<20480 ; Counter++) {
    	// Write high byte
    	 voidWriteData(copy_u8_Image[Counter]>>8);
    	// write low byte
    	 voidWriteData(copy_u8_Image[Counter]&0x00ff);

     }
	
}


static voidWriteCommand (u8 Copy_u8Command) {
u8 Loal_u8Temp=0;	
	/* Set A0  Pin to LOW*/
    MGPI_voidPinWrite(TFT_A0_PIN,LOW);
	
	/* Send Command over SPI*/
    MSPI1_voidSendReceiveSynch(Copy_u8Command , & Loal_u8Temp);
}


static voidWriteData (u8 Copy_u8Data) {
	u8 Loal_u8Temp=0;	
	/* Set A0  Pin to HIGH*/
    MGPI_voidPinWrite(TFT_A0_PIN,HIGH);
	
	/* Send DATA over SPI*/	
    MSPI1_voidSendReceiveSynch(Copy_u8Data , & Loal_u8Temp);

}

