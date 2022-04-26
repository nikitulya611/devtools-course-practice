// Copyright 2022 Groshev Nikolay

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Groshev_Nikolay_ComplexNumberTest, TEST_DEFAULT_CONSTRUCTOR) {
  ComplexNumber z;

  EXPECT_EQ(z.getRe(), 0);
  EXPECT_EQ(z.getIm(), 0);
}

TEST(Groshev_Nikolay_ComplexNumberTest, TEST_INIT_CONSTRUCTOR) {
  double re = 1.0;
  double im = 2.0;
  ComplexNumber z(re, im);

  EXPECT_EQ(z.getRe(), 1.0);
  EXPECT_EQ(z.getIm(), 2.0);
}

TEST(Groshev_Nikolay_ComplexNumberTest, TEST_COPY_CONSTRUCTOR) {
  double re = 1.0;
  double im = 2.0;
  ComplexNumber z(re, im);
  ComplexNumber n = z;

  EXPECT_EQ(n.getRe(), 1.0);
  EXPECT_EQ(n.getIm(), 2.0);
}

TEST(Groshev_Nikolay_ComplexNumberTest, TEST_CAN_SUM) {
  double re1 = 1.0;
  double im1 = 2.0;
  double re2 = 1.0;
  double im2 = 2.0;
  ComplexNumber first(re1, im1);
  ComplexNumber second(re2, im2);

  ComplexNumber sum = first + second;

  EXPECT_EQ(2.0, sum.getRe());
  EXPECT_EQ(4.0, sum.getIm());
}

TEST(Groshev_Nikolay_ComplexNumberTest, TEST_CAN_MULTIPLE) {
  double re1 = 1.0;
  double im1 = 2.0;
  double re2 = 1.0;
  double im2 = 2.0;
  ComplexNumber first(re1, im1);
  ComplexNumber second(re2, im2);

  ComplexNumber sum = first * second;

  EXPECT_EQ(-3.0, sum.getRe());
  EXPECT_EQ(4.0, sum.getIm());
}

TEST(Groshev_Nikolay_ComplexNumberTest, TEST_CAN_DIV) {
  double re1 = 1.0;
  double im1 = 2.0;
  double re2 = 1.0;
  double im2 = 2.0;
  ComplexNumber first(re1, im1);
  ComplexNumber second(re2, im2);

  ComplexNumber sum = first / second;

  EXPECT_EQ(1, sum.getRe());
  EXPECT_EQ(0, sum.getIm());
}

TEST(Groshev_Nikolay_ComplexNumberTest, TEST_CAN_DIV_BY_NULL_WITH_EXCEPTION) {
  double re1 = 1.0;
  double im1 = 2.0;
  double re2 = 0.0;
  double im2 = 0.0;
  ComplexNumber first(re1, im1);
  ComplexNumber second(re2, im2);


  ASSERT_ANY_THROW(first / second);
}

TEST(Groshev_Nikolay_ComplexNumberTest, TEST_EQUALS_POSITIVE) {
  bool eq = 0;
  double re1 = 1.0;
  double im1 = 2.0;
  double re2 = 1.0;
  double im2 = 2.0;
  ComplexNumber first(re1, im1);
  ComplexNumber second(re2, im2);

  eq = first == second;

  EXPECT_EQ(1, eq);
}

TEST(Groshev_Nikolay_ComplexNumberTest, TEST_EQUALS_NEGATIVE) {
  bool eq = 0;
  double re1 = 1.0;
  double im1 = 2.0;
  double re2 = 0.0;
  double im2 = 0.0;
  ComplexNumber first(re1, im1);
  ComplexNumber second(re2, im2);

  eq = first == second;

  EXPECT_EQ(0, eq);
}

TEST(Groshev_Nikolay_ComplexNumberTest, TEST_UNQUALS_POSITIVE) {
  double re1 = 1.0;
  double im1 = 2.0;
  double re2 = 0.0;
  double im2 = 0.0;
  ComplexNumber first(re1, im1);
  ComplexNumber second(re2, im2);

  bool eq = first != second;

  EXPECT_EQ(1, eq);
}

TEST(Groshev_Nikolay_ComplexNumberTest, TEST_UNQUALS_NEGATIVE) {
  double re1 = 1.0;
  double im1 = 2.0;
  double re2 = 1.0;
  double im2 = 2.0;
  ComplexNumber first(re1, im1);
  ComplexNumber second(re2, im2);

  bool eq = first != second;

  EXPECT_EQ(0, eq);
}
