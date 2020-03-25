################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
USART\ Example\ 2.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
USART\ Example\ 2.list \

OBJCOPY_BIN += \
USART\ Example\ 2.bin \


# All Target
all: USART\ Example\ 2.elf secondary-outputs

# Tool invocations
USART\ Example\ 2.elf: $(OBJS) $(USER_OBJS) /Users/massimomerenda/Documents/STM32_NUCLEO_F401RE/USART\ Example\ 2/STM32F401RETX_FLASH.ld
	arm-none-eabi-gcc -o "USART Example 2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/Users/massimomerenda/Documents/STM32_NUCLEO_F401RE/USART Example 2/STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="USART Example 2.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

USART\ Example\ 2.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "USART Example 2.list"
	@echo 'Finished building: $@'
	@echo ' '

USART\ Example\ 2.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "USART Example 2.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
