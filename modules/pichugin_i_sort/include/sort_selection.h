// Copyright 2022 Pichugin Ilya

#ifndef MODULES_PICHUGIN_I_SORT_INCLUDE_SORT_SELECTION_H_
#define MODULES_PICHUGIN_I_SORT_INCLUDE_SORT_SELECTION_H_

#include <iostream>

#include "include/sort_selection.h"

class SortSelection {
 private:
  int* A;
  int count;

 public:
  SortSelection();
  SortSelection(int* _A, int _count);
  SortSelection(const SortSelection& obj) : SortSelection(obj.A, obj.count) {}
  SortSelection& operator=(const SortSelection& obj);

  void Sort();
  void Copy(int* _A, int _count);
  bool Ex(int* Arr, int count);
};

#endif  // MODULES_PICHUGIN_I_SORT_INCLUDE_SORT_SELECTION_H_
