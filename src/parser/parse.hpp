#ifndef PARSE_HPP
#define PARSE_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include "../lexer/lexer.hpp"
#include <fstream>




class Parser
{
    private:
        std::vector<Token> tokens;
        size_t position;
        std::vector<std::string> errors;
        std::string input;
        TokenType type;
        std::unordered_map<std::string, std::unordered_map<std::string, TokenType::NodeContent>> compiler_maps;
    
        
    public:
        Parser(const std::vector<Token>& tokens, int position, const std::string& input, Lexer  lexer) 
            : tokens(tokens), position(0), input(input), lexer(lexer){
        }       
        ~Parser() {}
        Lexer lexer;        

        Token Tokan;
        std::vector<Token> readFiles(const std::string& filename);
        std::vector<Token> readFiles(const std::vector<std::string>& filenames);
        void parse();
        void parseExpression(std::vector<Token> &tokens);
        void parseTerm();
        void parseFactor();
        void addError(const std::string& error);
        std::vector<std::string> getErrors() const { return errors; }
        std::string getValue() const { return Tokan.getValue(); }
        std::string setvalue(std::string value);
        const std::unordered_map<std::string, std::unordered_map<std::string, TokenType::NodeContent>> &getCompilerMaps() const { return compiler_maps; }
        const std::unordered_map<std::string, TokenType::NodeContent> *getCompilerMapForFile(const std::string &filename) const;
        std::unordered_map<std::string, TokenType::NodeContent> mergeCompilerMaps();
        std::vector<Token> getTokens() const { return tokens; }
        size_t getPosition() const { return position; }


};

#endif
