// Copyright 2022 Novozhilov Alexandr

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/binary_search_application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
