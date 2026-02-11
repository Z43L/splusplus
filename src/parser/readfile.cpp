#include "parse.hpp"


std::string Parser::setvalue(std::string value)
{
    return value;
}
std::vector<std::string> Parser::getErrors() const
{
    return errors;
}

std::vector<Token> Parser::readFiles(const std::string &filename)
{
    
    TokenType type;
    
    if (filename.empty())
    {
        addError("Filename is empty.");
        return tokens;
    }
    std::string filess  =  std::fstream(filename).is_open() ? std::string((std::istreambuf_iterator<char>(std::fstream(filename).rdbuf())), std::istreambuf_iterator<char>()) : "";
    if (filess.empty())
    {
        addError("Failed to read file: " + filename);
        return tokens;
    }
    Token token(type, filess);
    Parser::Tokan.token_map(type, filess);
    Lexer lexer(filess);
    token = lexer.nextToken();
    while (token.getType(token.nodeType).getNodeType() != TokenType::NodeType::EndOfFile)
    {
        tokens.push_back(token);
        token =- lexer.nextToken();
    }
    return tokens;
}

void Parser::addError(const std::string &error)
{
    errors.push_back(error);
}

void TokenType::parseStatement(Token &token, TokenType &type, Parser &parser)
{
    if (type.getNodeTypeString(TokenType::NodeType::Statement) == "Statement")
    {
        if(token.getValue() == "if")
        {
            type.parseStatement(token, type);
        }
        else if(token.getValue() == "while")
        {
            type.parseStatement(token, type);
        }
        else if(token.getValue() == "for")
        {
            type.parseStatement(token, type);
        }
        else if(token.getValue() == "return")
        {
            type.parseStatement(token, type);
        }
    }
    else
    {
        parser.addError("Expected a statement, but got: " + token.getValue());
    }
    if (token.getType() == TokenType::Type::Identifier)
    {
        if(type  + 1 < tokens.size() && tokens[position + 1].getType() == TokenType::Type::Operator && tokens[position + 1].getValue() == "=")
        {
            // Handle assignment statements
        }
        if(position + 1 < tokens.size() && tokens[position + 1].getType() == TokenType::Type::Punctuation && tokens[position + 1].getValue() == ";")
        {
        }
        if(position + 1 < tokens.size() && tokens[position + 1].getType() == TokenType::Type::Punctuation && tokens[position + 1].getValue() == "(")
        {
            // Handle function calls
            if(position + 2 < tokens.size() && tokens[position + 2].getType() == TokenType::Type::Punctuation && tokens[position + 2].getValue() == ")")
            {
                // Handle function calls with no arguments
            }
            else
            {
                // Handle function calls with arguments
            }
        }
        
        else
        {
            parser.addError("Unexpected identifier: " + token.getValue());
        }
    }
    else
    {
        parser.addError("Unexpected token: " + token.getValue());
    }
}
void Parser::parseExpression(std::vector<Token> &tokens)
{
    if (tokens.empty())
    { 
        addError("No tokens to parse.");
        return;
    }
    while(tokens[position].getType() != TokenType::EndOfFile)
    {
        parseStatement(tokens[position]);
    }
}  
void Parser::parse()
{
    parseExpression(tokens);
}