// Copyright 2022 Anastasiya Samoiluk

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Samoiluk_Anastasiya_ComplexNumberTest, Can_Create_Complex_Number) {
    double re = 2.0;
    double im = 0.1;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Samoiluk_Anastasiya_ComplexNumberTest, Can_Create_Copied_Number) {
    double re = 2.0;
    double im = 0.1;

    ComplexNumber z1(re, im);
    ComplexNumber z2(z1);

    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Samoiluk_Anastasiya_ComplexNumberTest, Can_Equate_Complex_Numbers) {
    double re = 2.0;
    double im = 0.1;

    ComplexNumber z1(re, im);
    ComplexNumber z2;
    z2 = z1;

    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Samoiluk_Anastasiya_ComplexNumberTest, Can_Change_Complex_Number) {
    double re1 = 2.0;
    double im1 = 0.1;

    ComplexNumber z1(re1, im1);

    double re2 = 5.0;
    double im2 = 0.8;

    z1.setRe(re2);
    z1.setIm(im2);

    EXPECT_EQ(re2, z1.getRe());
    EXPECT_EQ(im2, z1.getIm());
}

TEST(Samoiluk_Anastasiya_ComplexNumberTest, Can_Add_Complex_Numbers) {
    double re1 = 2.0;
    double im1 = 0.1;

    ComplexNumber z1(re1, im1);

    double re2 = 5.0;
    double im2 = 0.8;

    ComplexNumber z2(re2, im2);

    ComplexNumber sum = z1 + z2;

    EXPECT_EQ(7, sum.getRe());
    EXPECT_EQ(0.9, sum.getIm());
}

TEST(Samoiluk_Anastasiya_ComplexNumberTest, Can_Subtract_Complex_Numbers) {
    double re1 = 5.0;
    double im1 = 0.8;

    ComplexNumber z1(re1, im1);

    double re2 = 2.0;
    double im2 = 0.3;

    ComplexNumber z2(re2, im2);

    ComplexNumber sub = z1 - z2;

    EXPECT_EQ(3, sub.getRe());
    EXPECT_EQ(0.5, sub.getIm());
}

TEST(Samoiluk_Anastasiya_ComplexNumberTest, Can_Compare_Complex_Numbers_1) {
    double re1 = 2.0;
    double im1 = 0.1;

    ComplexNumber z1(re1, im1);

    double re2 = 5.0;
    double im2 = 0.8;

    ComplexNumber z2(re2, im2);

    EXPECT_TRUE(z1 != z2);
}

TEST(Samoiluk_Anastasiya_ComplexNumberTest, Can_Compare_Complex_Numbers_2) {
    double re1 = 2.0;
    double im1 = 0.1;

    ComplexNumber z1(re1, im1);

    double re2 = 2.0;
    double im2 = 0.1;

    ComplexNumber z2(re2, im2);

    EXPECT_TRUE(z1 == z2);
}
