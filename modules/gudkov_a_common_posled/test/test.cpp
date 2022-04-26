// Copyright 2022 Gudkov Andrey

#include <gtest/gtest.h>
#include "include/gudkov_a_common_posled.h"

TEST(Gudkov_common_seq, test_size_0) {
    _common_seq test;
    int res = test.find_common_seq();
    EXPECT_EQ(res, 0);
}

TEST(Gudkov_common_seq, test_first_size_0) {
    _common_seq test("", "asdasw");
    int res = test.find_common_seq();
    EXPECT_EQ(res, 0);
}

TEST(Gudkov_common_seq, test_second_size_0) {
    _common_seq test("asdasw", "");
    int res = test.find_common_seq();
    EXPECT_EQ(res, 0);
}

TEST(Gudkov_common_seq, test_expexted_4) {
    _common_seq test("abcabaac", "baccbca");
    int res = test.find_common_seq();
    EXPECT_EQ(res, 4);
}

TEST(Gudkov_common_seq, test_setters) {
    _common_seq test_seq;
    test_seq.set_first_seq("wadase");
    test_seq.set_second_seq("wadase");

    int res = test_seq.find_common_seq();
    EXPECT_EQ(res, 6);
}
