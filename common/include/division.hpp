#pragma once

#include "binary_operator.hpp"

class Division : public BinaryOperator<Division> {
public:
  Division() = default;
  ~Division() = default;

  template <typename LHS, typename RHS>
  auto operate(LHS lhs, RHS rhs) {
    return lhs / rhs;
  }
};