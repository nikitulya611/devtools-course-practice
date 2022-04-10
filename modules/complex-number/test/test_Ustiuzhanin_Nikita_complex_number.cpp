// Copyright 2022 Ustiuzhanin Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Ustiuzhanin_Nikita_ComplexNumberTest, Destroy_Im) {
    // Arrange
    double re1 = 0.0;
    double im1 = 1.0;

    double re2 = 0.0;
    double im2 = 1.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber result = z1 * z2;

    // Assert
    EXPECT_EQ(result.getRe(), -1);
    EXPECT_EQ(result.getIm(), 0);
}

TEST(Ustiuzhanin_Nikita_ComplexNumberTest, Equal_square) {
    // Arrange
    double re1 = 0.0;
    double im1 = 1.0;

    double re2 = 0.0;
    double im2 = -1.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_EQ(z1 * z1, z2 * z2);
}

TEST(Ustiuzhanin_Nikita_ComplexNumberTest, Divide_By_Zero) {
    // Arrange
    double re1 = 0.0;
    double im1 = 1.0;

    double re2 = 0.0;
    double im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_ANY_THROW(z1 / z2);
}
