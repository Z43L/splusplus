#ifndef IF_HPP
#define IF_HPP
#include "../../../../main.hpp"

struct t_IfControl
{
    char **condition;
    char ***variables;
    int variableCount;
    bool hasElse;
    bool hasElseIf;
    bool isExecuted;
} ;


class IfControl
{
    private:
        std::vector<Token> tokens;
        std::vector<std::string> errors;
        std::string input;
        t_IfControl ifControl;
        
    public:
        IfControl() {}
        ~IfControl() {}
       
        std::vector<std::string> getErrors() const { return errors; }
        char** getCondition() const { return ifControl.condition; }
        char*** getVariables() const { return ifControl.variables; }
        int getVariableCount() const { return ifControl.variableCount; }
        bool hasElse() const { return ifControl.hasElse; }
        bool hasElseIf() const { return ifControl.hasElseIf; }
        bool isExecuted() const { return ifControl.isExecuted; }
};




#endif