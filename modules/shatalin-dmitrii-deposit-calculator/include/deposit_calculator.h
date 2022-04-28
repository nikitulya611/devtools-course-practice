// Copyright 2022 Shatalin Dmitrii

#ifndef MODULES_SHATALIN_DMITRII_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_H_
#define MODULES_SHATALIN_DMITRII_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_H_
#include <vector>
#include <stdexcept>
#include <iostream>

class DepositCalculator{
 private:
     DepositCalculator();
 public:
     static double calculateDeposit(double amount, int years, double percent);
};

#endif  // MODULES_SHATALIN_DMITRII_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_H_
