/*!
*********************************************************************************************************
* @file     PORT.c
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
#include "Inc/PORT.h"

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
 **********************************************************************************************************************
 *  Function Name
 *  @brief       
 *  @usage       
 *  @param        
 *  @param       
 *  @return      
 *********************************************************************************************************************/
void Port_Init(Port_ConfigType* ConfigArrayOfPtrs)
{
    uint8_t PinId,PinOutputType,PinInitialLevel,PinMode,PinInternalAttach,PinOutputSpeed;
    uint8_t PinPort;
    uint8_t PinNumber; 
    GPIO_RegDef_t* UsedGpioPort_Ptr;
    for(uint8_t i=0; i<NUM_OF_USED_PINS;i++)
    {
        PinId            =ConfigArrayOfPtrs[i].pinId;
        PinMode          =ConfigArrayOfPtrs[i].pinMode;
        PinInternalAttach=ConfigArrayOfPtrs[i].pinInternalAttach;
        PinOutputSpeed   =ConfigArrayOfPtrs[i].pinOutputSpeed;
        PinOutputType    =ConfigArrayOfPtrs[i].OutputType;

        PinPort          = PinId/PIN_PORT_CONST;
        PinNumber        = PinId%PIN_PORT_CONST; 

        UsedGpioPort_Ptr = GPIOx(PinPort*GPIO_OFFSET);
        /*Pin mode*/
        UsedGpioPort_Ptr->MODER &=~(PORT_CONST_3<< (PORT_CONST_2*PinNumber));
        UsedGpioPort_Ptr->MODER |=PinMode<< (PORT_CONST_2*PinNumber);
        /*Pin Pull up or pull down*/
        UsedGpioPort_Ptr->PUPDR &=~(PORT_CONST_3   <<(PORT_CONST_2*PinNumber));
        UsedGpioPort_Ptr->PUPDR |=PinInternalAttach<<(PORT_CONST_2*PinNumber);
        
        switch(PinMode)
        {
            case Port_PIN_MODE_INPUT: /*Do Nothing*/break;
            case Port_PIN_MODE_GENERAL_PURPOSE_OUTPUT:
                /*Pin Output type*/
                UsedGpioPort_Ptr->OTYPER&=~(PORT_CONST_1<< (PORT_CONST_2*PinNumber));
                UsedGpioPort_Ptr->OTYPER|= (PinOutputType<<(PORT_CONST_2*PinNumber));
                /*Set initial value*/
                PinInitialLevel  =ConfigArrayOfPtrs[i].pinInitialLevel;
                Dio_WriteChannel(PinId,PinInitialLevel);
                /*Pin Speed*/
                UsedGpioPort_Ptr->OSPEEDR &=~(PORT_CONST_3<< (PORT_CONST_2*PinNumber));
                UsedGpioPort_Ptr->OSPEEDR |=PinOutputSpeed<< (PORT_CONST_2*PinNumber);
                break;
            case Port_PIN_MODE_ALTERNATE_FUNCTION: /*Not Available*/ break;
            case Port_PIN_MODE_ANALOG:             /*Not Available*/ break;
            default:break;
        }


    }

}


/**********************************************************************************************************************
 *  END OF FILE: PORT.c.h
 *********************************************************************************************************************/
