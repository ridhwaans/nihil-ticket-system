################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../assets/Account.cpp \
../assets/Ticket.cpp \
../assets/Transaction.cpp \
../assets/TransactionFile.cpp \
../assets/errors.cpp \
../assets/functions.cpp \
../assets/variables.cpp 

OBJS += \
./assets/Account.o \
./assets/Ticket.o \
./assets/Transaction.o \
./assets/TransactionFile.o \
./assets/errors.o \
./assets/functions.o \
./assets/variables.o 

CPP_DEPS += \
./assets/Account.d \
./assets/Ticket.d \
./assets/Transaction.d \
./assets/TransactionFile.d \
./assets/errors.d \
./assets/functions.d \
./assets/variables.d 


# Each subdirectory must supply rules for building sources it contributes
assets/%.o: ../assets/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


