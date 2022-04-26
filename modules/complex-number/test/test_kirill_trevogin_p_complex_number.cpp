// Copyright 2022 Trevogin Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kirill_Trevogi_ComplexNumberTest, Can_Sum) {
    double re1 = 55.0;
    double im1 = 0.5;

    double re2 = 45.0;
    double im2 = 0.6;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 + z2;

    EXPECT_EQ(100, z3.getRe());
    EXPECT_EQ(1.1, z3.getIm());
}


TEST(Kirill_Trevogi_ComplexNumberTest, Can_Get_Const) {
    double re = 5.0;
    double im = 0.4;
    ComplexNumber z(re, im);
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}


TEST(Kirill_Trevogi_ComplexNumberTest, Shto) {
    double reFirst = 1.0;
    double imFirst = 0.5;

    double reSecond = 0.0;
    double imSecond = 0.0;

    ComplexNumber numFirst(reFirst, imFirst);
    ComplexNumber numSecond(reSecond, imSecond);

    ASSERT_ANY_THROW(numFirst / numSecond);
}
