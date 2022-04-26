// Copyright 2022 Alimov Mikhail
#ifndef MODULES_ALIMOV_MIKE_CEACER_CIFIR_INCLUDE_ALIMOV_MIKE_CEACER_CIFIR_H_
#define MODULES_ALIMOV_MIKE_CEACER_CIFIR_INCLUDE_ALIMOV_MIKE_CEACER_CIFIR_H_

#include <string>
#include <vector>
using std::string;
using std::vector;

class CaesarCipher {
 public:
  string vvod;
  int offset;
  CaesarCipher();
  CaesarCipher(string vvod, int offset);
  string encrypt(string vvod, int offset);
  string decrypt(string vvod, int offset);

 private:
  const vector<string> alphabet = {
      "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
      "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
};

#endif  // MODULES_ALIMOV_MIKE_CEACER_CIFIR_INCLUDE_ALIMOV_MIKE_CEACER_CIFIR_H_
