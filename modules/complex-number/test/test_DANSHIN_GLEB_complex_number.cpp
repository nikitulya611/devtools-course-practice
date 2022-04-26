// Copyright 2022 Gleb "belgad" Danshin

#include <gtest/gtest.h>
#include <string>

#include "include/complex_number.h"

TEST(DanshinGlebComplexNumberTest, DefaultConstructor) {
  ASSERT_NO_THROW(ComplexNumber());
}

TEST(DanshinGlebComplexNumberTest, ParameterizedConstructor) {
  ASSERT_NO_THROW(ComplexNumber(1.0, 2.0));
}

TEST(DanshinGlebComplexNumberTest, CopyConstructor) {
  ASSERT_NO_THROW(ComplexNumber(ComplexNumber()));
}

TEST(DanshinGlebComplexNumberTest, AssignmentOperator) {
  auto origin = ComplexNumber(1.0, 2.0);
  auto copy = ComplexNumber();
  ASSERT_NO_THROW(copy = origin);
}

TEST(DanshinGlebComplexNumberTest, EqualityOperator) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(1.0, 2.0);
  ASSERT_EQ(first, second);
}

TEST(DanshinGlebComplexNumberTest, CopyEqualsToOrigin) {
  auto origin = ComplexNumber(1.0, 2.0);
  auto copy = origin;
  ASSERT_EQ(origin, copy);
}

TEST(DanshinGlebComplexNumberTest, InequalityOperator) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(3.0, 4.0);
  ASSERT_NE(first, second);
}

TEST(DanshinGlebComplexNumberTest, AdditionOperator) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(3.0, 4.0);
  auto product = first + second;
  ASSERT_EQ(product, ComplexNumber(4.0, 6.0));
}

TEST(DanshinGlebComplexNumberTest, SubtractionOperator) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(3.0, 4.0);
  auto product = first - second;
  ASSERT_EQ(product, ComplexNumber(-2.0, -2.0));
}

TEST(DanshinGlebComplexNumberTest, MultiplicationOperator) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(3.0, 4.0);
  auto product = first * second;
  ASSERT_EQ(product, ComplexNumber(-5.0, 10.0));
}

TEST(DanshinGlebComplexNumberTest, DivisionOperator) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(3.0, 4.0);
  auto product = first / second;
  ASSERT_EQ(product, ComplexNumber(0.44, 0.08));
}

TEST(DanshinGlebComplexNumberTest, DivisionByZeroError) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber();
  ASSERT_THROW(first / second, std::string);
}
