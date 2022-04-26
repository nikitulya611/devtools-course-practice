// Copyright 2022 Kruglov Aleksei

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kruglov_Aleksei_ComplexNumberTest, Create) {
    double real = 2.0;
    double imag = 1.0;
    ComplexNumber c(real, imag);

    EXPECT_DOUBLE_EQ(real, c.getRe());
    EXPECT_DOUBLE_EQ(imag, c.getIm());
}

TEST(Kruglov_Aleksei_ComplexNumberTest, Compare) {
    double real1 = 3.0;
    double imag1 = 1.0;
    ComplexNumber c1(real1, imag1);

    double real2 = 3.0;
    double imag2 = 1.0;
    ComplexNumber c2(real2, imag2);

    EXPECT_EQ(c1, c2);
}

TEST(Kruglov_Aleksei_ComplexNumberTest, Sum) {
    double real1 = 3.0;
    double imag1 = 1.0;
    ComplexNumber c1(real1, imag1);

    double real2 = 2.0;
    double imag2 = 1.0;
    ComplexNumber c2(real2, imag2);

    ComplexNumber result = c1 + c2;

    EXPECT_DOUBLE_EQ(5.0, result.getRe());
    EXPECT_DOUBLE_EQ(2.0, result.getIm());
}

TEST(Kruglov_Aleksei_ComplexNumberTest, Multiply) {
    double real1 = 2.0;
    double imag1 = 2.0;
    ComplexNumber c1(real1, imag1);

    double real2 = 3.0;
    double imag2 = 1.5;
    ComplexNumber c2(real2, imag2);

    ComplexNumber result = c1 * c2;

    EXPECT_DOUBLE_EQ(3.0, result.getRe());
    EXPECT_DOUBLE_EQ(9.0, result.getIm());
}

TEST(Kruglov_Aleksei_ComplexNumberTest, Divide) {
    double real1 = 2.0;
    double imag1 = 1.0;
    ComplexNumber c1(real1, imag1);

    double real2 = 2.0;
    double imag2 = 1.0;
    ComplexNumber c2(real2, imag2);

    ComplexNumber result = c1 / c2;

    EXPECT_DOUBLE_EQ(1, result.getRe());
    EXPECT_DOUBLE_EQ(0, result.getIm());
}

TEST(Kruglov_Aleksei_ComplexNumberTest, Subtract) {
    double real1 = 2.0;
    double imag1 = 2.0;
    ComplexNumber c1(real1, imag1);

    double real2 = 3.0;
    double imag2 = 1.5;
    ComplexNumber c2(real2, imag2);

    ComplexNumber result = c1 - c2;

    EXPECT_DOUBLE_EQ(-1.0, result.getRe());
    EXPECT_DOUBLE_EQ(0.5, result.getIm());
}
