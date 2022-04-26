// Copyright 2022 Kitaev Pavel

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/myasnikova_pseudographics.h"
#include "include/myasnikova_pseudographics_app.h"

PseudographicsApplication::PseudographicsApplication() : message_("") {}

std::string PseudographicsApplication::operator()(int argc, const char** argv) {
  if (argc == 1) {
    help("", "");
    return message_;
  }

  Pseudographics P;
  std::ostringstream stream;

  for (int i = 1; i < argc; i++) {
    std::string num_temp = argv[i];
    try {
      int num = stoi(num_temp);
      stream << P.PrintPseudographics(num);
    }
    catch (std::exception const& e) {
      stream << "Invalid argument";
    }
  }

  message_ = stream.str();
  return message_;
}

void PseudographicsApplication::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is a pseudographics test application.\n\n" +
    "Please provide arguments in the following format:\n\n" +
    "  $ " + appname + " <number> ...\n\n" +
    "Where <number> is a positive integer.\n";
}
