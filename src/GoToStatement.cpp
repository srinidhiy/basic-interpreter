#include "GoToStatement.h"
using namespace std;

GoToStatement::GoToStatement(int val) : m_val(val) {}

void GoToStatement::execute(ProgramState* state, ostream& outf) {
    // sets the counter to the specified line number
    int lines = state->get_num_lines();
    if (m_val > lines || m_val < 0) {
        // ends program by setting finish to true
        outf << "Illegal jump instruction" << endl;
        state->set_finish();
    }
    state->set_counter(m_val);
}
