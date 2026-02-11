#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class TokenType
{
    private:
        std::unordered_map<std::string, TokenType> map;
        std::string value;
        std::string type;
        int tokenTypeInt; 
        std::unordered_map<std::string, TokenType> punctuation;
        std::unordered_map<std::string, TokenType> operators ;
        std::unordered_map<std::string, TokenType> keywords ;

    public:
            TokenType() {};
            ~TokenType() {};

        struct ExecutionContext
        {
            std::unordered_map<std::string, int> variables;
            std::unordered_map<std::string, int> functions;
            std::unordered_map<std::string, int> classes;
            std::unordered_map<std::string, int> whileLoops;
            std::unordered_map<std::string, int> forLoops;
            std::unordered_map<std::string, int> ifStatements;
            std::unordered_map<std::string, int> elseIfStatements;
            std::unordered_map<std::string, int> elseStatements;
        };
        enum class NodeType
        {
            Program,
            Statement,
            Expression,
            Term,
            Factor
        };
        enum  class Type
        {
            Identifier= 0,
            Keyword= 1,
            Operator= 2,
            Punctuation= 3,
            Number= 4,
            String= 5,
            EndOfFile= 6
        };
        enum class OperatorType
        {
            Plus,
            Minus,
            Multiply,
            Divide
        };
        enum class ValueType
        {
            Number,
            Identifier,
            String
        };
        
        std::unordered_map<std::string, TokenType::Type> punctuation = {
            {";", TokenType::Type::Punctuation},
            {",", TokenType::Type::Punctuation},
            {"(", TokenType::Type::Punctuation},
            {")", TokenType::Type::Punctuation},
            {"{", TokenType::Type::Punctuation},
            {"}", TokenType::Type::Punctuation},
        } ;
        std::unordered_map<std::string, TokenType::Type> operators = {
            {"+", TokenType::Type::Operator},
            {"-", TokenType::Type::Operator},
            {"*", TokenType::Type::Operator},
            {"/", TokenType::Type::Operator},
            {"=", TokenType::Type::Operator}};
        std::unordered_map<std::string, TokenType::Type> keywords ={
            {"if", TokenType::Type::Keyword},
            {"else", TokenType::Type::Keyword},
            {"while", TokenType::Type::Keyword},
            {"for", TokenType::Type::Keyword},
            {"return", TokenType::Type::Keyword}}; 
        void parseStatement(Token token);
        NodeType getNodeType() const { return NodeType::Statement; }
        std::unordered_map<std::string, TokenType> getPunctuation() const { return punctuation; }
        std::unordered_map<std::string, TokenType> getOperators() const { return operators; }
        std::unordered_map<std::string, TokenType> getKeywords() const { return keywords; }
        std::string getValue() const { return value; }
        std::string getType() const { return type; }
        int getTokenTypeInt() const { return tokenTypeInt; }
        std::unordered_map<std::string, TokenType> load_token_map(TokenType::Type type) const;
        std::unordered_map<std::string, TokenType> setTokenMap(const std::unordered_map<std::string, TokenType> &new_map);
        std::unordered_map<std::string, TokenType>
};

class Token
{
    private:
        TokenType type;
        std::string value;
        int tokenTypeInt;
        std::unordered_map<std::string, TokenType> map;

    public:
        Token(TokenType type, const std::string &value) : type(type), value(value) {}
        ~Token() {}
        TokenType getType() const { return type; }
        std::string getValue() const { return value; }
        TokenType load_token_map(TokenType tipe) const;
        std::unordered_map<std::string, TokenType> token_map(TokenType type, const std::string &value);
        std::unordered_map<std::string, TokenType> getTokenMap() const { return map; }
        std::unordered_map<std::string, TokenType> setTokenMap(const std::unordered_map<std::string, TokenType> &new_map);
        std::unordered_map<std::string, TokenType> load_token_map(std::unordered_map<std::string, TokenType> tipe);
        std::unordered_map<std::string, TokenType> setvalue(std::unordered_map<std::string, TokenType> new_map);
        int getTokenTypeInt(TokenType type);
        
};

class Lexer
{
    private:
        std::string input;
        size_t position;
        size_t read_position;
        char current_char;
        bool is_end_of_file;
        bool is_loop;

    public:
        Lexer(const std::string &input) : input(input), position(0), read_position(0), current_char(0), is_end_of_file(false), is_loop(false) {};
        void readChar();
        Token nextToken();
        void skipWhitespace();
        Token readIdentifier();
        Token readNumber();
        Token readString();
        bool isLetter(char ch) const;
};

#endif // LEXER_HPP