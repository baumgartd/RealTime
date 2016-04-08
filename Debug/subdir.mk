################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GPIO.cpp \
../GamePlayer.cpp \
../Main.cpp \
../PWM.cpp \
../util.cpp 

OBJS += \
./GPIO.o \
./GamePlayer.o \
./Main.o \
./PWM.o \
./util.o 

CPP_DEPS += \
./GPIO.d \
./GamePlayer.d \
./Main.d \
./PWM.d \
./util.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


