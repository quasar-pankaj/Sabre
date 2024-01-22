#include "tokenizer.hpp"

#include <sstream>

std::vector<std::string> Tokenizer::tokenize()
{
    // Tokenizer simply takes a string and splits it into a vector of tokens on whitespaces
    // this is how the parsing will work in RPN language
    std::vector<std::string> tokens;
    std::istringstream iss(contents);
    std::string token;
    while (iss >> token)
    {
        tokens.push_back(token);
    }
    return tokens;
}