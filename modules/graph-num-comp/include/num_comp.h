// Copyright 2022 Petrova Polina

#ifndef MODULES_GRAPH_NUM_COMP_INCLUDE_NUM_COMP_H_
#define MODULES_GRAPH_NUM_COMP_INCLUDE_NUM_COMP_H_

#include <vector>
#include <random>

int generateRandEdge();

class matrixType {
 private:
    int numVert;
    std::vector<std::vector<int> > Graph;
 public:
    std::vector<bool> used;
    explicit matrixType(int n);  // where n - num of vertex
    matrixType(int numVert, const std::vector<std::vector<int> > &G);
    int& operator ()(int i, int j);
    int getNumVert();
    void DFS(int start, int f);
    int numComp(int f);
};
#endif  // MODULES_GRAPH_NUM_COMP_INCLUDE_NUM_COMP_H_
