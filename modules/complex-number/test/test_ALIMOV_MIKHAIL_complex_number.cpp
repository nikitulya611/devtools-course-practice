// Copyright 2022 ALIMOV MIKHAIL

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(ALIMOV_ALIMOV_MIKHAIL_ComplexNumber_Test1, sumirovaie) {
  ComplexNumber c1(8, 3);
  ComplexNumber c2(2, 2);
  ComplexNumber res(10.0, 5.0);
  ComplexNumber res2 = c1 + c2;

  EXPECT_EQ(res.getRe(), res2.getRe());
  EXPECT_EQ(res.getIm(), res2.getIm());
}

TEST(ALIMOV_MIKHAIL_ComplexNumber_Test2, ymnozenie) {
  ComplexNumber c1(8, 4);
  ComplexNumber c2(5, 7);
  ComplexNumber res(12.0, 76.0);
  ComplexNumber res2 = c1 * c2;

  EXPECT_EQ(res.getRe(), res2.getRe());
  EXPECT_EQ(res.getIm(), res2.getIm());
}

TEST(ALIMOV_MIKHAIL_ComplexNumber_Test3, vichitanie) {
  double re1 = 2346.5778;
  double re2 = -534634.8765;
  double im1 = 4235.4578;
  double im2 = 6236.234;

  ComplexNumber c1(re1, im1);
  ComplexNumber c2(re2, im2);
  ComplexNumber res = c1 - c2;

  double res_re = re1 - re2;
  double res_im = im1 - im2;

  EXPECT_EQ(res.getRe(), res_re);
  EXPECT_EQ(res.getIm(), res_im);
}

TEST(ALIMOV_MIKHAIL_ComplexNumber_Test4, delenie) {
  double re1 = 1.0;
  double im1 = 2.0;
  double re2 = 1.0;
  double im2 = 2.0;
  ComplexNumber first(re1, im1);
  ComplexNumber second(re2, im2);

  ComplexNumber res = first / second;

  EXPECT_EQ(1, res.getRe());
  EXPECT_EQ(0, res.getIm());
}
