/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 19 Sep 2020                           */
/* Version    :  V_01                                */
/*****************************************************/


#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void OS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Periodicity , void (*ptr)(void) );
void OS_voidStart(void);


#endif