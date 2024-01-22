#pragma once

#include <vector>

#include "loader.hpp"
#include "executable.hpp"

class ByteCodeLoader : public Loader
{
public:
    ByteCodeLoader() : Loader() {}
    ~ByteCodeLoader() {}

    std::vector<Executable *> load(std::string filename) override;

private:
    std::vector<Executable *> build(std::vector<char> bytecode);
};