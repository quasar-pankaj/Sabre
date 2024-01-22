#pragma once

#include "executable.hpp"
#include "execution_engine.hpp"
#include "number.hpp"
#include "object.hpp"

#include <stdexcept>
#include <type_traits>

template <typename Derived> class BinaryOperator : public Executable {
public:
  BinaryOperator() = default;
  ~BinaryOperator() = default;
  
  void execute(ExecutionEngine *engine) override {
    if (engine->size() < 2)
      throw std::invalid_argument("Invalid Value");

    Object *rhs = engine->pop();
    Object *lhs = engine->pop();
    Object *result;

    result = tryOperateGroup<long>(lhs, rhs);
    if (result != nullptr) {
      engine->push(result);
      delete lhs;
      delete rhs;
      return;
    }
    result = tryOperateGroup<double>(lhs, rhs);
    if (result != nullptr) {
      engine->push(result);
      delete lhs;
      delete rhs;
      return;
    }

    throw std::invalid_argument("Invalid Value");
  }

private:
  template <typename LHS> Object *tryOperateGroup(Object *lhs, Object *rhs) {
    Number<LHS> *lhsNum = dynamic_cast<Number<LHS> *>(lhs);
    if (lhsNum == nullptr) {
      return nullptr;
    }

    Number<long> *rhsNumLong = dynamic_cast<Number<long> *>(rhs);
    if (rhsNumLong != nullptr) {
      auto result = operate(lhsNum, rhsNumLong);
      return result;
    }
    Number<double> *rhsNumDouble = dynamic_cast<Number<double> *>(rhs);
    if (rhsNumDouble != nullptr) {
      auto result = operate(lhsNum, rhsNumDouble);
      return result;
    }

    return nullptr;
  }

  template <typename LHS, typename RHS>
  auto *operate(Number<LHS> *lhs, Number<RHS> *rhs) {
    auto result = dynamic_cast<Derived *>(this)->operate(lhs->getValue(),
                                                         rhs->getValue());
    return new Number<decltype(result)>(result);
  }
};