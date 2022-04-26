// Copyright 2022 Elanskiy Alexandr

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Elanskiy_Alexandr_ComplexNumberTest, Create) {
    ASSERT_NO_THROW(ComplexNumber z(5.2, 1.7));
}

TEST(Elanskiy_Alexandr_ComplexNumberTest, Subtraction) {
    double re1 = 5.0;
    double im1 = 1.0;
    double re2 = 2.0;
    double im2 = 1.5;

    ComplexNumber tmp1(re1, im1);
    ComplexNumber tmp2(re2, im2);

    ComplexNumber Subtraction = tmp1 - tmp2;

    EXPECT_EQ(re1 - re2, Subtraction.getRe());
    EXPECT_EQ(im1 - im2, Subtraction.getIm());
}

TEST(Elanskiy_Alexandr_ComplexNumberTest, Sum) {
    double re1 = 1.0;
    double im1 = 1.5;
    double re2 = 2.0;
    double im2 = 2.5;

    ComplexNumber tmp1(re1, im1);
    ComplexNumber tmp2(re2, im2);

    ComplexNumber Sum = tmp1 + tmp2;

    EXPECT_EQ(re1 + re2, Sum.getRe());
    EXPECT_EQ(im1 + im2, Sum.getIm());
}
