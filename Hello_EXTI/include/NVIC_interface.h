/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 2 Sep 2020                           */
/* Version    :  V_01                                */
/*****************************************************/


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_VoidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_VoidClearPendingFlag(u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void MNVIC_VoidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority ,u32 Copy_u32Group);


#define GROUP3 0X05FA0300    // 4 bits for group (IPR)--> group
#define GROUP4 0X05FA0400    // 3 bits for group and 1 bit for subgroup
#define GROUP5 0X05FA0500    // 2 bits for group and 2 bit for subgroup
#define GROUP6 0X05FA0600    // 1 bits for group and 3 bit for subgroup
#define GROUP7 0X05FA0700    // 0 bits for group and 4 bit for subgroup



#endif


