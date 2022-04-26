// Copyright 2022 Dydykin Pavel

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Dydykin_Pavel_ComplexNumberTest, Can_Sum) {
    double re1 = 1.5;
    double im1 = 0.3;

    double re2 = 4.5;
    double im2 = 0.7;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 + z2;

    EXPECT_EQ(6, z3.getRe());
    EXPECT_EQ(1, z3.getIm());
}

TEST(Dydykin_Pavel_ComplexNumberTest, Can_Minus) {
    double re1 = 1.0;
    double im1 = 2.0;

    double re2 = 2.0;
    double im2 = 1.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 - z2;

    EXPECT_EQ(-1, z3.getRe());
    EXPECT_EQ(1, z3.getIm());
}

TEST(Dydykin_Pavel_ComplexNumberTest, Can_Multiply) {
    double re1 = 2.0;
    double im1 = 1.0;

    double re2 = 3.0;
    double im2 = 2.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 * z2;

    EXPECT_EQ(4, z3.getRe());
    EXPECT_EQ(7, z3.getIm());
}


TEST(Dydykin_Pavel_ComplexNumberTest, Can_Compare) {
    double re1 = 2.0;
    double im1 = 1.0;

    double re2 = 2.0;
    double im2 = 1.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    EXPECT_EQ(z1, z2);
}
