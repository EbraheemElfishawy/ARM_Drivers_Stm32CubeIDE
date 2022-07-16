/*!
*********************************************************************************************************
* @file     DIO.h
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
#ifndef MCAL_DIO_INC_DIO_H_
#define MCAL_DIO_INC_DIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "DIO_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define BSRR_CHANNEL   16
#define DIO_CONST_0   0
#define DIO_CONST_1   1
#define DIO_CONST_2   2
#define DIO_CONST_3   3
#define DIO_CONST_4   4
#define DIO_CONST_5   5
#define DIO_CONST_6   6
#define DIO_CONST_7   7
#define DIO_CONST_8   8
#define DIO_CONST_9   9
#define DIO_CONST_10  10

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
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level );
Dio_PortLevelType Dio_ReadPort(Dio_PortLevelType PortLevel);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType PortLevel);
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);


#endif /* MCAL_DIO_INC_DIO_H_ */
/**********************************************************************************************************************
 *  END OF FILE: DIO.h.h
 *********************************************************************************************************************/
