// Copyright 2022 Bakina Kseniia

#include <gtest/gtest.h>
#include <functional>
#include <algorithm>
#include <vector>

#include "include/backina_kseniia_betcher.h"

TEST(Bakina_Kseniia_OddEvenBetcherConfluenceTest, check_default_comparator) {
    EXPECT_TRUE(default_comparator(3, 10));
    EXPECT_FALSE(default_comparator(7, 5));
}

TEST(Bakina_Kseniia_OddEvenBetcherConfluenceTest,
    check_func_get_random_vector) {
    unsigned int n = 10;
    std::vector<int> vector = EvenOddBetcher::get_random_vector(n);
    EXPECT_EQ(vector.size(), n);
    EXPECT_FALSE(vector.empty());
}

TEST(Bakina_Kseniia_OddEvenBetcherConfluenceTest,
    check_func_residue_handling) {
    std::vector<int> vector = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> check_vector1 = { 1, 3, 5, 7, 9 };
    std::vector<int> check_vector2 = { 2, 4, 6, 8, 10 };
    std::vector<int> result1;
    std::vector<int> result2;

    EvenOddBetcher::residue_handling(0, vector, &result1);
    EvenOddBetcher::residue_handling(1, vector, &result2);

    EXPECT_EQ(result1, check_vector1);
    EXPECT_EQ(result2, check_vector2);
}

TEST(Bakina_Kseniia_OddEvenBetcherConfluenceTest,
    check_func_partial_merger_with_default_comparator) {
    std::vector<int> vector1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> vector2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> check_vector1 = { 1, 1, 3, 3, 5, 5, 7, 7, 9, 9};
    std::vector<int> check_vector2 = { 2, 2, 4, 4, 6, 6, 8, 8, 10, 10 };
    std::vector<int> result1;
    std::vector<int> result2;

    EvenOddBetcher::partial_merger(0, vector1, vector2, &result1);
    EvenOddBetcher::partial_merger(1, vector1, vector2, &result2);

    EXPECT_EQ(result1, check_vector1);
    EXPECT_EQ(result2, check_vector2);
}

TEST(Bakina_Kseniia_OddEvenBetcherConfluenceTest,
    check_func_partial_merger_with_custom_comparator) {
    std::vector<int> vector1 = { 10, 9, 8 , 7, 6, 5, 4, 3, 2, 1 };
    std::vector<int> vector2 = { 10, 9, 8 , 7, 6, 5, 4, 3, 2, 1 };
    std::vector<int> check_vector1 = { 10, 10, 8, 8, 6, 6, 4, 4, 2, 2 };
    std::vector<int> check_vector2 = { 9, 9, 7, 7, 5, 5, 3, 3, 1, 1 };
    std::vector<int> result1;
    std::vector<int> result2;

    auto custom_comparator_greater = [](int a, int b) { return a > b; };
    EvenOddBetcher::partial_merger(0, vector1, vector2, &result1,
        custom_comparator_greater);
    EvenOddBetcher::partial_merger(1, vector1, vector2, &result2,
        custom_comparator_greater);

    EXPECT_EQ(result1, check_vector1);
    EXPECT_EQ(result2, check_vector2);
}

TEST(Bakina_Kseniia_OddEvenBetcherConfluenceTest,
    check_func_EvenOddBetcher_merge_with_default_comparator) {
    std::vector<int> vector1 = EvenOddBetcher::get_random_vector(100);
    std::vector<int> vector2 = EvenOddBetcher::get_random_vector(150);
    std::sort(vector1.begin(), vector1.end());
    std::sort(vector2.begin(), vector2.end());

    std::vector<int> check_vector(vector1);
    check_vector.insert(check_vector.end(), vector2.begin(), vector2.end());
    std::sort(check_vector.begin(), check_vector.end());

    std::vector<int> result =
        EvenOddBetcher::EvenOddBetcher_merge(vector1, vector2);

    EXPECT_EQ(result, check_vector);
}

TEST(Bakina_Kseniia_OddEvenBetcherConfluenceTest,
    check_func_EvenOddBetcher_merge_with_custom_comparator) {
    std::vector<int> vector1 = EvenOddBetcher::get_random_vector(100);
    std::vector<int> vector2 = EvenOddBetcher::get_random_vector(150);
    std::sort(vector1.begin(), vector1.end(), std::greater<int>());
    std::sort(vector2.begin(), vector2.end(), std::greater<int>());

    std::vector<int> check_vector(vector1);
    check_vector.insert(check_vector.end(), vector2.begin(), vector2.end());
    std::sort(check_vector.begin(), check_vector.end(), std::greater<int>());

    auto custom_comparator_greater = [](int a, int b) { return a > b; };
    std::vector<int> result = EvenOddBetcher::EvenOddBetcher_merge(
        vector1, vector2, custom_comparator_greater);

    EXPECT_EQ(result, check_vector);
}
