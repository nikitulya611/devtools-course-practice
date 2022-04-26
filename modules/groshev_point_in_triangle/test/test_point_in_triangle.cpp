// Copyright 2022 Groshev Nickolay
#include <gtest/gtest.h>
#include <tuple>
#include <string>

#include "include/point_in_triangle.h"

TEST(PointConstructor, Constructor_Without_Parameters) {
  ASSERT_NO_THROW(Point t);
}

TEST(PointConstructor, Constructor_With_Parameters) {
  ASSERT_NO_THROW(Point(5.0, 2.0));
}

TEST(PointConstructor, Constructor_With_Parameters_Can_Take_Minuses) {
  ASSERT_NO_THROW(Point(-5.0, 2.0));
}

TEST(PointConstructor, Can_Create_Point) {
  // Arrange
  Point a(3.0, 2.0);

  // Act & Assert
  ASSERT_TRUE(a.x == 3.0 && a.y == 2.0);
}

TEST(PointConstructor, Can_Create_Negative_Point) {
  // Arrange
  Point a(-3.0, -2.0);

  // Act & Assert
  ASSERT_TRUE(a.x == -3.0 && a.y == -2.0);
}

TEST(PointTest, Get_Coordinates_From_Default_Point) {
  // Arrange
  Point t;

  // Act & Assert
  ASSERT_TRUE((t.x == 0) && (t.y == 0));
}

TEST(PointTest, Get_Coordinates_From_Point) {
  // Arrange
  Point t(5.0, 2.0);

  // Act & Assert
  ASSERT_TRUE((t.x == 5.0) && (t.y == 2.0));
}

TEST(TriangleConstructor, Constructor_Without_Parameters) {
  ASSERT_NO_THROW(Triangle());
}

TEST(TriangleConstructor, Constructor_With_Parameters) {
  // Arrange
  Point a(-3.0, 0.0);
  Point b(3.0, 0.0);
  Point c(0.0, 3.0);

  // Act & Assert
  ASSERT_NO_THROW(Triangle(a, b, c));
}

TEST(TriangleConstructor, Constructor_With_Uncorrect_Parameters) {
  // Arrange
  Point a(3.0, 0.0);
  Point b(3.0, 0.0);
  Point c(0.0, 3.0);

  // Act & Assert
  ASSERT_ANY_THROW(Triangle(a, b, c));
}


TEST(TriangleConstructor, Constructor_Without_Parameters_Check_Default_Params) {
  // Arrange
  Triangle t;
  Point a(-3.0, 0.0);
  Point b(3.0, 0.0);
  Point c(0.0, 3.0);

  // Act & Assert
  ASSERT_TRUE(t.get_point_a() == a && t.get_point_b() == b &&
              t.get_point_c() == c);
}


TEST(PointTest, Correct_Comparison_Of_Two_Not_Equal_Points) {
  // Arrange
  Point a(1.0, 2.0);
  Point b(3.0, 4.0);

  // Act & Assert
  ASSERT_FALSE(a == b);
}

TEST(PointTest, Correct_Comparison_Of_Two_Equal_Points) {
  // Arrange
  Point a(1.0, 2.0);
  Point b(1.0, 2.0);

  // Act & Assert
  ASSERT_TRUE(a == b);
}

TEST(PointTest, Equal_Points_Are_Equal) {
  // Arrange
  Point a(1.0, 2.0);
  Point b(1.0, 2.0);

  // Act & Assert
  EXPECT_EQ(a, b);
}

TEST(PointTest, Equality_Operator) {
  // Arrange
  Point a(1.0, 2.0);
  Point b = a;

  // Act & Assert
  EXPECT_EQ(a, b);
}

TEST(PointTest, Correct_Params) {
  // Arrange
  Point a(1.0, 2.0);
  Point b = a;

  // Act & Assert
  ASSERT_TRUE(b.x == 1.0 && b.y == 2.0);
}


TEST(TrianglesTest, Throws_when_incorrect_points) {
  // Arrange
  Point a(1.0, 2.0);
  Point b(3.0, 4.0);
  Point c(5.0, 6.0);

  // Act & Assert
  ASSERT_ANY_THROW(Triangle(a, b, c));
}

TEST(TrianglesTest, Not_Throws_when_correct_points) {
  // Arrange
  Point a(-3.0, 0.0);
  Point b(3.0, 0.0);
  Point c(0.0, 3.0);

  // Act & Assert
  ASSERT_NO_THROW(Triangle(a, b, c));
}

TEST(TrianglesTest, Zero_Triangle_Is_No_Exist) {
  // Arrange
  Point a;
  Point b;
  Point c;

  // Act & Assert
  ASSERT_ANY_THROW(Triangle abc(a, b, c));
}

TEST(TrianglesTest, Get_points) {
  // Arrange
  Point a(-3.0, 0.0);
  Point b(3.0, 0.0);
  Point c(0.0, 3.0);
  Triangle t(a, b, c);

  // Act & Assert
  ASSERT_TRUE(t.get_point_a() == a && t.get_point_b() == b &&
              t.get_point_c() == c);
}

TEST(TrianglesTest, Normal_Triangle_Is_Exist) {
  // Arrange
  Point a(-3.0, 0.0);
  Point b(3.0, 0.0);
  Point c(0.0, 3.0);
  Triangle abc(a, b, c);

  // Act & Assert
  ASSERT_TRUE(abc.IsTriangleExist());
}


TEST(TrianglesTest, Correct_side_length) {
  // Arrange
  Point a(-3.0, 0.0);
  Point b(3.0, 0.0);
  Point c(0.0, 3.0);
  Triangle t(a, b, c);

  double length_ab = t.SideLength(a, b);
  double length_ac = t.SideLength(a, c);
  double length_bc = t.SideLength(b, c);


  // Act & Assert
  ASSERT_TRUE(length_ab == 6 && length_ac == length_bc);
}

TEST(PointInTriangle, Can_correctly_determine_point_in_triangle_positive ) {
  // Arrange
  Point a(-3.0, 0.0);
  Point b(3.0, 0.0);
  Point c(0.0, 3.0);
  Triangle t(a, b, c);

  Point currentPoint(0.0, 1.0);

  bool p = Triangle::IsPointInTriangle(t, currentPoint);
  // Act & Assert
  ASSERT_TRUE(p);
}

TEST(PointInTriangle, Can_correctly_determine_point_in_triangle_negative) {
  // Arrange
  Point a(-3.0, 0.0);
  Point b(3.0, 0.0);
  Point c(0.0, 3.0);
  Triangle t(a, b, c);

  Point currentPoint(0.0, 5.0);

  bool p = Triangle::IsPointInTriangle(t, currentPoint);
  // Act & Assert
  ASSERT_FALSE(p);
}

TEST(PointInTriangle, Point_in_triangle_with_minus_points) {
  // Arrange
  Point a(1.0, -4.0);
  Point b(4.0, -4.0);
  Point c(2.0, -1.0);
  Triangle t(a, b, c);

  Point currentPoint(2.0, -1.0);

  bool p = Triangle::IsPointInTriangle(t, currentPoint);
  // Act & Assert
  ASSERT_TRUE(p);
}

TEST(PointInTriangle, Point_in_triangle_second_case) {
  // Arrange
  Point a(-6.0, 0.0);
  Point b(-6.0, 4.0);
  Point c(-2.0, 0.0);
  Triangle t(a, b, c);

  Point currentPoint(-5.0, 1.0);

  bool p = Triangle::IsPointInTriangle(t, currentPoint);
  // Act & Assert
  ASSERT_TRUE(p);
}

TEST(PointInTriangle, Point_in_triangle_second_case_two) {
  // Arrange
  Point a(-6.0, -1.0);
  Point b(-2.0, -1.0);
  Point c(-6.0, -5.0);
  Triangle t(a, b, c);

  Point currentPoint(-5.0, -2.0);

  bool p = Triangle::IsPointInTriangle(t, currentPoint);
  // Act & Assert
  ASSERT_TRUE(p);
}
