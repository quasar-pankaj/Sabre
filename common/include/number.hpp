#pragma once

#include "executable.hpp"
#include "execution_engine.hpp"
#include "object.hpp"

#include <string>
#include <cstring>

template <typename T>
class Number : public Object, public Executable
{
public:
  Number(T value) { holder.value = value; }
  Number(char *bytes) { std::memcpy(this->holder.bytes, bytes, sizeof(T)); }

  ~Number() = default;

  T getValue() const { return holder.value; }
  char *getBytes() { return holder.bytes; }
  operator T() { return holder.value; }
  std::string toString() override
  {
    return std::to_string(static_cast<T>(holder.value));
  }
  void execute(ExecutionEngine *engine) override
  {
    engine->push(this);
  }

private:
  union number_holder
  {
    T value;
    char bytes[sizeof(T)];
  } holder;
};