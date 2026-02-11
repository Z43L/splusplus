#include "parse.hpp"

std::vector<Token> Parser::readFiles(const std::string &filename)
{
    std::vector<Token> tokens;
    if (filename.empty())
    {
        addError("Filename is empty.");
        return tokens;
    }
    std::string file   =  std::fstream(filename).is_open() ? std::string((std::istreambuf_iterator<char>(std::fstream(filename).rdbuf())), std::istreambuf_iterator<char>()) : "";
    if (file.empty())
    {
        addError("Failed to read file: " + filename);
        return tokens;
    }
    Lexer lexer(file);
    Token token = lexer.nextToken();
    while (token.getType() != TokenType::EndOfFile)
    {
        tokens.push_back(token);
        token = lexer.nextToken();
    }
    return tokens;
}

void Parser::addError(const std::string &error)
{
    errors.push_back(error);
}

void TokenType::parseStatement(Token token)
{
    if ( TokenType::NodeType::Statement == token.)
    {
        if(token.getValue() == "if")
        {b
            // Handle if statements
        }
        else if(token.getValue() == "while")
        {
            // Handle while statements
        }
        else if(token.getValue() == "for")
        {
            // Handle for statements
        }
        else if(token.getValue() == "return")
        {
            // Handle return statements
        }
        else
        {
            addError("Unknown keyword: " + token.getValue());
        }
    }
    else if (token.getType() == TokenType::Identifier)
    {
        if(position + 1 < tokens.size() && tokens[position + 1].getType() == TokenType::Operator && tokens[position + 1].getValue() == "=")
        {
            // Handle assignment statements
        }
        if(position + 1 < tokens.size() && tokens[position + 1].getType() == TokenType::Punctuation && tokens[position + 1].getValue() == ";")
        {
        }
        if(position + 1 < tokens.size() && tokens[position + 1].getType() == TokenType::Punctuation && tokens[position + 1].getValue() == "(")
        {
            // Handle function calls
            if(position + 2 < tokens.size() && tokens[position + 2].getType() == TokenType::Punctuation && tokens[position + 2].getValue() == ")")
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
            addError("Unexpected identifier: " + token.getValue());
        }
    }
    else
    {
        addError("Unexpected token: " + token.getValue());
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