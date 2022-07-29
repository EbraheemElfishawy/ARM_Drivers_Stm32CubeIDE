/*!
*********************************************************************************************************
* @file     GPT.c
* @author   Ebraheem El-Feshawy
* @tester   Ebraheem El-Feshawy
* @brief    
* @version  V1.0
* @date		Jul 15, 2022
*
* <b>File History</b>\n
* This section contains comments describing changes made to this file.\n
* Notice that changes are listed in reverse chronological order.\n
* <table border>
* <tr>
* <td><b> 19/8/2021 </b></td>
* <td><b> Ebraheem El-Feshawy </b></td>
* <td><b>  </b></td>
* </tr>
* </table>\n
*
* @note :  
*/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Inc/GPT.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**
*********************************************************************************************************************** 
*  @fn                 : Gpt_Init
*  Syntax              : void Gpt_Init(const Gpt_ConfigType* CfgPtr)
*  Service ID[hex]     : 0x01
*  Sync/Async          : Synchronous
*  Reentrancy          : Non Reentrant
*  @param[in]          : Gpt_ConfigType* CfgPtr - configuration structure
*                        for initializing the module.
*  @param[inout]       : None
*  @param[out]         : None
*  @retval             : None
*  Description         : Initializes the GPT driver.
*********************************************************************************************************************** 
*/
void Gpt_Init(const Gpt_ConfigType *CfgPtr)
{
    uint8_t               ChannelsCount =CfgPtr->GptChannelCount;
    Gpt_ChannelConfigType* ChannelCfgPtr=CfgPtr->GptChannelCfgPtr;

    uint8_t              ChannelId;
    uint32_t             ChannelTickFrequency;
    uint32_t             ChannelTickValueMax;
    Gpt_ChannelModeType  ChannelMode;
    Gpt_NotifyType       NotificationFn;
    uint8_t              Prescale;

    TIM_RegDef_t*   UsedTimerRegSet;
    for(uint8_t i=0; i<ChannelsCount;i++)
    {
        ChannelId           =ChannelCfgPtr[i].GptChannelId;
        ChannelTickFrequency=ChannelCfgPtr[i].GptChannelTickFrequency;
        ChannelTickValueMax =ChannelCfgPtr[i].GptChannelTickValueMax;
        ChannelMode         =ChannelCfgPtr[i].GptChannelMode;
        NotificationFn      =ChannelCfgPtr[i].GptNotificationFn;
        Prescale            =ChannelCfgPtr[i].GptPrescale;
        /************/
        switch(ChannelId)
        {
            case GPT_TIMER_CHANNEL_1 : UsedTimerRegSet =TIM1 ;break;
            case GPT_TIMER_CHANNEL_2 : UsedTimerRegSet =TIM2 ;break;
            case GPT_TIMER_CHANNEL_3 : UsedTimerRegSet =TIM3 ;break;
            case GPT_TIMER_CHANNEL_4 : UsedTimerRegSet =TIM4 ;break;
            case GPT_TIMER_CHANNEL_5 : UsedTimerRegSet =TIM5 ;break;
            case GPT_TIMER_CHANNEL_6 : UsedTimerRegSet =TIM6 ;break;
            case GPT_TIMER_CHANNEL_7 : UsedTimerRegSet =TIM7 ;break;
            case GPT_TIMER_CHANNEL_8 : UsedTimerRegSet =TIM8 ;break;
            case GPT_TIMER_CHANNEL_9 : UsedTimerRegSet =TIM9 ;break;
            case GPT_TIMER_CHANNEL_10: UsedTimerRegSet =TIM10;break;
            case GPT_TIMER_CHANNEL_11: UsedTimerRegSet =TIM11;break;
            case GPT_TIMER_CHANNEL_12: UsedTimerRegSet =TIM12;break;
            case GPT_TIMER_CHANNEL_13: UsedTimerRegSet =TIM13;break;
            case GPT_TIMER_CHANNEL_14: UsedTimerRegSet =TIM14;break;
            case GPT_TIMER_CHANNEL_15: /*********/;break;default:break;
        }
        if(ChannelId==GPT_SYSTICK_TIMER)
        {
            SYSTICK ->STK_CTRL &=~(STCR_MASK<<STCR_CLKSOURCE_PIN_ACCESS);
            SYSTICK ->STK_CTRL &=~(STCR_MASK<<STCR_TICKINT_PIN_ACCESS  );
        }
        else
        {
        UsedTimerRegSet->CR1 &=~(CR1_ARPE_MASK<<CR1_ARPE_BIT_ACCESS); 
        UsedTimerRegSet->CR1 |= (1<<CR1_ARPE_BIT_ACCESS);
        UsedTimerRegSet->CR1 &=~(CR1_OPM_MASK<<CR1_OPM_BIT_ACCESS); 
        UsedTimerRegSet->CR1 |= (ChannelMode <<CR1_OPM_BIT_ACCESS);
        UsedTimerRegSet->PSC  = Prescale;
        UsedTimerRegSet->ARR  = ChannelTickValueMax;
        }
    }
}
/** 
***********************************************************************************************************************
*  @fn                 : Gpt_DeInit
*  Syntax              : void Gpt_DeInit(void)
*  Service ID[hex]     : 0x02
*  Sync/Async          : Synchronous
*  Reentrancy          : Non Reentrant
*  @param[in]          : None
*  @param[inout]       : None
*  @param[out]         : None
*  @retval             : None
*  Description         : Deinitializes the GPT driver.
***********************************************************************************************************************
*/
void Gpt_DeInit(void)
{

}	
	
/**
***********************************************************************************************************************
*  @fn                 : Gpt_GetTimeElapsed
*  Syntax              : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType
*  Service ID[hex]     : 0x03
*  Sync/Async          : Synchronous
*  Reentrancy          : Reentrant
*  @param[in]          : Channel - ChannelId of the Gpt channel.
*  @param[inout]       : None
*  @param[out]         : None
*  @retval             : Gpt_ValueType Elapsed timer value (in number of ticks)
*  Description         : Returns the time already elapsed.
***********************************************************************************************************************
*/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    Gpt_ValueType ReturnValue=0;
    TIM_RegDef_t*   UsedTimerRegSet;
    switch(Channel)
        {
            case GPT_TIMER_CHANNEL_1 : UsedTimerRegSet =TIM1 ;break;
            case GPT_TIMER_CHANNEL_2 : UsedTimerRegSet =TIM2 ;break;
            case GPT_TIMER_CHANNEL_3 : UsedTimerRegSet =TIM3 ;break;
            case GPT_TIMER_CHANNEL_4 : UsedTimerRegSet =TIM4 ;break;
            case GPT_TIMER_CHANNEL_5 : UsedTimerRegSet =TIM5 ;break;
            case GPT_TIMER_CHANNEL_6 : UsedTimerRegSet =TIM6 ;break;
            case GPT_TIMER_CHANNEL_7 : UsedTimerRegSet =TIM7 ;break;
            case GPT_TIMER_CHANNEL_8 : UsedTimerRegSet =TIM8 ;break;
            case GPT_TIMER_CHANNEL_9 : UsedTimerRegSet =TIM9 ;break;
            case GPT_TIMER_CHANNEL_10: UsedTimerRegSet =TIM10;break;
            case GPT_TIMER_CHANNEL_11: UsedTimerRegSet =TIM11;break;
            case GPT_TIMER_CHANNEL_12: UsedTimerRegSet =TIM12;break;
            case GPT_TIMER_CHANNEL_13: UsedTimerRegSet =TIM13;break;
            case GPT_TIMER_CHANNEL_14: UsedTimerRegSet =TIM14;break;
            case GPT_TIMER_CHANNEL_15: /*********/;break;default:break;
        }
        if(Channel==GPT_SYSTICK_TIMER)
        {
           ReturnValue=(SYSTICK_MAX)-(SYSTICK->STK_VAL);
        }

        return ReturnValue;
}	
/**
***********************************************************************************************************************
*  @fn                 : Gpt_GetTimeRemaining
*  Syntax              : Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType
*  Service ID[hex]     : 0x04
*  Sync/Async          : Synchronous
*  Reentrancy          : Reentrant
*  @param[in]          : Channel - ChannelId of the Gpt channel.
*  @param[inout]       : None
*  @param[out]         : None
*  @retval             : Gpt_ValueType Remaining timer value (in number o
*                        ticks)
*  Description         : Returns the time remaining until the target time is
*                        reached.
***********************************************************************************************************************
*/
Gpt_ValueType Gpt_GetTimeRemaining	(Gpt_ChannelType Channel)
{
    Gpt_ValueType ReturnValue=0;
    TIM_RegDef_t*   UsedTimerRegSet;
    switch(Channel)
        {
            case GPT_TIMER_CHANNEL_1 : UsedTimerRegSet =TIM1 ;break;
            case GPT_TIMER_CHANNEL_2 : UsedTimerRegSet =TIM2 ;break;
            case GPT_TIMER_CHANNEL_3 : UsedTimerRegSet =TIM3 ;break;
            case GPT_TIMER_CHANNEL_4 : UsedTimerRegSet =TIM4 ;break;
            case GPT_TIMER_CHANNEL_5 : UsedTimerRegSet =TIM5 ;break;
            case GPT_TIMER_CHANNEL_6 : UsedTimerRegSet =TIM6 ;break;
            case GPT_TIMER_CHANNEL_7 : UsedTimerRegSet =TIM7 ;break;
            case GPT_TIMER_CHANNEL_8 : UsedTimerRegSet =TIM8 ;break;
            case GPT_TIMER_CHANNEL_9 : UsedTimerRegSet =TIM9 ;break;
            case GPT_TIMER_CHANNEL_10: UsedTimerRegSet =TIM10;break;
            case GPT_TIMER_CHANNEL_11: UsedTimerRegSet =TIM11;break;
            case GPT_TIMER_CHANNEL_12: UsedTimerRegSet =TIM12;break;
            case GPT_TIMER_CHANNEL_13: UsedTimerRegSet =TIM13;break;
            case GPT_TIMER_CHANNEL_14: UsedTimerRegSet =TIM14;break;
            case GPT_TIMER_CHANNEL_15: /*********/;break;
            default:break;
        }
        if(Channel==GPT_SYSTICK_TIMER)
        {
           ReturnValue=(SYSTICK->STK_VAL);
        }
        else
        {
        	ReturnValue= UsedTimerRegSet->CNT;
        }

        return ReturnValue;
}		
	
/**
***********************************************************************************************************************
*  @fn                 : Gpt_StartTimer
*  Syntax              : void Gpt_StartTimer(Gpt_ChannelType Channel,
*                                            Gpt_ValueType Value)
*  Service ID[hex]     : 0x05
*  Sync/Async          : Synchronous
*  Reentrancy          : Reentrant
*  @param[in]          : Channel - ChannelId of the Gpt channel.
*                        value - Target time in number of ticks.
*  @param[inout]       : None
*  @param[out]         : None
*  @retval             : None
*  Description         : Starts a timer channel.
***********************************************************************************************************************
*/
void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value )
{
    TIM_RegDef_t*   UsedTimerRegSet;
    switch(Channel)
        {
            case GPT_TIMER_CHANNEL_1 : UsedTimerRegSet =TIM1 ;break;
            case GPT_TIMER_CHANNEL_2 : UsedTimerRegSet =TIM2 ;break;
            case GPT_TIMER_CHANNEL_3 : UsedTimerRegSet =TIM3 ;break;
            case GPT_TIMER_CHANNEL_4 : UsedTimerRegSet =TIM4 ;break;
            case GPT_TIMER_CHANNEL_5 : UsedTimerRegSet =TIM5 ;break;
            case GPT_TIMER_CHANNEL_6 : UsedTimerRegSet =TIM6 ;break;
            case GPT_TIMER_CHANNEL_7 : UsedTimerRegSet =TIM7 ;break;
            case GPT_TIMER_CHANNEL_8 : UsedTimerRegSet =TIM8 ;break;
            case GPT_TIMER_CHANNEL_9 : UsedTimerRegSet =TIM9 ;break;
            case GPT_TIMER_CHANNEL_10: UsedTimerRegSet =TIM10;break;
            case GPT_TIMER_CHANNEL_11: UsedTimerRegSet =TIM11;break;
            case GPT_TIMER_CHANNEL_12: UsedTimerRegSet =TIM12;break;
            case GPT_TIMER_CHANNEL_13: UsedTimerRegSet =TIM13;break;
            case GPT_TIMER_CHANNEL_14: UsedTimerRegSet =TIM14;break;
            case GPT_TIMER_CHANNEL_15: /*********/;break;
            default:break;
        }
        if(Channel==GPT_SYSTICK_TIMER)
        {
            /*Put Value in STK Load register*/
            SYSTICK->STK_LOAD = Value;
            /*STK counter = 0*/
            SYSTICK->STK_VAL=0;
            /*Enable counter*/
            SYSTICK->STK_CTRL |= (STCR_MASK<<STCR_COUNTER_PIN_ACCESS);// To start counting down
        }
        else
        {
       // UsedTimerRegSet->ARR = Value;
        UsedTimerRegSet->CR1|=(1<<0);
        }

}	

	
/**
***********************************************************************************************************************
*  @fn                 : Gpt_StopTimer
*  Syntax              : void Gpt_StopTimer( Gpt_ChannelType Channel )
*  Service ID[hex]     : 0x06
*  Sync/Async          : Synchronous
*  Reentrancy          : Reentrant (but not for the same timer channel)
*  @param[in]          : Channel: Numeric identifier of the GPT channel.
*  @param[inout]       : None
*  @param[out]         : None
*  @retval             : None
*  Description         : Stops a timer channel.
***********************************************************************************************************************
*/

void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    TIM_RegDef_t*   UsedTimerRegSet;
    switch(Channel)
        {
            case GPT_TIMER_CHANNEL_1 : UsedTimerRegSet =TIM1 ;break;
            case GPT_TIMER_CHANNEL_2 : UsedTimerRegSet =TIM2 ;break;
            case GPT_TIMER_CHANNEL_3 : UsedTimerRegSet =TIM3 ;break;
            case GPT_TIMER_CHANNEL_4 : UsedTimerRegSet =TIM4 ;break;
            case GPT_TIMER_CHANNEL_5 : UsedTimerRegSet =TIM5 ;break;
            case GPT_TIMER_CHANNEL_6 : UsedTimerRegSet =TIM6 ;break;
            case GPT_TIMER_CHANNEL_7 : UsedTimerRegSet =TIM7 ;break;
            case GPT_TIMER_CHANNEL_8 : UsedTimerRegSet =TIM8 ;break;
            case GPT_TIMER_CHANNEL_9 : UsedTimerRegSet =TIM9 ;break;
            case GPT_TIMER_CHANNEL_10: UsedTimerRegSet =TIM10;break;
            case GPT_TIMER_CHANNEL_11: UsedTimerRegSet =TIM11;break;
            case GPT_TIMER_CHANNEL_12: UsedTimerRegSet =TIM12;break;
            case GPT_TIMER_CHANNEL_13: UsedTimerRegSet =TIM13;break;
            case GPT_TIMER_CHANNEL_14: UsedTimerRegSet =TIM14;break;
            case GPT_TIMER_CHANNEL_15: /*********/;break;
            default:break;
        }
        if(Channel==GPT_SYSTICK_TIMER)
        {
            SYSTICK->STK_CTRL &=~ (STCR_MASK<<STCR_COUNTER_PIN_ACCESS);
        }
}	

/**
***********************************************************************************************************************
*  @fn                 : Gpt_EnableNotification
*  Syntax              : void Gpt_EnableNotification( Gpt_ChannelType Channel)
*  Service ID[hex]     : 0x07
*  Sync/Async          : Synchronous
*  Reentrancy          : Reentrant (but not for the same timer channel)
*  @param[in]          : Channel: Numeric identifier of the GPT channel.
*  @param[inout]       : None
*  @param[out]         : None
*  @retval             : None
*  Description         : Enables the interrupt notification for a channel
*                        relevant in normal mode).
***********************************************************************************************************************
*/
void Gpt_EnableNotification	(Gpt_ChannelType Channel)
{
    TIM_RegDef_t*   UsedTimerRegSet;
    switch(Channel)
        {
            case GPT_TIMER_CHANNEL_1 : UsedTimerRegSet =TIM1 ;break;
            case GPT_TIMER_CHANNEL_2 : UsedTimerRegSet =TIM2 ;break;
            case GPT_TIMER_CHANNEL_3 : UsedTimerRegSet =TIM3 ;break;
            case GPT_TIMER_CHANNEL_4 : UsedTimerRegSet =TIM4 ;break;
            case GPT_TIMER_CHANNEL_5 : UsedTimerRegSet =TIM5 ;break;
            case GPT_TIMER_CHANNEL_6 : UsedTimerRegSet =TIM6 ;break;
            case GPT_TIMER_CHANNEL_7 : UsedTimerRegSet =TIM7 ;break;
            case GPT_TIMER_CHANNEL_8 : UsedTimerRegSet =TIM8 ;break;
            case GPT_TIMER_CHANNEL_9 : UsedTimerRegSet =TIM9 ;break;
            case GPT_TIMER_CHANNEL_10: UsedTimerRegSet =TIM10;break;
            case GPT_TIMER_CHANNEL_11: UsedTimerRegSet =TIM11;break;
            case GPT_TIMER_CHANNEL_12: UsedTimerRegSet =TIM12;break;
            case GPT_TIMER_CHANNEL_13: UsedTimerRegSet =TIM13;break;
            case GPT_TIMER_CHANNEL_14: UsedTimerRegSet =TIM14;break;
            case GPT_TIMER_CHANNEL_15: /*********/;break;
            default:break;
        }
        if(Channel==GPT_SYSTICK_TIMER)
        {
            SYSTICK ->STK_CTRL |= (STCR_MASK<<STCR_TICKINT_PIN_ACCESS);
        }
        else
        {
//        	UsedTimerRegSet->EGR &=~(EGR_TG_MASK<<EGR_TG_BIT_ACCESS);
//        	UsedTimerRegSet->EGR |= (EGR_TG_MASK<<EGR_TG_BIT_ACCESS);
        	UsedTimerRegSet->DIER&=~(DIER_TIE_MASK<<DIER_TIE_BIT_ACCESS);
        	UsedTimerRegSet->DIER |= (DIER_TIE_MASK<<DIER_TIE_BIT_ACCESS);
        }
}	
/**
***********************************************************************************************************************
*  @fn                 : Gpt_DisableNotification
*  Syntax              : void Gpt_DisableNotification( Gpt_ChannelType Channel)
*  Service ID[hex]     : 0x08
*  Sync/Async          : Synchronous
*  Reentrancy          : Reentrant (but not for the same timer channel)
*  @param[in]          : Channel: Numeric identifier of the GPT channel.
*  @param[inout]       : None
*  @param[out]         : None
*  @retval             : None
*  Description         : Disables the interrupt notification for a channel
*                        relevant in normal mode).
***********************************************************************************************************************
*/
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    TIM_RegDef_t*   UsedTimerRegSet;
    switch(Channel)
        {
            case GPT_TIMER_CHANNEL_1 : UsedTimerRegSet =TIM1 ;break;
            case GPT_TIMER_CHANNEL_2 : UsedTimerRegSet =TIM2 ;break;
            case GPT_TIMER_CHANNEL_3 : UsedTimerRegSet =TIM3 ;break;
            case GPT_TIMER_CHANNEL_4 : UsedTimerRegSet =TIM4 ;break;
            case GPT_TIMER_CHANNEL_5 : UsedTimerRegSet =TIM5 ;break;
            case GPT_TIMER_CHANNEL_6 : UsedTimerRegSet =TIM6 ;break;
            case GPT_TIMER_CHANNEL_7 : UsedTimerRegSet =TIM7 ;break;
            case GPT_TIMER_CHANNEL_8 : UsedTimerRegSet =TIM8 ;break;
            case GPT_TIMER_CHANNEL_9 : UsedTimerRegSet =TIM9 ;break;
            case GPT_TIMER_CHANNEL_10: UsedTimerRegSet =TIM10;break;
            case GPT_TIMER_CHANNEL_11: UsedTimerRegSet =TIM11;break;
            case GPT_TIMER_CHANNEL_12: UsedTimerRegSet =TIM12;break;
            case GPT_TIMER_CHANNEL_13: UsedTimerRegSet =TIM13;break;
            case GPT_TIMER_CHANNEL_14: UsedTimerRegSet =TIM14;break;
            case GPT_TIMER_CHANNEL_15: /*********/;break;
            default:break;
        }
        if(Channel==GPT_SYSTICK_TIMER)
        {
            SYSTICK ->STK_CTRL &=~(STCR_MASK<<STCR_TICKINT_PIN_ACCESS);
        }else
        {
        	UsedTimerRegSet->EGR &=~(EGR_TG_MASK<<EGR_TG_BIT_ACCESS);
        }
}	
	
void delay_ms(uint32_t delay)
{
	uint32_t Current = Gpt_GetTimeRemaining(GPT_TIMER_CHANNEL_2);
	while((  Gpt_GetTimeRemaining(GPT_TIMER_CHANNEL_2) -Current ) < (delay*16000) );
}

/**********************************************************************************************************************
 *  END OF FILE: GPT.c.h
 *********************************************************************************************************************/
