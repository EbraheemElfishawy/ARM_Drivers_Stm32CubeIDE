#include "main.h"
void SysTick_Handler(void);
extern Port_ConfigType AllPinConfigs[NUM_OF_USED_PINS];
extern const Gpt_ConfigType    Gpt_Configs;
uint32_t Counter=0;
volatile uint16_t i=0;
void delay_ms(uint32_t delay)
{
	uint32_t Current = Gpt_GetTimeRemaining(GPT_TIMER_CHANNEL_2);
	while((  Gpt_GetTimeRemaining(GPT_TIMER_CHANNEL_2) -Current ) < (delay*16000) );
}
int main()
{
    NVIC_Init();
    RCC->RCC_AHB1ENR |=(1<<0);/*GPIOAEN*/
    RCC->RCC_APB1ENR |=(1<<0);/*TIM2EN*/
//    RCC->RCC_APB1ENR |=(1<<2);/*TIM4EN*/
//    RCC->RCC_APB1ENR |=(1<<2);/*TIM4EN*/
//    RCC->RCC_APB2ENR |=(1<<3);/*TIM5EN*/
//    RCC->RCC_APB2ENR |=(1<<5);/*TIM7EN*/
    Port_Init(&AllPinConfigs);
    Gpt_Init(&Gpt_Configs);
    Dio_ReadChannel(Dio_CHANNEL_PA5);
	Gpt_EnableNotification(GPT_TIMER_CHANNEL_15);
	Gpt_EnableNotification(GPT_TIMER_CHANNEL_2);
    //Gpt_StartTimer(GPT_TIMER_CHANNEL_4, 1000000);
	Gpt_StartTimer(GPT_TIMER_CHANNEL_2, 100);
    while(1)
    {
    	Counter=Gpt_GetTimeRemaining(GPT_TIMER_CHANNEL_2);
    		Dio_FlipChannel(Dio_CHANNEL_PA5);
    		delay_ms(500);
    		i++;
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
