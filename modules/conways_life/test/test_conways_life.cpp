// Copyright 2022 Pinezhanin Evgeny

#include <gtest/gtest.h>

#include <vector>
#include "include/conways_life.h"

TEST(conways_life, default_constructor) {
    ASSERT_NO_THROW(ConwaysLife life);
}

TEST(conways_life, get_default_grid) {
    ConwaysLife life;
    std::vector<std::vector<bool>> def_grid{ {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0} };
    std::vector<std::vector<bool>> grid = life.getGrid();
    ASSERT_EQ(def_grid, grid);
}

TEST(conways_life, copy_constructor) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 1, 0, 1, 0},
                                         {0, 0, 1, 0, 0},
                                         {0, 0, 0, 0, 1},
                                         {0, 1, 0, 0, 0},
                                         {0, 0, 0, 1, 0} };
    life.setGrid(grid);
    ConwaysLife new_life(life);
    std::vector<std::vector<bool>> new_life_grid = new_life.getGrid();
    ASSERT_EQ(grid, new_life_grid);
}

TEST(conways_life, can_set_grid_and_get_grid) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 1, 0, 1, 0},
                                         {0, 0, 1, 0, 0},
                                         {0, 0, 0, 0, 1},
                                         {0, 1, 0, 0, 0},
                                         {0, 0, 0, 1, 0} };
    life.setGrid(grid);
    std::vector<std::vector<bool>> life_grid = life.getGrid();
    ASSERT_EQ(grid, life_grid);
}

TEST(conways_life, can_set_grid_only_rectangle) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 1, 0, 0},
                                         {0, 0, 0},
                                         {0, 0, 0, 0, 1},
                                         {0, 1, 0, 0, 0},
                                         {0, 1, 0} };
    ASSERT_ANY_THROW(life.setGrid(grid));
}

TEST(conways_life, cant_set_grid_height_less_3) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 1, 0, 0},
                                         {0, 0, 0, 1} };
    ASSERT_ANY_THROW(life.setGrid(grid));
}

TEST(conways_life, cant_set_grid_width_less_3) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 1},
                                         {0, 0},
                                         {1, 1} };
    ASSERT_ANY_THROW(life.setGrid(grid));
}

TEST(conways_life, next_gen_of_grid) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 0, 0, 0, 0},
                                         {0, 0, 1, 0, 0},
                                         {0, 1, 1, 1, 0},
                                         {0, 0, 1, 0, 0},
                                         {0, 0, 0, 0, 0} };
    life.setGrid(grid);
    std::vector<std::vector<bool>> new_grid{ {0, 0, 0, 0, 0},
                                             {0, 1, 1, 1, 0},
                                             {0, 1, 0, 1, 0},
                                             {0, 1, 1, 1, 0},
                                             {0, 0, 0, 0, 0} };
    life.nextGen(1);
    std::vector<std::vector<bool>> life_grid = life.getGrid();
    ASSERT_EQ(new_grid, life_grid);
}

TEST(conways_life, if_nextgen_less_one_throw) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 0, 0, 0, 0},
                                         {0, 0, 1, 0, 0},
                                         {0, 1, 1, 1, 0},
                                         {0, 0, 1, 0, 0},
                                         {0, 0, 0, 0, 0} };
    life.setGrid(grid);
    ASSERT_ANY_THROW(life.nextGen(0));
}

TEST(conways_life, next_gen_2_of_grid) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 1, 0, 0, 0},
                                         {0, 0, 1, 1, 1, 0, 0},
                                         {0, 0, 0, 1, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0} };
    life.setGrid(grid);
    std::vector<std::vector<bool>> new_grid{ {0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 1, 0, 0, 0},
                                             {0, 0, 1, 0, 1, 0, 0},
                                             {0, 1, 0, 0, 0, 1, 0},
                                             {0, 0, 1, 0, 1, 0, 0},
                                             {0, 0, 0, 1, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0} };
    life.nextGen(2);
    std::vector<std::vector<bool>> life_grid = life.getGrid();
    ASSERT_EQ(new_grid, life_grid);
}

TEST(conways_life, grid_is_torus) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {1, 1, 1, 0, 0},
                                         {1, 1, 1, 0, 0},
                                         {1, 1, 1, 0, 0},
                                         {0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0} };
    life.setGrid(grid);
    std::vector<std::vector<bool>> new_grid{ {1, 0, 1, 0, 0},
                                             {0, 0, 0, 1, 1},
                                             {1, 0, 1, 0, 0},
                                             {0, 1, 0, 0, 0},
                                             {0, 1, 0, 0, 0} };
    life.nextGen(1);
    std::vector<std::vector<bool>> life_grid = life.getGrid();
    ASSERT_EQ(new_grid, life_grid);
}

TEST(conways_life, can_get_grid_is_stable) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 0, 0, 0, 0, 0},
                                         {0, 0, 1, 1, 0, 0},
                                         {0, 1, 0, 0, 1, 0},
                                         {0, 0, 1, 1, 0, 0},
                                         {0, 0, 0, 0, 0, 0} };
    life.setGrid(grid);
    ASSERT_EQ(true, life.isStable());
}

TEST(conways_life, can_get_grid_isnt_stable) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {1, 0, 0, 0, 0, 0},
                                         {0, 0, 1, 1, 0, 0},
                                         {0, 1, 0, 0, 1, 0},
                                         {1, 0, 1, 1, 0, 0},
                                         {1, 0, 0, 0, 0, 0} };
    life.setGrid(grid);
    ASSERT_EQ(false, life.isStable());
}

TEST(conways_life, can_get_grid_is_periodic_2) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 0, 0, 0, 0},
                                         {0, 0, 1, 0, 0},
                                         {0, 0, 1, 0, 0},
                                         {0, 0, 1, 0, 0},
                                         {0, 0, 0, 0, 0} };
    life.setGrid(grid);
    ASSERT_EQ(2, life.isPeriodic(5));
}

TEST(conways_life, isnt_periodic_return_minus_one) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 0, 0, 0, 0},
                                         {0, 0, 1, 1, 0},
                                         {0, 1, 1, 1, 0},
                                         {0, 0, 1, 0, 0},
                                         {0, 0, 0, 0, 0} };
    life.setGrid(grid);
    ASSERT_EQ(-1, life.isPeriodic(5));
}

TEST(conways_life, can_get_grid_is_periodic_3) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                         {0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
                                         {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                                         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                                         {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
                                         {0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
                                         {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
    life.setGrid(grid);
    ASSERT_EQ(3, life.isPeriodic(5));
}

TEST(conways_life, grid_is_periodic_3_return_minus_one_if_arg_less_per) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                         {0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
                                         {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                                         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                                         {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
                                         {0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
                                         {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
    life.setGrid(grid);
    ASSERT_EQ(-1, life.isPeriodic(2));
}

TEST(conways_life, grid_is_periodic_1_is_stable) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 0, 0, 0, 0, 0},
                                         {0, 0, 1, 1, 0, 0},
                                         {0, 1, 0, 0, 1, 0},
                                         {0, 0, 1, 1, 0, 0},
                                         {0, 0, 0, 0, 0, 0} };
    life.setGrid(grid);
    ASSERT_EQ(1, life.isPeriodic(5));
}

TEST(conways_life, if_max_per_in_periodic_less_one_throw) {
    ConwaysLife life;
    std::vector<std::vector<bool>> grid{ {0, 0, 0, 0, 0, 0},
                                         {0, 0, 1, 1, 0, 0},
                                         {0, 1, 0, 0, 1, 0},
                                         {0, 0, 1, 1, 0, 0},
                                         {0, 0, 0, 0, 0, 0} };
    life.setGrid(grid);
    ASSERT_ANY_THROW(life.isPeriodic(0));
}
