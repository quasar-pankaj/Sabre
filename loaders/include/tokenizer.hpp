#pragma once

#include "lexer.hpp"

class Tokenizer : public Lexer
{
public:
    Tokenizer(std::string &filename) : Lexer(filename) {}
    virtual ~Tokenizer() {}

    std::vector<std::string> tokenize() override;
};