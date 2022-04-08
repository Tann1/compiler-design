################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../backend/debugger/Commander.cpp \
../backend/debugger/Debugger.cpp 

CPP_DEPS += \
./backend/debugger/Commander.d \
./backend/debugger/Debugger.d 

OBJS += \
./backend/debugger/Commander.o \
./backend/debugger/Debugger.o 


# Each subdirectory must supply rules for building sources it contributes
backend/debugger/%.o: ../backend/debugger/%.cpp backend/debugger/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tanishq/eclipse-workspace/assignment-04" -I"/home/tanishq/eclipse-workspace/assignment-04/target/generated-sources/antlr4" -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-backend-2f-debugger

clean-backend-2f-debugger:
	-$(RM) ./backend/debugger/Commander.d ./backend/debugger/Commander.o ./backend/debugger/Debugger.d ./backend/debugger/Debugger.o

.PHONY: clean-backend-2f-debugger

