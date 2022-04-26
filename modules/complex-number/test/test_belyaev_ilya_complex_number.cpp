// Copyright 2022 Ilya Belyaev
#include <gtest/gtest.h>
#include <cmath>
#include "include/complex_number.h"

TEST(BELYAEV_ILYA_ComplexNumberTest, Start) {
  ComplexNumber a(3, 2);
  ASSERT_EQ(3, a.getRe());
  ASSERT_EQ(2, a.getIm());
}

TEST(BELYAEV_ILYA_ComplexNumberTest, Plus) {
  ComplexNumber a(3, 3);
  ComplexNumber b(2, 2);
  ComplexNumber c = a + b;
  ASSERT_EQ(5.0, c.getRe());
  ASSERT_EQ(5.0, c.getIm());
}

TEST(BELYAEV_ILYA_ComplexNumberTest, Minus) {
  ComplexNumber a(3, 3);
  ComplexNumber b(2, 2);
  ComplexNumber c = a - b;
  ASSERT_EQ(1.0, c.getRe());
  ASSERT_EQ(1.0, c.getIm());
}

TEST(BELYAEV_ILYA_ComplexNumberTest, Not) {
  ComplexNumber a(3, 2);
  ComplexNumber b(4, 3);
  ASSERT_NE(b.getRe(), a.getRe());
  ASSERT_NE(a.getIm(), b.getIm());
}
