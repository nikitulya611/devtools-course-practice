// Copyright 2022 Kazhaeva Anastasia

#include <gtest/gtest.h>

#include "include/kazhaeva_complex.h"


TEST(Kazhaeva_Anastasia_complex_number,
Creating_a_zero_complex_number) {
ASSERT_NO_THROW(ComplexNumber());
}

TEST(Kazhaeva_Anastasia_complex_number, Creating_a_complex_number) {
ASSERT_NO_THROW(ComplexNumber(1, 2));
}

TEST(Kazhaeva_Anastasia_complex_number, Creating_a_complex_number_zero_im) {
ASSERT_NO_THROW(ComplexNumber(2, 0));
}

TEST(Kazhaeva_Anastasia_complex_number, Creating_a_complex_number_zero_re) {
ASSERT_NO_THROW(ComplexNumber(0, -4.1));
}


TEST(Kazhaeva_Anastasia_complex_number, Creating_a_complex_number_test2) {
ASSERT_NO_THROW(ComplexNumber(-1.324, 2.235));
}

TEST(Kazhaeva_Anastasia_complex_number, Creating_a_complex_number_copy) {
ASSERT_NO_THROW(ComplexNumber(ComplexNumber(1, 2)));
}

TEST(Kazhaeva_Anastasia_complex_number, Creating_a_complex_number_copy_test2) {
ASSERT_NO_THROW(ComplexNumber(ComplexNumber(-24.1, 2)));
}

TEST(Kazhaeva_Anastasia_complex_number, Creating_a_complex_number_copy_test3) {
ComplexNumber c1(-24.1, 2);
ASSERT_NO_THROW(ComplexNumber c2(c1));
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_equalization_operator_for_a_complex_number) {
ComplexNumber c1 = ComplexNumber(1, 2);
ComplexNumber c2 = ComplexNumber(-1, 2);
c2 = c1;
ASSERT_EQ(c2.getRe(), c1.getRe());
ASSERT_EQ(c2.getIm(), c1.getIm());
}

TEST(Kazhaeva_Anastasia_complex_number, Checking_function_set_Re) {
ComplexNumber c1 = ComplexNumber(-1, -2);
c1.setRe(-23.5);
c1.setIm(435.6);
ASSERT_EQ(-23.5, c1.getRe());
ASSERT_EQ(435.6, c1.getIm());
}

TEST(Kazhaeva_Anastasia_complex_number, Checking_function_set_Im) {
ComplexNumber c1 = ComplexNumber(-1, -2);
c1.setRe(3423.5);
c1.setIm(-435.633);
ASSERT_EQ(3423.5, c1.getRe());
ASSERT_EQ(-435.633, c1.getIm());
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_add_operator_for_a_complex_number) {
ComplexNumber c1 = ComplexNumber(1.222, 2.234);
ComplexNumber c2 = ComplexNumber(-1.222, 2.234);
ComplexNumber r = c2 + c1;
ASSERT_EQ(r.getRe(), 0);
ASSERT_EQ(r.getIm(), 4.468);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_subtraction_operator_for_a_complex_number) {
ComplexNumber c1 = ComplexNumber(1, 2);
ComplexNumber c2 = ComplexNumber(2, 2);
ComplexNumber r = c2 - c1;
ASSERT_EQ(r.getRe(), 1);
ASSERT_EQ(r.getIm(), 0);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_multiplication_operator_for_a_complex_number) {
ComplexNumber c1 = ComplexNumber(3, 2);
ComplexNumber c2 = ComplexNumber(7, 21);
ComplexNumber r = c2 * c1;
ASSERT_EQ(r.getRe(), -21);
ASSERT_EQ(r.getIm(), 77);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_division_operator_for_a_complex_number) {
ComplexNumber c1 = ComplexNumber(32, 21);
ComplexNumber c2 = ComplexNumber(43, 21);
ComplexNumber r = c2 / c1;
ASSERT_DOUBLE_EQ(r.getRe(), 1.240273037542662);
ASSERT_DOUBLE_EQ(r.getIm(), -0.15767918088737204);
}


TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_division_operator_for_a_complex_number_zero) {
ComplexNumber c1 = ComplexNumber();
ComplexNumber c2 = ComplexNumber(43, 21);
ASSERT_ANY_THROW(c2 / c1);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_division_operator_for_a_complex_number_zero_test2) {
ComplexNumber c1 = ComplexNumber();
ComplexNumber c2 = ComplexNumber(43.23, 2.22341);
ASSERT_NO_THROW(c1 / c2);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_comparison_operator_for_a_complex_number_false) {
ComplexNumber c1 = ComplexNumber();
ComplexNumber c2 = ComplexNumber(43, 21);
ASSERT_EQ(c1 == c2, false);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_comparison_operator_for_a_complex_number_true) {
ComplexNumber c1 = ComplexNumber(1, 2);
ComplexNumber c2 = ComplexNumber(1, 2);
ASSERT_EQ(c1 == c2, true);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_comparison_operator_for_a_complex_number_true_test2) {
ComplexNumber c1 = ComplexNumber();
ComplexNumber c2 = ComplexNumber();
ASSERT_EQ(c1 == c2, true);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_no_comparison_operator_for_a_complex_number_false) {
ComplexNumber c1 = ComplexNumber(1, 2);
ComplexNumber c2 = ComplexNumber(1, 2);
ASSERT_EQ(c1 != c2, false);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_no_comparison_operator_for_a_complex_number_false_test2) {
ComplexNumber c1 = ComplexNumber(1.234, -2);
ComplexNumber c2 = ComplexNumber(1.234, -2);
ASSERT_EQ(c1 != c2, false);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_no_comparison_operator_for_a_complex_number_true) {
ComplexNumber c1 = ComplexNumber();
ComplexNumber c2 = ComplexNumber(43, 21);
ASSERT_EQ(c1 != c2, true);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_magnitude_operator_for_a_complex_number) {
ComplexNumber c1 = ComplexNumber(2, 3);
ASSERT_DOUBLE_EQ(c1.magnitude(), 3.605551275463989);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_magnitude_operator_for_a_complex_number_test2) {
ComplexNumber c1 = ComplexNumber();
ASSERT_DOUBLE_EQ(c1.magnitude(), 0);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_argument_operator_for_a_complex_number) {
ComplexNumber c1 = ComplexNumber(2, 3);
ASSERT_DOUBLE_EQ(c1.argument(), 0.98279372324732905);
}

TEST(Kazhaeva_Anastasia_complex_number,
Checking_the_argument_operator_for_a_complex_number_test2) {
ComplexNumber c1 = ComplexNumber();
ASSERT_DOUBLE_EQ(c1.argument(), 0);
}
