// Copyright 2022 Kitaev Pavel

#include "include/line_intersection.h"

bool LineIntersection::isCrossing(double x1_start, double y1_start,
  double x1_end, double y1_end, double x2_start, double y2_start,
  double x2_end, double y2_end) {
  bool res = false;

  double den = (y2_end - y2_start) * (x1_start - x1_end) -
    (x2_end - x2_start) * (y1_start - y1_end);
  if (den == 0) {
    if ((x1_start * y1_end - x1_end * y1_start) * (x2_end - x2_start) -
      (x2_start * y2_end - x2_end * y2_start) * (x1_end - x1_start) == 0 &&
      (x1_start * y1_end - x1_end * y1_start) * (y2_end - y2_start) -
      (x2_start * y2_end - x2_end * y2_start) * (y1_end - y1_start) == 0) {
      res = true;
    }
  } else {
    double num_a = (x2_end - x1_end) * (y2_end - y2_start) -
      (x2_end - x2_start) * (y2_end - y1_end);
    double num_b = (x1_start - x1_end) * (y2_end - y1_end) -
      (x2_end - x1_end) * (y1_start - y1_end);
    double Ua = num_a / den;
    double Ub = num_b / den;
    Ua >= 0 && Ua <= 1 && Ub >= 0 && Ub <= 1 ? (res = true) : (res = false);
  }

  return res;
}
