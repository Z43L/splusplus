#include "while.hpp"
#include "../../jit/interprete.hpp"
std::unordered_map<std::string , TokenType> interprete::executeWhile(std::vector<Token> tokenswhile, int i)
{
        std::unordered_map<std::string , TokenType> new_token_map;
        int x = 0;
        while(tokenswhile.at(i).getType() != TokenType::Type::EndOfFile)
        {
                if(tokenswhile.at(i).getType() == TokenType::Type::Identifier && tokenswhile.at(i).getValue() == "if")
                {
                        auto if_map = interpreterIf(tokenswhile);
                        new_token_map.insert(if_map.begin(), if_map.end());
                        i++;

                }
                                
        }


}