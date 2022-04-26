// Copyright 2022 Kruglov Aleksei

#include "include/segment_tree.h"

#include <stdbool.h>
#include <string>
#include <limits>

void SegmentTree::init(int n) {
    size = 1;
    while (size < n)
        size *= 2;
    tree.assign(2 * size - 1, 0);
}

void SegmentTree::set(int pos, int value) {
    set(pos, value, 0, 0, size);
}

int SegmentTree::sum(int l, int r) {
    return sum(l, r, 0, 0, size);
}

void SegmentTree::update(int vertex) {
    tree[vertex] = tree[2 * vertex + 1] + tree[2 * vertex + 2];
}

void SegmentTree::set(int pos, int value, int vertex, int cur_l, int cur_r) {
    if (cur_r - cur_l == 1) {
        tree[vertex] = value;
        return;
    }
    int mid = (cur_l + cur_r) / 2;
    if (pos < mid)
        set(pos, value, 2 * vertex + 1, cur_l, mid);
    else
        set(pos, value, 2 * vertex + 2, mid, cur_r);

    update(vertex);
}

int SegmentTree::sum(int requested_l, int requested_r, int vertex,
                     int cur_l, int cur_r) {
    if (requested_l >= cur_r || requested_r <= cur_l) {
        return 0;
    }
    if (cur_l >= requested_l && cur_r <= requested_r) {
        return tree[vertex];
    }
    int mid = (cur_l + cur_r) / 2;
    int s1 = sum(requested_l, requested_r, 2 * vertex + 1, cur_l, mid);
    int s2 = sum(requested_l, requested_r, 2 * vertex + 2, mid, cur_r);
    return s1 + s2;
}
