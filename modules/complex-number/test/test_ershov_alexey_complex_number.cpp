// Copyright 2022 Ershov Alexey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(ershov_alexey_complex_number_test, complex_assignment) {
  ComplexNumber a;
  ComplexNumber b(10.2, 2.10);

  b = a;

  EXPECT_EQ(a.getRe(), 0.0);
  EXPECT_EQ(a.getIm(), 0.0);
  EXPECT_EQ(a.getRe(), b.getRe());
  EXPECT_EQ(a.getIm(), b.getIm());
}

TEST(ershov_alexey_complex_number_test, complex_set_single_assignment) {
  ComplexNumber a(10.0, 20.0);

  a.setRe(20.0);
  a.setIm(30.0);

  EXPECT_EQ(a.getRe(), 20.0);
  EXPECT_EQ(a.getIm(), 30.0);
}

TEST(ershov_alexey_complex_number_test, complex_set_pair_not_assignment) {
  ComplexNumber a;
  ComplexNumber b;

  a.setRe(10.0);
  a.setIm(20.0);
  b.setRe(-10.0);
  b.setIm(-20.0);

  EXPECT_NE(a.getRe(), b.getRe());
  EXPECT_NE(a.getIm(), b.getIm());
}

TEST(ershov_alexey_complex_number_test, complex_no_exception_multiply) {
  double a_re = 10.0, a_im = 10.0;
  double b_re = 20.0, b_im = 20.0;

  ComplexNumber a(a_re, a_im);
  ComplexNumber b(b_re, b_im);

  EXPECT_NO_THROW(a * b);
}
