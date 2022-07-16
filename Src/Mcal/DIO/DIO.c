/*!
*********************************************************************************************************
* @file     DIO.c
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
#include "Inc/DIO.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
    RCC->RCC_AHB1ENR |=(1<<0);
    UsedGpioPort_Ptr->MODER = 1<<10;
*/

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
 **********************************************************************************************************************
 *  Function Name Dio_ReadChannel
 *  @brief       
 *  @usage       
 *  @param   ChannelId     
 *  @return      
 *********************************************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint8_t ChannelPort   = ChannelId/BSRR_CHANNEL;
    uint8_t ChannelNumber = ChannelId%BSRR_CHANNEL;

    GPIO_RegDef_t* UsedGpioPort_Ptr = GPIOx(ChannelPort*GPIO_OFFSET);

    return (DIO_CONST_1) & ((UsedGpioPort_Ptr->IDR)>>ChannelNumber);
}
/**
 **********************************************************************************************************************
 *  Function Name
 *  @brief       
 *  @usage       
 *  @param        
 *  @param       
 *  @return      
 *********************************************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level )
{
    uint8_t ChannelPort   = ChannelId/BSRR_CHANNEL;
    uint8_t ChannelNumber = ChannelId%BSRR_CHANNEL;
    GPIO_RegDef_t* UsedGpioPort_Ptr = GPIOx(ChannelPort*GPIO_OFFSET);
    uint32_t BSSR_Val=0;

    BSSR_Val     = DIO_CONST_1 << (ChannelNumber+Level*BSRR_CHANNEL);
    UsedGpioPort_Ptr->BSRR= BSSR_Val;
}
/**
 **********************************************************************************************************************
 *  Function Name
 *  @brief       
 *  @usage       
 *  @param        
 *  @param       
 *  @return      
 *********************************************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortLevelType PortLevel)
{
    uint8_t ChannelPort   = PortLevel/BSRR_CHANNEL;
    GPIO_RegDef_t* UsedGpioPort_Ptr = GPIOx(ChannelPort*GPIO_OFFSET);

    return UsedGpioPort_Ptr->IDR;
}
/**
 **********************************************************************************************************************
 *  Function Name
 *  @brief       
 *  @usage       
 *  @param        
 *  @param       
 *  @return      
 *********************************************************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType PortLevel)
{
    GPIO_RegDef_t* UsedGpioPort_Ptr = GPIOx(PortId*GPIO_OFFSET);

    UsedGpioPort_Ptr->ODR = PortLevel;
}
/**
 **********************************************************************************************************************
 *  Function Name
 *  @brief       
 *  @usage       
 *  @param        
 *  @param       
 *  @return      
 *********************************************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    uint8_t ChannelPort   = ChannelId/BSRR_CHANNEL;
    uint8_t ChannelNumber = ChannelId%BSRR_CHANNEL;
    GPIO_RegDef_t* UsedGpioPort_Ptr = GPIOx(ChannelPort*GPIO_OFFSET);
    uint8_t ChannelVal=0;
    uint32_t BSSR_Val=0;

    ChannelVal= (DIO_CONST_1) & ((UsedGpioPort_Ptr->ODR)>>ChannelNumber);
    BSSR_Val      = DIO_CONST_1 << (ChannelNumber+ (ChannelVal)*BSRR_CHANNEL);
    UsedGpioPort_Ptr->BSRR = BSSR_Val;
    return ~ChannelVal;
}


/**********************************************************************************************************************
 *  END OF FILE: DIO.c.h
 *********************************************************************************************************************/
