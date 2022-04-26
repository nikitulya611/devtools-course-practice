// Copyright 2022 Myasnikova Varvara

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/line_intersection.h"
#include "include/line_intersection_app.h"

LineIntersectionApplication::LineIntersectionApplication() : message_("") {}

std::string LineIntersectionApplication::operator()(int argc,
  const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return message_;
  } else if (argc != 9) {
    help(argv[0], "ERROR: Should be 8 arguments.\n\n");
    return message_;
  }

  double coords[8];
  std::ostringstream stream;

  for (int i = 1; i < argc; i++) {
    std::string argv_temp = argv[i];
    try {
      coords[i - 1] = std::stod(argv_temp);
    }
    catch (std::exception const& e) {
      help(argv[0], "Invalid argument!\n\n");
      return message_;
    }
  }

  bool res = LineIntersection::isCrossing(coords[0], coords[1], coords[2],
    coords[3], coords[4], coords[5], coords[6], coords[7]);

  if (res) {
    stream << "Straight lines intersect";
  } else {
    stream << "The lines don't intersect";
  }

  message_ = stream.str();
  return message_;
}

void LineIntersectionApplication::help(const char* appname,
  const char* message) {
  message_ =
    std::string(message) +
    "This is a LineIntersection test application.\n\n" +
    "Please provide arguments in the following format:\n\n" +
    "  $ " + appname + "\n" +
    "\t<x1_start> ... <y1_start> ... \n" +
    "\t<x1_end>   ... <y1_end>   ...\n" +
    "\t<x2_start> ... <y2_start> ...\n" +
    "\t<x2_end>   ... <y2_end>   ...\n\n" +
    "Where <x/y> is a double or integer coordinate.\n";
}
