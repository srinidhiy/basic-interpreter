CXX = g++
CPPFLAGS = -Wall -g -I$(LIB_DIR)
BIN_DIR = bin
LIB_DIR = lib
SRC_DIR = src

all: $(BIN_DIR)/.dirstamp interpreter

interpreter: $(SRC_DIR)/Interpreter.o $(BIN_DIR)/FinishStatement.o $(BIN_DIR)/GoToStatement.o $(BIN_DIR)/IfStatement.o $(BIN_DIR)/LetStatement.o $(BIN_DIR)/OperatorStatement.o $(BIN_DIR)/PrintAll.o $(BIN_DIR)/PrintStatement.o $(BIN_DIR)/ProgramState.o $(BIN_DIR)/GosubStatement.o $(BIN_DIR)/ReturnStatement.o
	$(CXX) $(CPPFLAGS) $^ -o $@

$(BIN_DIR)/FinishStatement.o: $(SRC_DIR)/FinishStatement.cpp $(LIB_DIR)/FinishStatement.h $(LIB_DIR)/Statement.h $(LIB_DIR)/ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
$(BIN_DIR)/GoToStatement.o: $(SRC_DIR)/GoToStatement.cpp $(LIB_DIR)/GoToStatement.h $(LIB_DIR)/Statement.h $(LIB_DIR)/ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
$(BIN_DIR)/IfStatement.o: $(SRC_DIR)/IfStatement.cpp $(LIB_DIR)/IfStatement.h $(LIB_DIR)/Statement.h $(LIB_DIR)/ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
$(BIN_DIR)/LetStatement.o: $(SRC_DIR)/LetStatement.cpp $(LIB_DIR)/LetStatement.h $(LIB_DIR)/Statement.h $(LIB_DIR)/ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
$(BIN_DIR)/OperatorStatement.o: $(SRC_DIR)/OperatorStatement.cpp $(LIB_DIR)/OperatorStatement.h $(LIB_DIR)/Statement.h $(LIB_DIR)/ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
$(BIN_DIR)/PrintAll.o: $(SRC_DIR)/PrintAll.cpp $(LIB_DIR)/PrintAll.h $(LIB_DIR)/Statement.h $(LIB_DIR)/ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
$(BIN_DIR)/PrintStatement.o: $(SRC_DIR)/PrintStatement.cpp $(LIB_DIR)/PrintStatement.h $(LIB_DIR)/Statement.h $(LIB_DIR)/ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
$(BIN_DIR)/ProgramState.o: $(SRC_DIR)/ProgramState.cpp $(LIB_DIR)/ProgramState.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
$(BIN_DIR)/GosubStatement.o: $(SRC_DIR)/GosubStatement.cpp $(LIB_DIR)/ProgramState.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
$(BIN_DIR)/ReturnStatement.o: $(SRC_DIR)/ReturnStatement.cpp $(LIB_DIR)/ProgramState.h $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
$(BIN_DIR)/Interpreter.o: $(SRC_DIR)/Interpreter.cpp $(BIN_DIR)/FinishStatement.o $(BIN_DIR)/GoToStatement.o $(BIN_DIR)/IfStatement.o $(BIN_DIR)/LetStatement.o $(BIN_DIR)/OperatorStatement.o $(BIN_DIR)/PrintAll.o $(BIN_DIR)/PrintStatement.o $(BIN_DIR)/ProgramState.o $(BIN_DIR)/GosubStatement.o $(BIN_DIR)/ReturnStatement.o
	$(CXX) $(CPPFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp