#include "main.h"
void SysTick_Handler(void);
extern Port_ConfigType AllPinConfigs[NUM_OF_USED_PINS];
extern const Gpt_ConfigType    Gpt_Configs;
uint32_t Counter1=0;
uint32_t Counter2=0;
volatile uint16_t i=0;

#define EnablePrivilegedMode()
void ReadCONTROL(void)
{
	uint32_t ControlReg;
	__asm volatile ("MRS %0, CONTROL":"=r"(ControlReg):);
}

int main()
{
	__asm volatile ("SVC #0x32");
	RCC->RCC_AHB1ENR |=(1<<0);
	RCC->RCC_APB1ENR |=(1<<0);/*TIM2EN*/
	RCC->RCC_APB2ENR |=(1<<0);/*TIM1EN*/
    NVIC_Init();
    Port_Init(&AllPinConfigs);
    Gpt_Init(&Gpt_Configs);
    Gpt_EnableNotification(GPT_TIMER_CHANNEL_2);
    Gpt_StartTimer(GPT_TIMER_CHANNEL_2, 0xFFFE);
    LED_Init();


    while(1)
    {
    	//LED_Blink(LED_0, 1000, 500);
    	Counter1=Gpt_GetTimeRemaining(GPT_TIMER_CHANNEL_1);
    	Counter2=Gpt_GetTimeRemaining(GPT_TIMER_CHANNEL_2);
    }
}

void SVC_Handler(void)
{
	__asm volatile ("MOV R10,#80");
	__asm volatile ("MSR BASEPRI,R10");
}
void SysTick_Handler(void)
{
	Dio_FlipChannel(Dio_CHANNEL_PA5);
}
void TIM1_CC_IRQHandler(void)
{
	Dio_FlipChannel(Dio_CHANNEL_PA5);
}
void TIM1_BRK_TIM9_IRQHandler (void)
{
	Dio_FlipChannel(Dio_CHANNEL_PA5);
}
void TIM1_UP_TIM10_IRQHandler(void)
{
	Dio_FlipChannel(Dio_CHANNEL_PA5);
}
void TIM1_TRG_COM_TIM11_IRQHandler(void)
{
	Dio_FlipChannel(Dio_CHANNEL_PA5);
}
void TIM2_IRQHandler(void)
{
	Dio_FlipChannel(Dio_CHANNEL_PA5);
}

