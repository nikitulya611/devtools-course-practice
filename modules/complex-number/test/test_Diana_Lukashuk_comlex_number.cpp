// Copyright 2022 Lukashuk Diana

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Diana_ComplexNumberTest, Multiplication_By_Zero) {
  // Arrange
  double re = 10.0;
  double im = 20.0;

  // Act
  ComplexNumber a(re, im);
  ComplexNumber b(0, 0);
  ComplexNumber c;
  c = a * b;
  std::cout << c.getIm();
  // Assert
  EXPECT_EQ(c.getIm() == 0, 1);
  EXPECT_EQ(c.getRe() == 0, 1);
}

TEST(Diana_ComplexNumberTest, Can_Operator_With_Zero) {
  // Arrange
  double re = 10.0;
  double im = 2.0;

  // Act
  ComplexNumber a(re, im);
  ComplexNumber b(re, im);
  ComplexNumber c0;
  ComplexNumber c1;
  c0 = a - b;
  double res = 0;
  // Assert
  EXPECT_EQ(c0.getIm(), res);
  EXPECT_EQ(c0.getRe(), res);
}

TEST(Diana_ComplexNumberTest, Inequality) {
  // Arrange
  double re = 1.0;
  double im = 2.0;

  // Act
  ComplexNumber z0(0, 0);
  ComplexNumber z1(re, im);
  ComplexNumber z2(re, im);

  // Assert
  EXPECT_EQ(z2 == z1, 1);
  EXPECT_EQ(z2 != z0, 1);
}
