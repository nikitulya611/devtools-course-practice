// Copyright 2022 Remizova Antonina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Remizova_Antonina_ComplexNumberTest, Can_Create_ComplexNumber) {
    ComplexNumber a(5.0, 3.0);

    EXPECT_EQ(5.0, a.getRe());
    EXPECT_EQ(3.0, a.getIm());
}

TEST(Remizova_Antonina_ComplexNumberTest, Can_Create_Copy_ComplexNumber) {
    ComplexNumber a(3.0, 0.1);
    ComplexNumber b(a);

    EXPECT_EQ(3.0, b.getRe());
    EXPECT_EQ(0.1, b.getIm());
}

TEST(Remizova_Antonina_ComplexNumberTest, Can_Assign_ComplexNumber) {
    ComplexNumber a(3.0, 0.8);
    ComplexNumber b(4.0, 0.9);

    b = a;

    EXPECT_EQ(3.0, b.getRe());
    EXPECT_EQ(0.8, b.getIm());
}

TEST(Remizova_Antonina_ComplexNumberTest, Can_Summarize_ComplexNumber) {
    ComplexNumber a(4.0, 0.5);
    ComplexNumber b(2.0, 0.6);
    ComplexNumber sum = a + b;

    EXPECT_EQ(6.0, sum.getRe());
    EXPECT_EQ(1.1, sum.getIm());
}

TEST(Remizova_Antonina_ComplexNumberTest, Can_Subtract_ComplexNumber) {
    ComplexNumber a(3.0, 2.0);
    ComplexNumber b(5.0, 0.7);
    ComplexNumber dif = a - b;

    EXPECT_EQ(-2.0, dif.getRe());
    EXPECT_EQ(1.3, dif.getIm());
}

TEST(Remizova_Antonina_ComplexNumberTest, Can_Multiply_ComplexNumber) {
    ComplexNumber a(1.0, 1.0);
    ComplexNumber b(4.0, 2.0);
    ComplexNumber multi = a * b;

    EXPECT_EQ(2.0, multi.getRe());
    EXPECT_EQ(6.0, multi.getIm());
}
