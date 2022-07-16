################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Mcal/PORT/PORT.c 

OBJS += \
./Src/Mcal/PORT/PORT.o 

C_DEPS += \
./Src/Mcal/PORT/PORT.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Mcal/PORT/%.o: ../Src/Mcal/PORT/%.c Src/Mcal/PORT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Mcal-2f-PORT

clean-Src-2f-Mcal-2f-PORT:
	-$(RM) ./Src/Mcal/PORT/PORT.d ./Src/Mcal/PORT/PORT.o

.PHONY: clean-Src-2f-Mcal-2f-PORT

