/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  IntCrtl
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef IntCrtl_H
#define IntCrtl_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "../../../Config/NVIC_Cfg/NVIC_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/////////////////////////
#define PEND_SV        -6
#define SYSTICKK        -5
/////////////////////////
#define SV_CALL        -4
/////////////////////////
#define MEMORY_MANAGE  -3
#define BUS_FAULT      -2
#define USAGE_FAULT    -1
/////////////////////////

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define NVIC_ZERO   0
#define NVIC_ONE    1
#define APINT_VECTKEY 							0x05FA
#define IPR_BITSHIFT        4
#define GROUP_UNIT_DIFFERECE    0x100

#define MEMMANAGE_BITSHIFT  4
#define BUSFAULT_BITSHIFT   12
#define USAGEFAULT_BITSHIFT 20
#define SVC_BITSHIFT        28
#define PENDSV_BITSHIFT     20
#define SYSTICK_BITSHIFT    28

#define SYSTICK_INT_EN_BITSHIFT 1
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const NVIC_Configs_t NVIC_Cfg[NVIC_ACTIVATED_INT_SIZE];
extern const uint32_t Group;
 
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void NVIC_Init(void);
 
#endif  /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/