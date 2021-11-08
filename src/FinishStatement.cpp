#include "FinishStatement.h"
using namespace std;

FinishStatement::FinishStatement() {}

void FinishStatement::execute(ProgramState* state, ostream& outf) {
    // sets is_finished to true --> lets interpreter know program is over
    state->set_finish();
}
