/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  NVIC_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef NVIC_TYPES_H
#define NVIC_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

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
	NMI	=-14			,
	HardFault			,
	MemManage			,
	BusFault			,
	UsageFault			,
	Dummy               ,
	Dummy1              ,
	Dummy2              ,
	Dummy3              ,
    SVC				    ,
    DebugMon			,
	Dummy4              ,
    PendSV				,
    SysTick			    ,
    WWDG_IRQ=0     		,
    PVD_IRQ       		,
    TAMP_STAMP_IRQ		,
    RTC_WKUP_IRQ  		,
    FLASH_IRQ     		,
    RCC_IRQ       		,
    EXTI0_IRQ     		,
    EXTI1_IRQ     		,
    EXTI2_IRQ     		,
    EXTI3_IRQ     		,
    EXTI4_IRQ     		,
    DMA1_Stream0_IRQ    ,
    DMA1_Stream1_IRQ    ,
    DMA1_Stream2_IRQ    ,
    DMA1_Stream3_IRQ    ,
    DMA1_Stream4_IRQ    ,
    DMA1_Stream5_IRQ    ,
    DMA1_Stream6_IRQ    ,
    ADC_IRQ             ,
    CAN1_TX_IRQ         ,
    CAN1_RX0_IRQ        ,
    CAN1_RX1_IRQ        ,
    CAN1_SCE_IRQ        ,
    EXTI9_5_IRQ         ,
    TIM1_BRK_TIM9_IRQ   ,
    TIM1_UP_TIM10_IRQ   ,
    TIM1_TRG_COM_TIM11_IRQHandl,
    TIM1_CC_IRQ         ,
    TIM2_IRQ            ,
    TIM3_IRQ            ,
    TIM4_IRQ            ,
    I2C1_EV_IRQ         ,
    I2C1_ER_IRQ         ,
    I2C2_EV_IRQ         ,
    I2C2_ER_IRQ         ,
    SPI1_IRQ            ,
    SPI2_IRQ            ,
    USART1_IRQ          ,
    USART2_IRQ          ,
    USART3_IRQ          ,
    EXTI15_10_IRQ       ,
    RTC_Alarm_IRQ       ,
    OTG_FS_WKUP_IRQ     ,
    TIM8_BRK_TIM12_IRQ  ,
    TIM8_UP_TIM13_IRQ   ,
    TIM8_TRG_COM_TIM14_IRQHandl,
    TIM8_CC_IRQ          ,
    DMA1_Stream7_IRQ     ,
    FMC_IRQ              ,
    SDIO_IRQ             ,
    TIM5_IRQ             ,
    SPI3_IRQ             ,
    UART4_IRQ       	    ,
    UART5_IRQ       	    ,
    TIM6_DAC_IRQ    	    ,
    TIM7_IRQ        	    ,
    DMA2_Stream0_IRQ	    ,
    DMA2_Stream1_IRQ	    ,
    DMA2_Stream2_IRQ	    ,
    DMA2_Stream3_IRQ	    ,
    DMA2_Stream4_IRQ	    ,
	Dummy5,
	Dummy6,
    CAN2_TX_IRQ       	,
    CAN2_RX0_IRQ      	,
    CAN2_RX1_IRQ      	,
    CAN2_SCE_IRQ      	,
    OTG_FS_IRQ        	,
    DMA2_Stream5_IRQ  	,
    DMA2_Stream6_IRQ  	,
    DMA2_Stream7_IRQ  	,
    USART6_IRQ        	,
    I2C3_EV_IRQ       	,
    I2C3_ER_IRQ       	,
    OTG_HS_EP1_OUT_IRQ	,
    OTG_HS_EP1_IN_IRQ 	,
    OTG_HS_WKUP_IRQ   	,
    OTG_HS_IRQ        	,
    DCMI_IRQ          	,
	Dummy7,
	Dummy8,
    FPU_IRQ       		,
	Dummy9,
	Dummy10,
    SPI4_IRQ      		,
	Dummy11,
	Dummy12,
    SAI1_IRQ      		,
	Dummy13,
	Dummy14,
	Dummy15,
    SAI2_IRQ      		,
    QUADSPI_IRQ   		,
    CEC_IRQ       		,
    SPDIF_RX_IRQ  		,
    FMPI2C1_EV_IRQ		,
    FMPI2C1_ER_IRQ		
}NVIC_InterruptNumber;

typedef enum
{   
    BASE_GROUP=0x05FA0300,
    GROUP3    =0x05FA0300,//0 bit for sub & 4 bit For group   << 0
    GROUP4    =0x05FA0400,//1 bit for sub & 3 bit For group   << 1
    GROUP5    =0x05FA0500,//2 bit for sub & 2 bit For group   << 2
    GROUP6    =0x05FA0600,//3 bit for sub & 1 bit For group   << 3
    GROUP7    =0x05FA0700 //4 bit for sub & 0 bit For group   << 4
}NVIC_Groups_t;
typedef enum
{
    INTERRUPT_DISABLE=0,
    INERRUPT_ENABLE=1
}NVIC_InterruptState_t;
typedef struct 
{
    NVIC_InterruptNumber interruptNumber;
    uint8_t        groupPriority;
	uint8_t        subgroupPriority;
    NVIC_InterruptState_t   interruptState;
}NVIC_Configs_t;

#endif  /* NVIC_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: NVIC_Types.h
 *********************************************************************************************************************/
 