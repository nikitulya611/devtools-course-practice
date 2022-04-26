// Copyright 2022 Dydykin Pavel

#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

#include "include/radix_sort.h"

TEST(Dydykin_Pavel_Radix_Sort, Test_Get_Random_Array) {
    int size = 100;
    ASSERT_NO_THROW(RadixSort::Get_Random_Vector(size));
}

TEST(Dydykin_Pavel_Radix_Sort, Test_NumberOfPositiveRadix) {
    double number = 142646.345;
    EXPECT_EQ(RadixSort::LeftOfThePoint(number), 6);
}

TEST(Dydykin_Pavel_Radix_Sort, Test_NumberOfNegativeRadix) {
    double number = 345645.345236;
    EXPECT_EQ(RadixSort::RightOfThePoint(number), 6);
}

TEST(Dydykin_Pavel_Radix_Sort, Test_GetDigit) {
    double number = 473.5;

    int a = RadixSort::GetDigit(number, -1);
    int b = RadixSort::GetDigit(number, 0);
    int c = RadixSort::GetDigit(number, 1);
    int d = RadixSort::GetDigit(number, 2);

    EXPECT_EQ(a, 5);
    EXPECT_EQ(b, 3);
    EXPECT_EQ(c, 7);
    EXPECT_EQ(d, 4);
}

TEST(Dydykin_Pavel_Radix_Sort, Test_SortByOneRadix) {
     std::vector<double> vect = { 0.1, 0.6, 0.3, 0.9, 0.2 };
     std::vector<double> result = { 0.1, 0.2, 0.3, 0.6, 0.9 };
     std::vector<double> sorted = RadixSort::SortByOneRadix(vect, -1);
     EXPECT_EQ(sorted, result);
}

TEST(Dydykin_Pavel_Radix_Sort, Test_Little_Radix_Sort_Double) {
     std::vector<double> v(50);
     v = RadixSort::Get_Random_Vector(50);

     std::vector<double> tmp = RadixSort::Radix_Sort(v);
     std::sort(v.begin(), v.end());
     ASSERT_EQ(tmp, v);
}

TEST(Dydykin_Pavel_Radix_Sort, Test_Middle_Radix_Sort_Double) {
    std::vector<double> v(1000);
    v = RadixSort::Get_Random_Vector(1000);

    std::vector<double> tmp = RadixSort::Radix_Sort(v);
    std::sort(v.begin(), v.end());
    ASSERT_EQ(tmp, v);
}
