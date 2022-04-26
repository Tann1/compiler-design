ANTLRFILE=Pascal.g4
antlr4=java -jar ${ANTLR_JAR}


PROJECTPATH=$(shell pwd)
ANTLR_RUNTIME_INCLUDES=/usr/local/include/antlr4-runtime
ANTLR_INCLUDES=$(PROJECTPATH)/target/generated-sources/ant4
LIB_PATH=/usr/local/lib
LIB=antlr4-runtime
PROG=Pascal.cpp
OUT=prog.out
FRONTEND=frontend/*.cpp
BACKEND=backend/compiler/*.cpp backend/converter/*.cpp backend/interpreter/*.cpp 
INTERMEDIATE=intermediate/symtab/*.cpp intermediate/type/*.cpp intermediate/util/*.cpp
ANLTR_SOURCES=target/generated-sources/ant4/*.cpp
SOURCES=$(FRONTEND) $(INTERMEDIATE) $(BACKEND) $(ANLTR_SOURCES) $(PROG)

compile:
	g++ -o $(OUT) -I$(ANTLR_RUNTIME_INCLUDES) -I$(ANTLR_INCLUDES) -I$(PROJECTPATH) -L$(LIB_PATH) -w $(SOURCES) -l$(LIB)

antlr:
	$(antlr4) -o ./target/generated-sources/ant4 -no-listener -visitor -encoding UTF-8 -Dlanguage=Cpp $(ANTLRFILE)



clean:
	rm $(OUT) *.j