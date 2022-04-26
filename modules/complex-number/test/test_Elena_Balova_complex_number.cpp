// Copyright 2022 Balova Elena

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Balova_Elena_ComplexNumberTest1, add) {
  ComplexNumber c1(3, 2);
  ComplexNumber c2(7, 2);
  ComplexNumber result(10.0, 4.0);
  ComplexNumber result2 = c1 + c2;

  EXPECT_EQ(result.getRe(), result2.getRe());
  EXPECT_EQ(result.getIm(), result2.getIm());
}

TEST(Balova_Elena_ComplexNumberTest2, multiplication) {
  ComplexNumber c1(5, 4);
  ComplexNumber c2(6, 2);
  ComplexNumber result(22.0, 34.0);
  ComplexNumber result2 = c1 * c2;

  EXPECT_EQ(result.getRe(), result2.getRe());
  EXPECT_EQ(result.getIm(), result2.getIm());
}

TEST(Balova_Elena_ComplexNumberTest3, subtraction) {
  double re1 = 2346.5778;
  double re2 = -534634.8765;
  double im1 = 4235.4578;
  double im2 = 6236.234;

  ComplexNumber c1(re1, im1);
  ComplexNumber c2(re2, im2);
  ComplexNumber result = c1 - c2;

  double result_re = re1 - re2;
  double result_im = im1 - im2;

  EXPECT_EQ(result.getRe(), result_re);
  EXPECT_EQ(result.getIm(), result_im);
}

TEST(Balova_Elena_ComplexNumberTest4, subtraction2) {
  double re1 = 2.5778;
  double re2 = 5.8765;
  double im1 = 4.4578;
  double im2 = 6.234;

  ComplexNumber c1(re1, im1);
  ComplexNumber c2(re2, im2);
  ComplexNumber result = c1 - c2;

  double result_re = re1 - re2;
  double result_im = im1 - im2;

  EXPECT_EQ(result.getRe(), result_re);
  EXPECT_EQ(result.getIm(), result_im);
}
