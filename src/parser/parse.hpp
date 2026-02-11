#ifndef PARSE_HPP
#define PARSE_HPP

#include <string>
#include <vector>
#include "../../main.hpp"
#include <fstream>




class Parser
{
    private:
        std::vector<Token> tokens;
        size_t position;
        std::vector<std::string> errors;
        std::string input;
    public:
        Parser(const std::vector<Token>& tokens, const std::string& input) : tokens(tokens), position(0), input(input) {}
        ~Parser() {}
        std::vector<Token> readFiles(const std::string& filename);
        void parse();
        
        void parseExpression(std::vector<Token> &tokens);
        void parseTerm();
        void parseFactor();
        void addError(const std::string& error);
        std::vector<std::string> getErrors() const { return errors; }
};

#endif 