/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 9 Sep 2020                           */
/* Version    :  V_01                                */
/*****************************************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


void MEXTI_voidInit();                            // line and mode initialization 
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);       // Enable External Interrupt
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);     // Disable External Interrupt
void MEXTI_voidSwTrigger(u8 Copy_u8Line);      // sw trigger for int
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line ,u8 Copy_u8SenseMode );
void MEXTI_voidSetCallBack(void (*ptr) (void) );


#define  RISING     0
#define  FALLING    1
#define  ON_CHANGE  2


#endif


