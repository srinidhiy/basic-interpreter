// ProgramState.h
//
// CS 104 / Fall 2021
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a BASIC program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// We've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.
#include <iostream>
#include <map>
#include <stack>
#include <string>

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

class ProgramState {
public:
    ProgramState(int numLines);

    // You'll need to add a variety of methods here.  Rather than trying to
    // think of what you'll need to add ahead of time, add them as you find
    // that you need them.
    void increment_counter();
    int get_counter();
    int get_num_lines();
    void set_value(std::string variable_name, int value);
    void set_finish();
    bool get_finish();
    int add(int val1, int val2);
    int subtract(int val1, int val2);
    int multiply(int val1, int val2);
    int divide(int val1, int val2);
    int get_number(std::string variable);
    std::map<std::string, int> get_map();
    void set_counter(int val);
    std::stack<int> get_stack();
    void add_to_stack(int val);
    bool is_empty();
    void remove_from_stack();
    int top_stack();
    bool in_map(std::string variable);
    bool is_number(std::string variable);

private:
    int m_numLines;
    int counter;
    std::map<std::string, int> values;
    bool is_finished;
    std::stack<int> lines;
};

#endif
