################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/Stepper_Motor/Stepper_prog.c 

OBJS += \
./HALL/Stepper_Motor/Stepper_prog.o 

C_DEPS += \
./HALL/Stepper_Motor/Stepper_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/Stepper_Motor/%.o: ../HALL/Stepper_Motor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


