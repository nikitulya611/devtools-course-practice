// Copyright 2022 Novozhilov Alexandr
#include <vector>
#include "include/prime_numbers.h"

std::vector<int> PrimeNumbers::getPrimeNumbers(int from, int to) {
    if (to < from || from < 0 || to < 2) {
        throw std::invalid_argument("Enter the correct parameters!");
    }
    std::vector<int> result;
    std::vector<bool> prime(to + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= to; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= to; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = from; i < static_cast<int>(prime.size()); i++) {
        if (prime[i]) {
            result.push_back(i);
        }
    }
    return result;
}

void PrimeNumbers::printPrimeNumbers(int from, int to) {
    std::vector<int> primeNumbers = getPrimeNumbers(from, to);
    std::cout << "Prime numbers from: " << from << "  to: " << to << std::endl;
    std::cout << "[ ";
    for (int i = 0; i < static_cast<int>(primeNumbers.size()); i++) {
        std::cout << primeNumbers[i] <<" ";
    }
    std::cout << " ]";
    std::cout << std::endl;
}
