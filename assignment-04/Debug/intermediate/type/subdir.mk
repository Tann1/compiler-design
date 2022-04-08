################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../intermediate/type/TypeChecker.cpp 

CPP_DEPS += \
./intermediate/type/TypeChecker.d 

OBJS += \
./intermediate/type/TypeChecker.o 


# Each subdirectory must supply rules for building sources it contributes
intermediate/type/%.o: ../intermediate/type/%.cpp intermediate/type/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tanishq/eclipse-workspace/assignment-04" -I"/home/tanishq/eclipse-workspace/assignment-04/target/generated-sources/antlr4" -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-intermediate-2f-type

clean-intermediate-2f-type:
	-$(RM) ./intermediate/type/TypeChecker.d ./intermediate/type/TypeChecker.o

.PHONY: clean-intermediate-2f-type

