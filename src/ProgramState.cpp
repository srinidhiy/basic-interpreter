#include "ProgramState.h"

#include <cmath>
#include <iostream>

using namespace std;

ProgramState::ProgramState(int numLines) {
    m_numLines = numLines;
    is_finished = false;
    counter = 1;
}

void ProgramState::increment_counter() { counter++; }

void ProgramState::set_value(string variable_name, int value) {
    // values.insert(pair<string, int>(variable_name, value));
    // have to do it this way because insert only sets the value if there isn't already a key for that
    values[pair<string, int>(variable_name, value).first] = pair<string, int>(variable_name, value).second;
}

int ProgramState::get_counter() { return counter; }

void ProgramState::set_finish() { is_finished = true; }

bool ProgramState::get_finish() { return is_finished; }

map<string, int> ProgramState::get_map() { return values; }

// finds the number of operator variables from the string
int ProgramState::get_number(string variable) {
    int len = variable.length();
    char begin[len];
    // have to copy string into a char array for strtol
    for (int i = 0; i < len; i++) {
        begin[i] = variable[i];
    }

    if (begin[0] == '0' && len == 1) {
        return 0;
    }
    // if the string isn't a number it returns a 0
    if (strtol(begin, nullptr, 10) != 0) {
        return (stoi(variable));
    }
    // otherwise find the value for the key in the map
    else {
        return (values.find(variable)->second);
    }
}

int ProgramState::add(int val1, int val2) { return (val1 + val2); }

int ProgramState::subtract(int val1, int val2) { return (val1 - val2); }

int ProgramState::multiply(int val1, int val2) { return (val1 * val2); }

int ProgramState::divide(int val1, int val2) {
    double div = (double(val1) / double(val2));
    return floor(div);
}

void ProgramState::set_counter(int val) { counter = val; }

int ProgramState::get_num_lines() { return m_numLines; }

stack<int> ProgramState::get_stack() { return lines; }
void ProgramState::add_to_stack(int val) { lines.push(val); }

bool ProgramState::is_empty() { return lines.empty(); }

void ProgramState::remove_from_stack() { lines.pop(); }

int ProgramState::top_stack() { return lines.top(); }

bool ProgramState::in_map(string variable) {
    map<string, int>::iterator it = values.find(variable);
    // means the value is not in the map currently - outputs false
    return (it != values.end());
}

bool ProgramState::is_number(string variable) {
    if (variable[0] < 'A' || variable[0] > 'Z') {
        return true;
    } else {
        return false;
    }
}