// PrintStatement.cpp:
#include "PrintStatement.h"
using namespace std;

PrintStatement::PrintStatement(std::string variableName) : m_variableName(variableName) {}

void PrintStatement::execute(ProgramState* state, std::ostream& outf) {
    map<string, int> mapper = state->get_map();
    map<string, int>::iterator it = mapper.find(m_variableName);
    // means the value is not in the map currently - outputs zero and sets the value of the key as 0
    if (it == mapper.end()) {
        outf << "0" << endl;
        // state->get_map().insert(pair<string, int>(m_variableName, 0));
        state->set_value(m_variableName, 0);
    } else {
        outf << it->second << endl;
    }
    state->increment_counter();
}
