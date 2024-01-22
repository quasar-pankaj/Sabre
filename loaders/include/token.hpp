#pragma once

#include <string>

#include "token_type.hpp"

class Token
{
public:
    Token(TokenType type, std::string value, int line = 0, int column = 0) : type(type), value(value), line(line), column(column) {}

    TokenType getType() { return type; }
    std::string getValue() { return value; }

private:
    TokenType type;
    std::string value;
    int line;
    int column;
};