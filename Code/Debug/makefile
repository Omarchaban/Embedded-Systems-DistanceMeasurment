################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Distance_Measuring.lss \

FLASH_IMAGE += \
Distance_Measuring.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Distance_Measuring.elf secondary-outputs

# Tool invocations
Distance_Measuring.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Distance_Measuring.map -mmcu=atmega16 -o "Distance_Measuring.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Distance_Measuring.lss: Distance_Measuring.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Distance_Measuring.elf  >"Distance_Measuring.lss"
	@echo 'Finished building: $@'
	@echo ' '

Distance_Measuring.hex: Distance_Measuring.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Distance_Measuring.elf  "Distance_Measuring.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Distance_Measuring.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Distance_Measuring.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Distance_Measuring.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
