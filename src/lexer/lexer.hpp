#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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
    struct NodeContent
    {
        std::string value;
        std::string type;
        int tokenTypeInt;
        std::string punctuation;
        std::string operators;
        std::string keywords;
        ExecutionContext *context;
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
        Identifier = 0,
        Keyword = 1,
        Operator = 2,
        Punctuation = 3,
        Number = 4,
        String = 5,
        EndOfFile = 6
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
    void parseStatement(Token token);
    NodeType getNodeType() const;
    NodeContent *createNode(const std::string &value, const std::string &type);
    ExecutionContext createExecutionContext() const;
    std::unordered_map<std::string, TokenType> readExecutionContext(const ExecutionContext &context);
    int orderExecutionContext(const ExecutionContext &context);
    std::unordered_map<std::string, TokenType::Type> load_token_map(TokenType::Type type, std::string value);
    std::unordered_map<std::string, TokenType> setTokenMap(std::string value, TokenType type,std::unordered_map<std::string, TokenType> token_map);
    std::unordered_map<std::string, TokenType> setPuntuation(const std::unordered_map<std::string, TokenType> &new_map, int tokenTypeInt );
    std::unordered_map<std::string, TokenType> setOperators(const std::unordered_map<std::string, TokenType> &new_map);
    std::unordered_map<std::string, TokenType> setKeywords(const std::unordered_map<std::string, TokenType> &new_map);
    std::string setvalue(std::string value);
    ExecutionContext createExecutionContext() const;
    std::unordered_map<std::string, TokenType> readExecutionContext(const ExecutionContext &context);
    std::unordered_map<std::string, TokenType::NodeContent > TokenType::setTokenPriorityMap(std::string value, TokenType::PrincipalType principaltype , TokenType type,TokenType::NodeContent content, int i);
    std::string getNodeTypeString(NodeType nodeType);
    std::string getPrincipalTypeString(PrincipalType principalType);
    std::string getTypeString(Type type);
};

class Token
{
private:
    TokenType type;
    std::string value;
    int tokenTypeInt;
    std::unordered_map<std::string, int, TokenType> map;

public:
    Token(TokenType type, const std::string &value) : type(type), value(value) {}
    ~Token() {}
    TokenType getType() const { return type; }
    std::string getValue() const { return value; }
    TokenType load_token_map(TokenType tipe) const;
    std::unordered_map<std::string, TokenType> token_map(TokenType type, const std::string &value);
    std::unordered_map<std::string, int, TokenType> getTokenMap() const { return map; }
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
