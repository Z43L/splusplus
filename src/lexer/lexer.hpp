#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "../utils/core/lenguage_control_tructured/while.hpp"
class Token;
class TokenType
{
private:
    
    

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
        ExecutionContext *next;
    };
    
    enum class PrincipalType
    {
        Variable,
        Function,
        Class,
        WhileLoop,
        ForLoop,
        IfStatement,
        ElseIfStatement,
        ElseStatement,
        Export,
        Include,
        Define,
    };
    enum class NodeType
    {

        Program,
        Statement,
        Expression,
        Term,
        Factor
    };
    enum class Type
    {
        Identifier,
        Keyword,
        Operator ,
        Punctuation ,
        Number,
        String ,
        EndOfFile,
    };
    enum class OperatorType
    {
        Plus,
        Minus,
        Multiply,
        Divide,
        Equal,
        EqualMinus,
        EqualPlus,
        EqualMultiply,
        EqualDivide
        
    };
    enum class ValueType
    {
        Number,
        Identifier,
        String
    };
    enum class StattementType
    {
        If,
        ElseIf,
        Else,
        While,
        For,
        Return
    };
    struct NodeContent
    {
        int positionEjecution;
        std::string value;
        std::string type;
        int tokenTypeInt;
        std::string punctuation;
        std::string operators;
        std::string keywords;
        ExecutionContext *context;
        TokenType::PrincipalType PrincipalType;
        TokenType::NodeType NodeXType;
        TokenType::Type Type;
        TokenType::OperatorType OperatorType;
        TokenType::ValueType ValueType;
    };
    
    std::unordered_map<std::string, TokenType::Type> punctuation = {
        {";", TokenType::Type::Punctuation},
        {",", TokenType::Type::Punctuation},
        {"(", TokenType::Type::Punctuation},
        {")", TokenType::Type::Punctuation},
        {"{", TokenType::Type::Punctuation},
        {"}", TokenType::Type::Punctuation},
    };
    std::unordered_map<std::string, TokenType::Type> operators = {
        {"+", TokenType::Type::Operator},
        {"-", TokenType::Type::Operator},
        {"*", TokenType::Type::Operator},
        {"/", TokenType::Type::Operator},
        {"=", TokenType::Type::Operator}};
    std::unordered_map<std::string, TokenType::Type> keywords = {
        {"if", TokenType::Type::Keyword},
        {"else", TokenType::Type::Keyword},
        {"while", TokenType::Type::Keyword},
        {"for", TokenType::Type::Keyword},
        {"return", TokenType::Type::Keyword}};
    std::unordered_map<std::string, TokenType::PrincipalType> priority = {
        {"var", TokenType::PrincipalType::Variable},
        {"function", TokenType::PrincipalType::Function},
        {"class", TokenType::PrincipalType::Class},
        {"#include", TokenType::PrincipalType::Include},
        {"#define", TokenType::PrincipalType::Define},
        {"export", TokenType::PrincipalType::Export}};
    void parseStatement(Token &token, TokenType &type);
    NodeType getNodeType() const;
    NodeContent *createNode(const std::string &value, const std::string &type);
    ExecutionContext createExecutionContext() const;
    std::unordered_map<std::string, TokenType> readExecutionContext(const ExecutionContext &context);
    int orderExecutionContext(const ExecutionContext &context);
    std::unordered_map<std::string, TokenType::Type> load_token_map(TokenType::Type type, std::string value);
    std::unordered_map<std::string, TokenType> setPuntuation(const std::unordered_map<std::string, TokenType> &new_map, int tokenTypeInt);
    std::unordered_map<std::string, TokenType> setOperators(const std::unordered_map<std::string, TokenType> &new_map);
    std::unordered_map<std::string, TokenType> setKeywords(const std::unordered_map<std::string, TokenType> &new_map);
    std::string setvalue(std::string value);
    std::unordered_map<std::string, TokenType::NodeContent> setTokenPriorityMap(std::string value, TokenType::PrincipalType principaltype, TokenType type, TokenType::NodeContent content, int i);
    std::string getNodeTypeString(NodeType nodeType);
    std::string getPrincipalTypeString(PrincipalType principalType);
    std::string getTypeString(Type type);
    std::unordered_map<std::string, TokenType::NodeContent> getTokenType(std::string value, TokenType::PrincipalType principaltype, TokenType::ExecutionContext context, TokenType::NodeContent content, int i, TokenType type);
    std::string getTypeOperatorString(OperatorType type);
    std::string getPuntuationString(std::string value);
    std::string getStatementTypeString(StattementType type);
    std::unordered_map<std::string, TokenType::NodeContent> setTokenMap(std::string value, TokenType type, TokenType::PrincipalType principaltype, TokenType::ExecutionContext context, TokenType::NodeContent content);
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
        Lexer() : input(""), position(0), read_position(0), current_char(0), is_end_of_file(false), is_loop(false) {}
        Lexer(const std::string &input) : input(input), position(0), read_position(0), current_char(0), is_end_of_file(false), is_loop(false) {}
        void readChar();
        void readCharLoop();
        TokenType &type();
        Token &token(TokenType &type, const std::string &value);
        Token nextToken();
        void skipWhitespace();
        Token readIdentifier();
        Token readNumber();
        Token readString();
        int isLetter(char ch) ;
};



class Token
{
private:
    
    TokenType::Type type;
    std::string value;
    int tokenTypeInt;
    int positionEjecution;
    std::unordered_map<TokenType::Type, std::string> map;

public:
    Token() : type(TokenType::Type::EndOfFile), value("") {}
    Token(TokenType::Type type, const std::string &value) : type(type), value(value) {}
    ~Token() = default;
    TokenType::Type getType() const { return type; }
    std::string getValue() const { return value; }
    TokenType load_token_map(TokenType tipe) const;
    std::unordered_map<std::string, TokenType> token_map(TokenType type, const std::string &value);
    std::unordered_map<std::string, TokenType> getTokenMap(std::unordered_map<std::string, TokenType> map) const;
    std::unordered_map<std::string, TokenType> setTokenMap(const std::unordered_map<std::string, TokenType> &new_map);
    std::unordered_map<std::string, TokenType> load_token_map(std::unordered_map<std::string, TokenType> tipe);
    std::unordered_map<std::string, TokenType> setvalue(std::unordered_map<std::string, TokenType> new_map);
    int getTokenTypeInt(TokenType::Type type);
    int follow_token_map(const std::unordered_map<std::string, TokenType> &token_map);
    void addError(const std::string &error);
};



#endif // LEXER_HPP
