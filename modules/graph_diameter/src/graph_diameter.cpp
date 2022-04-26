// Copyright 2022 Gleb "belgad" Danshin
#include "include/graph_diameter.h"

#include <algorithm>
#include <queue>
#include <vector>

Graph::Graph()
    : graph_size_(0),
      weights_(Matrix(0, Vector(0))) {}

Graph::Graph(size_t graph_size)
    : graph_size_(graph_size), weights_(
      Matrix(graph_size, Vector(graph_size, 0))) {}

Graph::Graph(Matrix& weights)
    : graph_size_(weights.size()), weights_(weights) {}

size_t Graph::GetSize() const {
  return graph_size_;
}

void Graph::SetSize(size_t new_size) {
  auto n = std::min(graph_size_, new_size);
  Matrix new_weights(new_size, Vector(new_size, 0));
  for (size_t i = 0; i < n; ++i) {
    new_weights[i][i] = weights_[i][i];
    for (size_t j = i + 1; j < n; ++j) {
      new_weights[i][j] = new_weights[j][i] = weights_[i][j];
    }
  }
  weights_ = new_weights;
  graph_size_ = new_size;
}

void Graph::SetEdge(size_t first, size_t second, int weight) {
  auto n = std::max(first, second);
  if (n >= graph_size_) {
    this->SetSize(n + 1);
  }
  weights_[first][second] = weights_[second][first] = weight;
}

int Graph::FindDiameter() {
  if (graph_size_ < 2) {
    return 0;
  }
  std::vector<int> way_cost(graph_size_, -1);
  std::queue<size_t> vertex_to_visit;

  vertex_to_visit.push(static_cast<size_t>(0));
  way_cost[0] = 0;
  while (!vertex_to_visit.empty()) {
    auto now = vertex_to_visit.front();
    vertex_to_visit.pop();
    for (size_t i = 0; i < graph_size_; ++i) {
      if (weights_[now][i]) {
        auto new_cost = way_cost[now] + weights_[now][i];
        if (way_cost[i] == -1 || new_cost < way_cost[i]) {
          way_cost[i] = new_cost;
          vertex_to_visit.push(i);
        }
      }
    }
  }

  int max_way = way_cost[1];
  size_t max_way_index = 1;
  for (size_t i = 2; i < graph_size_; ++i) {
    if (way_cost[i] == -1) {
      return -1;
    }
    if (way_cost[i] > max_way) {
      max_way = way_cost[i];
      max_way_index = i;
    }
  }
  for (size_t i = 0; i < graph_size_; ++i) {
    way_cost[i] = -1;
  }

  vertex_to_visit.push(max_way_index);
  way_cost[max_way_index] = 0;
  while (!vertex_to_visit.empty()) {
    auto now = vertex_to_visit.front();
    vertex_to_visit.pop();
    for (size_t i = 0; i < graph_size_; ++i) {
      if (weights_[now][i]) {
        auto new_cost = way_cost[now] + weights_[now][i];
        if (way_cost[i] == -1 || new_cost < way_cost[i]) {
          way_cost[i] = new_cost;
          vertex_to_visit.push(i);
        }
      }
    }
  }

  max_way = way_cost[0];
  for (size_t i = 1; i < graph_size_; ++i) {
    if (way_cost[i] > max_way) {
      max_way = way_cost[i];
    }
  }
  return max_way;
}
