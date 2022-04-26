// Copyright 2022 Gleb "belgad" Danshin
#include "include/graph_diameter.h"

#include <gtest/gtest.h>
#include <vector>

TEST(GraphConstructors, DefaultConstructor) {
  ASSERT_NO_THROW(Graph{});
}

TEST(GraphConstructors, ParameterizedConstructorSizeT) {
  size_t graph_size{10};
  ASSERT_NO_THROW(Graph(graph_size));
}

TEST(GraphConstructors, ParameterizedConstructorVector) {
  std::vector<std::vector<int>> weights =
    {{0, 1, 2, 3},
     {1, 0, 1, 6},
     {2, 1, 0, 3},
     {3, 6, 3, 0}};
  ASSERT_NO_THROW(Graph(weights));
}

TEST(GraphMemberFunctions, GetSizeNoThrow) {
  auto graph = Graph{};
  ASSERT_NO_THROW(graph.GetSize());
}

TEST(GraphMemberFunctions, SetSizeNoThrow) {
  auto graph = Graph{};
  size_t new_size{10};
  ASSERT_NO_THROW(graph.SetSize(new_size));
}

TEST(GraphMemberFunctions, GetSizeEqualToSetted) {
  auto graph = Graph{};
  size_t new_size{10};
  graph.SetSize(new_size);
  ASSERT_EQ(graph.GetSize(), new_size);
}

TEST(GraphMemberFunctions, DecreaseGraphSize) {
  std::vector<std::vector<int>> weights =
    {{0, 1, 0, 0},
     {1, 0, 0, 0},
     {0, 0, 0, 1},
     {0, 0, 1, 0}};
  auto graph = Graph(weights);
  ASSERT_NO_THROW(graph.SetSize(2));
}

TEST(GraphMemberFunctions, IncreaseGraphSize) {
  std::vector<std::vector<int>> weights =
    {{0, 1, 0, 0},
     {1, 0, 0, 0},
     {0, 0, 0, 1},
     {0, 0, 1, 0}};
  auto graph = Graph(weights);
  ASSERT_NO_THROW(graph.SetSize(6));
}

TEST(GraphMemberFunctions, SetEdgeNoThrow) {
  auto graph = Graph{};
  size_t first{0};
  size_t second{1};
  int weight{10};
  ASSERT_NO_THROW(graph.SetEdge(first, second, weight));
}

TEST(GraphMemberFunctions, FindDiameterEmptyGraphNoThrow) {
  auto graph = Graph{};
  ASSERT_NO_THROW(graph.FindDiameter());
}

TEST(GraphMemberFunctions, FindDiameterEmptyGraphCorrectAnswer) {
  auto graph = Graph{};
  ASSERT_EQ(0, graph.FindDiameter());
}

TEST(GraphMemberFunctions, FindDiameterNonConnectedGraphNoThrow) {
  std::vector<std::vector<int>> weights =
    {{0, 1, 0, 0},
     {1, 0, 0, 0},
     {0, 0, 0, 1},
     {0, 0, 1, 0}};
  auto graph = Graph(weights);
  ASSERT_NO_THROW(graph.FindDiameter());
}

TEST(GraphMemberFunctions, FindDiameterNonConnectedGraphCorrectAnswer) {
  std::vector<std::vector<int>> weights =
    {{0, 1, 0, 0},
     {1, 0, 0, 0},
     {0, 0, 0, 1},
     {0, 0, 1, 0}};
  auto graph = Graph(weights);
  ASSERT_EQ(-1, graph.FindDiameter());
}

TEST(GraphMemberFunctions, FindDiameterConnectedGraphNoThrow) {
  std::vector<std::vector<int>> weights =
    {{0, 1, 1, 3},
     {1, 0, 0, 3},
     {1, 0, 0, 1},
     {3, 3, 1, 0}};
  auto graph = Graph(weights);
  ASSERT_NO_THROW(graph.FindDiameter());
}

TEST(GraphMemberFunctions, FindDiameterConnectedGraphCorrectAnswer) {
  std::vector<std::vector<int>> weights =
    {{0, 1, 1, 3},
     {1, 0, 0, 3},
     {1, 0, 0, 1},
     {3, 3, 1, 0}};
  auto graph = Graph(weights);
  ASSERT_EQ(3, graph.FindDiameter());
}
