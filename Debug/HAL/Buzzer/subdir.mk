################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Buzzer/Buzzer.c 

OBJS += \
./HAL/Buzzer/Buzzer.o 

C_DEPS += \
./HAL/Buzzer/Buzzer.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Buzzer/%.o: ../HAL/Buzzer/%.c HAL/Buzzer/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


