/*!
*********************************************************************************************************
* @file     GPT_Types.h
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
#ifndef MCAL_GPT_INC_GPT_TYPES_H_
#define MCAL_GPT_INC_GPT_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPT_SYSTICK_TIMER 15

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL TYPEDEFS AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32_t Gpt_ValueType;
typedef void (* Gpt_NotifyType)(void);

typedef enum
{
	GPT_TIMER_CHANNEL_1=1,
	GPT_TIMER_CHANNEL_2,
	GPT_TIMER_CHANNEL_3,
	GPT_TIMER_CHANNEL_4,
	GPT_TIMER_CHANNEL_5,
	GPT_TIMER_CHANNEL_6,
	GPT_TIMER_CHANNEL_7,
	GPT_TIMER_CHANNEL_8,
	GPT_TIMER_CHANNEL_9,
	GPT_TIMER_CHANNEL_10,
	GPT_TIMER_CHANNEL_11,
	GPT_TIMER_CHANNEL_12,
	GPT_TIMER_CHANNEL_13,
	GPT_TIMER_CHANNEL_14,
    GPT_TIMER_CHANNEL_15=GPT_SYSTICK_TIMER
}Gpt_ChannelType;
typedef enum
{
	GPT_CH_MODE_CONTINOUS,
	GPT_CH_MODE_ONESHOT
}Gpt_ChannelModeType;

typedef enum
{
	GPT_PREDEF_TIMER_1US_16BIT=GPT_TIMER_CHANNEL_1,
	GPT_PREDEF_TIMER_1US_24BIT=GPT_SYSTICK_TIMER,
	GPT_PREDEF_TIMER_1US_32BIT=GPT_TIMER_CHANNEL_2,
	GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;

typedef struct 
{
    
    Gpt_ChannelType     GptChannelId;/**<Channel ID*/
    uint32_t            GptChannelTickFrequency;/**<*/
    uint32_t            GptChannelTickValueMax;/**<Maximum value in ticks, the timer channel is able to count. With the next tick, the timer rolls over to zero*/
    Gpt_ChannelModeType GptChannelMode;/**<Channel mode*/
    Gpt_NotifyType      GptNotificationFn;/**<Function pointer to callback function (for non-wakeup notification)*/
    uint8_t             GptPrescale;/**<The input GPT clock will be divided by this value*/
}Gpt_ChannelConfigType;

typedef struct 
{
    
    const Gpt_ChannelConfigType * 	GptChannelCfgPtr; /**<Pointer to Channel list*/
    uint32_t 	GptChannelCount;/**<Number of channels configured*/
}Gpt_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/



#endif /* MCAL_GPT_INC_GPT_TYPES_H_ */
/**********************************************************************************************************************
 *  END OF FILE: GPT_Types.h.h
 *********************************************************************************************************************/
