// Copyright 2022 Kim Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kim_Nikita_ComplexNumberTest, Can_Create_Zero) {
  // Arrange
  double re = 0.0;
  double im = 0.0;

  // Act
  ComplexNumber z(re, im);

  // Assert

  EXPECT_DOUBLE_EQ(re, z.getRe());
  EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Kim_Nikita_ComplexNumberTest, Can_Sum) {
  // Arrange
  double re_1 = 1.0;
  double im_1 = 0.1;
  double re_2 = 2.0;
  double im_2 = 0.2;

  // Act
  ComplexNumber z_1(re_1, im_1);
  ComplexNumber z_2(re_2, im_2);
  ComplexNumber z_3 = z_1 + z_2;

  // Assert
  EXPECT_DOUBLE_EQ(3, z_3.getRe());
  EXPECT_DOUBLE_EQ(0.3, z_3.getIm());
}

TEST(Kim_Nikita_ComplexNumberTest, Can_Prod) {
  // Arrange
  double re_1 = 1.0;
  double im_1 = 0.1;
  double re_2 = 2.0;
  double im_2 = 0.2;

  // Act
  ComplexNumber z_1(re_1, im_1);
  ComplexNumber z_2(re_2, im_2);
  ComplexNumber z_3 = z_1 * z_2;

  // Assert
  EXPECT_DOUBLE_EQ(1.98, z_3.getRe());
  EXPECT_DOUBLE_EQ(0.4, z_3.getIm());
}

TEST(Kim_Nikita_ComplexNumberTest, Can_Do_Large_Operations) {
  // Arrange
  double re_1 = 1.0;
  double im_1 = 0.1;
  double re_2 = 6.0;
  double im_2 = 8.0;
  double re_3 = 3.0;
  double im_3 = 4.0;
  double re_4 = 4.0;
  double im_4 = 0.4;

  // Act
  ComplexNumber z_1(re_1, im_1);
  ComplexNumber z_2(re_2, im_2);
  ComplexNumber z_3(re_3, im_3);
  ComplexNumber z_4(re_4, im_4);
  ComplexNumber z_5 = z_1*z_4 - z_2/z_3;

  // Assert
  EXPECT_DOUBLE_EQ(1.96, z_5.getRe());
  EXPECT_DOUBLE_EQ(0.8, z_5.getIm());
}
