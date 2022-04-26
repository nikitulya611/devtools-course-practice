// Copyright 2022 Yashin Kirill

#ifndef MODULES_YASHIN_KIRILL_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_
#define MODULES_YASHIN_KIRILL_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_

#include <vector>
#include <string>

template <class T>

class BinarySearch {
 public:
    BinarySearch() {}

    ~BinarySearch() {}

    int BinSearch(T key, std::vector<T> array, int left, int right) {
        if (left < 0 || left >= static_cast<int>(array.size())) {
            const std::string error_msg("Left search border is out of range");
            throw error_msg;
        }
        if (right < 0 || right >= static_cast<int>(array.size())) {
            const std::string error_msg("Right search border is out of range");
            throw error_msg;
        }
        if (right < left) {
            const std::string error_msg("Left border > right border");
            throw error_msg;
        }
        int middle = (left + right) / 2;
        bool flag = false;
        while (left <= right && !flag) {
            if (array[middle] == key) {
                flag = true;
            } else if (array[middle] > key) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
            middle = (left + right) / 2;
        }
        if (flag) {
            return middle;
        } else {
            return -1;
        }
    }
};

#endif  // MODULES_YASHIN_KIRILL_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_
