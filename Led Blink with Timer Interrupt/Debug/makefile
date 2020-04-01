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
Led\ Blink\ with\ Timer\ Interrupt.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Led\ Blink\ with\ Timer\ Interrupt.list \

OBJCOPY_BIN += \
Led\ Blink\ with\ Timer\ Interrupt.bin \


# All Target
all: Led\ Blink\ with\ Timer\ Interrupt.elf secondary-outputs

# Tool invocations
Led\ Blink\ with\ Timer\ Interrupt.elf: $(OBJS) $(USER_OBJS) /Users/massimomerenda/Documents/STM32_NUCLEO_F401RE/Led\ Blink\ with\ Timer\ Interrupt/STM32F401RETX_FLASH.ld
	arm-none-eabi-gcc -o "Led Blink with Timer Interrupt.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/Users/massimomerenda/Documents/STM32_NUCLEO_F401RE/Led Blink with Timer Interrupt/STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Led Blink with Timer Interrupt.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Led\ Blink\ with\ Timer\ Interrupt.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Led Blink with Timer Interrupt.list"
	@echo 'Finished building: $@'
	@echo ' '

Led\ Blink\ with\ Timer\ Interrupt.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Led Blink with Timer Interrupt.bin"
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
