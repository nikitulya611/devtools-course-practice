// Copyright 2022 Ustiuzhanin Nikita

#include <iostream>
#include <string>

#include "include/ratio_app.h"

int main(int argc, const char** argv) {
    RatioApplication app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
