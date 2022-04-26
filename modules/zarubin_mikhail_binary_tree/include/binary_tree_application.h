// Copyright 2022 Chornyi Yura

#ifndef MODULES_ZARUBIN_MIKHAIL_BINARY_TREE_INCLUDE_BINARY_TREE_APPLICATION_H_
#define MODULES_ZARUBIN_MIKHAIL_BINARY_TREE_INCLUDE_BINARY_TREE_APPLICATION_H_

#include <string>
#include <vector>

enum class ConsoleOperation { Add, Delete, Find };

class BinaryTreeApplication {
 public:
  BinaryTreeApplication();

  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateArguments(int argc, const char** argv);

  std::string m_message;
};

#endif  // MODULES_ZARUBIN_MIKHAIL_BINARY_TREE_INCLUDE_BINARY_TREE_APPLICATION_H_
