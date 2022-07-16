
#ifndef MCU_HW_H
#define MCU_HW_H

#define STM32F446xx    1
#define TM4c123        2
#define USED_MCU    STM32F446xx


#if USED_MCU == STM32F446xx


/*	@file 		 : STM32F44xx.h
*	@author      : Ebraheem Elfeshawy
*	@brief		 : This is the target specific header file, it includes memory addresses info,
*				   base peripheral definitions according to bus type.
*/


#ifndef STM32F446XX_H_
#define STM32F446XX_H_
#include <stdint.h>
/************************** Bit Banding *********************************************************/
#define PERIPHERAL_BIT_BAND_REGION_BASE		0x40000000
#define BIT_BAND_ALIAS_BASE					0x42000000

#define BYTE_OFFSET(REG_ADD)					( ((uint8_t)REG_ADD )-((uint8_t)PERIPHERAL_BIT_BAND_REGION_BASE) )
#define BIT_WORD_OFFSET(REG_ADD,BIT_NUMBER)	( (BYTE_OFFSET(REG_ADD)*32)+(BIT_NUMBER*4) )


#define BIT_WORD_REG_ADD(REG_ADD,BIT_NUMBER)		BIT_BAND_ALIAS_BASE+BIT_WORD_OFFSET(REG_ADD,BIT_NUMBER)

/**************************************************************************************************/
#define  NULL           0
#define  OK      		0
#define  NOK     		1
//#define  NULL_PTR      	2
/********************* 		Various memories base addresses 	*************************/
/*Reference manual chapter 3.Embedded Flash memory interface => 3.3       */
#define FLASH_BASE_ADDRESS 		0x08000000UL
/*Reference manual chapter 2.Memory and bus architecture => 2.2.2 Memory map and register boundary addresses*/
#define SRAM_BASE_ADDRESS		0x20000000UL // SRAM1 base Address 
/*Reference manual chapter 3.Embedded Flash memory interface => 3.3       */
#define ROM_BASE_ADDRESS  		0x1FFF0000UL //Read only for bootloader purposes

/*********************** 	Core Peripherals base addresses 	**************************/

/********************** RCC  ************************/
/*Datasheet chapter 5.Memory mapping page 67       */
#define RCC_BASE_ADDRESS			0x40023800UL
/*************************************************************/

/********************** SysTick ********************/
#define SYSTICK_BASE_ADDRESS		0xE000E010
/*************************************************************/

/********************** NVIC ********************/
#define NVIC_BASE_ADDRESS			0xE000E100
#define NVIC_STIR_BASE_ADDRESS		0xE000EF00
/***************************************************/

/********************** SCB ********************/
#define SCB_BASE_ADDRESS			0xE000ED00
/***************************************************/


/*********************** 	AHB1 Peripheral base addresses 		**************************/

/***************** GPIO REGISTERS ***************************/
/*Datasheet chapter 5.Memory mapping page 67       */
#define GPIO_OFFSET 0x400
#define GPIOA_BASE_ADDRESS		0x40020000UL
#define GPIOB_BASE_ADDRESS		0x40020400UL
#define GPIOC_BASE_ADDRESS		0x40020800UL
#define GPIOD_BASE_ADDRESS		0x40020C00UL
#define GPIOE_BASE_ADDRESS		0x40021000UL
#define GPIOF_BASE_ADDRESS		0x40021400UL
#define GPIOG_BASE_ADDRESS		0x40021800UL
#define GPIOH_BASE_ADDRESS		0x40021C00UL
/*************************************************************/
/*********************** 	AHB2 Peripheral base addresses 		**************************/


/*********************** 	ABB1 Peripheral base addresses 		**************************/


/*********************** 	ABB2 Peripheral base addresses 		**************************/




/*************************************************************/	
/*********** GPIO Register definition structure *************/
/*************************************************************/
typedef struct
{
		volatile uint32_t MODER;    /*GPIO Port mode               register*/
		volatile uint32_t OTYPER;   /*GPIO Port output type        register*/
		volatile uint32_t OSPEEDR;  /*GPIO Port output speed       register*/
		volatile uint32_t PUPDR;    /*GPIO Port pullup/down        register*/
		volatile uint32_t IDR;      /*GPIO Port input data         register*/
		volatile uint32_t ODR;      /*GPIO Port output data        register*/
		volatile uint32_t BSRR;     /*GPIO Port bit set/reset      register*/
		volatile uint32_t LCKR;     /*GPIO Port lock               register*/
		volatile uint32_t AFR[2]; 	/*GPIO Port alternate function registers*/// Because there are high and low registers
}GPIO_RegDef_t;

/*********** GPIOA peripheral definitions ********************/
#define GPIOx(OFFSET)	((GPIO_RegDef_t*)(GPIOA_BASE_ADDRESS+OFFSET))
#define GPIOA			((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)	
#define GPIOB			((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)	
#define GPIOC			((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)	
#define GPIOD			((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)	
#define GPIOE			((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)	
#define GPIOF			((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)	
#define GPIOG			((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)	
#define GPIOH			((GPIO_RegDef_t*)GPIOH_BASE_ADDRESS)

/**************************************************************/
/************** RCC Register definition structure**************/
/**************************************************************/
typedef struct
{
		volatile uint32_t RCC_CR;
		volatile uint32_t RCC_PLLCFGR;
		volatile uint32_t RCC_CFGR;
		volatile uint32_t RCC_CIR;
		volatile uint32_t RCC_AHB1RSTR;
		volatile uint32_t RCC_AHB2RSTR;
		volatile uint32_t RCC_AHB3RSTR;
		volatile uint32_t RESERVED0;
		volatile uint32_t RCC_APB1RSTR;
		volatile uint32_t RCC_APB2RSTR;
		volatile uint32_t RESERVED1;
		volatile uint32_t RESERVED2;
		volatile uint32_t RCC_AHB1ENR;
		volatile uint32_t RCC_AHB2ENR;
		volatile uint32_t RCC_AHB3ENR;
		volatile uint32_t RESERVED3;
		volatile uint32_t RCC_APB1ENR;
		volatile uint32_t RCC_APB2ENR;
		volatile uint32_t RESERVED4;
		volatile uint32_t RESERVED5;
		volatile uint32_t RCC_AHB1LPENR;
		volatile uint32_t RCC_AHB2LPENR;
		volatile uint32_t RCC_AHB3LPENR;
		volatile uint32_t RESERVED6;
		volatile uint32_t RCC_APB1LPENR;
		volatile uint32_t RCC_APB2LPENR;
		volatile uint32_t RESERVED7;
		volatile uint32_t RESERVED8;
		volatile uint32_t RCC_BDCR;
		volatile uint32_t RCC_CSR;
		volatile uint32_t RESERVED9;
		volatile uint32_t RESERVED10;
		volatile uint32_t RCC_SSCGR;
		volatile uint32_t RCC_PLLI2SCFGR;
		volatile uint32_t RCC_PLLSAICFGR;
		volatile uint32_t RCC_DCKCFGR;
		volatile uint32_t RCC_CKGATENR;
		volatile uint32_t RCC_DCKCFGR2;
}RCC_RegDef_t;
/*********** RCC peripheral definitions ********************/
#define RCC			((RCC_RegDef_t*)RCC_BASE_ADDRESS)
/***********************************************************/

/**************************************************************/
/************** SysTick Register definition structure**********/
/**************************************************************/
typedef struct
{
		volatile uint32_t STK_CTRL;
		volatile uint32_t STK_LOAD;
		volatile uint32_t STK_VAL;
		volatile uint32_t STK_CALIB;
}SYSTICK_RegDef_t;
/*********** SysTick peripheral definitions ********************/
#define SYSTICK			((SYSTICK_RegDef_t*)SYSTICK_BASE_ADDRESS)
/***********************************************************/

/**************************************************************/
/************** NVIC Register definition structure**********/
/**************************************************************/
typedef struct
{
	// Carefully, look at register offsets
	volatile uint32_t NVIC_ISER     [ 8  ];//8 registers(each = 4 bytes)
	volatile uint32_t NVIC_RESERVED0[ 24 ];
	volatile uint32_t NVIC_ICER     [ 8  ];
	volatile uint32_t NVIC_RESERVED1[ 24 ];
	volatile uint32_t NVIC_ISPR     [ 8  ];
	volatile uint32_t NVIC_RESERVED2[ 24 ];
	volatile uint32_t NVIC_ICPR     [ 8  ];
	volatile uint32_t NVIC_RESERVED3[ 24 ];
	volatile uint32_t NVIC_IABR     [ 8  ];
	volatile uint32_t NVIC_RESERVED4[ 24 ];
	volatile uint32_t NVIC_RESERVED5[ 32 ];
	volatile uint8_t  NVIC_IPR      [ 240];
}NVIC_RegDef_t;
/*********** NVIC peripheral definitions ********************/
#define NVIC			((NVIC_RegDef_t*    )NVIC_BASE_ADDRESS     )
#define NVIC_STIR		((volatile uint32_t*)NVIC_STIR_BASE_ADDRESS)
/***********************************************************/

/************** SCB Register definition structure**********/
typedef struct{

	volatile uint32_t SCB_CPUID;
	volatile uint32_t SCB_ICSR;
	volatile uint32_t SCB_VTOR;
	volatile uint32_t SCB_AIRCR;
	volatile uint32_t SCB_SCR;
	volatile uint32_t SCB_CCR;
	volatile uint32_t SCB_SHPR1;
	volatile uint32_t SCB_SHPR2;
	volatile uint32_t SCB_SHPR3;
	volatile uint32_t SCB_SHCSR;
	volatile uint32_t SCB_CFSR;
	volatile uint32_t SCB_HFSR;
	volatile uint32_t SCB_RESERVED;
	volatile uint32_t SCB_MMFAR;
	volatile uint32_t SCB_BFAR;
}SCB_RegDef_t;
typedef union 
{ 
	uint32_t 	DWORD;
	struct 
	{
		uint32_t VECTACTIVE   :9;
		uint32_t          	  :2;
		uint32_t RETTOBASE    :1;
		uint32_t VECTPENDING  :6;
		uint32_t			  :4;
		uint32_t ISRPENDING   :1;
		uint32_t DEBUGSTATUS  :1;
		uint32_t          	  :1;
		uint32_t PENDSTCLR	  :1;
		uint32_t PENDSTSET    :1;
		uint32_t PENDSVCLR    :1;
		uint32_t PENDSVSET    :1;
		uint32_t              :2;
		uint32_t NMIPENDSET   :1; 
	} BIT;/*4.3.3 Interrupt Control and State Register*/
} SCB_ICSR_Tag;


typedef union
{
	uint32_t	DWORD;
	struct 
	{
		uint32_t MEMFAULTACT   :1;
		uint32_t BUSFAULTACT   :1;
		uint32_t     		   :1;
		uint32_t USGFAULTACT   :1;
		uint32_t			   :3;
		uint32_t SVCALLACT     :1;
		uint32_t MONITORACT    :1;
		uint32_t          	   :1;
		uint32_t PENDSVACT	   :1;
		uint32_t SYSTICKACT    :1;
		uint32_t USGFAULTPENDED:1;
		uint32_t MEMFAULTPENDED:1;
		uint32_t BUSFAULTPENDED:1;
		uint32_t SVCALLPENDED  :1;
		uint32_t MEMFAULTENA   :1;
		uint32_t BUSFAULTENA   :1;
		uint32_t USGFAULTENA   :1;
		uint32_t          	   :13;
	}BIT;	
}SCB_SHCSR_Tag;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define SCB_ICSR                                ((volatile  SCB_ICSR_Tag*)(SCB_BASE_ADDRESS+0x04))
#define SCB_AIRCR                              *((volatile uint32_t*     )(SCB_BASE_ADDRESS+0x0C))
#define SCB_SHCSR                               ((volatile SCB_SHCSR_Tag*)(SCB_BASE_ADDRESS+0x24))

/*********** SCB peripheral definitions ********************/
#define SCB         ((volatile SCB_RegDef_t *) SCB_BASE_ADDRESS )
/**************************************************************/



#endif
/************************************************TM4c123**************************************************************/
/************************************************TM4c123**************************************************************/
/************************************************TM4c123**************************************************************/
/************************************************TM4c123**************************************************************/
#elif USED_MCU == TM4c123

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32_t VECTACTIVE   :9;
    uint32_t          	  :2;
    uint32_t RETTOBASE    :1;
    uint32_t VECTPENDING  :6;
	uint32_t			  :4;
    uint32_t ISRPENDING   :1;
    uint32_t DEBUGSTATUS  :1;
	uint32_t          	  :1;
    uint32_t PENDSTCLR	  :1;
    uint32_t PENDSTSET    :1;
    uint32_t PENDSVCLR    :1;
    uint32_t PENDSVSET    :1;
    uint32_t              :2;
    uint32_t NMIPENDSET   :1; 
} ICSR_BF;/*4.3.3 Interrupt Control and State Register*/
typedef union 
{
    uint32_t R;
     ICSR_BF B;
} ICSR_Tag;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define AIRCR                                  *((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define  ICSR                                *((volatile  ICSR_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  

#endif/* MCU_HW_H */ 
/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
