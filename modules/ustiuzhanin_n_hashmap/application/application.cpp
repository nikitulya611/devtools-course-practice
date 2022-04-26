// Copyright 2022 Pichugin Ilya

#include <iostream>
#include <string>

#include "include/hashmap_app.h"

int main(int argc, const char** argv) {
    HashmapApplication app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
