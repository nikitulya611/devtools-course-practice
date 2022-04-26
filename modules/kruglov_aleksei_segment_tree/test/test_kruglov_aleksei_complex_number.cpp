// Copyright 2022 Kruglov Aleksei

#include <gtest/gtest.h>

#include "include/segment_tree.h"

TEST(SegmentTree, Create) {
    SegmentTree tree;
    ASSERT_NO_THROW(tree.init(1000));
}

TEST(SegmentTree, Sum0) {
    SegmentTree tree;
    tree.init(10);
    EXPECT_EQ(tree.sum(0, 10), 0);
}

TEST(SegmentTree, Sum1) {
    SegmentTree tree;
    tree.init(10);
    int value = 10;
    tree.set(5, value);
    tree.set(1, value);
    tree.set(9, value);
    EXPECT_EQ(tree.sum(0, 10), 30);
}

TEST(SegmentTree, Sum2) {
    SegmentTree tree;
    tree.init(10);
    int value = 10;
    tree.set(5, value);
    tree.set(1, value);
    tree.set(9, value);
    EXPECT_EQ(tree.sum(0, 6), 20);
}

TEST(SegmentTree, Sum3) {
    SegmentTree tree;
    tree.init(10);
    int value = 10;
    tree.set(5, value);
    tree.set(1, value);
    tree.set(9, value);
    EXPECT_EQ(tree.sum(5, 10), 20);
}

TEST(SegmentTree, Sum4) {
    SegmentTree tree;
    tree.init(10);
    int value = 10;
    tree.set(5, value);
    tree.set(1, value);
    tree.set(9, value);
    EXPECT_EQ(tree.sum(5, 9), 10);
}

TEST(SegmentTree, Sum5) {
    SegmentTree tree;
    tree.init(10);
    int value = 10;
    tree.set(5, value);
    tree.set(1, value);
    tree.set(9, value);
    EXPECT_EQ(tree.sum(5, 6), 10);
}

TEST(SegmentTree, Sum6) {
    SegmentTree tree;
    tree.init(10);
    int value = 10;
    tree.set(5, value);
    tree.set(1, value);
    tree.set(9, value);
    EXPECT_EQ(tree.sum(1, 10), 30);
}

TEST(SegmentTree, Sum7) {
    SegmentTree tree;
    tree.init(20);
    for (int i = 0; i < 20; i++) {
        tree.set(i, i);
    }
    for (int i = 0; i < 20; i++) {
        for (int j = i + 1; j < 20; j++) {
            int expected_sum = (i + j)*(j - i + 1) / 2;
            EXPECT_EQ(expected_sum, tree.sum(i, j + 1));
        }
    }
}

