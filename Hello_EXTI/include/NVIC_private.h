/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 2 Sep 2020                           */
/* Version    :  V_01                                */
/*****************************************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


// Registers Definition 

#define NVIC_ISER0    *((u32*)0xE000E100)    // Enable External Interrupts         0  :  30
#define NVIC_ISER1    *((u32*)0xE000E104)    // Enable External Interrupts         32 :  64

#define NVIC_ICER0    *((u32*)0xE000E180)    // Disable External Interrupts        0  :  30
#define NVIC_ICER1    *((u32*)0xE000E184)    // Disable External Interrupts        32 :  64

#define NVIC_ISPR0    *((u32*)0xE000E200)    // Set Pending Flag for Interrupts    0  :  30
#define NVIC_ISPR1    *((u32*)0xE000E204)    // Set Pending Flag for Interrupts    32 :  64

#define NVIC_ICPR0    *((u32*)0xE000E280)    // Clear Pending Flag for Interrupts  0 :  30
#define NVIC_ICPR1    *((u32*)0xE000E284)    // Clear Pending Flag for Interrupts  32 :  64

#define NVIC_IABR0    *((volatile u32*)0xE000E300)    // Active Bit Flag Resister for Interrupts  0 :  30
#define NVIC_IABR1    *((volatile u32*)0xE000E204)    // Active Bit Flag Resister for Interrupts  32 :  64


#define NVIC_IPR       ((volatile u8 *)0xE000E400)     // Interrupt priority register
#define SCB_AIRCR     *((volatile u32*)0xE000ED0C)    // SCB AIRCR Register For group prioity determination


#endif
