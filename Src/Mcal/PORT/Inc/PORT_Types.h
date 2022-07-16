/*!
*********************************************************************************************************
* @file     PORT_Types.h
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
#ifndef MCAL_PORT_INC_PORT_TYPES_H_
#define MCAL_PORT_INC_PORT_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PIN_PORT_CONST  16

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    /*PortA*/
    Port_PIN_PA0,Port_PIN_PA1,Port_PIN_PA2,Port_PIN_PA3,Port_PIN_PA4,Port_PIN_PA5,Port_PIN_PA6,Port_PIN_PA7,
    Port_PIN_PA8,Port_PIN_PAo,Port_PIN_PA10,Port_PIN_PA11,Port_PIN_PA12,Port_PIN_PA13,Port_PIN_PA14,Port_PIN_PA15,
    /*PortB*/
    Port_PIN_PB0,Port_PIN_PB1,Port_PIN_PB2,Port_PIN_PB3,Port_PIN_PB4,Port_PIN_PB5,Port_PIN_PB6,Port_PIN_PB7,
    Port_PIN_PB8,Port_PIN_PBo,Port_PIN_PB10,Port_PIN_PB11,Port_PIN_PB12,Port_PIN_PB13,Port_PIN_PB14,Port_PIN_PB15,
    /*PortC*/
    Port_PIN_PC0,Port_PIN_PC1,Port_PIN_PC2,Port_PIN_PC3,Port_PIN_PC4,Port_PIN_PC5,Port_PIN_PC6,Port_PIN_PC7,
    Port_PIN_PC8,Port_PIN_PCo,Port_PIN_PC10,Port_PIN_PC11,Port_PIN_PC12,Port_PIN_PC13,Port_PIN_PC14,Port_PIN_PC15,
    /*PortD*/
    Port_PIN_PD0,Port_PIN_PD1,Port_PIN_PD2,Port_PIN_PD3,Port_PIN_PD4,Port_PIN_PD5,Port_PIN_PD6,Port_PIN_PD7,
    Port_PIN_PD8,Port_PIN_PDo,Port_PIN_PD10,Port_PIN_PD11,Port_PIN_PD12,Port_PIN_PD13,Port_PIN_PD14,Port_PIN_PD15,
    /*PortE*/
    Port_PIN_PE0,Port_PIN_PE1,Port_PIN_PE2,Port_PIN_PE3,Port_PIN_PE4,Port_PIN_PE5,Port_PIN_PE6,Port_PIN_PE7,
    Port_PIN_PE8,Port_PIN_PEo,Port_PIN_PE10,Port_PIN_PE11,Port_PIN_PE12,Port_PIN_PE13,Port_PIN_PE14,Port_PIN_PE15,
    /*PortF*/
    Port_PIN_PF0,Port_PIN_PF1,Port_PIN_PF2,Port_PIN_PF3,Port_PIN_PF4,Port_PIN_PF5,Port_PIN_PF6,Port_PIN_PF7,
    Port_PIN_PF8,Port_PIN_PFo,Port_PIN_PF10,Port_PIN_PF11,Port_PIN_PF12,Port_PIN_PF13,Port_PIN_PF14,Port_PIN_PF15,
    /*PortG*/
    Port_PIN_PG0,Port_PIN_PG1,Port_PIN_PG2,Port_PIN_PG3,Port_PIN_PG4,Port_PIN_PG5,Port_PIN_PG6,Port_PIN_PG7,
    Port_PIN_PG8,Port_PIN_PGo,Port_PIN_PG10,Port_PIN_PG11,Port_PIN_PG12,Port_PIN_PG13,Port_PIN_PG14,Port_PIN_PG15,
    /*PortH*/
    Port_PIN_PH0,Port_PIN_PH1,Port_PIN_PH2,Port_PIN_PH3,Port_PIN_PH4,Port_PIN_PH5,Port_PIN_PH6,Port_PIN_PH7,
    Port_PIN_PH8,Port_PIN_PHo,Port_PIN_PH10,Port_PIN_PH11,Port_PIN_PH12,Port_PIN_PH13,Port_PIN_PH14,Port_PIN_PH15
}Port_PinType;
typedef enum
{
    Port_PIN_DIR_INPUT,
    Port_PIN_DIR_OUTPUT
}Port_PinDirectionType;

typedef enum
{
    Port_PIN_MODE_INPUT,/*Default*/
    Port_PIN_MODE_GENERAL_PURPOSE_OUTPUT,
    Port_PIN_MODE_ALTERNATE_FUNCTION,
    Port_PIN_MODE_ANALOG
}Port_PinModeType;
typedef enum
{
    Port_PIN_INITIAL_LOW_LEVEL =1,
    Port_PIN_INITIAL_HIGH_LEVEL=0
}Port_InitialLevelType;
typedef enum
{
    Port_OUTPUT_TYPE_PUSHPULL,
    Port_OUTPUT_TYPE_OPENDRAIN
}Port_OutputTypeType;
typedef enum
{
    Port_PIN_ATTACH_NO_PULL,
    Port_PIN_ATTACH_PULL_UP,
    Port_PIN_ATTACH_PULL_DOWN,
    Port_PIN_ATTACH_RESERVED
}Port_PinInternalAttachType;
typedef enum
{
    Port_PIN_SPEED_LOW,
    Port_PIN_SPEED_MEDIUM,
    Port_PIN_SPEED_FAST,
    Port_PIN_SPEED_HIGH
}Port_PintOutputSpeedType;

typedef struct
{
    Port_PinType                pinId;
    Port_PinDirectionType       pinDirection;
    Port_OutputTypeType         OutputType;
    Port_PinModeType            pinMode;
    Port_InitialLevelType       pinInitialLevel;
    Port_PinInternalAttachType  pinInternalAttach;
    Port_PintOutputSpeedType    pinOutputSpeed;
}Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/



#endif /* MCAL_PORT_INC_PORT_TYPES_H_ */
/**********************************************************************************************************************
 *  END OF FILE: PORT_Types.h
 *********************************************************************************************************************/
