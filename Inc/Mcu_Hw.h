
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
/*********************** 	AHB3 Peripheral base addresses 		**************************/

/*********************** 	AHB2 Peripheral base addresses 		**************************/

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

/*********************** 	APB2 Peripheral base addresses 		**************************/

/*f446re ref manual 2.2.2 Memory map and register boundary addresses page 58*/
#define TIM11_BASE_ADDRESS	0x40014800 /*0x4001 4800 - 0x4001 4BFF*/
#define TIM10_BASE_ADDRESS	0x40014400 /*0x4001 4400 - 0x4001 47FF*/
#define TIM9_BASE_ADDRESS	0x40014000 /*0x4001 4000 - 0x4001 43FF*/

#define TIM8_BASE_ADDRESS	0x40010400 /*0x4001 0400 - 0x4001 07FF*/
#define TIM1_BASE_ADDRESS	0x40010000 /*0x4001 0000 - 0x4001 03FF*/

/*********************** 	APB1 Peripheral base addresses 		**************************/
/*f446re ref manual 2.2.2 Memory map and register boundary addresses page 59*/
#define TIM14_BASE_ADDRESS	0x40002000 /*0x4000 2000 - 0x4000 23FF*/
#define TIM13_BASE_ADDRESS	0x40001C00 /*0x4000 1C00 - 0x4000 1FFF*/
#define TIM12_BASE_ADDRESS	0x40001800 /*0x4000 1800 - 0x4000 1BFF*/
#define TIM7_BASE_ADDRESS	0x40001400 /*0x4000 1400 - 0x4000 17FF*/
#define TIM6_BASE_ADDRESS	0x40001000 /*0x4000 1000 - 0x4000 13FF*/
#define TIM5_BASE_ADDRESS	0x40000C00 /*0x4000 0C00 - 0x4000 0FFF*/
#define TIM4_BASE_ADDRESS	0x40000800 /*0x4000 0800 - 0x4000 0BFF*/
#define TIM3_BASE_ADDRESS	0x40000400 /*0x4000 0400 - 0x4000 07FF*/
#define TIM2_BASE_ADDRESS	0x40000000 /*0x4000 0000 - 0x4000 03FF*/



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
#define NVIC_STIR		*((volatile uint32_t*)NVIC_STIR_BASE_ADDRESS)
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
/*********** SCB peripheral definitions ********************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define SCB        							    ((volatile SCB_RegDef_t *)(SCB_BASE_ADDRESS     ))
#define SCB_ICSR                                ((volatile  SCB_ICSR_Tag*)(SCB_BASE_ADDRESS+0x04))
#define SCB_AIRCR                              *((volatile uint32_t*     )(SCB_BASE_ADDRESS+0x0C))
#define SCB_SHCSR                               ((volatile SCB_SHCSR_Tag*)(SCB_BASE_ADDRESS+0x24))

/***********************************************************************************************************************/
/*************************************************************/	
/*********** TIMERS Register definition structure *************/
/*************************************************************/
/** 
  * @brief TIM
  */

typedef struct
{
   uint32_t CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
   uint32_t CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
   uint32_t SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
   uint32_t DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
   uint32_t SR;          /*!< TIM status register,                 Address offset: 0x10 */
   uint32_t EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
   uint32_t CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
   uint32_t CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
   uint32_t CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
   uint32_t CNT;         /*!< TIM counter register,                Address offset: 0x24 */
   uint32_t PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
   uint32_t ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
   uint32_t RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
   uint32_t CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
   uint32_t CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
   uint32_t CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
   uint32_t CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
   uint32_t BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
   uint32_t DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
   uint32_t DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
   uint32_t OR;          /*!< TIM option register,                 Address offset: 0x50 */
} TIM_RegDef_t;
/*********** TIMERS peripheral definitions ********************/
#define TIM14	((TIM_RegDef_t*)TIM14_BASE_ADDRESS)
#define TIM13	((TIM_RegDef_t*)TIM13_BASE_ADDRESS)
#define TIM12	((TIM_RegDef_t*)TIM12_BASE_ADDRESS)
#define TIM7	((TIM_RegDef_t*)TIM7_BASE_ADDRESS )
#define TIM6	((TIM_RegDef_t*)TIM6_BASE_ADDRESS )
#define TIM5	((TIM_RegDef_t*)TIM5_BASE_ADDRESS )
#define TIM4	((TIM_RegDef_t*)TIM4_BASE_ADDRESS )
#define TIM3	((TIM_RegDef_t*)TIM3_BASE_ADDRESS )
#define TIM2	((TIM_RegDef_t*)TIM2_BASE_ADDRESS )
#define TIM8	((TIM_RegDef_t*)TIM8_BASE_ADDRESS )
#define TIM1	((TIM_RegDef_t*)TIM1_BASE_ADDRESS )
#define TIM11	((TIM_RegDef_t*)TIM11_BASE_ADDRESS)
#define TIM10	((TIM_RegDef_t*)TIM10_BASE_ADDRESS)
#define TIM9	((TIM_RegDef_t*)TIM9_BASE_ADDRESS )

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
