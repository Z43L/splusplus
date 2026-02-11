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
        TokenType type;
        
    public:
        Parser(const std::vector<Token>& tokens, int position, const std::string& input) 
            : tokens(tokens), position(0), input(input), Tokan(!tokens.empty() ? tokens[0] : Parser::Tokan.getType(Parser::Tokan.nodeType ) ) {
        }
        ~Parser() {}
        Lexer lexer;
        Token Tokan;
        std::vector<Token> readFiles(const std::string& filename);
        void parse();
        void addError( std::string &error);
        void parseExpression(std::vector<Token> &tokens);
        void parseTerm();
        void parseFactor();
        void addError(const std::string& error);
        std::vector<std::string> getErrors() const { return errors; }
        std::string getValue() const { return Tokan.getValue(); }
        std::string setvalue(std::string value);
};

#endif