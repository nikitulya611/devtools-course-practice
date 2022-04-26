// Copyright 2022 Kurguzikov Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kurguzikov_Kirill_ComplexNumberTest,
  Install_Complex_Number) {
  // Arrange
  double real = 5.0;
  double imaginary = 7.0;

  // Act
  ComplexNumber first(real, imaginary);

  // Assert
  EXPECT_EQ(real, first.getRe());
  EXPECT_EQ(imaginary, first.getIm());
}

TEST(Kurguzikov_Kirill_ComplexNumberTest,
  Can_Addition) {
  // Arrange
  double first_real = 5.0;
  double first_imaginary = 7.0;

  double second_real = 8.0;
  double second_imaginary = 10.0;

  // Act
  ComplexNumber first(first_real, first_imaginary);
  ComplexNumber second(second_real, second_imaginary);
  second = first + second;

  // Assert
  EXPECT_EQ(first_real + second_real, second.getRe());
  EXPECT_EQ(first_imaginary + second_imaginary,
  second.getIm());
}

TEST(Kurguzikov_Kirill_ComplexNumberTest,
  Can_Subtraction) {
  // Arrange
  double first_real = 5.0;
  double first_imaginary = 7.0;

  double second_real = 8.0;
  double second_imaginary = 10.0;

  // Act
  ComplexNumber first(first_real, first_imaginary);
  ComplexNumber second(second_real, second_imaginary);
  second = first - second;

  // Assert
  EXPECT_EQ(first_real - second_real, second.getRe());
  EXPECT_EQ(first_imaginary - second_imaginary, second.getIm());
}

TEST(Kurguzikov_Kirill_ComplexNumberTest,
  Can_Multiplication_By_Zero) {
  // Arrange
  double first_real = 5.0;
  double first_imaginary = 0.0;

  double second_real = 0.0;
  double second_imaginary = 10.0;

  double res_real = (first_real * second_real) -
  (first_imaginary * second_imaginary);
  double res_imaginary = (first_real * second_imaginary) +
  (first_imaginary * second_real);
  // Act
  ComplexNumber first(first_real, first_imaginary);
  ComplexNumber second(second_real, second_imaginary);
  second = first * second;

  // Assert
  EXPECT_EQ(res_real, second.getRe());
  EXPECT_EQ(res_imaginary, second.getIm());
}

TEST(Kurguzikov_Kirill_ComplexNumberTest,
  Can_Multiplication) {
  // Arrange
  double first_real = 5.0;
  double first_imaginary = 7.0;

  double second_real = 8.0;
  double second_imaginary = 10.0;

  double res_real = (first_real * second_real) -
  (first_imaginary * second_imaginary);
  double res_imaginary = (first_real * second_imaginary) +
  (first_imaginary * second_real);
  // Act
  ComplexNumber first(first_real, first_imaginary);
  ComplexNumber second(second_real, second_imaginary);
  second = first * second;

  // Assert
  EXPECT_EQ(res_real, second.getRe());
  EXPECT_EQ(res_imaginary, second.getIm());
}

TEST(Kurguzikov_Kirill_ComplexNumberTest,
  Can_Division) {
  // Arrange
  double first_real = 5.0;
  double first_imaginary = 7.0;

  double second_real = 8.0;
  double second_imaginary = 10.0;

  double den = 1.0 / (second_real * second_real +
  second_imaginary * second_imaginary);
  double res_real = den * first_real * second_real +
  den * first_imaginary * second_imaginary;
  double res_imaginary = den * first_imaginary *
  second_real - den * first_real * second_imaginary;

  // Act
  ComplexNumber first(first_real, first_imaginary);
  ComplexNumber second(second_real, second_imaginary);
  second = first / second;

  // Assert
  EXPECT_EQ(res_real, second.getRe());
  EXPECT_EQ(res_imaginary, second.getIm());
}

TEST(Kurguzikov_Kirill_ComplexNumberTest,
  Can_Comparison) {
  // Arrange
  double first_real = 5.0;
  double first_imaginary = 7.0;

  double second_real = 8.0;
  double second_imaginary = 10.0;

  // Act
  ComplexNumber first(first_real, first_imaginary);
  ComplexNumber second(second_real, second_imaginary);

  // Assert
  EXPECT_EQ(false, first == second);
  EXPECT_EQ(true, first != second);
}
