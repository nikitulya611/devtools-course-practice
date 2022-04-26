// Copyright 2022 Zaitsev Alexander

#include <gtest/gtest.h>

#include <map>
#include <string>
#include <vector>

#include "./include/number_translation.h"

TEST(zaitsev_a_translating_a_number_into_a_word, translate_0) {
  int number = 0;
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(number));
  std::string answer("zero ");
  ASSERT_EQ(word, answer);
}

TEST(zaitsev_a_translating_a_number_into_a_word, translate_7) {
  int number = 7;
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(number));
  std::string answer("seven ");
  ASSERT_EQ(word, answer);
}

TEST(zaitsev_a_translating_a_number_into_a_word, translate_37) {
  int number = 37;
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(number));
  std::string answer("thirty seven ");
  ASSERT_EQ(word, answer);
}

TEST(zaitsev_a_translating_a_number_into_a_word, translate_111117) {
  int number = 111117;
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(number));
  std::string answer("one hundred eleven thousand one hundred seventeen  ");
  ASSERT_EQ(word, answer);
}

TEST(zaitsev_a_translating_a_number_into_a_word, translate_11117) {
  int number = 11117;
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(number));
  std::string answer("eleven thousand one hundred seventeen  ");
  ASSERT_EQ(word, answer);
}

TEST(zaitsev_a_translating_a_number_into_a_word, translate_11) {
  int number = 11;
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(number));
  std::string answer("eleven  ");
  ASSERT_EQ(word, answer);
}

TEST(zaitsev_a_translating_a_number_into_a_word, translate_minus_39) {
  int number = -39;
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(number));
  std::string answer("minus thirty nine ");
  ASSERT_EQ(word, answer);
}

TEST(zaitsev_a_translating_a_word_into_a_number, translate_50) {
  int answer = 50;
  std::string word("fifty ");
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_word_into_a_number, translate_minus_11111) {
  int answer = -11111;
  std::string word(
      "minus eleven thousand one hundred eleven ");
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_word_into_a_number, translate_minus_1119) {
  int answer = -1119;
  std::string word("minus one thousand one hundred nineteen ");
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_word_into_a_number, translate_311117) {
  int answer = 311117;
  std::string word("three hundred eleven thousand one hundred seventeen ");
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_word_into_a_number, translate_minus_999999) {
  int answer = -999999;
  std::string word(
      "minus nine hundred ninety nine thousand nine hundred ninety nine ");
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_word_into_a_number, translate_999999) {
  int answer = 999999;
  std::string word(
      "nine hundred ninety nine thousand nine hundred ninety nine ");
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_word_into_a_number, translate_minus_364) {
  int answer = -364;
  std::string word("minus three hundred sixty four ");
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_word_into_a_number, translate_578) {
  int answer = 578;
  std::string word("five hundred seventy eight ");
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_word_into_a_number, translate_minus_798) {
  std::string word("minus seven hundred ninety eight ");
  int answer = -798;
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_word_into_a_number, translate_517) {
  std::string word("five hundred seventeen ");
  int answer = 517;
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_word_into_a_number, translate_957867) {
  std::string word(
      "nine hundred fifty seven thousand eight hundred sixty seven ");
  int answer = 957867;
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_number_into_a_word_and_translate_back,
     translate_1090_and_translate_back) {
  int answer = 1090;
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(answer));
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_number_into_a_word_and_translate_back,
     translate_732388_and_translate_back) {
  int answer = 732388;
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(answer));
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_number_into_a_word_and_translate_back,
     translate_49724_and_translate_back) {
  int answer = 49724;
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(answer));
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_number_into_a_word_and_translate_back,
     translate_minus_32855_and_translate_back) {
  int answer = -32855;
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(answer));
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_number_into_a_word_and_translate_back,
     translate_650_and_translate_back) {
  int answer = 650;
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(answer));
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(word));
  ASSERT_EQ(answer, number);
}

TEST(zaitsev_a_translating_a_word_into_a_number_and_translate_back,
     translate_ten_thousand_fifty_seven_and_translate_back) {
  std::string answer("ten  thousand fifty seven ");
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(answer));
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(number));
  ASSERT_EQ(answer, word);
}

TEST(zaitsev_a_translating_a_word_into_a_number_and_translate_back,
     translate_957867_and_translate_back) {
  std::string answer(
      "nine hundred fifty seven thousand eight hundred sixty seven ");
  translating_a_word_in_a_number word_in_a_number;
  int number(word_in_a_number.translating_a_word_into_a_number(answer));
  translating_a_number_in_a_word number_in_a_word;
  std::string word(number_in_a_word.translating_a_number_into_a_word(number));
  ASSERT_EQ(answer, word);
}
