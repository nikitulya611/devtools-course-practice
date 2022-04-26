// Copyright 2022 Bakina Kseniia

#include <ctime>
#include <cstdlib>
#include <vector>


#include "include/backina_kseniia_betcher.h"

std::vector<int> EvenOddBetcher::get_random_vector(int n) {
    std::srand(std::time(0));
    std::vector<int> vec;
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = std::rand() * ((std::rand() % 2 == 0) ? -1 : 1);
    }
    return vec;
}

void EvenOddBetcher::residue_handling(int iter, const std::vector<int>& vec,
    std::vector<int>* result) {
    int vec_size = vec.size();
    if (iter < vec_size) {
        for (int k = iter; k < vec_size; k += 2) {
            result->push_back(vec[k]);
        }
    }
}

void EvenOddBetcher::partial_merger(int iter_init, const std::vector<int>& vec1,
    const std::vector<int>& vec2, std::vector<int>* res,
    bool comparator(int, int)) {
    int iter1 = iter_init, iter2 = iter_init;
    int vec1_size = vec1.size(), vec2_size = vec2.size();
    while (iter1 < vec1_size && iter2 < vec2_size) {
        if (comparator(vec1[iter1], vec2[iter2])) {
            res->push_back(vec1[iter1]);
            iter1 += 2;
        } else {
            res->push_back(vec2[iter2]);
            iter2 += 2;
        }
    }
    residue_handling(iter1, vec1, res);
    residue_handling(iter2, vec2, res);
}

std::vector<int> EvenOddBetcher::EvenOddBetcher_merge(
    const std::vector<int>& vec1, const std::vector<int>& vec2,
    bool comparator(int, int)) {
    std::vector<int> odd_vec;
    std::vector<int> even_vec;
    partial_merger(0, vec1, vec2, &even_vec, comparator);
    partial_merger(1, vec1, vec2, &odd_vec, comparator);

    std::vector<int> result;
    if (!even_vec.empty()) {
        result.push_back(even_vec[0]);
    }
    int res_it1 = 1;
    int res_it2 = 0;
    int even_vec_size = even_vec.size();
    int odd_vec_size = odd_vec.size();
    while (res_it1 < even_vec_size && res_it2 < odd_vec_size) {
        if (comparator(even_vec[res_it1], odd_vec[res_it2])) {
            result.push_back(even_vec[res_it1]);
            result.push_back(odd_vec[res_it2]);
        } else {
            result.push_back(odd_vec[res_it2]);
            result.push_back(even_vec[res_it1]);
        }
        ++res_it1, ++res_it2;
    }
    residue_handling(res_it1, even_vec, &result);
    residue_handling(res_it2, odd_vec, &result);

    return result;
}
