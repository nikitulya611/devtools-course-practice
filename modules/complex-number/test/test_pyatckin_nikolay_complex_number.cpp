// Copyright 2022 Pyatckin Nikolay

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pyatckin_Nikolay_ComplexNumberTest1, add) {
  ComplexNumber c1(5, 3);
  ComplexNumber c2(2.5, 1.5);
  ComplexNumber res(7.5, 4.5);
  ComplexNumber res2 = c1 + c2;

  EXPECT_EQ(res.getRe(), res2.getRe());
  EXPECT_EQ(res.getIm(), res2.getIm());
}

TEST(Pyatckin_Nikolay_ComplexNumberTest2, multiplication) {
  ComplexNumber c1(2, 1);
  ComplexNumber c2(3, 2);
  ComplexNumber res(4.0, 7.0);
  ComplexNumber res2 = c1 * c2;

  EXPECT_EQ(res.getRe(), res2.getRe());
  EXPECT_EQ(res.getIm(), res2.getIm());
}

TEST(Pyatckin_Nikolay_ComplexNumberTest3, subtraction) {
  double re1 = 2.0;
  double re2 = 3.0;
  double im1 = 2.0;
  double im2 = 1.5;

  ComplexNumber c1(re1, im1);
  ComplexNumber c2(re2, im2);
  ComplexNumber res = c1 - c2;

  double res_re = re1 - re2;
  double res_im = im1 - im2;

  EXPECT_EQ(res.getRe(), res_re);
  EXPECT_EQ(res.getIm(), res_im);
}

TEST(Pyatckin_Nikolay_ComplexNumberTest4, divide) {
    double re1 = 5.0;
    double im1 = 3.0;
    ComplexNumber z1(re1, im1);

    double re2 = 2.5;
    double im2 = 1.5;
    ComplexNumber z2(re2, im2);

    ComplexNumber result = z1 / z2;

    EXPECT_EQ(2, result.getRe());
    EXPECT_EQ(0, result.getIm());
}
