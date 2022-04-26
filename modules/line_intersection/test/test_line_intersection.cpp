// Copyright 2022 Kitaev Pavel

#include <gtest/gtest.h>
#include "include/line_intersection.h"

TEST(Line_Intersection, Long_Lines_Intersection) {
  bool res = LineIntersection::isCrossing(10.5, 10, 1, 1, 5, 9, 2, 0);
  ASSERT_EQ(res, true);
}

TEST(Line_Intersection, Short_Lines_Intersection) {
  bool res = LineIntersection::isCrossing(0, 0, 1, 1, 0, 1, 1, 0);
  ASSERT_EQ(res, true);
}

TEST(Line_Intersection, Long_Lines_Intersection_Do_Not_Intersect) {
  bool res = LineIntersection::isCrossing(0, 10, 10, 0, 11, 11, 15.5, 0);
  ASSERT_EQ(res, false);
}

TEST(Line_Intersection, Short_Lines_Intersection_Do_Not_Intersect) {
  bool res = LineIntersection::isCrossing(0, 0, 1, 1, 3, 3, 4, 0);
  ASSERT_EQ(res, false);
}

TEST(Line_Intersection, Points) {
  bool res = LineIntersection::isCrossing(0, 0, 0, 0, 0, 0, 0, 0);
  ASSERT_EQ(res, true);
}

TEST(Line_Intersection, NoThrow) {
  ASSERT_NO_THROW(LineIntersection::isCrossing(0, 0, 0, 0, 0, 0, 0, 0));
}

TEST(Line_Intersection, Superimposed_Lines) {
  bool res = LineIntersection::isCrossing(0, 0, 10, 10, 0, 0, 10, 10);
  ASSERT_EQ(res, true);
}

TEST(Line_Intersection, Double_Point_1) {
  bool res = LineIntersection::isCrossing(17.8, 14.3, 2.7, 4.6, 28.19,
    45.1, 20.23, 23.91);
  ASSERT_EQ(res, false);
}

TEST(Line_Intersection, Double_Point_2) {
  bool res = LineIntersection::isCrossing(1.1, 1.1, 20.2, 20.20, 1.1,
    20.20, 40.40, 1.1);
  ASSERT_TRUE(res);
}

TEST(Line_Intersection, Double_Point_3) {
  bool res = LineIntersection::isCrossing(18.19, 0.0, 2.2, 20.20, 10.8,
    12.0, 10.7, 40.12);
  ASSERT_FALSE(res);
}
