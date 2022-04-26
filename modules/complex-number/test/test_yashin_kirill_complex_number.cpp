// Copyright 2022 Yashin Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Yashin_Kirill_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    ASSERT_NO_THROW(z.getRe());
    ASSERT_NO_THROW(z.getIm());
}

TEST(Yashin_Kirill_ComplexNumberTest, Can_Add_Positive) {
    // Arrange
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(1.0, 1.0);

    // Act
    ComplexNumber z3 = z1 + z2;

    // Assert
    EXPECT_EQ(2, z3.getRe());
    EXPECT_EQ(2, z3.getIm());
}

TEST(Yashin_Kirill_ComplexNumberTest, Can_Add_Negative) {
    // Arrange
    ComplexNumber z1(-1.0, -1.0);
    ComplexNumber z2(-1.0, -1.0);

    // Act
    ComplexNumber z3 = z1 + z2;

    // Assert
    EXPECT_EQ(-2, z3.getRe());
    EXPECT_EQ(-2, z3.getIm());
}

TEST(Yashin_Kirill_ComplexNumberTest, Can_Sub) {
    // Arrange
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(1.0, 1.0);

    // Act
    ComplexNumber z3 = z1 - z2;

    // Assert
    EXPECT_EQ(0, z3.getRe());
    EXPECT_EQ(0, z3.getIm());
}

TEST(Yashin_Kirill_ComplexNumberTest, Can_Mul) {
    // Arrange
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(1.0, 1.0);

    // Act
    ComplexNumber z3 = z1 * z2;

    // Assert
    EXPECT_EQ(0, z3.getRe());
    EXPECT_EQ(2, z3.getIm());
}

TEST(Yashin_Kirill_ComplexNumberTest, Can_Div) {
    // Arrange
    ComplexNumber z1(2.0, 1.0);
    ComplexNumber z2(1.0, 1.0);

    // Act
    ComplexNumber z3 = z1 / z2;

    // Assert
    EXPECT_EQ(1.5, z3.getRe());
    EXPECT_EQ(-0.5, z3.getIm());
}

TEST(Yashin_Kirill_ComplexNumberTest, Can_Mul_On_Negative) {
    // Arrange
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(-1.0, 1.0);

    // Act
    ComplexNumber z3 = z1 * z2;

    // Assert
    EXPECT_EQ(-2, z3.getRe());
    EXPECT_EQ(0, z3.getIm());
}

TEST(Yashin_Kirill_ComplexNumberTest, Can_Div_On_Negative) {
    // Arrange
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(-1.0, 1.0);

    // Act
    ComplexNumber z3 = z1 / z2;

    // Assert
    EXPECT_EQ(0, z3.getRe());
    EXPECT_EQ(-1, z3.getIm());
}
