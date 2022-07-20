#include "main.h"
void SysTick_Handler(void);
extern Port_ConfigType AllPinConfigs[NUM_OF_USED_PINS];
extern const Gpt_ConfigType    Gpt_Configs;
int main()
{
    NVIC_Init();
    RCC->RCC_AHB1ENR |=(1<<0);/*GPIOAEN*/
    RCC->RCC_APB1ENR |=(1<<2);/*TIM4EN*/
    Port_Init(&AllPinConfigs);
    Gpt_Init(&Gpt_Configs);
    Dio_ReadChannel(Dio_CHANNEL_PA5);
	Gpt_EnableNotification(GPT_TIMER_CHANNEL_15);
	Gpt_EnableNotification(GPT_TIMER_CHANNEL_4);
    Gpt_StartTimer(GPT_TIMER_CHANNEL_15, 1000000);
    Gpt_StartTimer(GPT_TIMER_CHANNEL_4, 1000);

    while(1)
    {

    }
} 
void SysTick_Handler(void)
{
	//Dio_FlipChannel(Dio_CHANNEL_PA5);
}
void TIM4_IRQHandler(void)
{
	Dio_FlipChannel(Dio_CHANNEL_PA5);
}
