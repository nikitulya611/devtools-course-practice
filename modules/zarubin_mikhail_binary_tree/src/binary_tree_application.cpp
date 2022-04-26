// Copyright 2022 Chornyi Yura

#include "include/binary_tree_application.h"
#include "include/binary_tree.h"

#include <string.h>
#include <sstream>
#include <string>
#include <vector>

BinaryTreeApplication::BinaryTreeApplication() : m_message() {}

void BinaryTreeApplication::help(const char* appname, const char* message) {
  std::ostringstream stream;
  stream << message << "This is a binary tree application.\n\n"
         << "Please provide arguments in the following format:\n\n"
         <<

      "  $ " << appname << " <value_or_values> "
         << "<operation> <operand>\n\n"
         <<

      "Where all arguments are integer numbers, "
         << "and <operation> is one of 'add', 'delete', 'find'.\n";

  m_message = stream.str();
}

bool isOnlyCharacter(const std::string& str) {
  return str.find_first_of("0123456789") == std::string::npos;
}

bool validateTypeOfArguments(int argc, const char** argv) {
  bool result = false;
  bool operationFinded = false;
  for (int i = 1; i < argc; ++i) {
    if (operationFinded) {
      if ((i + 1) == argc && !isOnlyCharacter(argv[i])) {
        result = true;
      }
    }

    if (isOnlyCharacter(argv[i])) {
      if (i + 2 == argc) {
        operationFinded = true;
      }
    }
  }

  return result;
}

bool BinaryTreeApplication::validateArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc < 4) {
    help(argv[0], "ERROR: Should be at least 4 arguments.\n\n");
    return false;
  }

  if (!validateTypeOfArguments(argc, argv)) {
    help(argv[0]);
    return false;
  }

  return true;
}

double tryParseToInt(const char* arg) {
  int result = 0;

  try {
    result = std::stoi(arg);
  } catch (const std::invalid_argument& e) {
    throw std::string("ERROR: Cannot be cast to an integer!");
  } catch (const std::out_of_range& e) {
    throw std::string("ERROR : Number out of range!");
  }

  return result;
}

ConsoleOperation tryParseToOperation(const char* arg) {
  ConsoleOperation operation;

  if (strcmp(arg, "add") == 0) {
    operation = ConsoleOperation::Add;
  } else if (strcmp(arg, "delete") == 0) {
    operation = ConsoleOperation::Delete;
  } else if (strcmp(arg, "find") == 0) {
    operation = ConsoleOperation::Find;
  } else {
    throw std::string("ERROR: Wrong operation!");
  }

  return operation;
}

std::string BinaryTreeApplication::operator()(int argc, const char** argv) {
  if (!validateArguments(argc, argv)) {
    return m_message;
  }

  std::vector<int> vectorOfValues;
  ConsoleOperation operation;
  int operand;

  try {
    for (int i = 1; i < argc - 2; ++i) {
      vectorOfValues.push_back(tryParseToInt(argv[i]));
    }

    operation = tryParseToOperation(argv[argc - 2]);
    operand = tryParseToInt(argv[argc - 1]);
  } catch (const std::string& stringException) {
    return stringException;
  }

  std::ostringstream stream;
  BinaryTree tree(vectorOfValues);
  switch (operation) {
    case ConsoleOperation::Add:
      tree.insertByValue(operand);
      stream << "Operand " << operand << " was added!\n";
      break;
    case ConsoleOperation::Delete:
      tree.deleteByValue(operand);
      stream << "Operand " << operand << " was deleted!\n";
      break;
    case ConsoleOperation::Find:
      bool isFind = tree.findByValue(operand);
      stream << "Operand " << operand
             << (isFind ? " was founded!\n" : " not founded!\n");
      break;
  }

  m_message = stream.str();
  return m_message;
}
