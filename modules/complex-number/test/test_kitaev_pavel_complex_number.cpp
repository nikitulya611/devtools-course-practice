// Copyright 2022 Kitaev Pavel

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kitaev_Pavel_ComplexNumberTest,
  Can_Instantiate_ComplexNumber) {
  // Arrange
  double re = 10.0;
  double im = 15.0;

  // Act
  ComplexNumber z(re, im);

  // Assert
  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Kitaev_Pavel_ComplexNumberTest, Can_Perform_Sum) {
  // Arrange
  double a_re = 10.0;
  double a_im = 15.0;

  double b_re = 19.0;
  double b_im = 28.0;

  // Act
  ComplexNumber a(a_re, a_im);
  ComplexNumber b(b_re, b_im);
  b = a + b;

  // Assert
  EXPECT_EQ(a_re + b_re, b.getRe());
  EXPECT_EQ(a_im + b_im, b.getIm());
}

TEST(Kitaev_Pavel_ComplexNumberTest,
  Can_Perform_Difference) {
  // Arrange
  double a_re = 10.0;
  double a_im = 15.0;

  double b_re = 19.0;
  double b_im = 28.0;

  // Act
  ComplexNumber a(a_re, a_im);
  ComplexNumber b(b_re, b_im);
  b = a - b;

  // Assert
  EXPECT_EQ(a_re - b_re, b.getRe());
  EXPECT_EQ(a_im - b_im, b.getIm());
}

TEST(Kitaev_Pavel_ComplexNumberTest,
  Can_Perform_Multiplication) {
  // Arrange
  double a_re = 10.0;
  double a_im = 15.0;

  double b_re = 19.0;
  double b_im = 28.0;

  double res_re = (a_re * b_re) - (a_im * b_im);
  double res_im = (a_re * b_im) + (a_im * b_re);
  // Act
  ComplexNumber a(a_re, a_im);
  ComplexNumber b(b_re, b_im);
  b = a * b;

  // Assert
  EXPECT_EQ(res_re, b.getRe());
  EXPECT_EQ(res_im, b.getIm());
}

TEST(Kitaev_Pavel_ComplexNumberTest,
  Can_Perform_Multiplication_in_Zerro) {
  // Arrange
  double a_re = 10.0;
  double a_im = 0.0;

  double b_re = 0.0;
  double b_im = 10.0;

  double res_re = (a_re * b_re) - (a_im * b_im);
  double res_im = (a_re * b_im) + (a_im * b_re);
  // Act
  ComplexNumber a(a_re, a_im);
  ComplexNumber b(b_re, b_im);
  b = a * b;

  // Assert
  EXPECT_EQ(res_re, b.getRe());
  EXPECT_EQ(res_im, b.getIm());
}

TEST(Kitaev_Pavel_ComplexNumberTest,
  Can_Perform_Division) {
  // Arrange
  double a_re = 40.0;
  double a_im = 20.0;

  double b_re = 20.0;
  double b_im = 10.0;

  double den = 1.0 / (b_re * b_re + b_im * b_im);
  double res_re = den * a_re * b_re + den * a_im * b_im;
  double res_im = den * a_im * b_re - den * a_re * b_im;

  // Act
  ComplexNumber a(a_re, a_im);
  ComplexNumber b(b_re, b_im);
  b = a / b;

  // Assert
  EXPECT_EQ(res_re, b.getRe());
  EXPECT_EQ(res_im, b.getIm());
}

TEST(Kitaev_Pavel_ComplexNumberTest, Can_Do_Comparison) {
  // Arrange
  double a_re = 10.0;
  double a_im = 20.0;

  double b_re = 10.0;
  double b_im = 20.0;

  // Act
  ComplexNumber a(a_re, a_im);
  ComplexNumber b(b_re, b_im);

  // Assert
  EXPECT_EQ(true, a == b);
  EXPECT_EQ(false, a != b);
}
