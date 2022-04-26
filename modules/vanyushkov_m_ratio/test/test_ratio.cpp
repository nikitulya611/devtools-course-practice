// Copyright 2022 Vanyushkov Maxim

#include <gtest/gtest.h>

#include "include/ratio.h"

TEST(Vanyushkov_Maxim_Ratio, can_create_ratio) {
    ASSERT_NO_THROW(Ratio());
}

TEST(Vanyushkov_Maxim_Ratio, can_create_ratio_with_numerator) {
    ASSERT_NO_THROW(Ratio(1));
}

TEST(Vanyushkov_Maxim_Ratio, can_create_ratio_with_values) {
    ASSERT_NO_THROW(Ratio(1, 3));
}

TEST(Vanyushkov_Maxim_Ratio, currect_create_ratio) {
    int numerator = 1;
    int denominator = 3;

    Ratio ratio(numerator, denominator);

    ASSERT_EQ(ratio.get_numerator(), numerator);
    ASSERT_EQ(ratio.get_denominator(), denominator);
}

TEST(Vanyushkov_Maxim_Ratio, currect_create_ratio_with_used_gcd) {
    int numerator = 4;
    int denominator = 10;
    int gcd = 2;

    Ratio ratio(numerator, denominator);

    ASSERT_EQ(ratio.get_numerator(), numerator / gcd);
    ASSERT_EQ(ratio.get_denominator(), denominator / gcd);
}

TEST(Vanyushkov_Maxim_Ratio, currect_create_ratio_witn_minus_in_numerator) {
    int numerator = 1;
    int denominator = -3;

    Ratio ratio(numerator, denominator);

    ASSERT_EQ(ratio.get_numerator(), -numerator);
    ASSERT_EQ(ratio.get_denominator(), -denominator);
}

TEST(Vanyushkov_Maxim_Ratio, any_throw_with_zero_denominator) {
    ASSERT_ANY_THROW(Ratio(0, 0));
}

TEST(Vanyushkov_Maxim_Ratio, create_ratio_with_1_denom_if_used_0_numer) {
    Ratio ratio(0, 10);
    ASSERT_EQ(ratio.get_denominator(), 1);
}

TEST(Vanyushkov_Maxim_Ratio, can_copy_ratio) {
    int numerator = 1;
    int denominator = 3;

    Ratio ratio(numerator, denominator);

    ASSERT_NO_THROW(Ratio(ratio));
}

TEST(Vanyushkov_Maxim_Ratio, can_currect_copy_ratio) {
    int numerator = 1;
    int denominator = 3;

    Ratio ratio(numerator, denominator);
    Ratio copy_ratio(ratio);

    ASSERT_EQ(ratio.get_numerator(), copy_ratio.get_numerator());
    ASSERT_EQ(ratio.get_denominator(), copy_ratio.get_denominator());
}

TEST(Vanyushkov_Maxim_Ratio, can_add_ratios_currect) {
    int num1 = 1, den1 = 21;
    int num2 = 20, den2 = 7;
    int res_num = num1 * den2 + num2 * den1;
    int res_den = den1 * den2;

    Ratio r1(num1, den1);
    Ratio r2(num2, den2);
    Ratio res = r1 + r2;

    ASSERT_EQ(res, Ratio(res_num, res_den));
}

TEST(Vanyushkov_Maxim_Ratio, can_sub_ratios_currect) {
    int num1 = 1, den1 = 21;
    int num2 = 20, den2 = 7;
    int res_num = num1 * den2 - num2 * den1;
    int res_den = den1 * den2;

    Ratio r1(num1, den1);
    Ratio r2(num2, den2);
    Ratio res = r1 - r2;

    ASSERT_EQ(res, Ratio(res_num, res_den));
}

TEST(Vanyushkov_Maxim_Ratio, can_mul_ratios_currect) {
    int num1 = 1, den1 = 21;
    int num2 = 20, den2 = 7;
    int res_num = num1 * num2;
    int res_den = den1 * den2;

    Ratio r1(num1, den1);
    Ratio r2(num2, den2);
    Ratio res = r1 * r2;

    ASSERT_EQ(res, Ratio(res_num, res_den));
}

TEST(Vanyushkov_Maxim_Ratio, can_div_ratios_currect) {
    int num1 = 1, den1 = 21;
    int num2 = 20, den2 = 7;
    int res_num = num1 * den2;
    int res_den = den1 * num2;

    Ratio r1(num1, den1);
    Ratio r2(num2, den2);
    Ratio res = r1 / r2;

    ASSERT_EQ(res, Ratio(res_num, res_den));
}

TEST(Vanyushkov_Maxim_Ratio, get_throw_when_div_by_zero) {
    int num = 1, den = 21;

    Ratio r1(num, den);
    Ratio r2(0);

    ASSERT_ANY_THROW(r1 / r2);
}

TEST(Vanyushkov_Maxim_Ratio, can_unary_plus) {
    int numerator = 1;
    int denominator = 3;

    Ratio ratio1(numerator, denominator);
    Ratio ratio2 = +ratio1;

    ASSERT_EQ(ratio1.get_numerator(), ratio2.get_numerator());
    ASSERT_EQ(ratio1.get_denominator(), ratio2.get_denominator());
}

TEST(Vanyushkov_Maxim_Ratio, can_unary_minus) {
    int numerator = 1;
    int denominator = 3;

    Ratio ratio1(numerator, denominator);
    Ratio ratio2 = -ratio1;

    ASSERT_EQ(ratio1.get_numerator(), -ratio2.get_numerator());
    ASSERT_EQ(ratio1.get_denominator(), ratio2.get_denominator());
}

TEST(Vanyushkov_Maxim_Ratio, can_check_eq) {
    int numerator = 1;
    int denominator = 3;

    Ratio ratio1(numerator, denominator);
    Ratio ratio2(numerator, denominator);

    ASSERT_TRUE(ratio1 == ratio2);
}

TEST(Vanyushkov_Maxim_Ratio, can_check_ne) {
    int numerator = 1;
    int denominator = 3;

    Ratio ratio1(numerator, denominator);
    Ratio ratio2(numerator + 1, denominator);

    ASSERT_TRUE(ratio1 != ratio2);
}

TEST(Vanyushkov_Maxim_Ratio, can_check_lt) {
    int numerator = 1;
    int denominator = 3;

    Ratio ratio1(numerator, denominator);
    Ratio ratio2(numerator + 1, denominator);

    ASSERT_TRUE(ratio1 < ratio2);
}

TEST(Vanyushkov_Maxim_Ratio, can_check_gt) {
    int numerator = 1;
    int denominator = 3;

    Ratio ratio1(numerator + 1, denominator);
    Ratio ratio2(numerator, denominator);

    ASSERT_TRUE(ratio1 > ratio2);
}

TEST(Vanyushkov_Maxim_Ratio, can_check_le) {
    int numerator = 1;
    int denominator = 3;

    Ratio ratio1(numerator, denominator);
    Ratio ratio2(numerator + 1, denominator);

    ASSERT_TRUE(ratio1 <= ratio2);
}

TEST(Vanyushkov_Maxim_Ratio, can_check_ge) {
    int numerator = 1;
    int denominator = 3;

    Ratio ratio1(numerator + 1, denominator);
    Ratio ratio2(numerator, denominator);

    ASSERT_TRUE(ratio1 >= ratio2);
}

TEST(Vanyushkov_Maxim_Ratio, return_int_part_of_ratio) {
    int numerator = 7, denominator = 3;

    Ratio ratio(numerator, denominator);

    ASSERT_EQ(ratio.div(), numerator / denominator);
}

TEST(Vanyushkov_Maxim_Ratio, return_mod_of_ratio) {
    int numerator = 7, denominator = 3;

    Ratio ratio(numerator, denominator);

    ASSERT_EQ(ratio.mod(), numerator % denominator);
}

TEST(Vanyushkov_Maxim_Ratio, return_currect_negative_mod_of_ratio) {
    int numerator = -7, denominator = 3;
    int res = denominator - std::abs(numerator) % denominator;

    Ratio ratio(numerator, denominator);

    ASSERT_EQ(ratio.mod(), res);
}

TEST(Vanyushkov_Maxim_Ratio, ratio_to_double) {
    int numerator = 2, denominator = 5;
    double res = static_cast<double>(numerator) / denominator;

    Ratio ratio(numerator, denominator);

    ASSERT_DOUBLE_EQ(ratio.to_double(), res);
}

TEST(Vanyushkov_Maxim_Ratio, can_set_ratio) {
    int numerator = 2, denominator = 5;

    Ratio ratio;
    ratio.set_ratio(numerator, denominator);

    ASSERT_EQ(ratio.get_numerator(), numerator);
    ASSERT_EQ(ratio.get_denominator(), denominator);
}
