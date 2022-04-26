// Copyright 2022 Novozhilov Alexandr

#include <gtest/gtest.h>
#include <vector>
#include "include/prime_numbers.h"

TEST(PrimeNumbersTest, throws_when_incorrect_parameters1) {
    ASSERT_ANY_THROW(PrimeNumbers::printPrimeNumbers(-2, -5));
}

TEST(PrimeNumbersTest, throws_when_incorrect_parameters2) {
    ASSERT_ANY_THROW(PrimeNumbers::printPrimeNumbers(10, 5));
}

TEST(PrimeNumbersTest, print_prime_numbers_works) {
    ASSERT_NO_THROW(PrimeNumbers::printPrimeNumbers(4, 10));
}

TEST(PrimeNumbersTest, get_throws_when_incorrect_parameters1) {
    ASSERT_ANY_THROW(PrimeNumbers::printPrimeNumbers(-2, -5));
}

TEST(PrimeNumbersTest, get_throws_when_incorrect_parameters2) {
    ASSERT_ANY_THROW(PrimeNumbers::printPrimeNumbers(10, 5));
}

TEST(PrimeNumbersTest, get_prime_numbers_works) {
    ASSERT_NO_THROW(PrimeNumbers::getPrimeNumbers(4, 10));
}

TEST(PrimeNumbersTest, get_prime_numbers_returns_correct_result) {
    std::vector<int> expectedResult;
    expectedResult.push_back(2);
    expectedResult.push_back(3);
    expectedResult.push_back(5);
    expectedResult.push_back(7);
    expectedResult.push_back(11);
    ASSERT_EQ(PrimeNumbers::getPrimeNumbers(0, 11), expectedResult);
}
