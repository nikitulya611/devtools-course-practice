// Copyright 2022 Chornyi Yura

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(OpeartionSuite, OperationPlus) {
    // Arrange
    ComplexNumber z1(2, 1);
    ComplexNumber z2(1, 2);

    // Act
    ComplexNumber z3 = z1 + z2;

    // Assert
    ASSERT_EQ(z3.getRe(), 3);
    ASSERT_EQ(z3.getIm(), 3);
}

TEST(OpeartionSuite, OperationMinus) {
    // Arrange
    ComplexNumber z1(2, 1);
    ComplexNumber z2(1, 2);

    // Act
    ComplexNumber z3 = z1 - z2;

    // Assert
    ASSERT_EQ(z3.getRe(), 1);
    ASSERT_EQ(z3.getIm(), -1);
}

TEST(OpeartionSuite, OperationMultiply) {
    // Arrange
    ComplexNumber z1(2, 1);
    ComplexNumber z2(1, 2);

    // Act
    ComplexNumber z3 = z1 * z2;

    // Assert
    ASSERT_EQ(z3.getRe(), 0);
    ASSERT_EQ(z3.getIm(), 5);
}

TEST(OpeartionSuite, OperationDevide) {
    // Arrange
    ComplexNumber z1(1, 1);
    ComplexNumber z2(1, 1);

    // Act
    ComplexNumber z3 = z1 / z2;

    // Assert
    ASSERT_EQ(z3.getRe(), 1);
    ASSERT_EQ(z3.getIm(), 0);
}
