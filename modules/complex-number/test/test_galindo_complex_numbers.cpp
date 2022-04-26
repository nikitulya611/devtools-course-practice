// Copyright 2022 Javier Galindo

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Galindo_Javier_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Galindo_Javier_ComplexNumberTest, Can_Get_CompNumb) {
    double re = 10.0;
    double im = 0.5;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Galindo_Javier_ComplexNumberTest, Can_Add) {
    double a_re = 5.0;
    double a_im = 10.0;

    double b_re = 15.0;
    double b_im = 23.0;


    ComplexNumber a(a_re, a_im);
    ComplexNumber b(b_re, b_im);
    ComplexNumber c = a + b;

    EXPECT_EQ(a_re + b_re, c.getRe());
    EXPECT_EQ(a_im + b_im, c.getIm());
}

TEST(Galindo_Javier_ComplexNumberTest, Can_Subtract) {
    double a_re = 6.0;
    double a_im = 19.0;

    double b_re = 12.0;
    double b_im = 11.0;

    ComplexNumber a(a_re, a_im);
    ComplexNumber b(b_re, b_im);
    ComplexNumber c = a - b;

    EXPECT_EQ(a_re - b_re, c.getRe());
    EXPECT_EQ(a_im - b_im, c.getIm());
}
