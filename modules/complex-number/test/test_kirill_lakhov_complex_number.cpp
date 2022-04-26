// Copyright 2022 Lakhov Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Lakhov_Kirill_ComplexNumberTest, Can_Sum) {
    double re1 = 5.0;
    double im1 = 3.0;
    ComplexNumber z1(re1, im1);

    double re2 = 2.5;
    double im2 = 1.5;
    ComplexNumber z2(re2, im2);

    ComplexNumber result = z1 + z2;

    EXPECT_EQ(7.5, result.getRe());
    EXPECT_EQ(4.5, result.getIm());
}

TEST(Lakhov_Kirill_ComplexNumberTest, Can_Subtract) {
    double re1 = 5.0;
    double im1 = 3.0;
    ComplexNumber z1(re1, im1);

    double re2 = 2.5;
    double im2 = 1.5;
    ComplexNumber z2(re2, im2);

    ComplexNumber result = z1 - z2;

    EXPECT_EQ(2.5, result.getRe());
    EXPECT_EQ(1.5, result.getIm());
}

TEST(Lakhov_Kirill_ComplexNumberTest, Can_Multiply) {
    double re1 = 5.0;
    double im1 = 3.0;
    ComplexNumber z1(re1, im1);

    double re2 = 2.5;
    double im2 = 1.5;
    ComplexNumber z2(re2, im2);

    ComplexNumber result = z1 * z2;

    EXPECT_EQ(8, result.getRe());
    EXPECT_EQ(15, result.getIm());
}

TEST(Lakhov_Kirill_ComplexNumberTest, Can_Divide) {
    double re1 = 5.0;
    double im1 = 3.0;
    ComplexNumber z1(re1, im1);

    double re2 = 2.5;
    double im2 = 1.5;
    ComplexNumber z2(re2, im2);

    ComplexNumber result = z1 / z2;

    EXPECT_EQ(2, result.getRe());
    EXPECT_EQ(0, result.getIm());
}

TEST(Lakhov_Kirill_ComplexNumberTest, Can_Compare_1) {
    double re1 = 5.0;
    double im1 = 3.0;
    ComplexNumber z1(re1, im1);

    double re2 = 2.5;
    double im2 = 1.5;
    ComplexNumber z2(re2, im2);

    EXPECT_FALSE(z1 == z2);
}

TEST(Lakhov_Kirill_ComplexNumberTest, Can_Compare_2) {
    double re1 = 5.0;
    double im1 = 3.0;
    ComplexNumber z1(re1, im1);

    double re2 = 5.0;
    double im2 = 3.0;
    ComplexNumber z2(re2, im2);

    EXPECT_TRUE(z1 == z2);
}


TEST(Lakhov_Kirill_ComplexNumberTest, Can_Copy) {
    double re = 5.0;
    double im = 3.0;

    ComplexNumber z1(re, im);
    ComplexNumber z2(z1);

    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}
