// Copyright 2022 Moskvin Stanislav

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Moskvin_Stanislav_ComplexNumberTest, can_init) {
    ASSERT_NO_THROW(ComplexNumber a);
}

TEST(Moskvin_Stanislav_ComplexNumberTest, returns_correct) {
    double r1 = 2.1, i1 = 2.2;

    ComplexNumber a(r1, i1);

    EXPECT_DOUBLE_EQ(r1, a.getRe());
    EXPECT_DOUBLE_EQ(i1, a.getIm());
}

TEST(Moskvin_Stanislav_ComplexNumberTest, sets_values_correctly) {
    double r1 = 2.1, i1 = 2.2;
    ComplexNumber a;

    a.setRe(r1);
    a.setIm(i1);

    EXPECT_DOUBLE_EQ(r1, a.getRe());
    EXPECT_DOUBLE_EQ(i1, a.getIm());
}

TEST(Moskvin_Stanislav_ComplexNumberTest, can_copy) {
    double r1 = 2.1, i1 = 2.2;

    ComplexNumber a(1.1, 2.2);

    ASSERT_NO_THROW(ComplexNumber b(a));
}

TEST(Moskvin_Stanislav_ComplexNumberTest, currect_copy) {
    double r1 = 2.1, i1 = 2.2;

    ComplexNumber a(r1, i1);
    ComplexNumber b(a);

    EXPECT_TRUE(a == b);
}

TEST(Moskvin_Stanislav_ComplexNumberTest, currect_sum) {
    double r1 = 2.1, i1 = 2.2, r2 = 0.1 , i2 = 0.2;

    ComplexNumber a(r1, i1);
    ComplexNumber b(r2, i2);

    ComplexNumber Sum = a + b;

    EXPECT_EQ(r1 + r2, Sum.getRe());
    EXPECT_EQ(i1 + i2, Sum.getIm());
}

TEST(Moskvin_Stanislav_ComplexNumberTest, currect_subtraction) {
    double r1 = 2.1, i1 = 2.2, r2 = 0.1 , i2 = 0.2;

    ComplexNumber a(r1, i1);
    ComplexNumber b(r2, i2);

    ComplexNumber Subtraction = a - b;

    EXPECT_EQ(r1 - r2, Subtraction.getRe());
    EXPECT_EQ(i1 - i2, Subtraction.getIm());
}

TEST(Moskvin_Stanislav_ComplexNumberTest, currect_multiplies) {
    double r1 = 2.0, i1 = 2.2, r2 = 2.2 , i2 = 1.0;

    ComplexNumber a(r1, i1);
    ComplexNumber b(r2, i2);

    ComplexNumber Multiplies = a * b;

    EXPECT_EQ(r1 * r2 - i1 * i2, Multiplies.getRe());
    EXPECT_EQ(r1 * i2 + i1 * r2, Multiplies.getIm());
}

TEST(Moskvin_Stanislav_ComplexNumberTest, currect_division) {
    double r1 = 2.2, i1 = 2.2, r2 = 2.0 , i2 = 1.0;

    ComplexNumber a(r1, i1);
    ComplexNumber b(r2, i2);

    ComplexNumber Division = a / b;

    double n1 = r1 * r2 + i1 * i2;
    double n2 = i1 * r2 - r1 * i2;
    double d = 1.0 / (r2 * r2 + i2 * i2);

    EXPECT_DOUBLE_EQ(n1 * d, Division.getRe());
    EXPECT_DOUBLE_EQ(n2 * d, Division.getIm());
}

TEST(Moskvin_Stanislav_ComplexNumberTest, currect_equality_1) {
    double r1 = 2.2, i1 = 2.2, r2 = 2.2 , i2 = 2.2;

    ComplexNumber a(r1, i1);
    ComplexNumber b(r2, i2);

    EXPECT_TRUE(a == b);
}

TEST(Moskvin_Stanislav_ComplexNumberTest, currect_equality_2) {
    double r1 = 2.2, i1 = 2.2, r2 = 2.2 , i2 = 2.0;

    ComplexNumber a(r1, i1);
    ComplexNumber b(r2, i2);

    EXPECT_TRUE(a != b);
}
