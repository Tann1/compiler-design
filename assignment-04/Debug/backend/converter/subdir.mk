################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../backend/converter/CodeGenerator.cpp \
../backend/converter/Converter.cpp 

CPP_DEPS += \
./backend/converter/CodeGenerator.d \
./backend/converter/Converter.d 

OBJS += \
./backend/converter/CodeGenerator.o \
./backend/converter/Converter.o 


# Each subdirectory must supply rules for building sources it contributes
backend/converter/%.o: ../backend/converter/%.cpp backend/converter/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tanishq/eclipse-workspace/assignment-04" -I"/home/tanishq/eclipse-workspace/assignment-04/target/generated-sources/antlr4" -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-backend-2f-converter

clean-backend-2f-converter:
	-$(RM) ./backend/converter/CodeGenerator.d ./backend/converter/CodeGenerator.o ./backend/converter/Converter.d ./backend/converter/Converter.o

.PHONY: clean-backend-2f-converter

