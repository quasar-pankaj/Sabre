#include "loader.hpp"
#include "addition.hpp"
#include "division.hpp"
#include "equals.hpp"
#include "multiplication.hpp"
#include "subtraction.hpp"

Loader::Loader()
{
    instruction_set = {
        {Instruction::Plus, new Addition()},
        {Instruction::Minus, new Subtraction()},
        {Instruction::Multiply, new Multiplication()},
        {Instruction::Divide, new Division()},
        {Instruction::Pop, new Equals()},
    };
    instructions_mapping = {
        {"+", Instruction::Plus},
        {"-", Instruction::Minus},
        {"*", Instruction::Multiply},
        {"/", Instruction::Divide},
        {"=", Instruction::Pop},
    };
    interpretation_set = {
        {"+", instruction_set[Instruction::Plus]},
        {"-", instruction_set[Instruction::Minus]},
        {"*", instruction_set[Instruction::Multiply]},
        {"/", instruction_set[Instruction::Divide]},
        {"=", instruction_set[Instruction::Pop]},
    };
}

Loader::~Loader()
{
    instruction_set.clear();
    instructions_mapping.clear();
    for (auto it = interpretation_set.begin(); it != interpretation_set.end(); ++it)
    {
        delete it->second;
    }
    interpretation_set.clear();
}