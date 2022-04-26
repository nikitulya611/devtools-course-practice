// Copyright 2022 Shurygina A

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(ComplexNumberTest, Can_Get_Parts) {
    double re = 2.0;
    double im = 0.5;
    ComplexNumber z(re, im);
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(ComplexNumberTest, Can_Sum) {
    double reFirst = 1.0;
    double imFirst = 0.5;

    double reSecond = 2.0;
    double imSecond = 0.4;

    ComplexNumber numFirst(reFirst, imFirst);
    ComplexNumber numSecond(reSecond, imSecond);
    ComplexNumber result = numFirst + numSecond;

    EXPECT_EQ(3, result.getRe());
    EXPECT_EQ(0.9, result.getIm());
}

TEST(ComplexNumberTest, Assert_Throw_If_Devision_On_Zero) {
    double reFirst = 1.0;
    double imFirst = 0.5;

    double reSecond = 0.0;
    double imSecond = 0.0;

    ComplexNumber numFirst(reFirst, imFirst);
    ComplexNumber numSecond(reSecond, imSecond);

    ASSERT_ANY_THROW(numFirst / numSecond);
}

TEST(ComplexNumberTest, Can_Compare_Complex_Number) {
    double reFirst = 1.0;
    double imFirst = 0.5;

    double reSecond = 1.0;
    double imSecond = 0.5;

    ComplexNumber numFirst(reFirst, imFirst);
    ComplexNumber numSecond(reSecond, imSecond);

    EXPECT_EQ(numFirst, numSecond);
}

TEST(ComplexNumberTest, Can_Assign_Complex_Number) {
    double reFirst = 1.0;
    double imFirst = 0.5;

    double reSecond = 3.0;
    double imSecond = 0.0;

    ComplexNumber numFirst(reFirst, imFirst);
    ComplexNumber numSecond(reSecond, imSecond);
    numSecond = numFirst;

    EXPECT_EQ(numFirst, numSecond);
}



