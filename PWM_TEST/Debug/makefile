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
PWM_TEST.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
PWM_TEST.list \

OBJCOPY_BIN += \
PWM_TEST.bin \


# All Target
all: PWM_TEST.elf secondary-outputs

# Tool invocations
PWM_TEST.elf: $(OBJS) $(USER_OBJS) /Users/massimomerenda/STM32CubeIDE/workspace_1.0.0/PWM_TEST/STM32F401RETX_FLASH.ld
	arm-none-eabi-gcc -o "PWM_TEST.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/Users/massimomerenda/STM32CubeIDE/workspace_1.0.0/PWM_TEST/STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="PWM_TEST.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

PWM_TEST.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "PWM_TEST.list"
	@echo 'Finished building: $@'
	@echo ' '

PWM_TEST.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "PWM_TEST.bin"
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
