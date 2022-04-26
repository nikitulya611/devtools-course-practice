// Copyright 2022 Bakina Kseniia

#ifndef MODULES_BAKINA_KSENIIA_BETCHER_INCLUDE_BACKINA_KSENIIA_BETCHER_H_
#define MODULES_BAKINA_KSENIIA_BETCHER_INCLUDE_BACKINA_KSENIIA_BETCHER_H_

#include <vector>

auto default_comparator = [](int a, int b) { return a < b; };

class EvenOddBetcher {
 public:
    static std::vector<int> get_random_vector(int n);
    static void residue_handling(int iter, const std::vector<int>& vec,
         std::vector<int>* res);
    static void partial_merger(int iter_init, const std::vector<int>& vec1,
         const std::vector<int>& vec2, std::vector<int>* res,
         bool comparator(int, int) = default_comparator);
    static std::vector<int> EvenOddBetcher_merge(const std::vector<int>& v1,
         const std::vector<int>& v2,
         bool comparator(int, int) = default_comparator);
};

#endif  // MODULES_BAKINA_KSENIIA_BETCHER_INCLUDE_BACKINA_KSENIIA_BETCHER_H_
