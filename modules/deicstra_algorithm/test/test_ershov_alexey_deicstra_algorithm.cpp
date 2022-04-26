// Copyright 2022 Ershov Alexey

#include <gtest/gtest.h>

#include <vector>

#include "./include/ershov_alexey_deicstra_algorithm.h"

TEST(Algorithm, Test_Default_No_Throw) { ASSERT_NO_THROW(Algorithm deicstra); }

TEST(Algorithm, Test_Default_Copy_No_Throw) {
  Algorithm deicstra;
  ASSERT_NO_THROW(Algorithm simpleAlgorithm(deicstra));
}

TEST(Random_Vector, Test_Default_No_Throw) {
  Algorithm deicstra;
  ASSERT_NO_THROW(deicstra.getRandomVector());
}

TEST(Random_Vector, Test_No_Throw) {
  size_t count = 10;
  Algorithm deicstra;
  ASSERT_NO_THROW(deicstra.getRandomVector(count));
}

TEST(Deicstra_Algorithm, Test_Default_No_Throw) {
  Algorithm deicstra;
  ASSERT_NO_THROW(deicstra.getDeicstra());
}

TEST(Deicstra_Algorithm, Test_Default_Top_No_Throw) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  Algorithm deicstra;

  ASSERT_NO_THROW(deicstra.getDeicstra(graf));
}

TEST(Deicstra_Algorithm, Test_No_Throw) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const size_t top = 5;
  Algorithm deicstra;

  ASSERT_NO_THROW(deicstra.getDeicstra(graf, top));
}

TEST(Deicstra_Algorithm, Test_Top_Greater_Count_No_Throw) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const size_t top = 10;
  Algorithm deicstra;

  ASSERT_NO_THROW(deicstra.getDeicstra(graf, top));
}

TEST(Deicstra_Algorithm, Test_Top_Null_Vector_No_Throw) {
  const std::vector<std::vector<size_t>> graf = {};
  const size_t top = 10;
  Algorithm deicstra;

  ASSERT_NO_THROW(deicstra.getDeicstra(graf, top));
}

TEST(Deicstra_Algorithm, Test_Default_Top_Null_Vector_No_Throw) {
  const std::vector<std::vector<size_t>> graf = {};
  Algorithm deicstra;
  ASSERT_NO_THROW(deicstra.getDeicstra(graf));
}

TEST(Deicstra_Algorithm, Test_First_Top_Null_Vector_No_Throw) {
  const std::vector<std::vector<size_t>> graf = {};
  const size_t top = 0;
  Algorithm deicstra;

  ASSERT_NO_THROW(deicstra.getDeicstra(graf, top));
}

TEST(Deicstra_Algorithm, Test_Single_Top_Correctness) {
  const std::vector<std::vector<size_t>> graf = {{10}};
  const size_t top = 0;
  const size_t count = graf.size();
  const std::vector<size_t> trueResult = {0};
  bool check = true;
  Algorithm deicstra;

  std::vector<size_t> algorithmResult = deicstra.getDeicstra(graf, 0);
  for (size_t i = 0; i < count; ++i) {
    if (trueResult[i] != algorithmResult[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Deicstra_Algorithm, Test_First_Top_With_Static_Data) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const std::vector<size_t> trueResult = {0, 7, 9, 20, 20, 11};
  bool check = true;
  const size_t count = graf.size();
  Algorithm deicstra;

  std::vector<size_t> algorithmResult = deicstra.getDeicstra(graf, 0);
  for (size_t i = 0; i < count; ++i) {
    if (trueResult[i] != algorithmResult[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Deicstra_Algorithm, Test_No_Top_With_Static_Data) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const std::vector<size_t> trueResult = {0, 7, 9, 20, 20, 11};
  bool check = true;
  const size_t count = graf.size();
  Algorithm deicstra;

  std::vector<size_t> algorithmResult = deicstra.getDeicstra(graf);
  for (size_t i = 0; i < count; ++i) {
    if (trueResult[i] != algorithmResult[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Deicstra_Algorithm, Test_Default_Top_With_Default_Data) {
  const std::vector<size_t> trueResult = {0, 7, 9, 20, 20, 11};
  bool check = true;
  const size_t count = 6;
  Algorithm deicstra;

  std::vector<size_t> algorithmResult = deicstra.getDeicstra();
  for (size_t i = 0; i < count; ++i) {
    if (trueResult[i] != algorithmResult[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Deicstra_Algorithm, Test_Last_Top_With_Static_Data) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  const std::vector<size_t> trueResult = {11, 12, 2, 13, 9, 0};
  bool check = true;
  const size_t count = graf.size();
  Algorithm deicstra;

  std::vector<size_t> algorithmResult = deicstra.getDeicstra(graf, count - 1);
  for (size_t i = 0; i < count; ++i) {
    if (trueResult[i] != algorithmResult[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Deicstra_Algorithm, Test_Last_Top_Two_Times_Static) {
  const std::vector<std::vector<size_t>> graf = {
      {0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};
  bool check = true;
  const size_t count = graf.size();
  Algorithm deicstra;

  const std::vector<size_t> algorithmResultFirst =
      deicstra.getDeicstra(graf, count - 1);

  const std::vector<size_t> algorithmResultSecond =
      deicstra.getDeicstra(graf, count - 1);

  for (size_t i = 0; i < count; ++i) {
    if (algorithmResultFirst[i] != algorithmResultSecond[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}

TEST(Deicstra_Algorithm, Test_Last_Top_Two_Times_Random) {
  Algorithm deicstra;
  const std::vector<std::vector<size_t>> graf = deicstra.getRandomVector(10);
  bool check = true;
  const size_t count = graf.size();

  const std::vector<size_t> algorithmResultFirst =
      deicstra.getDeicstra(graf, count - 1);

  const std::vector<size_t> algorithmResultSecond =
      deicstra.getDeicstra(graf, count - 1);

  for (size_t i = 0; i < count; ++i) {
    if (algorithmResultFirst[i] != algorithmResultSecond[i]) {
      check = false;
    }
  }

  ASSERT_EQ(check, true);
}
