// Copyright 2022 Kitaev Pavel

#include <iostream>
#include <string>

#include "include/myasnikova_pseudographics_app.h"

int main(int argc, const char** argv) {
  PseudographicsApplication P_app;
  std::string output = P_app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
