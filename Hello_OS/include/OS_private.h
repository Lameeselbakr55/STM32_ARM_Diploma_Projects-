/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 19 Sep 2020                           */
/* Version    :  V_01                                */
/*****************************************************/


#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H


typedef struct {
	
	u16 periodicity   ; 
	void(*FPtr)(void) ;
	
}Task; 



#endif
