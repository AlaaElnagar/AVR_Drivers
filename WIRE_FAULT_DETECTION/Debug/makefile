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
WIRE_FAULT_DETECTION.lss \

FLASH_IMAGE += \
WIRE_FAULT_DETECTION.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: WIRE_FAULT_DETECTION.elf secondary-outputs

# Tool invocations
WIRE_FAULT_DETECTION.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,WIRE_FAULT_DETECTION.map -mmcu=atmega32 -o "WIRE_FAULT_DETECTION.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

WIRE_FAULT_DETECTION.lss: WIRE_FAULT_DETECTION.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S WIRE_FAULT_DETECTION.elf  >"WIRE_FAULT_DETECTION.lss"
	@echo 'Finished building: $@'
	@echo ' '

WIRE_FAULT_DETECTION.hex: WIRE_FAULT_DETECTION.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex WIRE_FAULT_DETECTION.elf  "WIRE_FAULT_DETECTION.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: WIRE_FAULT_DETECTION.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 WIRE_FAULT_DETECTION.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) WIRE_FAULT_DETECTION.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
