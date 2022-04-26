// Copyright 2022 Shatalin_Dmitrii

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(My_Test_SH_D_ComplexNumberTest, Can_Create_Zero_Complex_Number) {
    double a = 0.0;
    double b = 0.0;
    ComplexNumber h(a, b);
    EXPECT_EQ(a, h.getRe());
    EXPECT_EQ(b, h.getIm());
}

TEST(My_Test_SH_D_ComplexNumberTest, Can_Subtraction_Complex_Number) {
    ComplexNumber a(7, 6);
    ComplexNumber b(2, 4);
    ComplexNumber h = a - b;
    EXPECT_EQ(5, h.getRe());
    EXPECT_EQ(2, h.getIm());
}

TEST(My_Test_SH_D_ComplexNumberTest, Can_Addition_Complex_Number) {
    ComplexNumber a(8, 4);
    ComplexNumber b(1, 3);
    ComplexNumber h = a + b;
    EXPECT_EQ(9, h.getRe());
    EXPECT_EQ(7, h.getIm());
}

TEST(My_Test_SH_D_ComplexNumberTest, Can_Multiply_Complex_Number) {
    double a1 = 3.0;
    double b1 = 2.0;
    double a2 = 5.0;
    double b2 = 4.0;
    ComplexNumber h1(a1, b1);
    ComplexNumber h2(a2, b2);
    ComplexNumber h3 = h1 * h2;
    EXPECT_EQ(7, h3.getRe());
    EXPECT_EQ(22, h3.getIm());
}
