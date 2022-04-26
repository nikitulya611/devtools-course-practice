// Copyright 2022 Gordeev Viktor

#include <gtest/gtest.h>
#include "../include/complex_number.h"

TEST(GordeevComplexNumberTest, Throw_On_Zero) {
    double re1 = 5.0;
    double im1 = 0.5;
    double re2 = 0.0;
    double im2 = 0.0;
    ComplexNumber val1(re1, im1);
    ComplexNumber val2(re2, im2);

    ASSERT_ANY_THROW(val1 / val2);
}

TEST(GordeevComplexNumberTest, Can_Sum_Vals) {
    double re1 = 5.0;
    double im1 = 0.5;
    double re2 = 3.0;
    double im2 = 0.5;
    ComplexNumber val1(re1, im1);
    ComplexNumber val2(re2, im2);
    ComplexNumber res = val1 + val2;

    EXPECT_EQ(8, res.getRe());
    EXPECT_EQ(1, res.getIm());
}

TEST(GordeevComplexNumberTest, Assignment_Of_Number) {
    double re1 = 5.0;
    double im1 = 0.5;
    double re2 = 0.0;
    double im2 = 0.0;
    ComplexNumber val1(re1, im1);
    ComplexNumber val2(re2, im2);
    val2 = val1;

    EXPECT_EQ(val1, val2);
}

TEST(GordeevComplexNumberTest, Can_Get_Parts_Of_Value) {
    double re = 5.0;
    double im = 0.5;
    ComplexNumber val(re, im);
    EXPECT_EQ(re, val.getRe());
    EXPECT_EQ(im, val.getIm());
}

TEST(GordeevComplexNumberTest, Can_Compare_Complex_Number) {
    double re1 = 5.0;
    double im1 = 0.5;
    double re2 = 5.0;
    double im2 = 0.5;
    ComplexNumber val1(re1, im1);
    ComplexNumber val2(re2, im2);

    EXPECT_EQ(val1, val2);
}
