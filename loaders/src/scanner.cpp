#include "scanner.hpp"

#include <sstream>

std::vector<std::string> Scanner::tokenize()
{
    // Todo: implement a recursive lexical scanner here after developing the CFG
    // <expression>:= <term> + <term> | <term> - <term>
    // <term>:= <factor> * <factor> | <factor> / <factor>
    // <factor>:= <number> | ( <expression> )
    // <number>:= <digit> <digit>* | - <digit> <digit>* | <digit> <digit>*.<digit>* | - <digit> <digit>*.<digit>*
    // <digit>:= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
    // <whitespace>:= ' ' | '\t' | '\n' | '\r'
    // 
    std::vector<std::string> tokens;
    std::istringstream iss(contents);
    std::string token;
    while (iss >> token)
    {
        tokens.push_back(token);
    }
    return tokens;
}