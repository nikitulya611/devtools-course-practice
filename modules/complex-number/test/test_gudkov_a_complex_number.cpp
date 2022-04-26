// Copyright 2022 Gudkov Andrey

#include <gtest/gtest.h>
#include "../include/complex_number.h"

TEST(Gudkov_Andrey_comp_number_test, firt_test) {
    ComplexNumber c1(23, 4);
    ComplexNumber c2(1, 7);
    ComplexNumber res(24.0, 11.0);
    ComplexNumber res2 = c1 + c2;

    EXPECT_EQ(res.getRe(), res2.getRe());
    EXPECT_EQ(res.getIm(), res2.getIm());
}


TEST(Gudkov_Andrey_comp_number_test, second_test) {
    ComplexNumber a;
    ComplexNumber b(110.23, 25.15);
    b = a;
    EXPECT_EQ(a.getRe(), 0.0);
    EXPECT_EQ(a.getIm(), 0.0);
    EXPECT_EQ(a.getRe(), b.getRe());
    EXPECT_EQ(a.getIm(), b.getIm());
}


TEST(Gudkov_Andrey_comp_number_test, third_test) {
    ComplexNumber z(27.0, 8.0);
    double re = 27.0;
    double im = 8.0;

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
