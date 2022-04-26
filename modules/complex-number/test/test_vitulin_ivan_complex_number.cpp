// Copyright 2022 Vitulin Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vitulin_Ivan_ComplexNumberTest, Creating_Zero_Complex_Number) {
    double re_part = 0.0;
    double im_part = 0.0;

    ComplexNumber z(re_part, im_part);

    EXPECT_EQ(re_part, z.getRe());
    EXPECT_EQ(im_part, z.getIm());
}

TEST(Vitulin_Ivan_ComplexNumberTest, Calculating_Sum_Of_Complex_Numbers) {
    double re_part1 = 5.3;
    double im_part1 = 0.8;
    double re_part2 = 4.7;
    double im_part2 = 3.2;

    ComplexNumber z1(re_part1, im_part1);
    ComplexNumber z2(re_part2, im_part2);
    ComplexNumber z3 = z1 + z2;

    EXPECT_EQ(10, z3.getRe());
    EXPECT_EQ(4, z3.getIm());
}

TEST(Vitulin_Ivan_ComplexNumberTest, Calculating_Subtr_Of_Complex_Numbers) {
    double re_part1 = 7.0;
    double im_part1 = 1.6;
    double re_part2 = 5.2;
    double im_part2 = 0.1;

    ComplexNumber z1(re_part1, im_part1);
    ComplexNumber z2(re_part2, im_part2);
    ComplexNumber z3 = z1 - z2;

    EXPECT_DOUBLE_EQ(1.8, z3.getRe());
    EXPECT_DOUBLE_EQ(1.5, z3.getIm());
}

TEST(Vitulin_Ivan_ComplexNumberTest, Calculating_Multiply_Of_Complex_Numbers) {
    double re_part1 = 5.4;
    double im_part1 = 2.6;
    double re_part2 = 8.5;
    double im_part2 = 1.1;

    ComplexNumber z1(re_part1, im_part1);
    ComplexNumber z2(re_part2, im_part2);
    ComplexNumber z3 = z1 * z2;

    EXPECT_DOUBLE_EQ(43.04, z3.getRe());
    EXPECT_DOUBLE_EQ(28.04, z3.getIm());
}

TEST(Vitulin_Ivan_ComplexNumberTest, Calculating_Division_Of_Complex_Numbers) {
    double re_part1 = 1.0;
    double im_part1 = 2.0;
    double re_part2 = 3.0;
    double im_part2 = 4.0;

    ComplexNumber z1(re_part1, im_part1);
    ComplexNumber z2(re_part2, im_part2);
    ComplexNumber z3 = z1 / z2;

    EXPECT_DOUBLE_EQ(0.44, z3.getRe());
    EXPECT_DOUBLE_EQ(0.08, z3.getIm());
}

TEST(Vitulin_Ivan_ComplexNumberTest, Comparing_Equal_Complex_Numbers_1) {
    double re_part1 = 2.4;
    double im_part1 = 0.7;
    double re_part2 = 2.4;
    double im_part2 = 0.7;

    ComplexNumber z1(re_part1, im_part1);
    ComplexNumber z2(re_part2, im_part2);

    EXPECT_EQ(z1 == z2, 1);
}

TEST(Vitulin_Ivan_ComplexNumberTest, Comparing_Equal_Complex_Numbers_2) {
    double re_part1 = 2.4;
    double im_part1 = 0.7;
    double re_part2 = 2.4;
    double im_part2 = 0.7;

    ComplexNumber z1(re_part1, im_part1);
    ComplexNumber z2(re_part2, im_part2);

    EXPECT_EQ(z1 != z2, 0);
}

TEST(Vitulin_Ivan_ComplexNumberTest, Comparing_Non_Equal_Complex_Numbers_1) {
    double re_part1 = 2.4;
    double im_part1 = 0.7;
    double re_part2 = 3.4;
    double im_part2 = 0.8;

    ComplexNumber z1(re_part1, im_part1);
    ComplexNumber z2(re_part2, im_part2);

    EXPECT_EQ(z1 != z2, 1);
}

TEST(Vitulin_Ivan_ComplexNumberTest, Comparing_Non_Equal_Complex_Numbers_2) {
    double re_part1 = 2.4;
    double im_part1 = 0.7;
    double re_part2 = 3.4;
    double im_part2 = 0.8;

    ComplexNumber z1(re_part1, im_part1);
    ComplexNumber z2(re_part2, im_part2);

    EXPECT_EQ(z1 == z2, 0);
}

TEST(Vitulin_Ivan_ComplexNumberTest, Right_Reaction_Of_Division_On_Zero) {
    double re_part1 = 3.7;
    double im_part1 = 0.5;
    double re_part2 = 0.0;
    double im_part2 = 0.0;

    ComplexNumber z1(re_part1, im_part1);
    ComplexNumber z2(re_part2, im_part2);

    ASSERT_ANY_THROW(z1 / z2);
}

TEST(Vitulin_Ivan_ComplexNumberTest, Copying_Complex_Number) {
    double re_part1 = 3.5;
    double im_part1 = 1.4;

    ComplexNumber z1(re_part1, im_part1);
    ComplexNumber z2 = z1;

    EXPECT_DOUBLE_EQ(3.5, z2.getRe());
    EXPECT_DOUBLE_EQ(1.4, z2.getIm());
}
