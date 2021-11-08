#include "IfStatement.h"
using namespace std;

IfStatement::IfStatement(string varableName, string opperator, int val, string then, int line_num)
        : m_variableName(varableName), m_opperator(opperator), m_val(val), m_then(then), m_line_num(line_num) {}

void IfStatement::execute(ProgramState* state, ostream& outf) {
    if (m_line_num > state->get_num_lines() || m_line_num < 0) {
        // ends program if the line number to go out of bounds fails
        outf << "Illegal jump instruction" << endl;
        state->set_finish();
    }
    int first_num = state->get_number(m_variableName);
    if (m_opperator[0] == '<' && m_opperator.length() == 1) {
        if (first_num < m_val) {
            state->set_counter(m_line_num);
            return;
        }

    } else if (m_opperator[0] == '>' && m_opperator.length() == 1) {
        if (first_num > m_val) {
            state->set_counter(m_line_num);
            return;
        }

    } else if (m_opperator == "<=") {
        if (first_num <= m_val) {
            state->set_counter(m_line_num);
            return;
        }

    } else if (m_opperator == ">=") {
        if (first_num >= m_val) {
            state->set_counter(m_line_num);
            return;
        }

    } else if (m_opperator[0] == '=' && m_opperator.length() == 1) {
        if (first_num == m_val) {
            state->set_counter(m_line_num);
            return;
        }

    } else if (m_opperator == "<>") {
        if (first_num != m_val) {
            state->set_counter(m_line_num);
            return;
        }
    }
    state->increment_counter();
}
