// Copyright 2022 Krivosheev Miron

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Krivosheev_Miron_ComplexNumberTest, DefaultConstructor) {
  double re = 0.0;
  double im = 0.0;

  ComplexNumber z;

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Krivosheev_Miron_ComplexNumberTest, AssignConstructor) {
  double re = 2.0;
  double im = 5.0;

  ComplexNumber z(2.0, 5.0);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Krivosheev_Miron_ComplexNumberTest, CopyConstructor) {
  ComplexNumber z1(-1.0, -2.0);
  ComplexNumber z2(z1);

  EXPECT_EQ(z1.getRe(), z2.getRe());
  EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Krivosheev_Miron_ComplexNumberTest, AssignOprator) {
  ComplexNumber z1(1.0, 6.0);
  ComplexNumber z2;

  z2 = z1;

  EXPECT_EQ(z1.getRe(), z2.getRe());
  EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Krivosheev_Miron_ComplexNumberTest, AdditionNumbers) {
  double re = 4.2;
  double im = 8.4;
  ComplexNumber z1(1.0, 6.0);
  ComplexNumber z2(3.2, 2.4);
  ComplexNumber z3;

  z3 = z1 + z2;

  EXPECT_EQ(re, z3.getRe());
  EXPECT_EQ(im, z3.getIm());
}


TEST(Krivosheev_Miron_ComplexNumberTest, SubtractionNumbers) {
  double re = -3.0;
  double im = 10.0;
  ComplexNumber z1(-1.0, 6.0);
  ComplexNumber z2(2, -4);
  ComplexNumber z3;

  z3 = z1 - z2;

  EXPECT_EQ(re, z3.getRe());
  EXPECT_EQ(im, z3.getIm());
}

TEST(Krivosheev_Miron_ComplexNumberTest, MultiplyNumbers) {
  double re = -5.0;
  double im = -31.0;
  ComplexNumber z1(-5.0, -2.0);
  ComplexNumber z2(3.0, 5.0);
  ComplexNumber z3;

  z3 = z1 * z2;

  EXPECT_EQ(re, z3.getRe());
  EXPECT_EQ(im, z3.getIm());
}

TEST(Krivosheev_Miron_ComplexNumberTest, DivisionNumbers) {
  double re = -2.2758620;
  double im = -0.6896551;
  double eps = 0.0000001;
  ComplexNumber z1(-8.0, 10.0);
  ComplexNumber z2(2.0, -5.0);
  ComplexNumber z3;

  z3 = z1 / z2;

  ASSERT_NEAR(re, z3.getRe(), eps);
  ASSERT_NEAR(im, z3.getIm(), eps);
}

TEST(Krivosheev_Miron_ComplexNumberTest, EqualityOperatorPossitive) {
  ComplexNumber z1(2.0, 5.0);
  ComplexNumber z2(2.0, 5.0);

  ASSERT_TRUE(z1 == z2);
}

TEST(Krivosheev_Miron_ComplexNumberTest, EqualityOperatorNegetive) {
  ComplexNumber z1(2.0, 5.0);
  ComplexNumber z2(-2.0, 5.0);

  ASSERT_FALSE(z1 == z2);
}

TEST(Krivosheev_Miron_ComplexNumberTest, NotEqualityOperatorPossitive) {
  ComplexNumber z1(10.0, 5.0);
  ComplexNumber z2(10.0, -5.0);

  ASSERT_TRUE(z1 != z2);
}

TEST(Krivosheev_Miron_ComplexNumberTest, NotEqualityOperatorNegetive) {
  ComplexNumber z1(0.0, 3.0);
  ComplexNumber z2(0.0, 3.0);

  ASSERT_FALSE(z1 != z2);
}
