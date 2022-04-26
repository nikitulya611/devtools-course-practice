// Copyright 2022 Artem Trukhanov

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Trukhanov_Artem_ComplexNumberTest, Can_Create_Zero) {
    double re = 0.0;
    double im = 0.0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Trukhanov_Artem_ComplexNumberTest, Can_Create_Complex_Number) {
    ComplexNumber z(2.0, 3.0);

    EXPECT_EQ(2.0, z.getRe());
    EXPECT_EQ(3.0, z.getIm());
}

TEST(Trukhanov_Artem_ComplexNumberTest, Can_Assign_Complex_Number) {
    ComplexNumber z(2.0, 3.0);
    ComplexNumber x;
    x = z;

    EXPECT_EQ(x.getRe(), z.getRe());
    EXPECT_EQ(x.getIm(), z.getIm());
}

TEST(Trukhanov_Artem_ComplexNumberTest, Can_Add_Complex_Numbers) {
    ComplexNumber z(2.0, 3.0);
    ComplexNumber x(3.0, 4.0);
    ComplexNumber y;

    y = z + x;

    EXPECT_EQ(5, y.getRe());
    EXPECT_EQ(7, y.getIm());
}

TEST(Trukhanov_Artem_ComplexNumberTest, Can_Subtract_Complex_Numbers) {
    ComplexNumber z(5.0, 3.0);
    ComplexNumber x(3.0, 1.0);
    ComplexNumber y;

    y = z - x;

    EXPECT_EQ(2, y.getRe());
    EXPECT_EQ(2, y.getIm());
}
