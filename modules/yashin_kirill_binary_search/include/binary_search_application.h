// Copyright 2022 Yashin Kirill

#ifndef MODULES_YASHIN_KIRILL_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_APPLICATION_H_
#define MODULES_YASHIN_KIRILL_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_APPLICATION_H_

#include <string>

#include "include/binary_search.h"

class Application {
 private:
     std::string getHelp(const std::string& appname);
     bool checkArgument(const std::string& str);
     int parseArgument(const char* arg);
 public:
     std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_YASHIN_KIRILL_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_APPLICATION_H_
