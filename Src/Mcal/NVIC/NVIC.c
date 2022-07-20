/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Inc/NVIC.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void NVIC_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void NVIC_Init(void)
{
	uint8_t NVIC_Cfg_Counter;
	NVIC_InterruptNumber InterruptNumber;/*Signed int*/
	uint8_t SubgroupPriority;
	uint8_t Groupriority;
	NVIC_InterruptState_t InterruptState;
	

/*TODO Configure Grouping\SubGrouping System in Application Interrupt and Reset Control Register (AIRCR) in SCB*/
    SCB_AIRCR =  (Group);

/*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SHPRx Registers*/  
	for(NVIC_Cfg_Counter=0;NVIC_Cfg_Counter<NVIC_ACTIVATED_INT_SIZE;NVIC_Cfg_Counter++)
	{	
		InterruptNumber =NVIC_Cfg[NVIC_Cfg_Counter].interruptNumber;
		SubgroupPriority=NVIC_Cfg[NVIC_Cfg_Counter].subgroupPriority;
		Groupriority	=NVIC_Cfg[NVIC_Cfg_Counter].groupPriority;
		InterruptState  =NVIC_Cfg[NVIC_Cfg_Counter].interruptState; 
		//page 229 in f446 programming manual
		uint8_t Priority =  (SubgroupPriority) | (Groupriority) << ( (Group - BASE_GROUP) / GROUP_UNIT_DIFFERECE )  ;// 0x100 Hex  ---> 256 Decimal
		
		if( InterruptNumber < NVIC_ZERO )
		{
			//Core Peripheral
			switch(InterruptNumber)
			{
				case MemManage :
					SCB->SCB_SHPR1 = ( Priority ) << (MEMMANAGE_BITSHIFT );
					SCB_SHCSR->BIT.MEMFAULTENA=InterruptState;
					break;
				case BusFault  :
					SCB->SCB_SHPR1 = ( Priority ) << (BUSFAULT_BITSHIFT  );
					SCB_SHCSR->BIT.BUSFAULTENA=InterruptState;
					break;
				case UsageFault:
					SCB->SCB_SHPR1 = ( Priority ) << (USAGEFAULT_BITSHIFT);
					SCB_SHCSR->BIT.USGFAULTENA=InterruptState;
					break;
				case SVC       :SCB->SCB_SHPR2 = ( Priority ) << (SVC_BITSHIFT   );break;
				case PendSV    :SCB->SCB_SHPR3 = ( Priority ) << (PENDSV_BITSHIFT);break;
				case SysTick   :
					SCB->SCB_SHPR3 = ( Priority ) << (SYSTICK_BITSHIFT);
					SYSTICK->STK_CTRL = InterruptState << SYSTICK_INT_EN_BITSHIFT;
					break;
				default:break;
			}
		}
		else if( InterruptNumber >= 0 )
		{
			NVIC->NVIC_IPR [ InterruptNumber/4  ] |=  Priority << ((8*(InterruptNumber%4))+4) ;
			NVIC->NVIC_ISER[ InterruptNumber/31 ] &= ~(NVIC_ONE << (InterruptNumber%31));
			NVIC->NVIC_ISER[ InterruptNumber/31 ] |= InterruptState << (InterruptNumber%31) ;
		}
	}
    
	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
	for(NVIC_Cfg_Counter=0;NVIC_Cfg_Counter<NVIC_ACTIVATED_INT_SIZE;NVIC_Cfg_Counter++)
	{	
		InterruptNumber= NVIC_Cfg[NVIC_Cfg_Counter].interruptNumber;
		
		if(InterruptNumber>=0)
		{
			NVIC->NVIC_ISER[ InterruptNumber/8 ] &= ~(NVIC_ONE << (InterruptNumber%8));
			NVIC->NVIC_ISER[ InterruptNumber/8 ] |= InterruptState << (InterruptNumber%8) ;
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
