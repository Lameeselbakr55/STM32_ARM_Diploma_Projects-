/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 8 Aug 2020                           */
/* Version    :  V_01                                */
/*****************************************************/


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*Options  :   RCC_HSE_CRYSTAL
               RCC_HSE_RC
               RCC_HSI
               RCC_PLL                     */

#define RCC_Clock_Type    RCC_HSE_CRYSTAL 



/*Options  :   RCC_PPL_IN_HSI_DIV_2
               RCC_PPL_IN_HSE_DIV_2
               RCC_PPL_IN_HSE            */
 
/* Note : Select value only if you have PLL as input clock source */                  
#if RCC_Clock_Type == RCC_PLL    
#define RCC_PLL_INPUT    RCC_PPL_IN_HSE_DIV_2  
#endif


/* Note : Select value only if you have PLL as input clock source */                  
#if RCC_Clock_Type == RCC_PLL 
/*Options  : 2 TO 16    */
#define RCC_PLL_MUL_VAL    4
#endif



#endif