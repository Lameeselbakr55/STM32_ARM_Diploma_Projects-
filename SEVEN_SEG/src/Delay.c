/*
 * Delay.c
 *
 *  Created on: Sep 1, 2020
 *      Author: Lamees
 */


void Delay (void){
int w=1000;
	 for(int i = 0 ; i < w ; i++ )
			{
				for(int i = 0 ; i < w ; i++ )
				{
				asm("NOP");
				}
			}
}

