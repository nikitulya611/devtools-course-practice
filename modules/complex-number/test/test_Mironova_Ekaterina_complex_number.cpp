// Copyright 2022 Mironova Ekaterina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Mironova_Ekaterina_ComplexNumberTest, can_create_complex_number) {
    ASSERT_NO_THROW(ComplexNumber z(1.0, 2.0));
}

TEST(Mironova_Ekaterina_ComplexNumberTest, getRe_works_correct) {
    double re = 1.0;
    double im = 2.0;
    ComplexNumber z(re, im);
    EXPECT_DOUBLE_EQ(re, z.getRe());
}

TEST(Mironova_Ekaterina_ComplexNumberTest, getIm_works_correct) {
    double re = 1.0;
    double im = 2.0;
    ComplexNumber z(re, im);
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Mironova_Ekaterina_ComplexNumberTest, setRe_works_correct) {
    ComplexNumber z;
    double re = 1.0;
    z.setRe(re);
    EXPECT_DOUBLE_EQ(re, z.getRe());
}

TEST(Mironova_Ekaterina_ComplexNumberTest, setIm_works_correct) {
    ComplexNumber z;
    double im = 1.0;
    z.setIm(im);
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Mironova_Ekaterina_ComplexNumberTest, addition_is_correct) {
    double re1 = 1.0, re2 = 3.0;
    double im1 = 2.0, im2 = 4.0;
    ComplexNumber z1(re1, im1), z2(re2, im2), z_res;
    z_res = z1 + z2;
    EXPECT_DOUBLE_EQ(re1 + re2, z_res.getRe());
    EXPECT_DOUBLE_EQ(im1 + im2, z_res.getIm());
}

TEST(Mironova_Ekaterina_ComplexNumberTest, subtraction_is_correct) {
    double re1 = 1.0, re2 = 3.0;
    double im1 = 2.0, im2 = 4.0;
    ComplexNumber z1(re1, im1), z2(re2, im2), z_res;
    z_res = z1 - z2;
    EXPECT_DOUBLE_EQ(re1 - re2, z_res.getRe());
    EXPECT_DOUBLE_EQ(im1 - im2, z_res.getIm());
}

TEST(Mironova_Ekaterina_ComplexNumberTest, multiplication_is_correct) {
    double re1 = 1.0, re2 = 3.0;
    double im1 = 2.0, im2 = 4.0;
    ComplexNumber z1(re1, im1), z2(re2, im2), z_res;
    z_res = z1 * z2;
    EXPECT_DOUBLE_EQ(re1 * re2 - im1 * im2, z_res.getRe());
    EXPECT_DOUBLE_EQ(re1 * im2 + re2 * im1, z_res.getIm());
}

TEST(Mironova_Ekaterina_ComplexNumberTest, division_is_correct) {
    double re1 = 5.0, re2 = 3.5;
    double im1 = 2.5, im2 = -6.0;
    ComplexNumber z1(re1, im1), z2(re2, im2), z_res;
    z_res = z1 / z2;
    double resRe = (re1 * re2 + im1 * im2) / (re2 * re2 + im2 * im2);
    double resIm = (re2 * im1 - re1 * im2) / (re2 * re2 + im2 * im2);
    EXPECT_DOUBLE_EQ(resRe, z_res.getRe());
    EXPECT_DOUBLE_EQ(resIm, z_res.getIm());
}

TEST(Mironova_Ekaterina_ComplexNumberTest, cant_divide_by_zero) {
    double re1 = 1.0, re2 = 0.0;
    double im1 = 2.0, im2 = 0.0;
    ComplexNumber z1(re1, im1), z2(re2, im2);
    ASSERT_ANY_THROW(z1 / z2);
}
