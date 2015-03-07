################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../communication.c \
../file_manager.c \
../lib.c \
../main.c \
../user_interface.c \
../user_manager.c 

OBJS += \
./communication.o \
./file_manager.o \
./lib.o \
./main.o \
./user_interface.o \
./user_manager.o 

C_DEPS += \
./communication.d \
./file_manager.d \
./lib.d \
./main.d \
./user_interface.d \
./user_manager.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


