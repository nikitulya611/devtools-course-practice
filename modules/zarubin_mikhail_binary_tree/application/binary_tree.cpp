// Copyright 2022 Chornyi Yura

#include <iostream>
#include <string>

#include "include/binary_tree_application.h"

int main(int argc, const char** argv) {
  BinaryTreeApplication app;
  std::string output = app(argc, argv);
  std::cout << output;
  return 0;
}
