// Copyright 2022 Ustiuzhanin Nikita

#include <string>
#include <sstream>

#include "include/ratio.h"
#include "include/ratio_app.h"

RatioApplication::RatioApplication() : message_("") {}

void RatioApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a ratio number calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <first_numerator> <first_denominator> " +
        "<second_numerator> <second_denominator> <operation>\n\n" +

        "Where all arguments are integer numbers, " +
        "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool RatioApplication::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string RatioApplication::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.first_numerator = parseInt(argv[1]);
        args.first_denominator = parseInt(argv[2]);
        args.second_numerator = parseInt(argv[3]);
        args.second_denominator = parseInt(argv[4]);
        args.operation = parseOperation(argv[5]);
    }
    catch (std::string& str) {
        return str;
    }

    Ratio first(args.first_numerator, args.first_denominator);
    Ratio second(args.second_numerator, args.second_denominator);

    Ratio result;
    std::ostringstream stream;

    switch (args.operation) {
    case '+':
        result = first + second;
        stream << "Numerator = " << result.get_numerator() << " "
            << "Denominator = " << result.get_denominator();
        break;
    case '-':
        result = first - second;
        stream << "Numerator = " << result.get_numerator() << " "
            << "Denominator = " << result.get_denominator();
        break;
    case '*':
        result = first * second;
        stream << "Numerator = " << result.get_numerator() << " "
            << "Denominator = " << result.get_denominator();
        break;
    case '/':
        try {
            result = first / second;
            stream << "Numerator = " << result.get_numerator() << " "
                << "Denominator = " << result.get_denominator();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}
