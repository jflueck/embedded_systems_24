################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 9
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include src/lab3/subdir.mk
-include src/lib/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ecs.elf \

EXECUTABLES_QUOTED += \
"ecs.elf" \

EXECUTABLES_OS_FORMAT += \
ecs.elf \

SECONDARY_SIZE += \
ecs.siz \
ecs.siz \

SECONDARY_SIZE_QUOTED += \
"ecs.siz" \
"ecs.siz" \

SECONDARY_SIZE_OS_FORMAT += \
ecs.siz \
ecs.siz \

SECONDARY_SIZE += \
ecs.siz \
ecs.siz \

SECONDARY_SIZE_QUOTED += \
"ecs.siz" \
"ecs.siz" \

SECONDARY_SIZE_OS_FORMAT += \
ecs.siz \
ecs.siz \


# All Target
all: warning-messages explicit-dependencies ecs.elf secondary-outputs

# Tool invocations
ecs.elf: $(OBJS) C:/Users/ecs/Desktop/embedded_systems_24/work/ecs/Project_Settings/Linker_Files/S32K1xx_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #10 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "ecs.elf" "@ecs.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

ecs.siz: $(EXECUTABLES)
	@echo 'Executing target #11 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*/*.d  ./*/*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE) $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

