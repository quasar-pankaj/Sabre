#pragma once

#include "binary_operator.hpp"

class Subtraction : public BinaryOperator<Subtraction> {
public:
  Subtraction() = default;
  ~Subtraction() = default;

  template <typename LHS, typename RHS>
  auto operate(LHS lhs, RHS rhs) {
    return lhs - rhs;
  }
};