// Copyright 2022 Ermakov Pavel

#include <gtest/gtest.h>
#include <utility>
#include "include/ermakov_pavel_tringle_params.h"

#define EPSILON 0.0001

TEST(Ermakov_lab2, test_get_a_point_with_default_constructor) {
    _Triangle a;
    std::pair<float, float> a_point = a.get_a_poin();
    std::pair<float, float> expected = { 0, 0 };
    EXPECT_EQ(a_point, expected);
}

TEST(Ermakov_lab2, test_get_a_point_with_param_constructor) {
    _Triangle a({ 1, 0 }, { 5, 3 }, { 7, 0 });
    std::pair<float, float> a_point = a.get_a_poin();
    std::pair<float, float> expected = { 1, 0 };
    EXPECT_EQ(a_point, expected);
}

TEST(Ermakov_lab2, test_get_b_point_with_default_constructor) {
    _Triangle a;
    std::pair<float, float> b_point = a.get_b_poin();
    std::pair<float, float> expected = { 2, 4 };
    EXPECT_EQ(b_point, expected);
}

TEST(Ermakov_lab2, test_get_b_point_with_param_constructor) {
    _Triangle a({ 1, 0 }, { 5, 3 }, { 7, 0 });
    std::pair<float, float> b_point = a.get_b_poin();
    std::pair<float, float> expected = { 5, 3 };
    EXPECT_EQ(b_point, expected);
}

TEST(Ermakov_lab2, test_get_c_point_with_default_constructor) {
    _Triangle a;
    std::pair<float, float> c_point = a.get_c_poin();
    std::pair<float, float> expected = { 4, 0 };
    EXPECT_EQ(c_point, expected);
}

TEST(Ermakov_lab2, test_get_c_point_with_param_constructor) {
    _Triangle a({ 1, 0 }, { 5, 3 }, { 7, 0 });
    std::pair<float, float> c_point = a.get_c_poin();
    std::pair<float, float> expected = { 7, 0 };
    EXPECT_EQ(c_point, expected);
}

TEST(Ermakov_lab2, test_change_a_point) {
    _Triangle a({ 1, 0 }, { 5, 3 }, { 7, 0 });
    _Triangle b({ 0, 0 }, { 5, 3 }, { 7, 0 });
    a.set_a_poin({ 0, 0 });
    std::pair<float, float> expected = { 0, 0 };
    EXPECT_EQ(a.get_a_poin(), expected);
}

TEST(Ermakov_lab2, test_change_b_point) {
    _Triangle a({ 1, 0 }, { 5, 3 }, { 7, 0 });
    _Triangle b({ 1, 0 }, { 7, 3 }, { 7, 0 });
    a.set_b_poin({ 7, 3 });
    std::pair<float, float> expected = { 7, 3 };

    EXPECT_EQ(a.get_b_poin(), expected);
}

TEST(Ermakov_lab2, test_change_c_point) {
    _Triangle a({ 1, 0 }, { 5, 3 }, { 7, 0 });
    _Triangle b({ 1, 0 }, { 5, 3 }, { 5, 2 });
    a.set_c_poin({ 5, 2 });
    std::pair<float, float> expected = { 5, 2 };

    EXPECT_EQ(a.get_c_poin(), expected);
}

TEST(Ermakov_lab2, get_square) {
    _Triangle a({ 0, 0 }, { 6, 0 }, { 6, 3 });
    float square = a.get_square();
    float expected = 8.99995f;
    ASSERT_NEAR(square, expected, EPSILON);
}

TEST(Ermakov_lab2, get_perimetr) {
    _Triangle a({ 0, 0 }, { 6, 0 }, { 6, 3 });
    float perimetr = a.get_perimetr();
    float expected = 15.7082f;
    ASSERT_NEAR(perimetr, expected, EPSILON);
}

TEST(Ermakov_lab2, get_height_of_buttom_side) {
    _Triangle a({ 0, 0 }, { 2, 3 }, { 4, 0 });
    float buttom_side = a.get_side_lenght({ 0, 0 }, { 4, 0 });
    float height = a.get_height(buttom_side);
    float expected = 3;
    ASSERT_NEAR(height, expected, EPSILON);
}

TEST(Ermakov_lab2, get_side_lenght) {
    _Triangle a({ 0, 0 }, { 2, 3 }, { 4, 0 });
    float b = a.get_side_lenght({ 0, 0 }, { 4, 0 });
    float expected = 4;
    ASSERT_NEAR(b, expected, EPSILON);
}
