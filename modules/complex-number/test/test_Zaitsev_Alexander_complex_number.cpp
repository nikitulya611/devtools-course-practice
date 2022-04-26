// Copyright 2022 Zaitsev Alexander

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Zaitsev_Alexander_ComplexNumberTest, Can_Create_Zero) {
  double re = 0.0;
  double im = 0.0;
  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Zaitsev_Alexander_ComplexNumberTest, Can_Imaginary_Nubmer) {
  double re = 0.0;
  double im = 7.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Zaitsev_Alexander_ComplexNumberTest, Can_Create_Real_Nubmer) {
  double re = 14.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}
