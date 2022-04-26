// Copyright 2022 Pichugin Ilya

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>

#include "include/hashmap.h"
#include "include/hashmap_app.h"

HashmapApplication::HashmapApplication() : message_("") {}

void HashmapApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a hashmap test application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <operation> <key / key value> ..." +
        "Where <key or value> is integer numbers, " +
        "and <operation> is one of 'INSERT', 'ERASE', 'READ'.\n";
}

std::string HashmapApplication::operator()(int argc, const char** argv) {
    if (argc == 1) {
        help("", "");
        return message_;
    }

    Hashmap<int, int> map;

    std::ostringstream stream;

    for (int i = 1; i < argc; i++) {
        std::string operation = argv[i];
        try {
            if (operation == "READ") {
                stream << "Reading by key \"" << argv[i+1] << "\": "
                    << map[std::stoi(argv[i+1])] << std::endl;
                i++;
            } else if (operation == "ERASE") {
                stream << "Erasing by key \"" << argv[i+1] << "\": "
                    << map[std::stoi(argv[i+1])] << std::endl;
                i++;
            } else if (operation == "INSERT") {
                map.insert(std::stoi(argv[i + 1]), std::stoi(argv[i + 2]));
                stream << "Inserting record, key \""
                    << argv[i+1] << "\", value "
                    << map[std::stoi(argv[i+1])] << std::endl;
                i += 2;
            } else {
                throw std::string("Wrong operation");
            }
        }
        catch (std::string& str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}
