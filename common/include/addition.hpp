#pragma once

#include "binary_operator.hpp"

class Addition : public BinaryOperator<Addition> {
public:
  Addition() = default;
  ~Addition() = default;

  template <typename LHS, typename RHS> auto operate(LHS lhs, RHS rhs) {
    return lhs + rhs;
  }
};