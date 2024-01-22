#pragma once

#include "binary_operator.hpp"

class Multiplication : public BinaryOperator<Multiplication> {
public:
  Multiplication() = default;
  ~Multiplication() = default;

  template <typename LHS, typename RHS>
  auto operate(LHS lhs, RHS rhs) {
    return lhs * rhs;
  }
};