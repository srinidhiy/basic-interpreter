#ifndef OPERATOR_STATEMENT_INCLUDED
#define OPERATOR_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class OperatorStatement : public Statement {
public:
    OperatorStatement(std::string variableName, std::string value, int specifier);
    virtual void execute(ProgramState* state, std::ostream& outf);

private:
    std::string m_variableName;
    std::string m_value;
    int m_specifier;
};

#endif