// Copyright 2022 Myasnikova Varvara

#include <iostream>
#include <string>

#include "include/line_intersection_app.h"

int main(int argc, const char** argv) {
  LineIntersectionApplication LI_app;
  std::string output = LI_app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
