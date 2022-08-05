################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Code/DIO.c \
../Code/LCD.c \
../Code/Ultrasonic.c \
../Code/icu.c \
../Code/main.c 

OBJS += \
./Code/DIO.o \
./Code/LCD.o \
./Code/Ultrasonic.o \
./Code/icu.o \
./Code/main.o 

C_DEPS += \
./Code/DIO.d \
./Code/LCD.d \
./Code/Ultrasonic.d \
./Code/icu.d \
./Code/main.d 


# Each subdirectory must supply rules for building sources it contributes
Code/%.o: ../Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


