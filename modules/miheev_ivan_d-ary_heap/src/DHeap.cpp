// Copyright 2022 Miheev Ivan

#include <algorithm>
#include "include/DHeap.h"

// Function to insert element in heap
void DHeap::insert(double n) {
  if (this->isFull() || this->isEmpty())
    heaparr.resize(++capacity);

  heaparr[size++] = n;

  // If heap is not heapified.
  heapify(size-1);
}

// Function to extract minimum node from heap
double DHeap::extractMin() {
  if (isEmpty()) throw "empty heap!";

  // Store the root node
  double root = heaparr[0];

  // Replace root node with last node
  double lastNode = heaparr[--size];
  heaparr[0] = lastNode;

  // heapify root
  deheapify(0);

  return root;
}

// Function to order parent roots at given idx (swap with the smallest parent)
void DHeap::heapify(int idx) {
  if (idx > size) throw "out of heap size";
  int par, curr = idx;

  do {
    par = (curr - 1) / d;
    if (heaparr[par] > heaparr[curr]) {
      std::swap(heaparr[par], heaparr[curr]);
      curr = par;
    } else {
      break;
    }
  } while (par != 0);
}

// Function to order child roots at given idx (swap with the smallest child)
void DHeap::deheapify(int idx) {
  if (idx > size) throw "out of heap size";
  int smallest = idx;

  if (smallest < size) {
    for (int i = 1; i <= d; i++)
      if (d * idx + i < size && heaparr[d * idx + i] < heaparr[smallest])
        smallest = d * idx + i;
  }

  if (smallest != idx) {
    std::swap(heaparr[smallest], heaparr[idx]);
    deheapify(smallest);
  }
}

// Function to decrease value in heap
void DHeap::decreaseValue(int pos, int val) {
  // Get the node and update its value
  heaparr[pos] = val;

  // If heap is not heapified.
  heapify(pos);
}
