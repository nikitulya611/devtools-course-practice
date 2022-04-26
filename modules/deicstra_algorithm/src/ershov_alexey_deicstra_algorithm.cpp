// Copyright 2022 Ershov Alexey

#include "./include/ershov_alexey_deicstra_algorithm.h"

#include <omp.h>

#include <algorithm>
#include <random>
#include <utility>
#include <vector>

std::vector<std::vector<size_t>> Algorithm::getRandomVector(
    const size_t count) {
  std::vector<std::vector<size_t>> graf(count, std::vector<size_t>(count));
  std::mt19937 gen(0);
  for (size_t i = 0; i < count; ++i) {
    graf[i][i] = 0;
    for (size_t j = i + 1; j < count; ++j) {
      graf[i][j] = gen() % 100;
      graf[j][i] = graf[i][j];
    }
  }
  return graf;
}

std::vector<size_t> Algorithm::getDeicstra(
    const std::vector<std::vector<size_t>>& graf, size_t top) {
  const size_t count = graf.size();
  if (graf.size() == 0) {
    return std::vector<size_t>(0);
  }
  if (top >= count) {
    top = count - 1;
  }
  std::vector<bool> visitedTops(count);
  std::vector<size_t> dist(count, 10000);
  dist[top] = 0;
  size_t min_dist = 0;
  size_t min_vertex = top;

  while (min_dist < 10000) {
    size_t i = min_vertex;
    visitedTops[i] = true;
    for (size_t j = 0; j < count; ++j)
      if ((dist[i] + graf[i][j] < dist[j]) && (graf[i][j] != 0))
        dist[j] = dist[i] + graf[i][j];
    min_dist = 10000;
    for (size_t j = 0; j < count; ++j)
      if (!visitedTops[j] && dist[j] < min_dist) {
        min_dist = dist[j];
        min_vertex = j;
      }
  }

  return dist;
}
