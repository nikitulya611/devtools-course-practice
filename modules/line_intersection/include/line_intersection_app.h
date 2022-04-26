// Copyright 2022 Myasnikova Varvara

#ifndef MODULES_LINE_INTERSECTION_INCLUDE_LINE_INTERSECTION_APP_H_
#define MODULES_LINE_INTERSECTION_INCLUDE_LINE_INTERSECTION_APP_H_

#include <string>
#include <sstream>

#include "include/line_intersection.h"

class LineIntersectionApplication {
 public:
    LineIntersectionApplication();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    std::string message_;
};

#endif  // MODULES_LINE_INTERSECTION_INCLUDE_LINE_INTERSECTION_APP_H_
