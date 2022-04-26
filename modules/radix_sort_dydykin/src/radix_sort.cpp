// Copyright 2022 Dydykin Pavel

#include <vector>
#include <string>

#include "include/radix_sort.h"

std::vector<double> RadixSort::Get_Random_Vector(int size) {
    std::mt19937 gen(time(0));
    std::uniform_real_distribution<> urd(0, 10000);
    std::vector<double> vector(size);
    for (int i = 0; i < static_cast<int>(vector.size()); i++) {
        vector[i] = urd(gen);
    }
    return vector;
}

int RadixSort::LeftOfThePoint(double number) {
    int radix = 0;
    while (number > 1) {
        number = number / 10;
        radix++;
    }
    return radix;
}

int RadixSort::RightOfThePoint(double number) {
    std::ostringstream strs;
    strs << number;
    std::string str = strs.str();
    int size = str.size();
    int pos = str.find('.');
    int value = size - pos - 1;
    return value;
}

int RadixSort::GetDigit(double number, int radix) {
    if (radix > 0) {
        double mask = pow(10, radix);
        double tmp = number / mask;
        return static_cast<int>(tmp) % 10;
    }
    return  static_cast<int>(number * pow(10, -radix)) % 10;
}

std::vector<double> RadixSort::SortByOneRadix
    (const std::vector<double>& vect, int rad) {
    std::vector<double> res;
    std::vector <std::vector<double>> radix(10);

    for (int i = 0; i < static_cast<int>(vect.size()); i++) {
        radix[GetDigit(vect[i], rad)].push_back(vect[i]);
    }
    for (int i = 0; i < static_cast<int>(radix.size()); ++i)
        for (int j = 0; j < static_cast<int>(radix[i].size()); ++j)
            res.push_back(radix[i][j]);
    return res;
}

std::vector<double> RadixSort::Radix_Sort(const std::vector<double>& vect) {
    int size = vect.size();
    int maxRadixNegativeZero = RightOfThePoint(vect[0]);
    for (int i = 1; i < size; ++i) {
        int radixNegativeZero = 0;
        radixNegativeZero = RightOfThePoint(vect[i]);
        if (radixNegativeZero > maxRadixNegativeZero) {
            maxRadixNegativeZero = radixNegativeZero;
        }
    }
    double max_elem = vect[0];
    for (int i = 1; i < size; i++) {
        if (vect[i] > max_elem) {
            max_elem = vect[i];
        }
    }
    int maxRadixPositiveZero = LeftOfThePoint(max_elem);
    std::vector<double> result(vect);
    for (int i = -maxRadixNegativeZero; i <= maxRadixPositiveZero; i++) {
        result = SortByOneRadix(result, i);
    }
    return result;
}
