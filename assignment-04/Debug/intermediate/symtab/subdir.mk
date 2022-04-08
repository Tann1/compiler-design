################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../intermediate/symtab/Predefined.cpp 

CPP_DEPS += \
./intermediate/symtab/Predefined.d 

OBJS += \
./intermediate/symtab/Predefined.o 


# Each subdirectory must supply rules for building sources it contributes
intermediate/symtab/%.o: ../intermediate/symtab/%.cpp intermediate/symtab/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tanishq/eclipse-workspace/assignment-04" -I"/home/tanishq/eclipse-workspace/assignment-04/target/generated-sources/antlr4" -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-intermediate-2f-symtab

clean-intermediate-2f-symtab:
	-$(RM) ./intermediate/symtab/Predefined.d ./intermediate/symtab/Predefined.o

.PHONY: clean-intermediate-2f-symtab

