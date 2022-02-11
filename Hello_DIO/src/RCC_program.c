/*****************************************************/
/* Author     : Lamees Elbakr                        */
/* Date       : 8 Aug 2020                           */
/* Version    :  V_01                                */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void) {

#if   RCC_Clock_Type == RCC_HSE_CRYSTAL
   RCC_CR=0x00010000 ;       // Enable HSE with No bypass
   RCC_CFGR=0x00000001;     // HSE is system clock

#elif RCC_Clock_Type == RCC_HSE_RC
   RCC_CR=0x00050000       // Enable HSE with bypass
   RCC_CFGR=0x00000001;    // HSE is system clock

#elif RCC_Clock_Type == RCC_HSI
   RCC_CR=0x00000081     // Enable HSI + Trimming =0 
   RCC_CFGR=0x00000000;    // HSI is system clock

#elif RCC_Clock_Type ==  RCC_PLL 
   RCC_CR=0x00000001      // Enable PLL         

   #if    RCC_PLL_INPUT ==  RCC_PPL_IN_HSI_DIV_2



   #elif  RCC_PLL_INPUT ==  RCC_PPL_IN_HSE_DIV_2

   #elif  RCC_PLL_INPUT ==  RCC_PPL_IN_HSE
               
#endif
#else
   #error ("You choosed wrong clock type")

#endif

}



void RCC_voidEnableClock (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if(Copy_u8PerId <= 31)
      {
         switch(Copy_u8BusId)
          {
            case RCC_AHB   : SET_BIT(RCC_AHBENR  ,Copy_u8PerId);    break;
            case RCC_APB1  : SET_BIT(RCC_APB1ENR ,Copy_u8PerId);    break;
            case RCC_APB2  : SET_BIT(RCC_APB2ENR ,Copy_u8PerId);    break;
           // default      :   //Return Error                       break;
          }
      }
    else
    {
      // Return Error
    }
}


void RCC_voidDisableClock (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if(Copy_u8PerId <= 31)
      {
         switch(Copy_u8BusId)
          {
            case RCC_AHB   : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId);    break;
            case RCC_APB1  : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);    break;
            case RCC_APB2  : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);    break;
           // default      :   //Return Error                       break;
          }
      }
    else
    {
      // Return Error
    }
}
