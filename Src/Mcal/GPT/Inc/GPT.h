/*!
*********************************************************************************************************
* @file     GPT.h
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
#ifndef MCAL_GPT_INC_GPT_H_
#define MCAL_GPT_INC_GPT_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "GPT_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define STCR_MASK					0b1
#define STCR_CLKSOURCE_PIN_ACCESS 	2
#define STCR_TICKINT_PIN_ACCESS 	1
#define STCR_COUNTER_PIN_ACCESS 	0

#define SYSTICK_MAX 0x00FFFFFF

#define CR1_ARPE_MASK       0b1 
#define CR1_ARPE_BIT_ACCESS 7
#define CR1_OPM_MASK       0b1 
#define CR1_OPM_BIT_ACCESS 3

#define EGR_TG_MASK       0b1
#define EGR_TG_BIT_ACCESS 6

#define DIER_TIE_MASK       0b1
#define DIER_TIE_BIT_ACCESS 6
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA 
 *********************************************************************************************************************/
extern const Gpt_ConfigType    Gpt_Configs;
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
void Gpt_Init(const Gpt_ConfigType *CfgPtr);	
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
void Gpt_DeInit(void);	
	
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
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
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
Gpt_ValueType Gpt_GetTimeRemaining	(Gpt_ChannelType Channel);	
	
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
void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value );

	
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

void Gpt_StopTimer(Gpt_ChannelType Channel);

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
void Gpt_EnableNotification	(Gpt_ChannelType Channel);
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
void Gpt_DisableNotification(Gpt_ChannelType Channel);
	
/**
***********************************************************************************************************************
*  @fn                 : Gpt_SetMode
*  Syntax              : void Gpt_SetMode( Gpt_ModeType Mode )
*  Service ID[hex]     : 0x09
*  Sync/Async          : Synchronous
*  Reentrancy          : Non Reentrant
*  @param[in]          : Mode GPT_MODE_NORMAL: Normal operation mode of the GPT
* driver.
*                             GPT_MODE_SLEEP: Sleep mode of the GPT driver
* (wakeup capable).
*  @param[inout]       : None
*  @param[out]         : None
*  @retval             : None
*  Description         : Sets the operation mode of the GPT.
***********************************************************************************************************************
*/
#endif /* MCAL_GPT_INC_GPT_H_ */
/**********************************************************************************************************************
 *  END OF FILE: GPT.h.h
 *********************************************************************************************************************/
