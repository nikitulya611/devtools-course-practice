// Copyright 2022 Gudkov Andrey

#ifndef MODULES_GUDKOV_A_COMMON_POSLED_INCLUDE_GUDKOV_A_COMMON_POSLED_H_
#define MODULES_GUDKOV_A_COMMON_POSLED_INCLUDE_GUDKOV_A_COMMON_POSLED_H_

#include <string>
#include <vector>

class _common_seq {
    std::string first_seq;
    std::string second_seq;

 public:
    _common_seq();
    _common_seq(std::string first, std::string second);
    void set_first_seq(std::string s);
    void set_second_seq(std::string s);
    int find_common_seq();
    ~_common_seq();
};

#endif  // MODULES_GUDKOV_A_COMMON_POSLED_INCLUDE_GUDKOV_A_COMMON_POSLED_H_
