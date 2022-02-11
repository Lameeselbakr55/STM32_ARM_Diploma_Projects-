/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 8 Aug 2020                           */
/* Version    :  V_01                                */
/*****************************************************/


#ifndef SEV_SEG_PRIVATE_H
#define SEV_SEG_PRIVATE_H


  
void SEV_SEG_voidInit (void);

// Pins ARR
 u8 PINS_ARR[16] = {

	  SEV_SEG_PIN_A,
	  SEV_SEG_PIN_B,
	  SEV_SEG_PIN_C,
	  SEV_SEG_PIN_D,
	  SEV_SEG_PIN_E,
	  SEV_SEG_PIN_F,
	  SEV_SEG_PIN_G,
	  SEV_SEG_PIN_H

};


 // Numbers ARR
 u8 Numbers_ARR[10]= {
         0b00111111 ,        //0
         0b00000110 ,        //1
         0b01011011 ,        //2
         0b01001111 ,        //3
         0b01100110 ,        //4
         0b01101101 ,        //5
         0b01111101 ,        //6
         0b01000111 ,        //7
         0b01111111 ,        //8
         0b01101111          //9
 };

#endif
