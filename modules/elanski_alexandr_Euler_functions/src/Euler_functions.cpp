  // Copyright 2022 Elanskiy Alexandr

#include "include/Euler_functions.h"
#include <gtest/gtest.h>
#include <utility>

int class_for_fun::Function_Euler(int number) {
    int result = number;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            while (number % i == 0) {
                number /= i;
            }
            result -= result / i;
        }
    }
    if (number > 1) {
        result -= result / number;
    }
    return result;
}
