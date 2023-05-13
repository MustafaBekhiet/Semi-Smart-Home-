################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../Buzzer.c \
../DC_Moto.c \
../Exti.c \
../GPIO.c \
../Global_Program.c \
../KeyPad.c \
../LCD.c \
../LED.c \
../main.c \
../temperature.c 

OBJS += \
./ADC.o \
./Buzzer.o \
./DC_Moto.o \
./Exti.o \
./GPIO.o \
./Global_Program.o \
./KeyPad.o \
./LCD.o \
./LED.o \
./main.o \
./temperature.o 

C_DEPS += \
./ADC.d \
./Buzzer.d \
./DC_Moto.d \
./Exti.d \
./GPIO.d \
./Global_Program.d \
./KeyPad.d \
./LCD.d \
./LED.d \
./main.d \
./temperature.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


