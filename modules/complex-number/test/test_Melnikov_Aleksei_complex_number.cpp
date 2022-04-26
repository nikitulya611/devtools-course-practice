// Copyright 2022 Melnikov Aleksei

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Melnikov_Aleksei_ComplexNumberTest1, add) {
  ComplexNumber c1(5, 4);
  ComplexNumber c2(6, 2);
  ComplexNumber res(11.0, 6.0);
  ComplexNumber res2 = c1 + c2;

  EXPECT_EQ(res.getRe(), res2.getRe());
  EXPECT_EQ(res.getIm(), res2.getIm());
}

TEST(Melnikov_Aleksei_ComplexNumberTest2, multiplication) {
  ComplexNumber c1(5, 4);
  ComplexNumber c2(6, 2);
  ComplexNumber res(22.0, 34.0);
  ComplexNumber res2 = c1 * c2;

  EXPECT_EQ(res.getRe(), res2.getRe());
  EXPECT_EQ(res.getIm(), res2.getIm());
}

TEST(Melnikov_Aleksei_ComplexNumberTest3, subtraction) {
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

TEST(Melnikov_Aleksei_ComplexNumberTest4, subtraction2) {
  double re1 = 2.5778;
  double re2 = 5.8765;
  double im1 = 4.4578;
  double im2 = 6.234;

  ComplexNumber c1(re1, im1);
  ComplexNumber c2(re2, im2);
  ComplexNumber res = c1 - c2;

  double res_re = re1 - re2;
  double res_im = im1 - im2;

  EXPECT_EQ(res.getRe(), res_re);
  EXPECT_EQ(res.getIm(), res_im);
}
