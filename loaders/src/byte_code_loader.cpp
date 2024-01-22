#include "byte_code_loader.hpp"
#include "number.hpp"

#include <fstream>
#include <stdexcept>

std::vector<Executable *> ByteCodeLoader::load(std::string filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file)
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    // get the file size
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // read the data into a vector<char>
    std::vector<char> data(fileSize);
    file.read(data.data(), fileSize);

    return build(data);
}

std::vector<Executable *> ByteCodeLoader::build(std::vector<char> bytecode)
{
    std::vector<Executable *> instructions;
    for (int i = 0; i < bytecode.size(); i++)
    {
        auto instruction = static_cast<Instruction>(bytecode[i]);
        auto it = instruction_set.find(instruction);
        if (it != instruction_set.end())
        {
            instructions.push_back(it->second);
        }
        else if (instruction == Instruction::Pushd)
        {
            i++;
            double number = 0;
            std::memcpy(&number, &bytecode[i], sizeof(double));
            instructions.push_back(new Number<double>(number));
            i += sizeof(double) - 1;
        }
        else if (instruction == Instruction::Pushl)
        {
            i++;
            long number = 0;
            std::memcpy(&number, &bytecode[i], sizeof(long));
            instructions.push_back(new Number<long>(number));
            i += sizeof(long) - 1;
        }
        else
        {
            throw std::runtime_error("Invalid instruction: " + std::to_string(bytecode[i]));
        }
    }
    return instructions;
}