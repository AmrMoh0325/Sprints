################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Services/TDelay/subdir.mk
-include MCAL/Timer/subdir.mk
-include MCAL/PWM/subdir.mk
-include MCAL/EX_INT/subdir.mk
-include MCAL/DIO/subdir.mk
-include ECUAL/Ultrasonic/subdir.mk
-include ECUAL/SW_ICU/subdir.mk
-include ECUAL/LCD/subdir.mk
-include ECUAL/HBridge/subdir.mk
-include APP/HBridgeControl/subdir.mk
-include APP/GetDistance/subdir.mk
-include APP/DisplayDistance/subdir.mk
-include APP/CarControl/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := AutoCar3
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AutoCar3.lss \

FLASH_IMAGE += \
AutoCar3.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AutoCar3.elf secondary-outputs

# Tool invocations
AutoCar3.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AutoCar3.map -mmcu=atmega32 -o "AutoCar3.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AutoCar3.lss: AutoCar3.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AutoCar3.elf  >"AutoCar3.lss"
	@echo 'Finished building: $@'
	@echo ' '

AutoCar3.hex: AutoCar3.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AutoCar3.elf  "AutoCar3.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AutoCar3.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AutoCar3.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AutoCar3.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
