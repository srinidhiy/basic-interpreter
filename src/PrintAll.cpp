#include "PrintAll.h"
using namespace std;

PrintAll::PrintAll() {}

void PrintAll::execute(ProgramState* state, std::ostream& outf) {
    // uses map iterator to print all the keys and values
    map<string, int>::iterator it;
    map<string, int> mapper = state->get_map();
    for (it = mapper.begin(); it != mapper.end(); it++) {
        outf << it->first << " " << it->second << endl;
    }
    state->increment_counter();
}