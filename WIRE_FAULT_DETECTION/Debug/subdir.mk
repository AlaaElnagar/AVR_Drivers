################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Prog.c \
../DIO_Program.c \
../GIE_Program.c \
../LCD_Program.c \
../Timer1_Prog.c \
../main.c 

OBJS += \
./ADC_Prog.o \
./DIO_Program.o \
./GIE_Program.o \
./LCD_Program.o \
./Timer1_Prog.o \
./main.o 

C_DEPS += \
./ADC_Prog.d \
./DIO_Program.d \
./GIE_Program.d \
./LCD_Program.d \
./Timer1_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


