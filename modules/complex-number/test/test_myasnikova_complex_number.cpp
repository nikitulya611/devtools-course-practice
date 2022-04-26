// Copyright 2022 Myasnikova Varvara

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Myasnikova_Varvara_ComplexNumberTest,
  Create_ComplexNumber) {
  double real = 25.0;
  double imag = 32.0;

  ComplexNumber cn(real, imag);

  EXPECT_EQ(real, cn.getRe());
  EXPECT_EQ(imag, cn.getIm());
}

TEST(Myasnikova_Varvara_ComplexNumberTest,
  Perform_Sum) {
  double a_real = 25.0;
  double a_imag = 32.0;
  double b_real = 27.0;
  double b_imag = 38.0;

  ComplexNumber a(a_real, a_imag);
  ComplexNumber b(b_real, b_imag);
  b = a + b;

  EXPECT_EQ(a_real + b_real, b.getRe());
  EXPECT_EQ(a_imag + b_imag, b.getIm());
}

TEST(Myasnikova_Varvara_ComplexNumberTest,
  Perform_Difference) {
  double a_real = 25.0;
  double a_imag = 32.0;
  double b_real = 27.0;
  double b_imag = 38.0;

  ComplexNumber a(a_real, a_imag);
  ComplexNumber b(b_real, b_imag);
  b = a - b;

  EXPECT_EQ(a_real - b_real, b.getRe());
  EXPECT_EQ(a_imag - b_imag, b.getIm());
}

TEST(Myasnikova_Varvara_ComplexNumberTest,
  Perform_Multiplication) {
  double a_real = 25.0;
  double a_imag = 32.0;
  double b_real = 27.0;
  double b_imag = 38.0;

  double re_res = (a_real * b_real) -
    (a_imag * b_imag);
  double im_res = (a_real * b_imag) +
    (a_imag * b_real);

  ComplexNumber a(a_real, a_imag);
  ComplexNumber b(b_real, b_imag);
  b = a * b;

  EXPECT_EQ(re_res, b.getRe());
  EXPECT_EQ(im_res, b.getIm());
}

TEST(Myasnikova_Varvara_ComplexNumberTest,
  Perform_Multiplication_by_Zerro) {
  double a_real = 25.0;
  double a_imag = 0.0;
  double b_real = 0.0;
  double b_imag = 25.0;

  double re_res = (a_real * b_real) -
    (a_imag * b_imag);
  double im_res = (a_real * b_imag) +
    (a_imag * b_real);

  ComplexNumber a(a_real, a_imag);
  ComplexNumber b(b_real, b_imag);
  b = a * b;

  EXPECT_EQ(re_res, b.getRe());
  EXPECT_EQ(im_res, b.getIm());
}

TEST(Myasnikova_Varvara_ComplexNumberTest,
  Perform_Division) {
  double a_real = 30.0;
  double a_imag = 15.0;
  double b_real = 15.0;
  double b_imag = 5.0;

  double d = 1.0 / (b_real * b_real +
    b_imag * b_imag);
  double re_res = d * a_real * b_real +
    d * a_imag * b_imag;
  double im_res = d * a_imag * b_real -
    d * a_real * b_imag;

  ComplexNumber a(a_real, a_imag);
  ComplexNumber b(b_real, b_imag);
  b = a / b;

  EXPECT_EQ(re_res, b.getRe());
  EXPECT_EQ(im_res, b.getIm());
}

TEST(Myasnikova_Varvara_ComplexNumberTest,
  Do_Compare) {
  double a_real = 25.0;
  double a_imag = 32.0;
  double b_real = 25.0;
  double b_imag = 32.0;

  ComplexNumber a(a_real, a_imag);
  ComplexNumber b(b_real, b_imag);

  EXPECT_EQ(true, a == b);
  EXPECT_EQ(false, a != b);
}
