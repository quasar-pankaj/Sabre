#include "addition.hpp"
#include "division.hpp"
#include "equals.hpp"
#include "executable.hpp"
#include "multiplication.hpp"
#include "subtraction.hpp"
#include "virtual_machine.hpp"

VirtualMachine::~VirtualMachine()
{
  instructions_map.clear();
  instructions.clear();
  while (!ds.empty())
  {
    delete ds.top();
    ds.pop();
  }
  delete loader;
}

void VirtualMachine::run(std::string &filename)
{
  instructions = loader->load(filename);
  for (auto ip = instructions.begin(); ip != instructions.end(); ++ip)
  {
    (*ip)->execute(this);
  }
}

void VirtualMachine::push(Object *object) { ds.push(object); }

Object *VirtualMachine::pop()
{
  Object *object = ds.top();
  ds.pop();
  return object;
}

bool VirtualMachine::empty() { return ds.empty(); }
