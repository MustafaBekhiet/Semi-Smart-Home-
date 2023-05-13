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
Semi_SmartHome.lss \

FLASH_IMAGE += \
Semi_SmartHome.hex \

EEPROM_IMAGE += \
Semi_SmartHome.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Semi_SmartHome.elf secondary-outputs

# Tool invocations
Semi_SmartHome.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Semi_SmartHome.map -mmcu=atmega32 -o "Semi_SmartHome.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Semi_SmartHome.lss: Semi_SmartHome.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Semi_SmartHome.elf  >"Semi_SmartHome.lss"
	@echo 'Finished building: $@'
	@echo ' '

Semi_SmartHome.hex: Semi_SmartHome.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Semi_SmartHome.elf  "Semi_SmartHome.hex"
	@echo 'Finished building: $@'
	@echo ' '

Semi_SmartHome.eep: Semi_SmartHome.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Semi_SmartHome.elf  "Semi_SmartHome.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Semi_SmartHome.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Semi_SmartHome.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Semi_SmartHome.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
