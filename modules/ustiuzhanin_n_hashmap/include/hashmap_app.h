// Copyright 2022 Pichugin Ilya

#ifndef MODULES_USTIUZHANIN_N_HASHMAP_INCLUDE_HASHMAP_APP_H_
#define MODULES_USTIUZHANIN_N_HASHMAP_INCLUDE_HASHMAP_APP_H_

#include <string>
#include <sstream>

#include "include/hashmap.h"

class HashmapApplication {
 public:
    HashmapApplication();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    std::string message_;
};

#endif  // MODULES_USTIUZHANIN_N_HASHMAP_INCLUDE_HASHMAP_APP_H_
