################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/Mcal/PORT/subdir.mk
-include Src/Mcal/NVIC/subdir.mk
-include Src/Mcal/GPT/subdir.mk
-include Src/Mcal/DIO/subdir.mk
-include Src/Config/PORT/subdir.mk
-include Src/Config/NVIC_Cfg/subdir.mk
-include Src/Config/GPT/subdir.mk
-include Src/Config/DIO/subdir.mk
-include Src/App/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := FWD_Internship
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
FWD_Internship.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
FWD_Internship.list \

OBJCOPY_BIN += \
FWD_Internship.bin \


# All Target
all: main-build

# Main-build Target
main-build: FWD_Internship.elf secondary-outputs

# Tool invocations
FWD_Internship.elf: $(OBJS) $(USER_OBJS) H:\FWD\ARM\Stm32CubeIDE_Workplace\FWD_Internship\STM32F446RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "FWD_Internship.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"H:\FWD\ARM\Stm32CubeIDE_Workplace\FWD_Internship\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="FWD_Internship.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

FWD_Internship.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "FWD_Internship.list"
	@echo 'Finished building: $@'
	@echo ' '

FWD_Internship.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "FWD_Internship.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) FWD_Internship.bin FWD_Internship.elf FWD_Internship.list default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
