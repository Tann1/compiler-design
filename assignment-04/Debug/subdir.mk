################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Pascal.cpp 

CPP_DEPS += \
./Pascal.d 

OBJS += \
./Pascal.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tanishq/eclipse-workspace/assignment-04" -I"/home/tanishq/eclipse-workspace/assignment-04/target/generated-sources/antlr4" -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Pascal.d ./Pascal.o

.PHONY: clean--2e-

