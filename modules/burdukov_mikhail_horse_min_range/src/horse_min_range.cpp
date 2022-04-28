// Copyright 2022 Burdukov Mikhail

#include "include/horse_min_range.h"

#include <cassert>
#include <queue>
#include <utility>
#include <vector>

int minHorseRange::calc_range() const {
  assert(start.first >= 0 && start.first < table_size);
  assert(finish.second >= 0 && finish.second < table_size);
  const int never_was = -1;
  std::vector<std::vector<int>> was(table_size,
                                    std::vector<int>(table_size, never_was));
  was[start.first][start.second] = 0;
  std::queue<std::pair<int, int>> q;
  q.push(start);
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    if (x == finish) break;
    for (size_t i = 0; i < di.size(); i++) {
      auto y(x);
      y.first += di[i];
      y.second += dj[i];
      if (y.first >= 0 && y.first < table_size && y.second >= 0 &&
          y.second < table_size && was[y.first][y.second] == never_was &&
          table[y.first][y.second] != 1) {
        was[y.first][y.second] = was[x.first][x.second] + 1;
        q.push(y);
      }
    }
  }
  return was[finish.first][finish.second];
}
