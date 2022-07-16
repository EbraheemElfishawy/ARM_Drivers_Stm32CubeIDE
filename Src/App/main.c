#include "main.h"

extern Port_ConfigType AllPinConfigs[NUM_OF_USED_PINS];
int main()
{
    NVIC_Init();
    RCC->RCC_AHB1ENR |=(1<<0);
    Port_Init(&AllPinConfigs);
    Dio_ReadChannel(Dio_CHANNEL_PA5);
    while(1)
    {
    	Dio_FlipChannel(Dio_CHANNEL_PA5);
    	Dio_FlipChannel(Dio_CHANNEL_PA5);
    	Dio_FlipChannel(Dio_CHANNEL_PA5);
    	Dio_FlipChannel(Dio_CHANNEL_PA5);
    	Dio_FlipChannel(Dio_CHANNEL_PA5);
    	Dio_FlipChannel(Dio_CHANNEL_PA5);
    	//for(uint8_t i=0;i<1000000;i++);
    }
} 
