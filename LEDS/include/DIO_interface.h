/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 28 Sep 2020                          */
/* Version    :  V_02                                */
/*****************************************************/


#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define GPIOA   0
#define GPIOB   1
#define GPIOC   2



#define OUTPUT_10MHZ_PP      0b0001
#define OUTPUT_10MHZ_OD      0b0101
#define OUTPUT_10MHZ_AFPP    0b1001
#define OUTPUT_10MHZ_AFOD    0b1101

#define OUTPUT_2MHZ_PP       0b0010
#define OUTPUT_2MHZ_OD       0b0110
#define OUTPUT_2MHZ_AFPP     0b1010
#define OUTPUT_2MHZ_AFOD     0b1110

#define OUTPUT_50MHZ_PP      0b0011
#define OUTPUT_50MHZ_OD      0b0111
#define OUTPUT_50MHZ_AFPP    0b1011
#define OUTPUT_50MHZ_AFOD    0b1111


#define INPUT_ANALOG         0b0000
#define INPUT_FLOATING       0b0100
#define INPUT_PULL           0b1000

#define HIGH                 1
#define LOW                  0



void MGPI_voidPinMode(u8 copy_u8_port , u8 copy_u8_pin, u8 copy_u8_mode );

void MGPI_voidPinWrite(u8 copy_u8_port , u8 copy_u8_pin, u8 copy_u8_value );

u8 MGPI_u8PinRead(u8 copy_u8_port , u8 copy_u8_pin);



#endif