// Interpreter.cpp
#include "FinishStatement.h"
#include "GoToStatement.h"
#include "GosubStatement.h"
#include "IfStatement.h"
#include "LetStatement.h"
#include "OperatorStatement.h"
#include "PrintAll.h"
#include "PrintStatement.h"
#include "ReturnStatement.h"
#include "Statement.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement*>& program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement* parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);

int main() {
    cout << "Enter BASIC program file name: ";
    string filename;
    getline(cin, filename);
    ifstream infile(filename.c_str());
    if (!infile) {
        cout << "Cannot open " << filename << "!" << endl;
        return 1;
    }
    interpretProgram(infile, cout);
}

void parseProgram(istream& inf, vector<Statement*>& program) {
    program.push_back(NULL);

    string line;
    while (!inf.eof()) {
        getline(inf, line);
        program.push_back(parseLine(line));
    }
}

Statement* parseLine(string line) {
    Statement* statement;
    stringstream ss;
    string type;
    string var;
    string second_var;
    string then;
    string opperator;
    int curr_num;
    int val;
    int line_num;

    ss << line;
    ss >> curr_num;
    ss >> type;

    if (type == "LET") {
        ss >> var;
        ss >> val;
        // Note:  Because the project spec states that we can assume the file
        //	  contains a syntactically legal program, we know that
        //	  any line that begins with "LET" will be followed by a space
        //	  and then a variable and then an integer value.
        statement = new LetStatement(var, val);
    }

    // Incomplete;  TODO:  Finish this function! - have to do this for all of the other statement types
    else if (type == "END" || type == ".") {
        statement = new FinishStatement();
    }

    else if (type == "PRINT") {
        ss >> var;
        statement = new PrintStatement(var);
    }

    else if (type == "PRINTALL") {
        statement = new PrintAll();
    }
    // for all the operators, calls same class but changes implementation depending on 3rd argument
    else if (type == "ADD") {
        ss >> var;
        ss >> second_var;
        statement = new OperatorStatement(var, second_var, 0);
    }

    else if (type == "SUB") {
        ss >> var;
        ss >> second_var;
        statement = new OperatorStatement(var, second_var, 1);
    }

    else if (type == "MULT") {
        ss >> var;
        ss >> second_var;
        statement = new OperatorStatement(var, second_var, 2);
    }

    else if (type == "DIV") {
        ss >> var;
        ss >> second_var;
        statement = new OperatorStatement(var, second_var, 3);
    }

    else if (type == "GOTO") {
        ss >> val;
        statement = new GoToStatement(val);
    }

    else if (type == "IF") {
        ss >> var;
        ss >> opperator;
        ss >> val;
        ss >> then;
        ss >> line_num;
        statement = new IfStatement(var, opperator, val, then, line_num);

    }

    else if (type == "GOSUB") {
        ss >> val;
        statement = new GosubStatement(val);
    }

    else if (type == "RETURN") {
        statement = new ReturnStatement();
    }

    return statement;
}

void interpretProgram(istream& inf, ostream& outf) {
    vector<Statement*> program;
    parseProgram(inf, program);

    // Incomplete;  TODO:  Finish this function!
    // instantiate program state
    ProgramState* state = new ProgramState(program.size());
    // goes until it's a finish statement, i.e. END or .
    while (state->get_finish() != true) {
        // current statement executes
        program[state->get_counter()]->execute(state, outf);
    }
    int vec_size = program.size();
    for (int i = 0; i < vec_size; i++) {
        delete program[i];
    }
    delete state;
    return;
}
