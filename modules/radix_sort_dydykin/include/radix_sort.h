// Copyright 2022 Dydykin Pavel

#ifndef MODULES_RADIX_SORT_DYDYKIN_INCLUDE_RADIX_SORT_H_
#define MODULES_RADIX_SORT_DYDYKIN_INCLUDE_RADIX_SORT_H_
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

class RadixSort {
 public:
     static std::vector<double> Get_Random_Vector(int size);
     static int LeftOfThePoint(double number);
     static int RightOfThePoint(double number);
     static int GetDigit(double number, int radix);
     static std::vector<double>
         SortByOneRadix(const std::vector<double>& vect, int rad);
     static std::vector<double> Radix_Sort(const std::vector<double>& vect);
};

#endif  // MODULES_RADIX_SORT_DYDYKIN_INCLUDE_RADIX_SORT_H_
