#pragma once

#include <string>
#include <vector>

class Lexer
{
public:
    Lexer(std::string &filename);
    virtual ~Lexer();

    virtual std::vector<std::string> tokenize() = 0;

protected:
    std::string contents;
};