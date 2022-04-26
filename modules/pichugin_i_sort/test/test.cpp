// Copyright 2022 Pichugin Ilya

#include <gtest/gtest.h>
#include "include/sort_selection.h"

TEST(SelectionSort, Throw_NO) {
  int Arr[] = {2, 5, 1, 8};
  ASSERT_NO_THROW(SortSelection(Arr, 4));
}

TEST(SelectionSort, Sort_Not_OKAY) {
  int Arr[] = {2, 5, 1, 8};

  int Arr_res[] = {1, 2, 5, 8};
  SortSelection res(Arr, 4);

  res.Sort();

  ASSERT_EQ(res.Ex(Arr, 4), 0);
}

TEST(SelectionSort, Throw_NO_oprer) {
  int Arr[] = {2, 5, 1, 8};
  SortSelection s;
  ASSERT_NO_THROW(s.operator=(s));
}

TEST(SelectionSort, Throw_NO_oprerr) {
  int Arr[] = {2, 5, 1, 8};
  SortSelection s(Arr, 4);
  ASSERT_NO_THROW(s.operator=(s));
}

TEST(SelectionSort, Throw_NO_Copy) {
  int Arr[] = {2, 5, 1, 8};
  SortSelection s;
  ASSERT_NO_THROW(s.Copy(Arr, 4));
}

TEST(SelectionSort, Throw_NO_def) {
  ASSERT_NO_THROW(SortSelection());
}

TEST(SelectionSort, Throw_NO_sort) {
  int Arr[] = {2, 5, 1, 8};
  SortSelection s;
  ASSERT_NO_THROW(s.Sort());
}

TEST(SelectionSort, Throw_NO_operator) {
  int Arr[] = {2, 5, 1, 8};
  SortSelection s, s1;
  s.Sort();
  ASSERT_NO_THROW(s1 = s);
}

TEST(SelectionSort, Sort_OKAY) {
  int Arr[] = {2, 5, 1, 8};

  int Arr_res[] = {1, 2, 5, 8};
  SortSelection res(Arr, 4);

  res.Sort();

  ASSERT_EQ(res.Ex(Arr_res, 4), 1);
}
