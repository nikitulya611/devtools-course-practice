// Copyright 2022 Burdukov Mikhail

#include <gtest/gtest.h>

#include "include/horse_min_range.h"

TEST(minHorseRange, Create) {
    ASSERT_NO_THROW(minHorseRange hourse);
}

TEST(minHorseRange, Range_without_barriers) {
    chess_position_t st('a', 1);
    chess_position_t fin('b', 3);
    minHorseRange a(st, fin);
    EXPECT_EQ(1, a.calc_range());
}

TEST(minHorseRange, Range_without_barriers1) {
    chess_position_t st('a', 1);
    chess_position_t fin('b', 3);
    minHorseRange a;
    a.set_start(st);
    a.set_finish(fin);
    EXPECT_EQ(1, a.calc_range());
}

TEST(minHorseRange, Range_without_barriers3) {
    chess_position_t st('a', 1);
    chess_position_t fin('b', 7);
    minHorseRange a;
    a.set_start(st);
    a.set_finish(fin);
    EXPECT_EQ(3, a.calc_range());
}


TEST(minHorseRange, Range_without_barriers4) {
    chess_position_t st('a', 1);
    chess_position_t fin('g', 8);
    minHorseRange a;
    a.set_start(st);
    a.set_finish(fin);
    EXPECT_EQ(5, a.calc_range());
}

TEST(minHorseRange, Range_with_barriers) {
    chess_position_t st('a', 1);
    chess_position_t fin('b', 3);
    chess_position_t bar('g', 8);
    minHorseRange a;
    a.set_start(st);
    a.set_finish(fin);
    a.set_barrier(bar);
    EXPECT_EQ(1, a.calc_range());
}

TEST(minHorseRange, Range_with_barriers1) {
    chess_position_t st('a', 1);
    chess_position_t fin('b', 7);
    chess_position_t bar('g', 8);
    minHorseRange a;
    a.set_start(st);
    a.set_finish(fin);
    a.set_barrier(bar);
    EXPECT_EQ(3, a.calc_range());
}

TEST(minHorseRange, Range_with_barriers3) {
    chess_position_t st('a', 1);
    chess_position_t fin('b', 3);
    chess_position_t bar('h', 2);
    minHorseRange a(st, fin);
    a.set_barrier(bar);
    EXPECT_EQ(1, a.calc_range());
}
