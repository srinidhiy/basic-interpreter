#include "ReturnStatement.h"
using namespace std;

ReturnStatement::ReturnStatement() {}

void ReturnStatement::execute(ProgramState* state, ostream& outf) {
    // checks if stack is empty - if not, set counter to top of stack and pop
    if (state->is_empty()) {
        outf << "Illegal jump instruction" << endl;
        state->set_finish();
    } else {
        int returned = state->top_stack();
        state->set_counter(returned);
        state->remove_from_stack();
        state->increment_counter();
    }
}
