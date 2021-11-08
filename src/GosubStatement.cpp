#include "GosubStatement.h"
using namespace std;

GosubStatement::GosubStatement(int val) : m_val(val) {}

void GosubStatement::execute(ProgramState* state, ostream& outf) {
    // adds current line to stack, sets counter to input line
    int curr = state->get_counter();
    state->add_to_stack(curr);
    state->set_counter(m_val);
}
