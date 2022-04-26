// Copyright 2022 Bakina Kseniia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bakina_Kseniia_ComplexNumberTest, check_initialization_constructor) {
    double cn1Real = 3.56, cn1Im = 7.9;
    ComplexNumber cn1(cn1Real, cn1Im);

    EXPECT_DOUBLE_EQ(cn1Real, cn1.getRe());
    EXPECT_DOUBLE_EQ(cn1Im, cn1.getIm());
}

TEST(Bakina_Kseniia_ComplexNumberTest, check_copy_constructor) {
    double cn1Real = 3.56, cn1Im = 7.9;
    ComplexNumber cn1(cn1Real, cn1Im);
    ComplexNumber cn2(cn1);

    EXPECT_TRUE(cn1 == cn2);
}

TEST(Bakina_Kseniia_ComplexNumberTest, check_setters) {
    double cn1Real = 1.47, cn1Im = 0.6;
    ComplexNumber cn1;

    cn1.setRe(cn1Real);
    cn1.setIm(cn1Im);

    EXPECT_DOUBLE_EQ(cn1Real, cn1.getRe());
    EXPECT_DOUBLE_EQ(cn1Im, cn1.getIm());
}

TEST(Bakina_Kseniia_ComplexNumberTest, check_equality_operation) {
    ComplexNumber cn1(3.56, 7.9);
    ComplexNumber cn2(3.56, 7.9);
    ComplexNumber cn3(4.1, 8.0);

    EXPECT_TRUE(cn1 == cn2);
    EXPECT_FALSE(cn1 == cn3);
}

TEST(Bakina_Kseniia_ComplexNumberTest, check_inequality_operation) {
    ComplexNumber cn1(3.56, 7.9);
    ComplexNumber cn2(3.56, 7.9);
    ComplexNumber cn3(4.1, 8.0);

    EXPECT_TRUE(cn1 != cn3);
    EXPECT_FALSE(cn1 != cn2);
}

TEST(Bakina_Kseniia_ComplexNumberTest, check_addition) {
    double cn1Real = 3.56, cn1Im = 7.9;
    ComplexNumber cn1(cn1Real, cn1Im);

    double cn2Real = 4.44, cn2Im = 0.1;
    ComplexNumber cn2(cn2Real, cn2Im);

    ComplexNumber sum = cn1 + cn2;

    EXPECT_DOUBLE_EQ(cn1Real + cn2Real, sum.getRe());
    EXPECT_DOUBLE_EQ(cn1Im + cn2Im, sum.getIm());
}

TEST(Bakina_Kseniia_ComplexNumberTest, check_subtraction) {
    double cn1Real = 3.56, cn1Im = 7.9;
    ComplexNumber cn1(cn1Real, cn1Im);

    double cn2Real = 4.44, cn2Im = 0.1;
    ComplexNumber cn2(cn2Real, cn2Im);

    ComplexNumber dif = cn1 - cn2;

    EXPECT_DOUBLE_EQ(cn1Real - cn2Real, dif.getRe());
    EXPECT_DOUBLE_EQ(cn1Im - cn2Im, dif.getIm());
}

TEST(Bakina_Kseniia_ComplexNumberTest, check_multiplication) {
    double cn1Real = 3.56, cn1Im = 7.9;
    ComplexNumber cn1(cn1Real, cn1Im);

    double cn2Real = 4.44, cn2Im = 0.1;
    ComplexNumber cn2(cn2Real, cn2Im);

    ComplexNumber mul = cn1 * cn2;

    EXPECT_DOUBLE_EQ(cn1Real * cn2Real - cn1Im * cn2Im, mul.getRe());
    EXPECT_DOUBLE_EQ(cn1Real * cn2Im + cn1Im * cn2Real, mul.getIm());
}

TEST(Bakina_Kseniia_ComplexNumberTest, check_division) {
    double cn1Real = 6.3, cn1Im = 9.6;
    ComplexNumber cn1(cn1Real, cn1Im);

    double cn2Real = 3.2, cn2Im = 8.1;
    ComplexNumber cn2(cn2Real, cn2Im);

    ComplexNumber div = cn1 / cn2;

    double numerator1 = cn1Real * cn2Real + cn1Im * cn2Im;
    double numerator2 = cn1Im * cn2Real - cn1Real * cn2Im;
    double denominator = 1.0 / (cn2Real * cn2Real + cn2Im * cn2Im);
    EXPECT_DOUBLE_EQ(numerator1 * denominator, div.getRe());
    EXPECT_DOUBLE_EQ(numerator2 * denominator, div.getIm());
}
