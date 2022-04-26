// Copyright 2022 Pichugin Ilya

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(TESTING_COMPLEX, Can_Create_Zero) {
  double re = 0.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(TESTING_COMPLEX, Can_Create_Umnozenie) {
  ComplexNumber c1(1.0, 1.0);
  ComplexNumber c2(2.0, 3.0);
  ComplexNumber s1 = c2 * c1;
  ComplexNumber result = c1 * c2;

  EXPECT_EQ(s1 == result, 1);
}

TEST(TESTING_COMPLEX, Can_Create_Plus) {
  ComplexNumber c1(2.0, 1.0);
  ComplexNumber c2(2.0, 3.0);
  ComplexNumber s1(4, 4);
  ComplexNumber result = c1 + c2;

  EXPECT_EQ(s1 == result, 1);
}

TEST(TESTING_COMPLEX, Can_Create_Minus) {
  ComplexNumber c1(2.0, 1.0);
  ComplexNumber c2(2.0, 3.0);
  ComplexNumber s1(0, -2);
  ComplexNumber result = c1 - c2;

  EXPECT_EQ(s1 == result, 1);
}
