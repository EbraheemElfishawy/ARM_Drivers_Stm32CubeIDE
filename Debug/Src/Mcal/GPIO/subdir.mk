################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Mcal/GPIO/GPIO.c 

OBJS += \
./Src/Mcal/GPIO/GPIO.o 

C_DEPS += \
./Src/Mcal/GPIO/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Mcal/GPIO/%.o: ../Src/Mcal/GPIO/%.c Src/Mcal/GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Mcal-2f-GPIO

clean-Src-2f-Mcal-2f-GPIO:
	-$(RM) ./Src/Mcal/GPIO/GPIO.d ./Src/Mcal/GPIO/GPIO.o

.PHONY: clean-Src-2f-Mcal-2f-GPIO

