#pragma once

#include "executable.hpp"
#include "execution_engine.hpp"

#include <map>
#include <stack>
#include <string>
#include <vector>

class VirtualMachine : public ExecutionEngine
{
public:
  VirtualMachine(Loader *loader) : ExecutionEngine(loader) {}
  virtual ~VirtualMachine();

  void run(std::string &filename) override;
  void push(Object *) override;
  Object *pop() override;
  bool empty() override;
  int size() override { return ds.size(); }

private:
  std::vector<Executable *> instructions;
  std::stack<Object *> ds;
  std::vector<Executable *> instructions_map;
};