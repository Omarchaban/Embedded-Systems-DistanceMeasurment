################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../LCD.c \
../TIMER1.c \
../Ultrasonic.c \
../icu.c \
../main.c 

OBJS += \
./DIO.o \
./LCD.o \
./TIMER1.o \
./Ultrasonic.o \
./icu.o \
./main.o 

C_DEPS += \
./DIO.d \
./LCD.d \
./TIMER1.d \
./Ultrasonic.d \
./icu.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


