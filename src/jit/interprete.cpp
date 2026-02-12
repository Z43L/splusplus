#include "interprete.hpp"

interprete::interprete(const std::string& input) : lexer(input), current_token_index(0), loop_counter(0), salida_status(0) {}
interprete::~interprete() {}
std::unordered_map<std::string , TokenType> interprete::getCurrentTokens(){
    std::unordered_map<std::string , TokenType> token_map;
    token_map = lexer.nextToken().getTokenMap(token_map);
    return token_map;
}
std::unordered_map<std::string, TokenType> interprete::tokenize(std::string input, Lexer& lexer) {
    // Aquí se implementaría la lógica para tokenizar el código de entrada
    // utilizando el lexer proporcionado.

    std::unordered_map<std::string, TokenType> token_map;
    token_map = lexer.nextToken().getTokenMap(token_map);
    return token_map;
    
} 
std::vector<Token> interprete::interpretWhile(std::vector<Token> tokens ) { // Aquí se implementaría la lógica para interpretar el código de entrada // utilizando los tokens obtenidos del lexer. std::unordered_map<std::string , TokenType> token_map;

        int i = 0;
        std::vector<Token> tokewhile;
        if(tokens.at(0).getValue() == "while" )
        {
            while(tokens.at(i).getType() != TokenType::Type::EndOfFile)
            {
                tokewhile.push_back(tokens.at(i));
                i++;
             
            }
            
        }
    return tokewhile;
}

std::vector<Token> interprete::interpreterIf(std::vector<Token> tokens )
{
    int i = 0;
    std::vector<Token> tokeif;
    if(tokens.at(0).getValue() == "if" )
    {
        while(tokens.at(i).getType() != TokenType::Type::EndOfFile)
        {
            tokeif.push_back(tokens.at(i));
            i++;
        }
        if(tokens.at(i).getValue() == "}" )
            return tokeif;
    }
    return tokeif;

}