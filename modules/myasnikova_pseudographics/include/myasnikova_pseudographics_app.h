// Copyright 2022 Kitaev Pavel

#ifndef MODULES_MYASNIKOVA_PSEUDOGRAPHICS_INCLUDE_MYASNIKOVA_PSEUDOGRAPHICS_APP_H_
#define MODULES_MYASNIKOVA_PSEUDOGRAPHICS_INCLUDE_MYASNIKOVA_PSEUDOGRAPHICS_APP_H_

#include <string>
#include <sstream>

#include "include/myasnikova_pseudographics.h"

class PseudographicsApplication {
 public:
    PseudographicsApplication();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    std::string message_;
};

#endif  // MODULES_MYASNIKOVA_PSEUDOGRAPHICS_INCLUDE_MYASNIKOVA_PSEUDOGRAPHICS_APP_H_
