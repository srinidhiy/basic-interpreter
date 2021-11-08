#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class IfStatement : public Statement {
public:
    IfStatement(std::string varableName, std::string opperator, int val, std::string then, int line_num);
    virtual void execute(ProgramState* state, std::ostream& outf);

private:
    std::string m_variableName;
    std::string m_opperator;
    int m_val;
    std::string m_then;
    int m_line_num;
};

#endif