// Copyright 2022 Lakhov Kirill

#include <gtest/gtest.h>

#include <vector>
#include "include/stohastic_variable.h"

TEST(Statistic_Values, Constructor) {
    std::vector<double> v = {1, 2, 3, 4};
    std::vector<double> p = {0.25, 0.25, 0.25, 0.25};
    StohasticVariable eps(v, p);
    ASSERT_EQ(eps.values(), v);
    ASSERT_EQ(eps.probabilities(), p);
}

TEST(Statistic_Values, Mean) {
    std::vector<double> v = {1, 2, 3, 4};
    std::vector<double> p = {0.2, 0.2, 0.55, 0.05};
    StohasticVariable eps(v, p);
    EXPECT_DOUBLE_EQ(eps.Mean(), 2.45);
}

TEST(Statistic_Values, Dispersion) {
    std::vector<double> v = {1, 2, 3, 4};
    std::vector<double> p = {0.2, 0.2, 0.55, 0.05};
    StohasticVariable eps(v, p);
    EXPECT_DOUBLE_EQ(eps.Dispersion(), 0.7475);
}


TEST(Statistic_Values, Raw_Moment_Case1) {
    std::vector<double> v = {-5, 1, 3, 1};
    std::vector<double> p = {0.1, 0.4, 0.3, 0.2};
    StohasticVariable eps(v, p);
    EXPECT_DOUBLE_EQ(eps.RawMoment(3), -3.8);
}

TEST(Statistic_Values, Raw_Moment_Case2) {
    std::vector<double> v = {-1, 1, 1, 13};
    std::vector<double> p = {0.1, 0.15, 0.15, 0.6};
    StohasticVariable eps(v, p);
    EXPECT_DOUBLE_EQ(eps.RawMoment(5), 222776);
}

TEST(Statistic_Values, Central_Moment_Case1) {
    std::vector<double> v = {-5, 1, 4, 1};
    std::vector<double> p = {0.1, 0.4, 0.3, 0.2};
    StohasticVariable eps(v, p);
    EXPECT_DOUBLE_EQ(eps.CentralMoment(3), -19.116);
}

TEST(Statistic_Values, Central_Moment_Case2) {
    std::vector<double> v = {-1, 1, 1, 13};
    std::vector<double> p = {0.1, 0.15, 0.15, 0.6};
    StohasticVariable eps(v, p);
    EXPECT_DOUBLE_EQ(eps.CentralMoment(5), -9072);
}
