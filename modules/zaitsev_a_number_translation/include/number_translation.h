// Copyright 2022 Zaitsev Alexander

#ifndef MODULES_ZAITSEV_A_NUMBER_TRANSLATION_INCLUDE_NUMBER_TRANSLATION_H_
#define MODULES_ZAITSEV_A_NUMBER_TRANSLATION_INCLUDE_NUMBER_TRANSLATION_H_

#include <map>
#include <string>
#include <vector>
class translating_a_number_in_a_word {
 public:
  std::string translating_a_number_into_a_word(const int& value);
  std::map<int, std::string> write_numbers();
  std::vector<int> digits_of_number(const int& number);
};
class translating_a_word_in_a_number {
 public:
  int translating_a_word_into_a_number(std::string word);
  std::map<std::string, int> write_words();
};
#endif  // MODULES_ZAITSEV_A_NUMBER_TRANSLATION_INCLUDE_NUMBER_TRANSLATION_H_
