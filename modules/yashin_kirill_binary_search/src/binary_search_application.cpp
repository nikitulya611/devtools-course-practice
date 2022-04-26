// Copyright 2022 Yashin Kirill

#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "include/binary_search_application.h"
#include "include/binary_search.h"

std::string Application::getHelp(const std::string& appname) {
    return  "This is an application to demonstrate"
        " the operation of the binary search algorithm\n"
        "Format for arguments:\n" +
        appname + " <element_to_find> \n"
        "Argument must be positive!\n"
        "Demo array - [1, 3, 5, 15, 46]";
}

std::string Application::operator()(int argc, const char** argv) {
    int numberToFind;
    int result;
    std::vector<int> demoArr { 1, 3, 5, 15, 46 };
    if (argc == 1)
        return getHelp(argv[0]);
    try {
        if (argc > 2) {
            std::string error_msg = "Error occured: ";
            error_msg += "Should be 1 argument.\nYou entered more!\n";
            throw std::runtime_error(error_msg);
        }
        numberToFind = parseArgument(argv[1]);
    }
    catch (std::exception& exp) {
        return exp.what();
    }

    BinarySearch<int> bs;
    result = bs.BinSearch(numberToFind, demoArr, 0, 4);

    std::ostringstream oss;
    oss << result;
    return oss.str();
}

bool Application::checkArgument(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int Application::parseArgument(const char* arg) {
    if (!checkArgument(arg))
        throw std::runtime_error("Error occured: Wrong argument type.\n");
    return std::stoi(arg);
}
