#pragma once

#include "object.hpp"
#include "loader.hpp"

#include <map>
#include <string>
#include <vector>

class Executable;

class ExecutionEngine
{
public:
  ExecutionEngine(Loader *loader) : loader(loader){};
  virtual ~ExecutionEngine(){};

  virtual void run(std::string &filename) = 0;
  virtual void push(Object *) = 0;
  virtual Object *pop() = 0;
  virtual bool empty() = 0;
  virtual int size() = 0;

protected:
  Loader *loader;
};