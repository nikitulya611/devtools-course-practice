// Copyright 2022 Miheev Ivan

#include <gtest/gtest.h>
#include "include/DHeap.h"

TEST(miheev_ivan_dheap, can_call_constructor_with_default_param) {
  // Assert
  ASSERT_NO_THROW(DHeap());
}

TEST(miheev_ivan_dheap, can_call_constructor_with_input_param) {
  // Assert
  ASSERT_NO_THROW(DHeap(15, 6));
}

TEST(miheev_ivan_dheap, dary_larger_than_capacity) {
  // Assert
  ASSERT_NO_THROW(DHeap(5, 20));
}

TEST(miheev_ivan_dheap, can_create_heap_with_wrong_dary) {
  // Assert
  ASSERT_ANY_THROW(DHeap(3, -2));
}

TEST(miheev_ivan_dheap, can_create_heap_with_wrong_capacity) {
  // Assert
  ASSERT_ANY_THROW(DHeap(-5, 2));
}

TEST(miheev_ivan_dheap, empty_test) {
  // Arrange & Act
  DHeap hp;
  // Assert
  ASSERT_NO_THROW(hp.isEmpty());
}

TEST(miheev_ivan_dheap, not_empty_test) {
  // Arrange & Act
  DHeap hp;
  hp.insert(1);
  // Assert
  ASSERT_EQ(0, hp.isEmpty());
}

TEST(miheev_ivan_dheap, full_test) {
  // Arrange & Act
  DHeap hp;
  hp.insert(1);

  // Assert
  ASSERT_NO_THROW(hp.isFull());
}

TEST(miheev_ivan_dheap, not_full_test) {
  // Arrange & Act
  DHeap hp;

  // Assert
  ASSERT_EQ(0, hp.isFull());
}

TEST(miheev_ivan_dheap, insert_test) {
  // Arrange & Act
  DHeap hp;
  // Assert
  ASSERT_NO_THROW(hp.insert(0));
}

TEST(miheev_ivan_dheap, insert_multiply_values_test) {
  // Arrange & Act
  DHeap hp;
  for (int i = -4; i < 0; i++) hp.insert(i);
  // Assert
  ASSERT_NO_THROW(hp.insert(5));
}

TEST(miheev_ivan_dheap, extract_min_test) {
  // Arrange & Act
  DHeap hp;
  for (int i = 4; i > 0; i--) hp.insert(i);
  hp.insert(-5);
  // Assert
  ASSERT_EQ(-5, hp.extractMin());
}

TEST(miheev_ivan_dheap, extract_min_with_equal_values_test) {
  // Arrange & Act
  DHeap hp;
  for (int i = 4; i > 0; i--) hp.insert(1);
  // Assert
  ASSERT_EQ(1, hp.extractMin());
}

TEST(miheev_ivan_dheap, copy_constructor_test) {
  // Arrange & Act
  DHeap hp(4, 3);
  // Assert
  ASSERT_NO_THROW(DHeap(hp));
}

TEST(miheev_ivan_dheap, copy_constructor_equality_test) {
  // Arrange & Act
  DHeap hp(4, 3);
  DHeap cpyhp(hp);
  // Assert
  while (!hp.isEmpty()) {
    ASSERT_EQ(hp.extractMin(), cpyhp.extractMin());
  }
}

TEST(miheev_ivan_dheap, extract_decreased_value_test) {
  // Arrange & Act
  DHeap hp;
  for (int i = 10; i > 0; i--) hp.insert(i);
  hp.decreaseValue(5, -5);
  // Assert
    ASSERT_EQ(-5, hp.extractMin());
}

TEST(miheev_ivan_dheap, throw_empty_test) {
  // Arrange & Act
  DHeap hp;

  // Assert
  ASSERT_ANY_THROW(hp.extractMin());
}
