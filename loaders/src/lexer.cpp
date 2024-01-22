#include "lexer.hpp"

#include <fstream>

Lexer::Lexer(std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }
    std::string text((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
    file.close();

    contents = text;
}

Lexer::~Lexer()
{
    contents.clear();
}