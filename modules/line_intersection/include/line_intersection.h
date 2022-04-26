// Copyright 2022 Kitaev Pavel

#ifndef MODULES_LINE_INTERSECTION_INCLUDE_LINE_INTERSECTION_H_
#define MODULES_LINE_INTERSECTION_INCLUDE_LINE_INTERSECTION_H_

class LineIntersection {
 private:
    LineIntersection();
 public:
    static bool isCrossing(double x1_start, double y1_start, double x1_end,
      double y1_end, double x2_start, double y2_start,
      double x2_end, double y2_end);
};

#endif  // MODULES_LINE_INTERSECTION_INCLUDE_LINE_INTERSECTION_H_
