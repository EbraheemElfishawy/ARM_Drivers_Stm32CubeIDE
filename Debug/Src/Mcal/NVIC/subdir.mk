################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Mcal/NVIC/NVIC.c 

OBJS += \
./Src/Mcal/NVIC/NVIC.o 

C_DEPS += \
./Src/Mcal/NVIC/NVIC.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Mcal/NVIC/%.o: ../Src/Mcal/NVIC/%.c Src/Mcal/NVIC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Mcal-2f-NVIC

clean-Src-2f-Mcal-2f-NVIC:
	-$(RM) ./Src/Mcal/NVIC/NVIC.d ./Src/Mcal/NVIC/NVIC.o

.PHONY: clean-Src-2f-Mcal-2f-NVIC

