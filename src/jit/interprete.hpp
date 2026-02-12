#ifndef INTERPRETE_HPP
#define INTERPRETE_HPP

#include "../lexer/lexer.hpp"

class interprete {
    private:
        Lexer lexer;
        std::unordered_map<std::string, TokenType::Type> tokens;
        size_t current_token_index;
        size_t loop_counter;
        size_t salida_status;
    public:
        interprete(const std::string& input) : lexer(input), current_token_index(0) {}
        ~interprete(){};
        std::unordered_map<std::string, TokenType> tokenize(std::string input, Lexer& lexer);
        std::unordered_map<std::string, TokenType> getCurrentTokens();
        int getSalidaStatus();
        void setSalidaStatus(int status) ;
        std::vector<Token> interpret(TokenType::Type type,std::vector<Token> tokens,const std::string& value);
        std::vector<Token> executeWhile(std::vector<Token> tokens,std::string value);
        std::vector<Token> interpretWhile(std::vector<Token> tokens ) ;
        std::unordered_map<std::string , TokenType> executeWhile(std::vector<Token> tokenswhile, int i);
        std::vector<Token> interpreterIf(std::vector<Token> tokens );
        std::vector<std::string> executeIf(std::vector<Token> ifControl);
};

#endif
