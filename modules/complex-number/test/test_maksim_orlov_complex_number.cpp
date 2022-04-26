// Copyright 2022 Maksim Orlov

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Orlov_Maksim_ComplexNumberTest, can_create_zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_NEAR(re, z.getRe(), 0.01);
    EXPECT_NEAR(im, z.getIm(), 0.01);
}

TEST(Orlov_Maksim_ComplexNumberTest, can_create_number) {
    // Arrange
    double re = 3.0;
    double im = 2.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_NEAR(re, z.getRe(), 0.01);
    EXPECT_NEAR(im, z.getIm(), 0.01);
}

TEST(Orlov_Maksim_ComplexNumberTest, can_copy_number) {
    // Arrange
    double re = 3.0;
    double im = 2.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z2(z);

    // Assert
    EXPECT_NEAR(re, z2.getRe(), 0.01);
    EXPECT_NEAR(im, z2.getIm(), 0.01);
}

TEST(Orlov_Maksim_ComplexNumberTest, can_assign_number) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z2(3, 4);
    z2 = z;

    // Assert
    EXPECT_NEAR(re, z.getRe(), 0.01);
    EXPECT_NEAR(im, z.getIm(), 0.01);
}

TEST(Orlov_Maksim_ComplexNumberTest, can_add) {
    // Arrange
    double re1 = 3.0;
    double im1 = 4.0;
    double re2 = -1.0;
    double im2 = 2.5;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber res = z1 + z2;

    // Assert
    EXPECT_NEAR(re1 + re2, res.getRe(), 0.01);
    EXPECT_NEAR(im1 + im2, res.getIm(), 0.01);
}

TEST(Orlov_Maksim_ComplexNumberTest, can_subtract) {
    // Arrange
    double re1 = 3.0;
    double im1 = 4.0;
    double re2 = -1.0;
    double im2 = 2.5;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber res = z1 - z2;

    // Assert
    EXPECT_NEAR(re1 - re2, res.getRe(), 0.01);
    EXPECT_NEAR(im1 - im2, res.getIm(), 0.01);
}

TEST(Orlov_Maksim_ComplexNumberTest, can_multiply) {
    // Arrange
    double re1 = 3.0;
    double im1 = 4.0;
    double re2 = -1.0;
    double im2 = 2.5;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber res = z1 * z2;

    // Assert
    EXPECT_NEAR(re1 * re2 - im1 * im2, res.getRe(), 0.01);
    EXPECT_NEAR(im1 * re2 + re1 * im2, res.getIm(), 0.01);
}

TEST(Orlov_Maksim_ComplexNumberTest, can_divide) {
    // Arrange
    double re1 = 3.0;
    double im1 = 4.0;
    double re2 = -1.0;
    double im2 = 2.5;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber res = z1 / z2;

    // Assert
    EXPECT_NEAR((re1 * re2 + im1 * im2) / (re2 * re2 + im2 * im2),
        res.getRe(), 0.01);
    EXPECT_NEAR((im1 * re2 - re1 * im2) / (re2 * re2 + im2 * im2),
        res.getIm(), 0.01);
}

TEST(Orlov_Maksim_ComplexNumberTest, can_test_equality) {
    // Arrange
    double re1 = 3.0;
    double im1 = 4.0;
    double re2 = 3.0;
    double im2 = 4.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    ASSERT_TRUE(z1 == z2);
}

TEST(Orlov_Maksim_ComplexNumberTest, can_test_inequality) {
    // Arrange
    double re1 = 3.0;
    double im1 = 4.0;
    double re2 = -1.0;
    double im2 = 2.5;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    ASSERT_TRUE(z1 != z2);
}
