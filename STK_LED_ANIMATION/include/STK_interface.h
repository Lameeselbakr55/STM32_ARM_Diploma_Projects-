/*****************************************/
/* Author  :  Lamees Elbakr              */
/* Version :  V01                        */
/* Date    : 10 Sep 2020                 */
/*****************************************/




#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H
 

#define  AHB_DIV_BY_8     0  
#define  AHB              1


void MSTK_voidInit();
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle( u32 Copy_u32Ticks, void(*ptr)(void) );
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void(*ptr)(void) );
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);

#endif






 
 
 