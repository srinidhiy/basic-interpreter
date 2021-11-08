#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class GosubStatement : public Statement {
public:
    GosubStatement(int val);
    virtual void execute(ProgramState* state, std::ostream& outf);

private:
    int m_val;
};

#endif