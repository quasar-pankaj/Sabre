#pragma once

#include "executable.hpp"

#include <iostream>

class Equals : public Executable {

public:
  Equals() = default;
  ~Equals() = default;

  void execute(ExecutionEngine *engine) override {
    auto result = engine->pop();

    std::cout << result->toString() << std::endl;
  }
};