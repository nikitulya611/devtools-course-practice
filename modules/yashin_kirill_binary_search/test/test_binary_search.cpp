// Copyright 2022 Yashin Kirill

#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "include/binary_search.h"

TEST(Yashin_Kirill_Binary_Search_Test, can_find_int) {
    std::vector<int> array = {
        -5, -3, -1, 0, 1, 3, 5
    };
    BinarySearch<int> b;
    int result = b.BinSearch(0, array, 0, static_cast<int>(array.size()) - 1);
    ASSERT_EQ(3, result);
}

TEST(Yashin_Kirill_Binary_Search_Test, can_find_double) {
    std::vector<double> array = {
        -5.0, -3.0, -1.0, 0.0, 1.0, 3.0, 5.0
    };
    BinarySearch<double> b;
    int result = b.BinSearch(1.0, array, 0, static_cast<int>(array.size()) - 1);
    ASSERT_EQ(4, result);
}

TEST(Yashin_Kirill_Binary_Search_Test, can_find_string) {
    std::vector<std::string> array = {
        "a", "b", "c", "d", "e", "f"
    };
    BinarySearch<std::string> b;
    int result = b.BinSearch("b", array, 0, static_cast<int>(array.size()) - 1);
    ASSERT_EQ(1, result);
}

TEST(Yashin_Kirill_Binary_Search_Test, correct_work_on_missing_value) {
    std::vector<int> array = {
        -5, -3, -1, 0, 1, 3, 5
    };
    BinarySearch<int> b;
    int result = b.BinSearch(1337, array, 0,
        static_cast<int>(array.size()) - 1);
    ASSERT_EQ(-1, result);
}

TEST(Yashin_Kirill_Binary_Search_Test, correct_work_in_part_of_array) {
    std::vector<int> array = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
    BinarySearch<int> b;
    int result = b.BinSearch(3, array, 1, static_cast<int>(array.size()) - 3);
    ASSERT_EQ(3, result);
}

TEST(Yashin_Kirill_Binary_Search_Test, error_messages_test) {
    std::vector<int> array = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
    BinarySearch<int> b;
    try {
        int result = b.BinSearch(0, array, 1,
            static_cast<int>(array.size()) + 1);
        FAIL();
    } catch (const std::string error_msg) {
        ASSERT_EQ("Right search border is out of range", error_msg);
    }

    try {
        int result = b.BinSearch(0, array, -1,
            static_cast<int>(array.size()) + 1);
        FAIL();
    } catch (const std::string error_msg) {
        ASSERT_EQ("Left search border is out of range", error_msg);
    }

    try {
        int result = b.BinSearch(0, array,
            static_cast<int>(array.size()) - 1, 0);
        FAIL();
    } catch (const std::string error_msg) {
        ASSERT_EQ("Left border > right border", error_msg);
    }
}

TEST(Yashin_Kirill_Binary_Search_Test, search_in_unsorted) {
    std::vector<int> array = {
        2, 1, 4, 3, 6, 5, 0
    };
    BinarySearch<int> b;
    int result = b.BinSearch(4, array, 0,
        static_cast<int>(array.size()) - 1);
    ASSERT_EQ(-1, result);
}

TEST(Yashin_Kirill_Binary_Search_Test, equal_borders_search) {
    std::vector<int> array = {
        0, 1, 2, 3, 5, 6
    };
    BinarySearch<int> b;
    int result = b.BinSearch(1, array, 2, 2);
    ASSERT_EQ(-1, result);
}
