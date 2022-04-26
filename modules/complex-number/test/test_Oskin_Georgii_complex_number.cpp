// Copyright 2022 Oskin Georgii

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Oskin_Georgii_ComplexNumTest, Zero_Init) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    ASSERT_NO_THROW(z.getRe());
    ASSERT_NO_THROW(z.getIm());
}

TEST(Oskin_Georgii_ComplexNumTest, Init_by_Constructor) {
    // Arrange
    double re = 3.0;
    double im = 1.0;

    // Act
    ComplexNumber cn_1(re, im);
    ComplexNumber cn_2 = cn_1;

    // Assert
    EXPECT_EQ(cn_2.getRe(), 3.0);
    EXPECT_EQ(cn_2.getIm(), 1.0);
}

TEST(Oskin_Georgii_ComplexNumTest, ComplexNum_Comparsion_unInit) {
    // Arrange
    double re = 3.0;
    double im = 2.0;

    // Act
    ComplexNumber cn_1(re, im);
    ComplexNumber cn_2;
    bool tmp_1 = (cn_1 == cn_2);
    cn_2 = cn_1;
    bool tmp_2 = (cn_1 == cn_2);

    // Assert
    EXPECT_EQ(0, tmp_1);
    EXPECT_EQ(1, tmp_2);
}

TEST(Oskin_Georgii_ComplexNumTest, ComplexNum_Comparsion_Init) {
    // Arrange
    double re_1 = 3.0;
    double im_1 = 2.0;
    double re_2 = 4.0;
    double im_2 = 5.0;

    // Act
    ComplexNumber cn_1(re_1, im_1);
    ComplexNumber cn_2(re_2, im_2);
    bool tmp_1 = (cn_1 == cn_2);
    cn_2 = cn_1;
    bool tmp_2 = (cn_1 == cn_2);

    // Assert
    EXPECT_EQ(0, tmp_1);
    EXPECT_EQ(1, tmp_2);
}
