################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../assets/commands/addCredit.o \
../assets/commands/addCredit_admin.o \
../assets/commands/buy.o \
../assets/commands/create.o \
../assets/commands/delete.o \
../assets/commands/refund.o \
../assets/commands/sell.o 

CPP_SRCS += \
../assets/commands/addCredit.cpp \
../assets/commands/addCredit_admin.cpp \
../assets/commands/buy.cpp \
../assets/commands/create.cpp \
../assets/commands/delete.cpp \
../assets/commands/refund.cpp \
../assets/commands/sell.cpp 

OBJS += \
./assets/commands/addCredit.o \
./assets/commands/addCredit_admin.o \
./assets/commands/buy.o \
./assets/commands/create.o \
./assets/commands/delete.o \
./assets/commands/refund.o \
./assets/commands/sell.o 

CPP_DEPS += \
./assets/commands/addCredit.d \
./assets/commands/addCredit_admin.d \
./assets/commands/buy.d \
./assets/commands/create.d \
./assets/commands/delete.d \
./assets/commands/refund.d \
./assets/commands/sell.d 


# Each subdirectory must supply rules for building sources it contributes
assets/commands/%.o: ../assets/commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


