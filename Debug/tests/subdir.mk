################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/testAccount.cpp \
../tests/testAccounts.cpp \
../tests/testError.cpp \
../tests/testFunctions.cpp \
../tests/testTicket.cpp \
../tests/testTickets.cpp \
../tests/testTransaction.cpp 

OBJS += \
./tests/testAccount.o \
./tests/testAccounts.o \
./tests/testError.o \
./tests/testFunctions.o \
./tests/testTicket.o \
./tests/testTickets.o \
./tests/testTransaction.o 

CPP_DEPS += \
./tests/testAccount.d \
./tests/testAccounts.d \
./tests/testError.d \
./tests/testFunctions.d \
./tests/testTicket.d \
./tests/testTickets.d \
./tests/testTransaction.d 


# Each subdirectory must supply rules for building sources it contributes
tests/%.o: ../tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


