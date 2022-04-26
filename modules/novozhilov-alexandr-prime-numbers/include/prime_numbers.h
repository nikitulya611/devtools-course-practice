// Copyright 2022 Novozhilov Alexandr

#ifndef MODULES_NOVOZHILOV_ALEXANDR_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_H_
#define MODULES_NOVOZHILOV_ALEXANDR_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_H_
#include <vector>
#include <stdexcept>
#include <iostream>

class PrimeNumbers {
 private:
    PrimeNumbers();
 public:
    static std::vector<int> getPrimeNumbers(int from, int to);
    static void printPrimeNumbers(int from, int to);
};

#endif  // MODULES_NOVOZHILOV_ALEXANDR_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_H_
