################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../intermediate/util/CrossReferencer.cpp 

CPP_DEPS += \
./intermediate/util/CrossReferencer.d 

OBJS += \
./intermediate/util/CrossReferencer.o 


# Each subdirectory must supply rules for building sources it contributes
intermediate/util/%.o: ../intermediate/util/%.cpp intermediate/util/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tanishq/eclipse-workspace/assignment-04" -I"/home/tanishq/eclipse-workspace/assignment-04/target/generated-sources/antlr4" -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-intermediate-2f-util

clean-intermediate-2f-util:
	-$(RM) ./intermediate/util/CrossReferencer.d ./intermediate/util/CrossReferencer.o

.PHONY: clean-intermediate-2f-util

