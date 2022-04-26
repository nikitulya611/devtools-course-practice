// Copyright 2022 Kamenev Ilya

#include <gtest/gtest.h>

#include "../include/complex_number.h"

TEST(OpeartionSuite, SumTest) {
  ComplexNumber cn1(8, 4);
  ComplexNumber cn2(6, 3);

  ComplexNumber cn3 = cn1 + cn2;

  ASSERT_EQ(cn3.getRe(), 14);
  ASSERT_EQ(cn3.getIm(), 7);
}

TEST(OpeartionSuite, SubtractTest) {
  ComplexNumber cn1(8, 4);
  ComplexNumber cn2(6, 3);

  ComplexNumber cn3 = cn1 - cn2;

  ASSERT_EQ(cn3.getRe(), 2);
  ASSERT_EQ(cn3.getIm(), 1);
}

TEST(OpeartionSuite, MultiplyTest) {
  ComplexNumber cn1(8, 4);
  ComplexNumber cn2(6, 3);

  ComplexNumber cn3 = cn1 * cn2;

  ASSERT_EQ(cn3.getRe(), 36);
  ASSERT_EQ(cn3.getIm(), 48);
}
