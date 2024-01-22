#pragma once

#include <string>
#include <vector>
#include <map>

#include "executable.hpp"
#include "instructions.hpp"

class Loader
{
public:
    Loader() = default;
    virtual ~Loader();

    virtual std::vector<Executable *> load(std::string filename) = 0;

    std::map<Instruction, Executable *> getInstructionSet() { return instruction_set; }
    std::map<std::string, Instruction> getInstructionsMapping() { return instructions_mapping; }
    std::map<std::string, Executable *> getInterpretationSet() { return interpretation_set; }

protected:
    std::map<Instruction, Executable *> instruction_set;
    std::map<std::string, Instruction> instructions_mapping;
    std::map<std::string, Executable *> interpretation_set;
};
