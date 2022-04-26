// Copyright 2022 Pichugin Ilya
#include "include/sort_selection.h"

void SortSelection::Copy(int* _A, int _count) {
  if (_count <= 0) {
    A = nullptr;
    count = 0;
  }
    count = _count;
    A = new int[count];

  for (int i = 0; i < count; i++) {
      A[i] = _A[i];
    }
}

SortSelection::SortSelection() {
  A = nullptr;
  count = 0;
}

SortSelection::SortSelection(int* _A, int _count) { Copy(_A, _count); }

SortSelection& SortSelection::operator=(const SortSelection&) {
  if (count > 0) {
    delete[] A;
    count = 0;
  }

  Copy(A, count);
  return *this;
}

void SortSelection::Sort() {
  for (int i = 0; i < count; i++) {
    int k = i;
    int x = A[i];
    for (int j = i + 1; j < count; j++) {
      if (A[j] < x) {
        k = j;
        x = A[j];
      }
    }
    A[k] = A[i];
    A[i] = x;
  }
}

bool SortSelection::Ex(int* Arr, int count) {
  for (int i = 0; i < count; i++) {
    if (Arr[i] != A[i]) {
      return 0;
    }
  }
  return 1;
}
