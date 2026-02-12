#ifndef WHILE_HPP
#define WHILE_HPP


#include "../../jit/interprete.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "../lexer/lexer.hpp" 

class WhileControl {
    private:
        interprete& interp;
    public:
        WhileControl(interprete& interpreter) : interp(interpreter) {};
        

};
  
#endif