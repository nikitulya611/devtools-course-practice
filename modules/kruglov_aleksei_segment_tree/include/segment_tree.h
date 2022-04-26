// Copyright 2022 Kruglov Aleksei

#ifndef MODULES_KRUGLOV_ALEKSEI_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_H_
#define MODULES_KRUGLOV_ALEKSEI_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_H_

#include <vector>

class SegmentTree {
 public:
    void init(int n);
    void set(int pos, int value);
    int sum(int l, int r);

 private:
    std::vector<int> tree;
    int size;

    void update(int vertex);
    void set(int pos, int value, int vertex, int cur_l, int cur_r);
    int sum(int requested_l, int requested_r, int vertex, int cur_l, int cur_r);
};

#endif  // MODULES_KRUGLOV_ALEKSEI_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_H_
