#pragma once

#include <string>

class Object {
public:
  virtual ~Object() = default;
  virtual std::string toString() = 0;
};