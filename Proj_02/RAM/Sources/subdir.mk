################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/MCF52259_sysinit.c" \
"../Sources/exceptions.c" \
"../Sources/led.c" \
"../Sources/main.c" \
"../Sources/uart_support.c" \

C_SRCS += \
../Sources/MCF52259_sysinit.c \
../Sources/exceptions.c \
../Sources/led.c \
../Sources/main.c \
../Sources/uart_support.c \

OBJS += \
./Sources/MCF52259_sysinit_c.obj \
./Sources/exceptions_c.obj \
./Sources/led_c.obj \
./Sources/main_c.obj \
./Sources/uart_support_c.obj \

OBJS_QUOTED += \
"./Sources/MCF52259_sysinit_c.obj" \
"./Sources/exceptions_c.obj" \
"./Sources/led_c.obj" \
"./Sources/main_c.obj" \
"./Sources/uart_support_c.obj" \

C_DEPS += \
./Sources/MCF52259_sysinit_c.d \
./Sources/exceptions_c.d \
./Sources/led_c.d \
./Sources/main_c.d \
./Sources/uart_support_c.d \

OBJS_OS_FORMAT += \
./Sources/MCF52259_sysinit_c.obj \
./Sources/exceptions_c.obj \
./Sources/led_c.obj \
./Sources/main_c.obj \
./Sources/uart_support_c.obj \

C_DEPS_QUOTED += \
"./Sources/MCF52259_sysinit_c.d" \
"./Sources/exceptions_c.d" \
"./Sources/led_c.d" \
"./Sources/main_c.d" \
"./Sources/uart_support_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/MCF52259_sysinit_c.obj: ../Sources/MCF52259_sysinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/MCF52259_sysinit.args" -o "Sources/MCF52259_sysinit_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/exceptions_c.obj: ../Sources/exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/exceptions.args" -o "Sources/exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/led_c.obj: ../Sources/led.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/led.args" -o "Sources/led_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/uart_support_c.obj: ../Sources/uart_support.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/uart_support.args" -o "Sources/uart_support_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


