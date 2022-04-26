// Copyright 2022 Butescu Vladimir

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Butescu_Vladimir_ComplexNumberTest, Can_Init) {
    // Arrange
    double re = 1.0;
    double im = 2.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(1.0, z.getRe());
    EXPECT_DOUBLE_EQ(2.0, z.getIm());
}

TEST(Butescu_Vladimir_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Butescu_Vladimir_ComplexNumberTest, Can_Sum) {
    // Arrange
    double re = 2.0;
    double im = 1.0;

    double re1 = 1.0;
    double im1 = -2.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re1, im1);

    ComplexNumber sum = z + z1;

    // Assert
    EXPECT_DOUBLE_EQ(3.0, sum.getRe());
    EXPECT_DOUBLE_EQ(-1.0, sum.getIm());
}


TEST(Butescu_Vladimir_ComplexNumberTest, Can_Difference) {
    // Arrange
    double re = 2.0;
    double im = 1.0;

    double re1 = 1.0;
    double im1 = 2.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re1, im1);

    ComplexNumber diff = z - z1;

    // Assert
    EXPECT_DOUBLE_EQ(1.0, diff.getRe());
    EXPECT_DOUBLE_EQ(-1.0, diff.getIm());
}

TEST(Butescu_Vladimir_ComplexNumberTest, Can_Multiplication) {
    // Arrange
    double re = 2.0;
    double im = 3.0;

    double re1 = 1.0;
    double im1 = 4.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re1, im1);

    ComplexNumber mult = z * z1;

    // Assert
    EXPECT_DOUBLE_EQ(-10.0, mult.getRe());
    EXPECT_DOUBLE_EQ(11.0, mult.getIm());
}

TEST(Butescu_Vladimir_ComplexNumberTest, Can_Division) {
    // Arrange
    double re = 3.0;
    double im = 4.0;

    double re1 = 3.0;
    double im1 = 4.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re1, im1);

    ComplexNumber div = z / z1;

    // Assert
    EXPECT_DOUBLE_EQ(1.0, div.getRe());
    EXPECT_DOUBLE_EQ(0.0, div.getIm());
}

TEST(Butescu_Vladimir_ComplexNumberTest, Can_Equals_Unqals) {
    // Arrange
    double re = 10.0;
    double im = 20.0;

    double re1 = 10.0;
    double im1 = 20.0;

    // Act
    ComplexNumber eq(re, im);
    ComplexNumber un(re1, im1);

    // Assert
    EXPECT_DOUBLE_EQ(true, eq == un);
    EXPECT_DOUBLE_EQ(false, eq != un);
}
