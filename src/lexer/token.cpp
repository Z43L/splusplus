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
std::string TokenType::getStatementTypeString(StattementType type)
{
    switch (type)
    {
    case StattementType::If:
        return "If";
    case StattementType::ElseIf:
        return "ElseIf";
    case StattementType::Else:
        return "Else";
    case StattementType::While:
        return "While";
    case StattementType::For:
        return "For";
    case StattementType::Return:
        return "Return";
    default:
        return "Unknown";
    }
}
std::string TokenType::getTypeOperatorString(OperatorType type)
{
    switch (type)
    {
    case OperatorType::Plus:
        return "Plus";
    case OperatorType::Minus:
        return "Minus";
    case OperatorType::Multiply:
        return "Multiply";
    case OperatorType::Divide:
        return "Divide";
    case OperatorType::Equal:
        return "Equal";
    case OperatorType::EqualMinus:
        return "EqualMinus";
    case OperatorType::EqualPlus:
        return "EqualPlus";
    case OperatorType::EqualMultiply:
        return "EqualMultiply";
    case OperatorType::EqualDivide:
        return "EqualDivide";
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
void Token::addError(const std::string &error)
{
    std::cerr << "Error: " << error << std::endl;
}

int Token::getTokenTypeInt(TokenType type)
{
    if (type.getNodeType() == TokenType::NodeType::Statement)
    {
        return 1;
    }
    else if (type.getNodeType() == TokenType::NodeType::Expression)
    {
        return 2;
    }
    else if (type.getNodeType() == TokenType::NodeType::Term)
    {
        return 3;
    }
    else if (type.getNodeType() == TokenType::NodeType::Factor)
    {
        return 4;
    }
    else
    {
        return 0;
    }
}

std::unordered_map<std::string, TokenType> Token::getTokenMap(std::unordered_map<std::string, TokenType> map) const
{
    std::unordered_map<std::string, TokenType> token_map;
    for (const auto &entry : map)
    {
        token_map.insert(entry);
    }
    return token_map;
}

std::unordered_map<std::string, TokenType::NodeContent> TokenType::setTokenMap(std::string value, TokenType type,TokenType::PrincipalType principaltype, TokenType::ExecutionContext context, TokenType::NodeContent content)
{
    int i = 0;

    std::unordered_map<std::string, TokenType::NodeContent> token_map;
    while(context.variables.find(value) != context.variables.end())
    {
        i++;
        value = value + std::to_string(i);
        if(getNodeTypeString(content.NodeXType) == "Identifier")
        {
            content.type.insert(0, "Identifier");
            ExecutionContext context;
            content.context = &context;
            context.variables.insert({ value, 0});
            token_map.insert({value, content});
        }
        else if(getNodeTypeString(content.NodeXType) == "Keyword")
        {
            content.context = &context;
            content.positionEjecution = i;
            content.keywords =value;
            context.variables.insert({ value, i});
            content.type.insert(0, "Keyword");
            token_map.insert({value, content});
        }
        else if(getNodeTypeString(content.NodeXType) == "Operator")
        {
            if(getTypeOperatorString(content.OperatorType) == "Plus"|| getTypeOperatorString(content.OperatorType) == "Minus" || getTypeOperatorString(content.OperatorType) == "Multiply" || getTypeOperatorString(content.OperatorType) == "Divide" || getTypeOperatorString(content.OperatorType) == "Equal" || getTypeOperatorString(content.OperatorType) == "EqualMinus" || getTypeOperatorString(content.OperatorType) == "EqualPlus" || getTypeOperatorString(content.OperatorType) == "EqualMultiply" || getTypeOperatorString(content.OperatorType) == "EqualDivide")  
            {
                content.context = &context;
                content.positionEjecution = i;
                content.operators = value;
                context.variables.insert({ value, i});
                token_map.insert({value, content});
            }
            content.type.insert(0, "Operator");
        }
        else if(getNodeTypeString(content.NodeXType) == "Punctuation")
        {
            content.context = &context;
            if(getPuntuationString(value) == ";")
            {
                content.positionEjecution = i- 0;
            }
            else if(getPuntuationString(value) == "(")
            {
                content.positionEjecution =i- 1;
            }
            else if(getPuntuationString(value) == ")")
            {
                content.positionEjecution = i- 2;
            }
            else if(getPuntuationString(value) == "{")
            {
                content.positionEjecution = i- 3;
            }
            else if(getPuntuationString(value) == "}")
            {
                content.positionEjecution = i- 4;
            }
            else if(getPuntuationString(value) == ";")
            {
                content.positionEjecution = i- 5;
            }
            else if(getPuntuationString(value) == ",")
            {
                content.positionEjecution = i- 6;
            }
    
            content.punctuation = value;
            context.variables.insert({ value, 0});
            content.type.insert(0, "Punctuation");

        }
        else if(getNodeTypeString(content.NodeXType) == "Number")
        {
            content.context = &context;
            content.positionEjecution = i;
            content.tokenTypeInt = std::stoi(value);
            content.type.insert(0, "Number");
            context.variables.insert({ value, 0});
            token_map.insert({value, content});
        }
        else if(getNodeTypeString(content.NodeXType) == "String")
        {
            content.context = &context;
            content.positionEjecution = 0;
            content.type.insert(0, "String");
            context.variables.insert({ value, 0});
            token_map.insert({value, content});
        }
        else
        {   content.context = &context;
            content.positionEjecution = 0;
            content.type.insert(0, "Unknown");
            context.variables.insert({ value, 0});
            token_map.insert({value, content});
        }
    }
    
    return token_map;
}



int Token::follow_token_map(const std::unordered_map<std::string, TokenType> &token_map)
{
    auto it = token_map.find(this->value);
    if (it != token_map.end())
    {
        return -1;
        type = it->second;
    }
    return Token::getTokenTypeInt(nodeType);
}