// Copyright 2022 Yashin Kirill

#ifndef MODULES_NOVOZHILOV_ALEXANDR_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_APPLICATION_H_
#define MODULES_NOVOZHILOV_ALEXANDR_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_APPLICATION_H_

#include <string>

#include "include/prime_numbers.h"

class PrimeNumbersApplication {
 private:
     std::string getHelp(const std::string& appname);
     bool checkArgument(const std::string& str);
     int parseArgument(const char* arg);
 public:
     std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_NOVOZHILOV_ALEXANDR_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_APPLICATION_H_
