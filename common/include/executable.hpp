#pragma once

class ExecutionEngine;

class Executable {
public:
  Executable() = default;
  virtual ~Executable() = default;
  virtual void execute(ExecutionEngine *engine) = 0;
};