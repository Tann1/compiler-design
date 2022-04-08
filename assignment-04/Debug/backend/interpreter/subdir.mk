################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../backend/interpreter/Executor.cpp 

CPP_DEPS += \
./backend/interpreter/Executor.d 

OBJS += \
./backend/interpreter/Executor.o 


# Each subdirectory must supply rules for building sources it contributes
backend/interpreter/%.o: ../backend/interpreter/%.cpp backend/interpreter/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tanishq/eclipse-workspace/assignment-04" -I"/home/tanishq/eclipse-workspace/assignment-04/target/generated-sources/antlr4" -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-backend-2f-interpreter

clean-backend-2f-interpreter:
	-$(RM) ./backend/interpreter/Executor.d ./backend/interpreter/Executor.o

.PHONY: clean-backend-2f-interpreter

