// Copyright 2022 Albaraa Abuyassen

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Abuyaseen_Albaraa_tests, can_create_a_zero_number) {
  ComplexNumber sample;

  EXPECT_EQ(0, sample.getRe());
  EXPECT_EQ(0, sample.getIm());
}

TEST(Abuyaseen_Albaraa_tests, can_create_an_a_non_zero_number) {
  ComplexNumber sample(5.2, 2.3);

  EXPECT_EQ(5.2, sample.getRe());
  EXPECT_EQ(2.3, sample.getIm());
}

TEST(Abuyaseen_Albaraa_tests, can_copy_a_number) {
  ComplexNumber sample(5.2, 2.3);
  ComplexNumber sample_2(sample);

  EXPECT_EQ(sample_2.getRe(), sample.getRe());
  EXPECT_EQ(sample_2.getIm(), sample.getIm());
}

TEST(Abuyaseen_Albaraa_tests, can_assign) {
  ComplexNumber sample(5.2, 2.3);
  ComplexNumber sample_2;
  sample_2 = sample;

  EXPECT_EQ(sample_2.getRe(), sample.getRe());
  EXPECT_EQ(sample_2.getIm(), sample.getIm());
}

TEST(Abuyaseen_Albaraa_tests, can_sum) {
  ComplexNumber sample(5, 3.2);
  ComplexNumber sample_2(4, 1);
  ComplexNumber sample_3;
  sample_3 = sample + sample_2;

  EXPECT_EQ(9, sample_3.getRe());
  EXPECT_EQ(4.2, sample_3.getIm());
}
