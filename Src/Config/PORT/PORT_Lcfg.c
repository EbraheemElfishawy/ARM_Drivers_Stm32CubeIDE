/*!
*********************************************************************************************************
* @file     PORT_Lcfg.c
* @author   Ebraheem El-Feshawy
* @tester   Ebraheem El-Feshawy
* @brief    
* @version  V1.0
* @date		Jul 14, 2022
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
#include "../../Mcal/PORT/Inc/PORT_Types.h"
#include "PORT_Cfg.h"
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
 *  GLOBAL DATA 
 *********************************************************************************************************************/
Port_ConfigType AllPinConfigs[NUM_OF_USED_PINS]={
/* Pin Type     Pin Direction           Output Type                 Pin Mode                                Initial Value                   Pin Internal Attach         Pin Output Speed*/
{Port_PIN_PA5,  Port_PIN_DIR_OUTPUT,    Port_OUTPUT_TYPE_PUSHPULL,  Port_PIN_MODE_GENERAL_PURPOSE_OUTPUT,   0                          ,    Port_PIN_ATTACH_NO_PULL,    Port_PIN_SPEED_LOW},
{Port_PIN_PC13, Port_PIN_DIR_INPUT ,    Port_OUTPUT_TYPE_PUSHPULL,  Port_PIN_MODE_INPUT                 ,   0                          ,    Port_PIN_ATTACH_PULL_UP,    0                 },
{Port_PIN_PA6,  Port_PIN_DIR_OUTPUT,    Port_OUTPUT_TYPE_PUSHPULL,  Port_PIN_MODE_GENERAL_PURPOSE_OUTPUT,   Port_PIN_INITIAL_HIGH_LEVEL,    Port_PIN_ATTACH_NO_PULL,    Port_PIN_SPEED_LOW},
{Port_PIN_PA7,  Port_PIN_DIR_OUTPUT,    Port_OUTPUT_TYPE_PUSHPULL,  Port_PIN_MODE_GENERAL_PURPOSE_OUTPUT,   Port_PIN_INITIAL_HIGH_LEVEL,    Port_PIN_ATTACH_NO_PULL,    Port_PIN_SPEED_LOW},
{Port_PIN_PA8,  Port_PIN_DIR_OUTPUT,    Port_OUTPUT_TYPE_PUSHPULL,  Port_PIN_MODE_GENERAL_PURPOSE_OUTPUT,   Port_PIN_INITIAL_HIGH_LEVEL,    Port_PIN_ATTACH_NO_PULL,    Port_PIN_SPEED_LOW}
};

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/*********************************************************************************************************************
 *  END OF FILE: PORT_Lcfg.c
 *********************************************************************************************************************/
