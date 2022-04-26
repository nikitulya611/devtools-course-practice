// Copyright 2022 Borisov Maxim

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Borisov_Maxim_ComplexNumberTest, CanCreate) {
  double re = 2.2;
  double im = 4.5;
  ComplexNumber cn(re, im);
  EXPECT_EQ(re, cn.getRe());
  EXPECT_EQ(im, cn.getIm());
}

TEST(Borisov_Maxim_ComplexNumberTest, CanSetRe) {
  double re = 4.5;
  ComplexNumber cn(0.0, 0.0);
  cn.setRe(re);
  EXPECT_EQ(re, cn.getRe());
}

TEST(Borisov_Maxim_CompleNumberTest, CanSetIm) {
  double im = 4.5;
  ComplexNumber cn(0.0, 0.0);
  cn.setIm(im);
  EXPECT_EQ(im, cn.getIm());
}

TEST(Borisov_Maxim_ComplexNumberTest, CanOpPlus) {
  double re1 = 2.0;
  double im1 = 3.0;
  double re2 = 4.0;
  double im2 = 1.0;
  ComplexNumber cn1(re1, im1);
  ComplexNumber cn2(re2, im2);
  ComplexNumber cn_res = cn1 + cn2;

  EXPECT_DOUBLE_EQ(6.0, cn_res.getRe());
  EXPECT_DOUBLE_EQ(4.0, cn_res.getIm());
}
