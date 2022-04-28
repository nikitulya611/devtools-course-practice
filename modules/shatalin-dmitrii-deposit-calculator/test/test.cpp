// Copyright 2022 Shatalin Dmitrii

#include <gtest/gtest.h>
#include <vector>
#include "include/deposit_calculator.h"

TEST(DepositCalculatorTest, DepositCalculatorWorks) {
    ASSERT_NO_THROW(DepositCalculator::calculateDeposit(1.0, 1, 1.0));
}

TEST(DepositCalculatorTest, DepositCalculatorThrows1) {
    ASSERT_ANY_THROW(DepositCalculator::calculateDeposit(-1.0, 1, 1.0));
}

TEST(DepositCalculatorTest, DepositCalculatorThrows2) {
    ASSERT_ANY_THROW(DepositCalculator::calculateDeposit(1.0, -1, 1.0));
}

TEST(DepositCalculatorTest, DepositCalculatorThrows3) {
    ASSERT_ANY_THROW(DepositCalculator::calculateDeposit(1.0, 1, -1.0));
}

TEST(DepositCalculatorTest, DepositCalculatorReturnsCorrectResult) {
    ASSERT_DOUBLE_EQ(110.0,
        DepositCalculator::calculateDeposit(100.0, 1, 10.0));
}

TEST(DepositCalculatorTest, DepositCalculatorReturnsCorrectResult2) {
    ASSERT_DOUBLE_EQ(130.0,
        DepositCalculator::calculateDeposit(100.0, 3, 10.0));
}
