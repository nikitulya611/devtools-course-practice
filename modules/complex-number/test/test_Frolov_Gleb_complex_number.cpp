// Copyright 2022 Frolov Gleb

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Frolov_Gleb_ComplexNumberTest, Init_Constructor_Positive_Num) {
  double re = 2.0;
  double im = 5.0;
  ComplexNumber cn1(re, im);

  EXPECT_EQ(cn1.getRe(), 2.0);
  EXPECT_EQ(cn1.getIm(), 5.0);
}

TEST(Frolov_Gleb_ComplexNumberTest, Init_Constructor_Negative_Num) {
  double re = -2.0;
  double im = -5.0;
  ComplexNumber cn1(re, im);

  EXPECT_EQ(cn1.getRe(), -2.0);
  EXPECT_EQ(cn1.getIm(), -5.0);
}

TEST(Frolov_Gleb_ComplexNumberTest, Copy_Constructor) {
  double re = 3.0;
  double im = 1.0;
  ComplexNumber cn1(re, im);
  ComplexNumber cn2 = cn1;

  EXPECT_EQ(cn2.getRe(), 3.0);
  EXPECT_EQ(cn2.getIm(), 1.0);
}

TEST(Frolov_Gleb_ComplexNumberTest, Sum_Of_Numbers) {
  double re1 = 2.0;
  double im1 = 5.0;
  ComplexNumber cn1(re1, im1);
  double re2 = 5.0;
  double im2 = 3.0;
  ComplexNumber cn2(re2, im2);

  ComplexNumber sum = cn1 + cn2;

  EXPECT_EQ(7.0, sum.getRe());
  EXPECT_EQ(8.0, sum.getIm());
}

TEST(Frolov_Gleb_ComplexNumberTest, Sub_Of_Numbers) {
  double re1 = 2.0;
  double im1 = 5.0;
  ComplexNumber cn1(re1, im1);
  double re2 = 5.0;
  double im2 = 7.0;
  ComplexNumber cn2(re2, im2);

  ComplexNumber sub = cn2 - cn1;

  EXPECT_EQ(3.0, sub.getRe());
  EXPECT_EQ(2.0, sub.getIm());
}

TEST(Frolov_Gleb_ComplexNumberTest, Mult_Of_Numbers) {
  double re1 = 2.0;
  double im1 = 3.0;
  ComplexNumber cn1(re1, im1);
  double re2 = 3.0;
  double im2 = 2.0;
  ComplexNumber cn2(re2, im2);

  ComplexNumber mult = cn1 * cn2;

  EXPECT_EQ(0, mult.getRe());
  EXPECT_EQ(13, mult.getIm());
}

TEST(Frolov_Gleb_ComplexNumberTest, Mult_By_Zero) {
  double re1 = 2.0;
  double im1 = 3.0;
  ComplexNumber cn1(re1, im1);
  double re2 = 0;
  double im2 = 0;
  ComplexNumber cn2(re2, im2);

  ComplexNumber mult = cn1 * cn2;

  EXPECT_EQ(0, mult.getRe());
  EXPECT_EQ(0, mult.getIm());
}

TEST(Frolov_Gleb_ComplexNumberTest, Div_Of_Numbers) {
  double re1 = 1.0;
  double im1 = 2.0;
  ComplexNumber cn1(re1, im1);
  double re2 = 1.0;
  double im2 = 2.0;
  ComplexNumber cn2(re2, im2);

  ComplexNumber div = cn1 / cn2;

  EXPECT_EQ(1, div.getRe());
  EXPECT_EQ(0, div.getIm());
}

TEST(Frolov_Gleb_ComplexNumberTest, Div_By_Zero) {
  double re1 = 1.0;
  double im1 = 2.0;
  ComplexNumber cn1(re1, im1);
  double re2 = 0;
  double im2 = 0;
  ComplexNumber cn2(re2, im2);

  EXPECT_ANY_THROW(cn1 / cn2);
}
