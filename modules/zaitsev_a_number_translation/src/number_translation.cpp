// Copyright 2022 Zaitsev Alexander

#include "./include/number_translation.h"

#include <cmath>
#include <map>
#include <string>
#include <vector>

std::map<int, std::string> translating_a_number_in_a_word::write_numbers() {
  std::map<int, std::string> map;
  map.insert(std::make_pair(0, ""));
  map.insert(std::make_pair(1, "one"));
  map.insert(std::make_pair(2, "two"));
  map.insert(std::make_pair(3, "three"));
  map.insert(std::make_pair(4, "four"));
  map.insert(std::make_pair(5, "five"));
  map.insert(std::make_pair(6, "six"));
  map.insert(std::make_pair(7, "seven"));
  map.insert(std::make_pair(8, "eight"));
  map.insert(std::make_pair(9, "nine"));
  map.insert(std::make_pair(10, "ten"));
  map.insert(std::make_pair(11, "eleven"));
  map.insert(std::make_pair(12, "twelve"));
  map.insert(std::make_pair(13, "thirteen"));
  map.insert(std::make_pair(14, "fourteen"));
  map.insert(std::make_pair(15, "fifteen"));
  map.insert(std::make_pair(16, "sixteen"));
  map.insert(std::make_pair(17, "seventeen"));
  map.insert(std::make_pair(18, "eighteen"));
  map.insert(std::make_pair(19, "nineteen"));
  map.insert(std::make_pair(20, "twenty"));
  map.insert(std::make_pair(30, "thirty"));
  map.insert(std::make_pair(40, "fourty"));
  map.insert(std::make_pair(50, "fifty"));
  map.insert(std::make_pair(60, "sixty"));
  map.insert(std::make_pair(70, "seventy"));
  map.insert(std::make_pair(80, "eighty"));
  map.insert(std::make_pair(90, "ninety"));
  map.insert(std::make_pair(100, "hundred"));
  map.insert(std::make_pair(1000, "thousand"));
  return map;
}
std::map<std::string, int> translating_a_word_in_a_number::write_words() {
  std::map<std::string, int> map;
  map.insert(std::make_pair("", 0));
  map.insert(std::make_pair("one", 1));
  map.insert(std::make_pair("two", 2));
  map.insert(std::make_pair("three", 3));
  map.insert(std::make_pair("four", 4));
  map.insert(std::make_pair("five", 5));
  map.insert(std::make_pair("six", 6));
  map.insert(std::make_pair("seven", 7));
  map.insert(std::make_pair("eight", 8));
  map.insert(std::make_pair("nine", 9));
  map.insert(std::make_pair("ten", 10));
  map.insert(std::make_pair("eleven", 11));
  map.insert(std::make_pair("twelve", 12));
  map.insert(std::make_pair("thirteen", 13));
  map.insert(std::make_pair("fourteen", 14));
  map.insert(std::make_pair("fifteen", 15));
  map.insert(std::make_pair("sixteen", 16));
  map.insert(std::make_pair("seventeen", 17));
  map.insert(std::make_pair("eighteen", 18));
  map.insert(std::make_pair("nineteen", 19));
  map.insert(std::make_pair("twenty", 20));
  map.insert(std::make_pair("thirty", 30));
  map.insert(std::make_pair("fourty", 40));
  map.insert(std::make_pair("fifty", 50));
  map.insert(std::make_pair("sixty", 60));
  map.insert(std::make_pair("seventy", 70));
  map.insert(std::make_pair("eighty", 80));
  map.insert(std::make_pair("ninety", 90));
  map.insert(std::make_pair("hundred", 100));
  map.insert(std::make_pair("thousand", 1000));
  return map;
}
std::vector<int> translating_a_number_in_a_word::digits_of_number(
    const int& number) {
  std::vector<int> digits_of_number;
  int tmp = number;
  do {
    digits_of_number.push_back(tmp % 10);
    tmp /= 10;
  } while (tmp > 0);
  return digits_of_number;
}
std::string translating_a_number_in_a_word::translating_a_number_into_a_word(
    const int& value) {
  std::string word = "";
  int number = value;
  if (value < 0) {
    word += "minus ";
    number *= (-1);
  }
  std::map<int, std::string> digit(write_numbers());
  std::vector<int> rangs_of_digit(digits_of_number(number));
  for (int i = rangs_of_digit.size() - 1; i >= 0; i--) {
    if (i > 3) {
      if (rangs_of_digit[i] > 0 && i - 3 == 2) {
        if (rangs_of_digit[i - 1] * std::pow(10, i - 1 - 3) +
                    rangs_of_digit[i - 2] >
                10 &&
            rangs_of_digit[i - 1] * std::pow(10, i - 1 - 3) +
                    rangs_of_digit[i - 2] <
                20) {
          word += digit[rangs_of_digit[i]] + " " + digit[std::pow(10, i - 3)] +
                  " " +
                  digit[rangs_of_digit[i - 1] * std::pow(10, i - 1 - 3) +
                        rangs_of_digit[i - 2]] +
                  " " + digit[std::pow(10, 3)] + " ";
        } else {
          word +=
              digit[rangs_of_digit[i]] + " " + digit[std::pow(10, i - 3)] +
              " " + digit[rangs_of_digit[i - 1] * std::pow(10, (i - 1) - 3)] +
              " " + digit[rangs_of_digit[i - 2] * std::pow(10, (i - 2) - 3)] +
              " " + digit[std::pow(10, 3)] + " ";
        }
        i = 2;
      } else if (rangs_of_digit[i] > 0 && i - 3 == 1) {
        if (rangs_of_digit[i] * std::pow(10, i - 3) + rangs_of_digit[i - 1] >
                10 &&
            rangs_of_digit[i] * std::pow(10, i - 3) + rangs_of_digit[i - 1] <
                20) {
          word += digit[rangs_of_digit[i] * std::pow(10, i - 3) +
                        rangs_of_digit[i - 1]] +
                  " " + digit[std::pow(10, 3)] + " ";
        } else {
          word += digit[rangs_of_digit[i] * std::pow(10, i - 3)] + " " +
                  digit[rangs_of_digit[i - 1]] + " " + digit[std::pow(10, 3)] +
                  " ";
        }
        i = 2;
      }
    }
    if (i > 1) {
      if (rangs_of_digit[i] > 0) {
        word += digit[rangs_of_digit[i]] + " " + digit[std::pow(10, i)] + " ";
      }
    }
    if (i == 1) {
      if (rangs_of_digit[i] * std::pow(10, i) + rangs_of_digit[i - 1] > 10 &&
          rangs_of_digit[i] * std::pow(10, i) + rangs_of_digit[i - 1] < 20) {
        word +=
            digit[rangs_of_digit[i] * std::pow(10, i) + rangs_of_digit[i - 1]] +
            " ";
        break;
      } else {
        word += digit[rangs_of_digit[i] * std::pow(10, i)] + " " +
                digit[rangs_of_digit[i - 1]];
        break;
      }
    }
    if (i == 0) {
      if (rangs_of_digit[i] == 0) {
        word += "zero";
      } else {
        word += digit[rangs_of_digit[i]];
      }
    }
  }
  return word += " ";
}
int translating_a_word_in_a_number::translating_a_word_into_a_number(
    std::string word) {
  std::map<std::string, int> digit(write_words());
  int numbers = 0;
  char space = ' ';
  std::string words = "";
  int i = 0;
  if (word == "zero ") return 0;
  while (word[i] != 0) {
    if (word[i] != space) {
      words += word[i];
      i++;
    }
    if (words == "minus") {
      words.clear();
    }
    if (word[i] == space) {
      auto number = digit.find(words);
      int tmp = number->second;
      if (tmp < 100) {
        numbers += tmp;
      }
      if (tmp >= 100 && tmp < 1000) {
        if (numbers > 1000)
          numbers += numbers % 10 * tmp - numbers % 10;
        else
          numbers *= tmp;
      }
      if (tmp >= 1000) {
        numbers *= tmp;
      }
      words.clear();
      i++;
    }
  }
  words.clear();
  i = 0;
  while (word[i] != space) {
    if (word[i] != space) {
      words += word[i];
      i++;
    }
    if (words == "minus") {
      numbers *= (-1);
      break;
    }
  }
  return numbers;
}
