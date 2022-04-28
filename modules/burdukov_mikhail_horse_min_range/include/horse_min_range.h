// Copyright 2022 Burdukov Mikhail

#ifndef MODULES_BURDUKOV_MIKHAIL_HORSE_MIN_RANGE_INCLUDE_HORSE_MIN_RANGE_H_
#define MODULES_BURDUKOV_MIKHAIL_HORSE_MIN_RANGE_INCLUDE_HORSE_MIN_RANGE_H_

#include <utility>
#include <vector>

struct chess_position_t {
  char i;
  int j;
  std::pair<int, int> convert_to_pair() const {
    return std::pair<int, int>(i - 'a', j - 1);
  }
  chess_position_t(char a, int b) : i(a), j(b) {}
};

class minHorseRange {
 private:
  std::vector<std::vector<int>> table;
  std::pair<int, int> start, finish;
  const int table_size = 8;
  const std::vector<int> di = {2, 2, 1, 1, -2, -2, -1, -1};
  const std::vector<int> dj = {1, -1, 2, -2, 1, -1, 2, -2};

 public:
  minHorseRange()
      : start(std::pair<int, int>(1, 1)),
        finish(std::pair<int, int>(1, 1)) {
    table.assign(table_size, std::vector<int>(table_size, 0));
  }

  minHorseRange(chess_position_t s, chess_position_t f)
      : start(s.convert_to_pair()), finish(f.convert_to_pair()) {
    table.assign(table_size, std::vector<int>(table_size, 0));
  }
  void set_barrier(const chess_position_t& pos) {
    auto conv = pos.convert_to_pair();
    table[conv.first][conv.second] = 1;
  }
  void set_start(const chess_position_t& pos) { start = pos.convert_to_pair(); }
  void set_finish(const chess_position_t& pos) {
    finish = pos.convert_to_pair();
  }
  void set_table(const std::vector<std::vector<int>> _t) { table = _t; }
  int calc_range() const;
};

#endif  // MODULES_BURDUKOV_MIKHAIL_HORSE_MIN_RANGE_INCLUDE_HORSE_MIN_RANGE_H_
