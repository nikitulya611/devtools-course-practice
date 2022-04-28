// Copyright 2022 Butescu Vladimir

#include <string>
#include <algorithm>
#include <vector>
#include "include/levenshtein_distance.h"

int Levenshtein::insert(std::string::value_type ch) {
    return 1;
}

int Levenshtein::remove(std::string::value_type ch) {
    return 1;
}

int Levenshtein::replace(std::string::value_type lhs,
    std::string::value_type rhs) {
    if (lhs == rhs) {
        return 0;
    } else {
        return 1;
    }
}

int Levenshtein::LevenshteinDistance(std::string const& source,
    std::string const& target) {
    std::vector<std::vector<int>> lev_dist(source.length() + 1,
        std::vector<int>(target.length() + 1));

    lev_dist[0][0] = 0;

    for (std::size_t j = 0; j != target.length(); ++j) {
        lev_dist[0][j + 1] = lev_dist[0][j] + insert(target[j]);
    }

    for (std::size_t i = 0; i != source.length(); ++i) {
        lev_dist[i + 1][0] = lev_dist[i][0] + remove(source[i]);

        for (std::size_t j = 0; j != target.length(); ++j) {
            lev_dist[i + 1][j + 1] = std::min(std::min(
                lev_dist[i + 1][j] + insert(target[j]),
                lev_dist[i][j + 1] + remove(source[i])),
                lev_dist[i][j] + replace(source[i], target[j]));
        }
    }

    return lev_dist[source.length()][target.length()];
}
