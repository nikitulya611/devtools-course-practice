// Copyright 2022 Brazhnik Dmitry

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(BD_CN_TEST, TEST_COMPLEX_NUMBER_SUM_FIRST_AND_SECOND_TRUE) {
    ComplexNumber complexNumber1(1, 2);
    ComplexNumber complexNumber2(2, 1);
    ComplexNumber complexNumberResult = complexNumber1 + complexNumber2;

    EXPECT_EQ(3, complexNumberResult.getRe());
    EXPECT_EQ(3, complexNumberResult.getIm());
}

TEST(BD_CN_TEST, TEST_COMPLEX_NUMBER_MULTIPLY_FIRST_AND_SECOND_TRUE) {
    ComplexNumber complexNumber1(5, 10);
    ComplexNumber complexNumber2(3, 2);
    ComplexNumber complexNumberResult = complexNumber1 * complexNumber2;

    EXPECT_EQ(-5, complexNumberResult.getRe());
    EXPECT_EQ(40, complexNumberResult.getIm());
}

TEST(BD_CN_TEST, TEST_COMPLEX_NUMBER_SUBTRACTION_FIRST_AND_SECOND_TRUE) {
    ComplexNumber complexNumber1(5, 10);
    ComplexNumber complexNumber2(3, 2);
    ComplexNumber complexNumberResult = complexNumber1 - complexNumber2;

    EXPECT_EQ(2, complexNumberResult.getRe());
    EXPECT_EQ(8, complexNumberResult.getIm());
}
