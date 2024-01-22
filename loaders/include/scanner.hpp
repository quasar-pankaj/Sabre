#pragma once

#include "lexer.hpp"

class Scanner : public Lexer
{
public:
    Scanner(std::string &filename) : Lexer(filename) {}
    ~Scanner() {}

    std::vector<std::string> tokenize() override;

private:
};