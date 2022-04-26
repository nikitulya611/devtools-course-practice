// Copyright 2022 Zaitseva Ksenia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Zaitseva_Ksenia_ComplexNumberTest, Can_Subtract) {
    // Arrange
    double re1 = 1.5;
    double im1 = 0.4;
    double re2 = 9.3;
    double im2 = 0.3;

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);
    double re = re1 - re2;
    double im = im1 - im2;
    ComplexNumber z = a - b;

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Zaitseva_Ksenia_ComplexNumberTest, Equality) {
    // Arrange
    ComplexNumber a(1.5, 5.4);
    ComplexNumber b(9.0, 0.1);

    // Act
    b = a;

    // Assert
    EXPECT_EQ(b.getRe(), a.getRe());
    EXPECT_EQ(b.getIm(), a.getIm());
    EXPECT_EQ(a.getRe(), 1.5);
    EXPECT_EQ(a.getIm(), 5.4);
}

TEST(Zaitseva_Ksenia_ComplexNumberTest, Double_Equality) {
    // Arrange
    ComplexNumber a(1.5, 5.4);
    ComplexNumber b(9.0, 0.1);
    ComplexNumber c(0.0, 0.5);

    // Act
    c = b = a;

    // Assert
    EXPECT_EQ(c.getRe(), a.getRe());
    EXPECT_EQ(c.getIm(), a.getIm());
}


TEST(Zaitseva_Ksenia_ComplexNumberTest, Divide_by_zero) {
    // Arrange
    double re1 = 1.5;
    double im1 = 0.4;
    double re2 = 0.0;
    double im2 = 0.0;

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);

    // Assert
    ASSERT_ANY_THROW(a / b);
}
