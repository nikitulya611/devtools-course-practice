// Copyright 2022 Pinezhanin Evgeny

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pinezhanin_Evgeny_ComplexNumberTest, can_create_copied_complex_number) {
    double re = 5.0;
    double im = 6.0;
    ComplexNumber z(re, im);
    ComplexNumber z_copy(z);

    ASSERT_DOUBLE_EQ(z_copy.getRe(), z.getRe());
    ASSERT_DOUBLE_EQ(z_copy.getIm(), z.getIm());
}

TEST(Pinezhanin_Evgeny_ComplexNumberTest, can_assign_complex_number) {
    double re = 3.0;
    double im = 2.0;
    ComplexNumber z(re, im);
    ComplexNumber z_assign;
    z_assign = z;

    ASSERT_DOUBLE_EQ(z_assign.getRe(), z.getRe());
    ASSERT_DOUBLE_EQ(z_assign.getIm(), z.getIm());
}

TEST(Pinezhanin_Evgeny_ComplexNumberTest, can_get_re_complex_number) {
    double re = 3.0;
    double im = 2.0;
    ComplexNumber z(re, im);

    ASSERT_DOUBLE_EQ(z.getRe(), re);
}

TEST(Pinezhanin_Evgeny_ComplexNumberTest, can_get_im_complex_number) {
    double re = 3.0;
    double im = 2.0;
    ComplexNumber z(re, im);

    ASSERT_DOUBLE_EQ(z.getIm(), im);
}

TEST(Pinezhanin_Evgeny_ComplexNumberTest, can_change_re_complex_number) {
    double re = 3.0, re_new = 5.0;
    double im = 2.0;
    ComplexNumber z(re, im);
    z.setRe(re_new);

    ASSERT_DOUBLE_EQ(z.getRe(), re_new);
}

TEST(Pinezhanin_Evgeny_ComplexNumberTest, can_change_im_complex_number) {
    double re = 3.0;
    double im = 2.0, im_new = 5.0;
    ComplexNumber z(re, im);
    z.setIm(im_new);

    ASSERT_DOUBLE_EQ(z.getIm(), im_new);
}

TEST(Pinezhanin_Evgeny_ComplexNumberTest, can_compare_equal_numbers) {
    double re = 3.0;
    double im = 2.0;
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);

    ASSERT_EQ(z1, z2);
}

TEST(Pinezhanin_Evgeny_ComplexNumberTest, can_compare_inequal_numbers) {
    double re1 = 3.0, re2 = 5.0;
    double im1 = 2.0, im2 = 7.5;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ASSERT_NE(z1, z2);
}

TEST(Pinezhanin_Evgeny_ComplexNumberTest, can_add_complex_numbers) {
    double re1 = 3.0, re2 = 9.5, re3 = 12.5;
    double im1 = 2.0, im2 = 4.7, im3 = 6.7;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);
    z1 = z1 + z2;

    ASSERT_EQ(z1, z3);
}

TEST(Pinezhanin_Evgeny_ComplexNumberTest, can_subtract_complex_numbers) {
    double re1 = 3.0, re2 = 9.5, re3 = -6.5;
    double im1 = 2.0, im2 = 4.7, im3 = -2.7;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);
    z1 = z1 - z2;

    ASSERT_EQ(z1, z3);
}

TEST(Pinezhanin_Evgeny_ComplexNumberTest, can_multiply_complex_numbers) {
    double re1 = 3.0, re2 = 9.0, re3 = 17.0;
    double im1 = 2.0, im2 = 5.0, im3 = 33.0;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);
    z1 = z1 * z2;

    ASSERT_EQ(z1, z3);
}

TEST(Pinezhanin_Evgeny_ComplexNumberTest, can_divide_complex_numbers) {
    double re1 = 3.0, re2 = 6.0, re3 = 0.34;
    double im1 = 2.0, im2 = 8.0, im3 = -0.12;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);
    z1 = z1 / z2;

    ASSERT_EQ(z1, z3);
}

TEST(Pinezhanin_Evgeny_ComplexNumberTest, cant_divide_by_zero) {
    double re1 = 5.0, re2 = 0.0;
    double im1 = 3.0, im2 = 0.0;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ASSERT_ANY_THROW(z1 / z2);
}
