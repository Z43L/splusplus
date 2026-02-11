#include "lexer.hpp"

std::unordered_map<std::string, TokenType> Token::token_map(TokenType type, const std::string &value)
{
    std::unordered_map<std::string, TokenType> token_map;
    token_map.insert({value, type});
    return token_map;
}

std::string TokenType::getNodeTypeString(NodeType nodeType)
{
    switch (nodeType)
    {
    case NodeType::Program:
        return "Program";
    case NodeType::Statement:
        return "Statement";
    case NodeType::Expression:
        return "Expression";
    case NodeType::Term:
        return "Term";
    case NodeType::Factor:
        return "Factor";
    default:
        return "Unknown";
    }
}
std::string TokenType::getPrincipalTypeString(PrincipalType principalType)
{
    switch (principalType)
    {
    case PrincipalType::Variable:
        return "Variable";
    case PrincipalType::Function:
        return "Function";
    case PrincipalType::Class:
        return "Class";
    case PrincipalType::WhileLoop:
        return "WhileLoop";
    case PrincipalType::ForLoop:
        return "ForLoop";
    case PrincipalType::IfStatement:
        return "IfStatement";
    case PrincipalType::ElseIfStatement:
        return "ElseIfStatement";
    case PrincipalType::ElseStatement:
        return "ElseStatement";
    case PrincipalType::Export:
        return "Export";
    case PrincipalType::Include:
        return "Include";
    case PrincipalType::Define:
        return "Define";
    default:
        return "Unknown";
    }
}

std::unordered_map<std::string, TokenType::NodeContent> TokenType::setTokenPriorityMap(std::string value, TokenType::PrincipalType principaltype , TokenType type,TokenType::NodeContent content, int i )
{
    std::unordered_map<std::string, TokenType::NodeContent> token_map;
    if(getPrincipalTypeString(principaltype) == "var" || getPrincipalTypeString(principaltype) == "function" || getPrincipalTypeString(principaltype) == "class" || getPrincipalTypeString(principaltype) == "#include" || getPrincipalTypeString(principaltype) == "#define" || getPrincipalTypeString(principaltype) == "export")
    {
        content.type.replace(0, content.type.size(), "Identifier");
        ExecutionContext context;
        content.context = &context;
        context.variables.insert({ value, i});
        token_map.insert({value, content});
    }
    
    return token_map;
}



std::unordered_map<std::string, TokenType::Type> TokenType::load_token_map(
    TokenType::Type type,
    std::string value)
{
    std::unordered_map<std::string, TokenType::Type> token_map;

    switch (type)
    {
    case TokenType::Type::Identifier:
        token_map.insert({value, type});
        break;
    case TokenType::Type::Keyword:
        token_map.insert({value, type});
        break;
    case TokenType::Type::Operator:
        token_map.insert({value, type});
        break;
    case TokenType::Type::Punctuation:
        token_map.insert({value, type});
        break;
    default:
        break;
    }
    return token_map;
}
