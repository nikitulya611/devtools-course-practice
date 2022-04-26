// Copyright 2022 Yashin Kirill

#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "include/prime_numbers_application.h"

std::string PrimeNumbersApplication::getHelp(const std::string& appname) {
        return  "This is an application for finding prime numbers in range\n" \
        "Format for arguments:\n" +
        appname + " <left_border> <right_border> "
        "Where all arguments are positive integer more than 1." +
        "First argument must be less than second.";
}

std::string PrimeNumbersApplication::operator()(int argc, const char** argv) {
    int a, b;

    if (argc == 1)
        return getHelp(argv[0]);

    try {
        if (argc > 3) {
            std::string error_msg = "Error occured: ";
            error_msg += "Should be 2 arguments.\nYou entered more.\n";
            throw std::runtime_error(error_msg);
        }
        if (argc == 2) {
            std::string error_msg = "Error occured: ";
            error_msg += "Should be 2 arguments.\nYou entered one.\n";
            throw std::runtime_error(error_msg);
        }
        a = parseArgument(argv[1]);
        b = parseArgument(argv[2]);
        if (b < a) {
            std::string error_msg = "Error occured: ";
            error_msg += "First arg more than second.\n";
            throw std::runtime_error(error_msg);
        }
        if (a <= 1) {
            std::string error_msg = "Error occured: ";
            error_msg += "First arg <= 1.>\n";
            throw std::runtime_error(error_msg);
        }
        if (b <= 1) {
            std::string error_msg = "Error occured: ";
            error_msg += "Second arg <= 1.>\n";
            throw std::runtime_error(error_msg);
        }
    }
    catch (std::exception& exp) {
        return exp.what();
    }

    std::ostringstream oss;
    std::vector<int> prime = PrimeNumbers::getPrimeNumbers(a, b);
    if (!prime.empty()) {
        std::copy(prime.begin(), prime.end() - 1,
            std::ostream_iterator<int>(oss, " "));
        oss << prime.back();
    }
    return oss.str();
}

bool PrimeNumbersApplication::checkArgument(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int PrimeNumbersApplication::parseArgument(const char* arg) {
    if (!checkArgument(arg))
        throw std::runtime_error("Error occured: Wrong argument type.\n");
    return std::stoi(arg);
}
