################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO.c \
../LCD.c \
../MiniProject4.c \
../UltaSonic.c \
../icu.c 

OBJS += \
./GPIO.o \
./LCD.o \
./MiniProject4.o \
./UltaSonic.o \
./icu.o 

C_DEPS += \
./GPIO.d \
./LCD.d \
./MiniProject4.d \
./UltaSonic.d \
./icu.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


