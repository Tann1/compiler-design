################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../target/generated-sources/antlr4/CommanderBaseVisitor.cpp \
../target/generated-sources/antlr4/CommanderLexer.cpp \
../target/generated-sources/antlr4/CommanderParser.cpp \
../target/generated-sources/antlr4/CommanderVisitor.cpp \
../target/generated-sources/antlr4/PascalBaseVisitor.cpp \
../target/generated-sources/antlr4/PascalLexer.cpp \
../target/generated-sources/antlr4/PascalParser.cpp \
../target/generated-sources/antlr4/PascalVisitor.cpp 

CPP_DEPS += \
./target/generated-sources/antlr4/CommanderBaseVisitor.d \
./target/generated-sources/antlr4/CommanderLexer.d \
./target/generated-sources/antlr4/CommanderParser.d \
./target/generated-sources/antlr4/CommanderVisitor.d \
./target/generated-sources/antlr4/PascalBaseVisitor.d \
./target/generated-sources/antlr4/PascalLexer.d \
./target/generated-sources/antlr4/PascalParser.d \
./target/generated-sources/antlr4/PascalVisitor.d 

OBJS += \
./target/generated-sources/antlr4/CommanderBaseVisitor.o \
./target/generated-sources/antlr4/CommanderLexer.o \
./target/generated-sources/antlr4/CommanderParser.o \
./target/generated-sources/antlr4/CommanderVisitor.o \
./target/generated-sources/antlr4/PascalBaseVisitor.o \
./target/generated-sources/antlr4/PascalLexer.o \
./target/generated-sources/antlr4/PascalParser.o \
./target/generated-sources/antlr4/PascalVisitor.o 


# Each subdirectory must supply rules for building sources it contributes
target/generated-sources/antlr4/%.o: ../target/generated-sources/antlr4/%.cpp target/generated-sources/antlr4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tanishq/eclipse-workspace/assignment-04" -I"/home/tanishq/eclipse-workspace/assignment-04/target/generated-sources/antlr4" -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-target-2f-generated-2d-sources-2f-antlr4

clean-target-2f-generated-2d-sources-2f-antlr4:
	-$(RM) ./target/generated-sources/antlr4/CommanderBaseVisitor.d ./target/generated-sources/antlr4/CommanderBaseVisitor.o ./target/generated-sources/antlr4/CommanderLexer.d ./target/generated-sources/antlr4/CommanderLexer.o ./target/generated-sources/antlr4/CommanderParser.d ./target/generated-sources/antlr4/CommanderParser.o ./target/generated-sources/antlr4/CommanderVisitor.d ./target/generated-sources/antlr4/CommanderVisitor.o ./target/generated-sources/antlr4/PascalBaseVisitor.d ./target/generated-sources/antlr4/PascalBaseVisitor.o ./target/generated-sources/antlr4/PascalLexer.d ./target/generated-sources/antlr4/PascalLexer.o ./target/generated-sources/antlr4/PascalParser.d ./target/generated-sources/antlr4/PascalParser.o ./target/generated-sources/antlr4/PascalVisitor.d ./target/generated-sources/antlr4/PascalVisitor.o

.PHONY: clean-target-2f-generated-2d-sources-2f-antlr4

