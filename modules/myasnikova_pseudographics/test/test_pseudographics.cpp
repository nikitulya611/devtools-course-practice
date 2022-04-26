// Copyright 2022 Myasnikova Varvara

#include <gtest/gtest.h>
#include "include/myasnikova_pseudographics.h"

TEST(Pseudographics, CanPrint_1) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(1));
}

TEST(Pseudographics, CanPrint_2) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(2));
}

TEST(Pseudographics, CanPrint_3) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(3));
}

TEST(Pseudographics, CanPrint_4) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(4));
}

TEST(Pseudographics, CanPrint_5) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(5));
}

TEST(Pseudographics, CanPrint_6) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(6));
}

TEST(Pseudographics, CanPrint_7) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(7));
}

TEST(Pseudographics, CanPrint_8) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(8));
}

TEST(Pseudographics, CanPrint_9) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(9));
}

TEST(Pseudographics, CanPrint_0) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(0));
}

TEST(Pseudographics, CanPrintALotOfNumbers_1) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(12));
}

TEST(Pseudographics, CanPrintALotOfNumbers_2) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(123456789));
}

TEST(Pseudographics, CanPrintALotOfNumbers_3) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(102030));
}

TEST(Pseudographics, CanPrintALotOfNumbers_4) {
  Pseudographics p;
  ASSERT_NO_THROW(p.PrintPseudographics(223344));
}

TEST(Pseudographics, CannotPrintANegativeNumber) {
  Pseudographics p;
  ASSERT_EQ(p.PrintPseudographics(-10), "A negative number!");
}
