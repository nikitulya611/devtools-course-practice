// Copyright 2022 Butescu Vladimir
#ifndef MODULES_BUTESCU_LIVENSTEIN_DISTATNCE_INCLUDE_LEVENSHTEIN_DISTANCE_H_
#define MODULES_BUTESCU_LIVENSTEIN_DISTATNCE_INCLUDE_LEVENSHTEIN_DISTANCE_H_

#include <algorithm>
#include <vector>
#include <string>
#include <random>

class Levenshtein {
 public:
int insert(std::string::value_type ch);
int remove(std::string::value_type ch);
int replace(std::string::value_type lhs, std::string::value_type rhs);
int LevenshteinDistance(std::string const& source, std::string const& target);
};

#endif  // MODULES_BUTESCU_LIVENSTEIN_DISTATNCE_INCLUDE_LEVENSHTEIN_DISTANCE_H_
