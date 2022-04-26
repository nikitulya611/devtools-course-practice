// Copyright 2022 Gleb "belgad" Danshin
#ifndef MODULES_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_H_
#define MODULES_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_H_

#include <vector>

class Graph {
  using Vector = std::vector<int>;
  using Matrix = std::vector<Vector>;
 public:
  Graph();
  explicit Graph(size_t);
  explicit Graph(Matrix&);
  size_t GetSize() const;
  void SetSize(size_t);
  void SetEdge(size_t, size_t, int);
  int FindDiameter();
 private:
  size_t graph_size_;
  Matrix weights_;
};

#endif  // MODULES_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_H_
