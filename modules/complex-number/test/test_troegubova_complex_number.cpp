// Copyright 2022 Troegubova Alexandra

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Troegubova_Alexandra_ComplexNumberTest, Can_Create_Complex_Number) {
    double re = 12.5;
    double im = 20.6;

    ComplexNumber z(re, im);

    ASSERT_DOUBLE_EQ(re, z.getRe());
    ASSERT_DOUBLE_EQ(im, z.getIm());
}

TEST(Troegubova_Alexandra_ComplexNumberTest, Can_Add_Complex_Numbers) {
    double re1 = 12.5;
    double im1 = 20.6;
    double re2 = 1.25;
    double im2 = 3.15;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber sum;
    sum = z1 + z2;

    ASSERT_DOUBLE_EQ(re1 + re2, sum.getRe());
    ASSERT_DOUBLE_EQ(im1 + im2, sum.getIm());
}

TEST(Troegubova_Alexandra_ComplexNumberTest,
    Can_Find_The_Difference_Of_Complex_Numbers) {
    double re1 = 12.5;
    double im1 = 20.6;
    double re2 = 1.25;
    double im2 = 3.15;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber difference;
    difference = z1 - z2;

    ASSERT_DOUBLE_EQ(re1 - re2, difference.getRe());
    ASSERT_DOUBLE_EQ(im1 - im2, difference.getIm());
}

TEST(Troegubova_Alexandra_ComplexNumberTest, Can_Multiply_Complex_Numbers) {
    double re1 = 12.5;
    double im1 = 20.6;
    double re2 = 1.25;
    double im2 = 3.15;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber multiplication;
    multiplication = z1 * z2;

    ASSERT_DOUBLE_EQ(re1 * re2 - im1 * im2, multiplication.getRe());
    ASSERT_DOUBLE_EQ(re1 * im2 + im1 * re2, multiplication.getIm());
}

TEST(Troegubova_Alexandra_ComplexNumberTest,
    Correct_Comparison_Of_Equal_Numbers) {
    double re1 = 1.25;
    double im1 = 3.67;
    double re2 = 1.25;
    double im2 = 3.67;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ASSERT_TRUE(z1 == z2);
}


