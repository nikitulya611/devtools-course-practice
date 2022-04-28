// Copyright 2022 Butescu Vladimir

#include <gtest/gtest.h>
#include <string>
#include "include/levenshtein_distance.h"

TEST(Butescu_levenshtein_distance, test_zero_value) {
     Levenshtein L;
     std::string src = "";
     std::string dst = "";
     int distance =
     L.LevenshteinDistance(src, dst);

     ASSERT_EQ(distance, 0);
}

TEST(Butescu_levenshtein_distance, test_one_value) {
    Levenshtein L;
    std::string src = "1";
    std::string dst = "1";
    int distance =
        L.LevenshteinDistance(src, dst);

    ASSERT_EQ(distance, 0);
}

TEST(Butescu_levenshtein_distance, test_number) {
     Levenshtein L;
     std::string src = "125";
     std::string dst = "521";
     int distance =
     L.LevenshteinDistance(src, dst);

     ASSERT_EQ(distance, 2);
}

TEST(Butescu_levenshtein_distance, test_big_number) {
    Levenshtein L;
    std::string
        src = "3245254252413124";
    std::string
        dst = "124456767453";
    int distance =
        L.LevenshteinDistance(src, dst);

    ASSERT_EQ(distance, 11);
}

TEST(Butescu_levenshtein_distance, test_word) {
     Levenshtein L;
     std::string src = "string";
     std::string dst = "dog";
     int distance =
     L.LevenshteinDistance(src, dst);

     ASSERT_EQ(distance, 5);
}

TEST(Butescu_levenshtein_distance, test_big_word) {
    Levenshtein L;
    std::string
    src = "Floccinaucinihilipilification";
    std::string
    dst = "Antidisestablishmentarianism";
    int distance =
    L.LevenshteinDistance(src, dst);

    ASSERT_EQ(distance, 25);
}
