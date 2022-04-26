// Copyright 2022 Kuklin Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(class_ComplexNumber, can_create_complex_number) {
  ASSERT_NO_THROW(ComplexNumber());
}

TEST(class_ComplexNumber, can_create_complex_with_selected_params) {
  ASSERT_NO_THROW(ComplexNumber(0., 0.));
}

TEST(class_ComplexNumber, can_create_complex_with_other_params) {
  ASSERT_NO_THROW(ComplexNumber(4.1, 4.5));
}

TEST(class_ComplexNumber, can_create_complex_by_copy) {
  ComplexNumber a(2.0, 2.0);
  ASSERT_NO_THROW(ComplexNumber(a));
}

TEST(class_ComplexNumber, can_take_real_from_complex) {
  ComplexNumber a(3.0, 3.0);
  ASSERT_NO_THROW(a.getRe());
}

TEST(class_ComplexNumber, taken_real_is_equal_to_complex_real) {
  ComplexNumber a(3.0, 3.0);
  ASSERT_DOUBLE_EQ(a.getRe(), 3.0);
}

TEST(class_ComplexNumber, can_take_imaginary_from_complex) {
  ComplexNumber a(4.0, 4.0);
  ASSERT_NO_THROW(a.getIm());
}

TEST(class_ComplexNumber, taken_real_is_equal_to_complex_imaginary) {
  ComplexNumber a(4.0, 4.0);
  ASSERT_DOUBLE_EQ(a.getIm(), 4.0);
}

TEST(class_ComplexNumber, copied_complex_equal_to_source_complex) {
  ComplexNumber a(2.0, 2.0);
  ComplexNumber b(a);

  ASSERT_DOUBLE_EQ(a.getRe(), b.getRe());
  ASSERT_DOUBLE_EQ(a.getIm(), b.getIm());
}

TEST(class_ComplexNumber, can_set_real_for_complex) {
  ComplexNumber a;
  ASSERT_NO_THROW(a.setRe(5.0));
}

TEST(class_ComplexNumber, set_real_is_equal_to_complex_real) {
  ComplexNumber a;
  a.setRe(3.0);
  ASSERT_DOUBLE_EQ(a.getRe(), 3.0);
}

TEST(class_ComplexNumber, can_set_imaginary_for_complex) {
  ComplexNumber a;
  ASSERT_NO_THROW(a.setIm(5.0));
}

TEST(class_ComplexNumber, set_imaginary_is_equal_to_complex_real) {
  ComplexNumber a;
  a.setIm(4.0);
  ASSERT_DOUBLE_EQ(a.getIm(), 4.0);
}

TEST(class_ComplexNumber, can_assign_complex_to_another_complex) {
  ComplexNumber a, b;
  ASSERT_NO_THROW(b = a);
}

TEST(class_ComplexNumber, assigned_complex_equal_source_complex) {
  ComplexNumber a(2.0, 2.0), b;
  b = a;

  ASSERT_DOUBLE_EQ(a.getRe(), b.getRe());
  ASSERT_DOUBLE_EQ(a.getIm(), b.getIm());
}
