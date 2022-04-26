// Copyright 2022 Groshev Nickolay

#ifndef MODULES_GROSHEV_POINT_IN_TRIANGLE_INCLUDE_POINT_IN_TRIANGLE_H_
#define MODULES_GROSHEV_POINT_IN_TRIANGLE_INCLUDE_POINT_IN_TRIANGLE_H_

struct Point {
  double x, y;

  explicit Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

  Point& operator=(const Point& point) = default;

  bool operator==(const Point& point) const {
    if ((this->x == point.x) && (this->y == point.y)) {
      return true;
    } else {
      return false;
    }
  }
};

class Triangle {
 private:
  Point a, b, c;
  double ab = 0, bc = 0, ac = 0;

 public:
  Triangle();
  Triangle(Point _a, Point _b, Point _c);
  double SideLength(Point _a, Point _b);
  bool IsTriangleExist();

static bool IsPointInTriangle(Triangle t, Point currentPoint);

  Point get_point_a() const;
  Point get_point_b() const;
  Point get_point_c() const;
};

#endif  // MODULES_GROSHEV_POINT_IN_TRIANGLE_INCLUDE_POINT_IN_TRIANGLE_H_
