// Copyright 2022 Miheev Ivan

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Miheev_Ivan_ComplexNumberTest, Can_Create_Zero) {
  double re = 0.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Miheev_Ivan_ComplexNumberTest, Complex_Equals_Test) {
  double re1 = 2.0;
  double im1 = 1.5;

  ComplexNumber c1(re1, im1);

  EXPECT_EQ(2.0, c1.getRe());
  EXPECT_EQ(1.5, c1.getIm());
}

TEST(Miheev_Ivan_ComplexNumberTest, Complex_Sum_Test) {
  double re1 = 2.0;
  double im1 = 1.5;

  double re2 = 3.0;
  double im2 = 2.0;

  ComplexNumber c1(re1, im1);
  ComplexNumber c2(re2, im2);
  ComplexNumber s = c1 + c2;

  EXPECT_EQ(5.0, s.getRe());
  EXPECT_EQ(3.5, s.getIm());
}

TEST(Miheev_Ivan_ComplexNumberTest, Complex_Minus_Test) {
  double re1 = 2.0;
  double im1 = 1.5;

  double re2 = 3.0;
  double im2 = 2.0;

  ComplexNumber c1(re1, im1);
  ComplexNumber c2(re2, im2);
  ComplexNumber m = c1 - c2;

  EXPECT_EQ(-1.0, m.getRe());
  EXPECT_EQ(-0.5, m.getIm());
}

TEST(Miheev_Ivan_ComplexNumberTest, Complex_Multiply_Test) {
  double re1 = 2.0;
  double im1 = 1.5;

  double re2 = 3.0;
  double im2 = 2.0;

  ComplexNumber c1(re1, im1);
  ComplexNumber c2(re2, im2);
  ComplexNumber m = c2 * c1;

  EXPECT_EQ(3.0, m.getRe());
  EXPECT_EQ(8.5, m.getIm());
}
