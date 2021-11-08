#include "OperatorStatement.h"
using namespace std;

OperatorStatement::OperatorStatement(std::string variableName, std::string value, int specifier)
        : m_variableName(variableName), m_value(value), m_specifier(specifier) {}

void OperatorStatement::execute(ProgramState* state, std::ostream& outf) {
    // have to deal with when an uninitialized variable is called
    int val1 = 0;
    int val2 = 0;
    if (state->in_map(m_variableName) || (state->is_number(m_variableName) == true)) {
        val1 = state->get_number(m_variableName);
    } else {
        state->set_value(m_variableName, 0);
    }
    if (state->in_map(m_value) || (state->is_number(m_value) == true)) {
        val2 = state->get_number(m_value);
    } else {
        state->set_value(m_value, 0);
    }
    // depending on what the specifier is, you call that method
    if (m_specifier == 0) {
        int added = state->add(val1, val2);
        state->set_value(m_variableName, added);
    } else if (m_specifier == 1) {
        int subtracted = state->subtract(val1, val2);
        state->set_value(m_variableName, subtracted);
    } else if (m_specifier == 2) {
        int multiplied = state->multiply(val1, val2);
        state->set_value(m_variableName, multiplied);
    } else if (m_specifier == 3) {
        if (val2 == 0) {
            // ends the program by setting the finish to true
            outf << "Divide by zero exception" << endl;
            state->set_finish();
        }
        int divided = state->divide(val1, val2);
        state->set_value(m_variableName, divided);
    }

    state->increment_counter();
}