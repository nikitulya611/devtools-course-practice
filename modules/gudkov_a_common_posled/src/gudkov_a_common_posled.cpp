// Copyright 2022 Gudkov Andrey

#include "include/gudkov_a_common_posled.h"
#include <algorithm>
#include <string>
#include <vector>

_common_seq ::_common_seq() {
    this->first_seq = "";
    this->second_seq = "";
}

_common_seq ::_common_seq(std::string first,
    std::string second) {
    this->first_seq = first;
    this->second_seq = second;
}

void _common_seq::set_first_seq(std::string s) {
    this->first_seq = s;
}

void _common_seq::set_second_seq(std::string s) {
    this->second_seq = s;
}

int _common_seq ::find_common_seq() {
    int first_size = this->first_seq.size();
    int second_size = this->second_seq.size();
    if (first_size == 0 || second_size == 0) {
        return 0;
    }
    std::vector<std::vector<char>> _F(first_size + 1,
        std::vector<char>(second_size + 1, 0));
    for (int i = 1; i <= first_size; i++) {
        for (int j = 1; j <= second_size; j++) {
            if (this->first_seq[i - 1] == this->second_seq[j - 1]) {
                _F[i][j] = _F[i - 1][j - 1] + 1;
            } else {
                _F[i][j] = std::max(_F[i - 1][j], _F[i][j - 1]);
            }
        }
    }
    return _F[first_size][second_size];
}

_common_seq ::~_common_seq() {
    this->first_seq = "";
    this->second_seq = "";
}
