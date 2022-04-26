// Copyright 2022 Ermakov Pavel

#include <gtest/gtest.h>
#include "../include/complex_number.h"

TEST(Ermakov_Pavel_comp_test, test1) {
    double re = 5.0;
    double im = 6.0;
    ComplexNumber z(re, im);
    ComplexNumber z_copy(z);
    ASSERT_DOUBLE_EQ(z_copy.getRe(), z.getRe());
    ASSERT_DOUBLE_EQ(z_copy.getIm(), z.getIm());
}


TEST(Ermakov_Pavel_comp_test, test2) {
    ComplexNumber a;
    ComplexNumber b(10.2, 2.10);
    b = a;
    EXPECT_EQ(a.getRe(), 0.0);
    EXPECT_EQ(a.getIm(), 0.0);
    EXPECT_EQ(a.getRe(), b.getRe());
    EXPECT_EQ(a.getIm(), b.getIm());
}


TEST(Ermakov_Pavel_comp_test, test3) {
    ComplexNumber result;
    double re1 = 5.0;
    double im1 = 3.0;
    ComplexNumber z1(re1, im1);
    double re2 = 2.5;
    double im2 = 1.5;
    ComplexNumber z2(re2, im2);
    result = z1 + z2;
    EXPECT_EQ(7.5, result.getRe());
    EXPECT_EQ(4.5, result.getIm());
}

