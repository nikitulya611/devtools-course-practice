// Copyright 2022 Labinskaya Marina
#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Labinskaya_Marina_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Labinskaya_Marina_ComplexNumberTest, Can_Create_Not_A_Zero) {
    // Arrange
    double re = -2.0;
    double im = 3.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Labinskaya_Marina_ComplexNumberTest, Can_Add_Two_Numbers) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;
    double re2 = -1.0;
    double im2 = 4.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ComplexNumber z3 = z1 + z2;

    // Assert
    EXPECT_DOUBLE_EQ(re1 + re2, z3.getRe());
    EXPECT_DOUBLE_EQ(im1 + im2, z3.getIm());
}

TEST(Labinskaya_Marina_ComplexNumberTest, Can_Subtract_Two_Numbers) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;
    double re2 = -1.0;
    double im2 = 4.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ComplexNumber z3 = z1 - z2;

    // Assert
    EXPECT_DOUBLE_EQ(re1 - re2, z3.getRe());
    EXPECT_DOUBLE_EQ(im1 - im2, z3.getIm());
}

TEST(Labinskaya_Marina_ComplexNumberTest, Can_Multply_Two_Numbers) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;
    double re2 = -1.0;
    double im2 = 4.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ComplexNumber z3 = z1 * z2;

    // Assert
    EXPECT_DOUBLE_EQ(re1 * re2 - im1 * im2, z3.getRe());
    EXPECT_DOUBLE_EQ(re2 * im1 + re1 * im2, z3.getIm());
}

TEST(Labinskaya_Marina_ComplexNumberTest, Cant_Divide_By_Zero) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;
    double re2 = 0.0;
    double im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    ASSERT_ANY_THROW(z1 / z2);
}
