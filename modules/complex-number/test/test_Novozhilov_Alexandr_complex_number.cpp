// Copyright 2022 Novozhilov Alexandr

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Novozhilov_Alexandr_ComplexNumberTest, Default_Constructor_Works) {
    ASSERT_NO_THROW(ComplexNumber number);
}

TEST(Novozhilov_Alexandr_ComplexNumberTest, Constructor_With_Parametrs_Works) {
    ASSERT_NO_THROW(ComplexNumber number(0.0, 0.0));
}

TEST(Novozhilov_Alexandr_ComplexNumberTest, Copy_Constructor_Works) {
    ComplexNumber number1(1.0, 2.0);
    ASSERT_NO_THROW(ComplexNumber number2(number1));
}

TEST(Novozhilov_Alexandr_ComplexNumberTest, GetRe_Returns_Correct_Value) {
    ComplexNumber number(1.0, 2.0);
    ASSERT_DOUBLE_EQ(number.getRe(), 1.0);
}

TEST(Novozhilov_Alexandr_ComplexNumberTest, GetIm_Returns_Correct_Value) {
    ComplexNumber number(1.0, 2.0);
    ASSERT_DOUBLE_EQ(number.getIm(), 2.0);
}

TEST(Novozhilov_Alexandr_ComplexNumberTest, SetRe_Works_Correctly) {
    ComplexNumber number;
    number.setRe(2.5);
    ASSERT_DOUBLE_EQ(number.getRe(), 2.5);
}

TEST(Novozhilov_Alexandr_ComplexNumberTest, SetIm_Works_Correctly) {
    ComplexNumber number;
    number.setIm(1.0);
    ASSERT_DOUBLE_EQ(number.getIm(), 1.0);
}
