################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/lib/LPUART.c" \
"../src/lib/adc.c" \
"../src/lib/ecs.c" \
"../src/lib/gpio.c" \
"../src/lib/interrupt_manager.c" \

C_SRCS += \
../src/lib/LPUART.c \
../src/lib/adc.c \
../src/lib/ecs.c \
../src/lib/gpio.c \
../src/lib/interrupt_manager.c \

OBJS_OS_FORMAT += \
./src/lib/LPUART.o \
./src/lib/adc.o \
./src/lib/ecs.o \
./src/lib/gpio.o \
./src/lib/interrupt_manager.o \

C_DEPS_QUOTED += \
"./src/lib/LPUART.d" \
"./src/lib/adc.d" \
"./src/lib/ecs.d" \
"./src/lib/gpio.d" \
"./src/lib/interrupt_manager.d" \

OBJS += \
./src/lib/LPUART.o \
./src/lib/adc.o \
./src/lib/ecs.o \
./src/lib/gpio.o \
./src/lib/interrupt_manager.o \

OBJS_QUOTED += \
"./src/lib/LPUART.o" \
"./src/lib/adc.o" \
"./src/lib/ecs.o" \
"./src/lib/gpio.o" \
"./src/lib/interrupt_manager.o" \

C_DEPS += \
./src/lib/LPUART.d \
./src/lib/adc.d \
./src/lib/ecs.d \
./src/lib/gpio.d \
./src/lib/interrupt_manager.d \


# Each subdirectory must supply rules for building sources it contributes
src/lib/LPUART.o: ../src/lib/LPUART.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lib/LPUART.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/lib/LPUART.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lib/adc.o: ../src/lib/adc.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lib/adc.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/lib/adc.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lib/ecs.o: ../src/lib/ecs.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lib/ecs.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/lib/ecs.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lib/gpio.o: ../src/lib/gpio.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lib/gpio.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/lib/gpio.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lib/interrupt_manager.o: ../src/lib/interrupt_manager.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lib/interrupt_manager.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/lib/interrupt_manager.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


