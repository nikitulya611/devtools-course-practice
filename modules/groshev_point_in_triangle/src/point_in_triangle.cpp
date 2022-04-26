// Copyright 2022 Groshev Nickolay

#include "include/point_in_triangle.h"
#include <math.h>
#include <string>


double Triangle::SideLength(Point _a, Point _b) {
  return sqrt(pow((_b.x - _a.x), 2) + pow((_b.y - _a.y), 2));
}

Triangle::Triangle() : a(-3.0, 0.0), b(3.0, 0.0), c(0.0, 3.0) {
  ab = SideLength(a, b);
  bc = SideLength(b, c);
  ac = SideLength(a, c);
}

Triangle::Triangle(Point _a, Point _b, Point _c) : a(_a), b(_b), c(_c) {
  ab = SideLength(a, b);
  bc = SideLength(b, c);
  ac = SideLength(a, c);

  if (!IsTriangleExist()) {
    throw std::string("Triangle does not exist");
  }
}



bool Triangle::IsTriangleExist() {
  return (ab + bc > ac) && (ab + ac > bc) && (bc + ac > ab) ? true : false;
}

Point Triangle::get_point_a() const { return a; }

Point Triangle::get_point_b() const { return b; }

Point Triangle::get_point_c() const { return c; }

bool Triangle::IsPointInTriangle(Triangle t, Point currentPoint) {
    Point a = t.get_point_a();
    Point b = t.get_point_b();
    Point c = t.get_point_c();

    double x0 = currentPoint.x;
    double y0 = currentPoint.y;

    double x1 = a.x;
    double y1 = a.y;

    double x2 = b.x;
    double y2 = b.y;

    double x3 = c.x;
    double y3 = c.y;

    double a_mult = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    double b_mult = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    double c_mult = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);

    if ((a_mult >= 0 && b_mult >= 0 && c_mult >= 0) ||
        (a_mult <= 0 && b_mult <= 0 && c_mult <= 0)) {
      return true;
    } else {
      return false;
  }
}
