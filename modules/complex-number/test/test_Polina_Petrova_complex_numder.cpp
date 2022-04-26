// Copyright 2022 Petrova Polina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(ComplexNumberTest, Can_Create_Zero) {
    double re = 0.0;
    double im = 0.0;
    ComplexNumber z(re, im);
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
TEST(ComplexNumberTest, Return_correct_re) {
    ComplexNumber num(5, 7);
    EXPECT_EQ(5, num.getRe());
}
TEST(ComplexNumberTest, Return_correct_im) {
    ComplexNumber num(5, 7);
    EXPECT_EQ(7, num.getIm());
}
TEST(ComplexNumberTest, Correct_op_plus_re) {
    ComplexNumber num1(1.5, 7.7);
    ComplexNumber num2(0.7, 7.3);
    ComplexNumber res = num1 + num2;
    EXPECT_DOUBLE_EQ(2.2, res.getRe());
}
TEST(ComplexNumberTest, Correct_op_plus_im) {
    ComplexNumber num1(1.5, 7.7);
    ComplexNumber num2(0.7, 7.3);
    ComplexNumber res = num1 + num2;
    EXPECT_DOUBLE_EQ(15.0, res.getIm());
}
TEST(ComplexNumberTest, Correct_op_minus) {
    ComplexNumber num1(1.5, 7.7);
    ComplexNumber num2(0.7, 7.3);
    ComplexNumber res = num1 - num2;
    EXPECT_DOUBLE_EQ(0.8, res.getRe());
}
TEST(ComplexNumberTest, Correct_eq) {
    ComplexNumber num1(1.5, 7.7);
    ComplexNumber num2(1.5, 7.7);
    EXPECT_EQ(num1, num2);
}
TEST(ComplexNumberTest, Incorrect_eq) {
    ComplexNumber num1(1.5, 7.7);
    ComplexNumber num2(1.7, 7.7);
    EXPECT_NE(num1, num2);
}
TEST(ComplexNumberTest, Correct_op_division_on_zero) {
    ComplexNumber num1(7.7, 7.7);
    ComplexNumber num2(0, 0);
    ASSERT_ANY_THROW(num1 / num2);
}


