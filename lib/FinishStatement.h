#ifndef FINISH_STATEMENT_INCLUDED
#define FINISH_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class FinishStatement : public Statement {
public:
    FinishStatement();
    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif