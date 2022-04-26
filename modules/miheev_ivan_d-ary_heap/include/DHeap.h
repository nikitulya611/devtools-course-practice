// Copyright 2022 Miheev Ivan
#ifndef MODULES_MIHEEV_IVAN_D_ARY_HEAP_INCLUDE_DHEAP_H_
#define MODULES_MIHEEV_IVAN_D_ARY_HEAP_INCLUDE_DHEAP_H_

#include <stdlib.h>
#include <algorithm>
#include <vector>

// minimal element in the root of the heap
class DHeap {
 private:
  int d;  // Sets the d-ary of the heap
  int capacity, size;        // Number of nodes in the heap
  std::vector<double> heaparr;  // the array on which the heap is built

 public:
  DHeap() : d(2), capacity(1), size(0) {}  // Default constructor
  DHeap(int _capacity, int _d) :
    d(_d),
    capacity(_capacity),
    size(0),
    heaparr(_capacity) {
    if (d < 2) throw "d-ary of the heap can't be less then 2";
    if (capacity < 0) throw "capacity of the heap can't be less then 0";
  }
  DHeap(const DHeap& hp) :  // Default constructor
    d(hp.d),
    capacity(hp.capacity),
    size(hp.size),
    heaparr(hp.heaparr) {}
  ~DHeap() {
    heaparr.clear();
  }

  double extractMin();
  bool isEmpty() { return size == 0; }
  bool isFull() { return size == capacity; }
  void insert(double n);
  void heapify(int idx);
  void deheapify(int idx);
  void decreaseValue(int pos, int val);
};

#endif  // MODULES_MIHEEV_IVAN_D_ARY_HEAP_INCLUDE_DHEAP_H_
