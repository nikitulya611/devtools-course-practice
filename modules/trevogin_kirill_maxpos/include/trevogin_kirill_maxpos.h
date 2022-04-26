// Copyright 2022 Trevogin Kirill

#ifndef MODULES_TREVOGIN_KIRILL_MAXPOS_INCLUDE_TREVOGIN_KIRILL_MAXPOS_H_
#define MODULES_TREVOGIN_KIRILL_MAXPOS_INCLUDE_TREVOGIN_KIRILL_MAXPOS_H_

#include <vector>

class Longer {
 public:
    static std::vector<int> getRandomVector(int n);
    static std::vector<int> longestIncreasingSubsequence(std::vector<int> vec);
};

#endif  // MODULES_TREVOGIN_KIRILL_MAXPOS_INCLUDE_TREVOGIN_KIRILL_MAXPOS_H_
