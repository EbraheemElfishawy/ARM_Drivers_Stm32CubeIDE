/*!
*********************************************************************************************************
* @file     DIO_Types.h
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
#ifndef MCAL_DIO_INC_DIO_TYPES_H_
#define MCAL_DIO_INC_DIO_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    Dio_CHANNEL_PA0,Dio_CHANNEL_PA1,Dio_CHANNEL_PA2,Dio_CHANNEL_PA3,Dio_CHANNEL_PA4,Dio_CHANNEL_PA5,Dio_CHANNEL_PA6,Dio_CHANNEL_PA7,
    Dio_CHANNEL_PA8,Dio_CHANNEL_PAo,Dio_CHANNEL_PA10,Dio_CHANNEL_PA11,Dio_CHANNEL_PA12,Dio_CHANNEL_PA13,Dio_CHANNEL_PA14,Dio_CHANNEL_PA15,

    Dio_CHANNEL_PB0,Dio_CHANNEL_PB1,Dio_CHANNEL_PB2,Dio_CHANNEL_PB3,Dio_CHANNEL_PB4,Dio_CHANNEL_PB5,Dio_CHANNEL_PB6,Dio_CHANNEL_PB7,
    Dio_CHANNEL_PB8,Dio_CHANNEL_PBo,Dio_CHANNEL_PB10,Dio_CHANNEL_PB11,Dio_CHANNEL_PB12,Dio_CHANNEL_PB13,Dio_CHANNEL_PB14,Dio_CHANNEL_PB15,

    Dio_CHANNEL_PC0,Dio_CHANNEL_PC1,Dio_CHANNEL_PC2,Dio_CHANNEL_PC3,Dio_CHANNEL_PC4,Dio_CHANNEL_PC5,Dio_CHANNEL_PC6,Dio_CHANNEL_PC7,
    Dio_CHANNEL_PC8,Dio_CHANNEL_PCo,Dio_CHANNEL_PC10,Dio_CHANNEL_PC11,Dio_CHANNEL_PC12,Dio_CHANNEL_PC13,Dio_CHANNEL_PC14,Dio_CHANNEL_PC15,

    Dio_CHANNEL_PD0,Dio_CHANNEL_PD1,Dio_CHANNEL_PD2,Dio_CHANNEL_PD3,Dio_CHANNEL_PD4,Dio_CHANNEL_PD5,Dio_CHANNEL_PD6,Dio_CHANNEL_PD7,
    Dio_CHANNEL_PD8,Dio_CHANNEL_PDo,Dio_CHANNEL_PD10,Dio_CHANNEL_PD11,Dio_CHANNEL_PD12,Dio_CHANNEL_PD13,Dio_CHANNEL_PD14,Dio_CHANNEL_PD15,

    Dio_CHANNEL_PE0,Dio_CHANNEL_PE1,Dio_CHANNEL_PE2,Dio_CHANNEL_PE3,Dio_CHANNEL_PE4,Dio_CHANNEL_PE5,Dio_CHANNEL_PE6,Dio_CHANNEL_PE7,
    Dio_CHANNEL_PE8,Dio_CHANNEL_PEo,Dio_CHANNEL_PE10,Dio_CHANNEL_PE11,Dio_CHANNEL_PE12,Dio_CHANNEL_PE13,Dio_CHANNEL_PE14,Dio_CHANNEL_PE15,

    Dio_CHANNEL_PF0,Dio_CHANNEL_PF1,Dio_CHANNEL_PF2,Dio_CHANNEL_PF3,Dio_CHANNEL_PF4,Dio_CHANNEL_PF5,Dio_CHANNEL_PF6,Dio_CHANNEL_PF7,
    Dio_CHANNEL_PF8,Dio_CHANNEL_PFo,Dio_CHANNEL_PF10,Dio_CHANNEL_PF11,Dio_CHANNEL_PF12,Dio_CHANNEL_PF13,Dio_CHANNEL_PF14,Dio_CHANNEL_PF15,

    Dio_CHANNEL_PG0,Dio_CHANNEL_PG1,Dio_CHANNEL_PG2,Dio_CHANNEL_PG3,Dio_CHANNEL_PG4,Dio_CHANNEL_PG5,Dio_CHANNEL_PG6,Dio_CHANNEL_PG7,
    Dio_CHANNEL_PG8,Dio_CHANNEL_PGo,Dio_CHANNEL_PG10,Dio_CHANNEL_PG11,Dio_CHANNEL_PG12,Dio_CHANNEL_PG13,Dio_CHANNEL_PG14,Dio_CHANNEL_PG15,

    Dio_CHANNEL_PH0,Dio_CHANNEL_PH1,Dio_CHANNEL_PH2,Dio_CHANNEL_PH3,Dio_CHANNEL_PH4,Dio_CHANNEL_PH5,Dio_CHANNEL_PH6,Dio_CHANNEL_PH7,
    Dio_CHANNEL_PH8,Dio_CHANNEL_PHo,Dio_CHANNEL_PH10,Dio_CHANNEL_PH11,Dio_CHANNEL_PH12,Dio_CHANNEL_PH13,Dio_CHANNEL_PH14,Dio_CHANNEL_PH15
    
}Dio_ChannelType;
typedef enum
{
    Dio_PORT_A,
    Dio_PORT_B,
    Dio_PORT_C,
    Dio_PORT_D,
    Dio_PORT_E,
    Dio_PORT_F,
    Dio_PORT_G,
    Dio_PORT_H
}Dio_PortType;
typedef enum
{
    Dio_LOW_LEVEL =1,
    Dio_HIGH_LEVEL=0
}Dio_LevelType;
typedef enum
{
    NONE
}Dio_PortLevelType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/



#endif /* MCAL_DIO_INC_DIO_TYPES_H_ */
/**********************************************************************************************************************
 *  END OF FILE: DIO_Types.h.h
 *********************************************************************************************************************/
