// Copyright 2022 Petrova Polina

#include"../include/num_comp.h"
#include <vector>

// NOLINTNEXTLINE
matrixType::matrixType(int n) {
    matrixType::numVert = n;
    for (int i = 0; i < numVert; i++) {
        matrixType::Graph.push_back(std::vector<int>());
        for (int j = 0; j < numVert; j++) {
            Graph[i].push_back(0);
            if (i == j)
                Graph[i][j] = 0;
            else
                Graph[i][j] = generateRandEdge();
        }
    }
    for (int i = 0; i < numVert; i++)
        for (int j = 0; j < numVert; j++)
            Graph[i][j] = Graph[j][i];
}
int matrixType::getNumVert() {
    return this->Graph.size();
}
matrixType::matrixType(int numvert, const std::vector<std::vector<int>> &G)
    : numVert{numvert}, Graph{ G } {
    //  matrixType::numVert = numvert;
    //  matrixType::Graph = G;
}

int generateRandEdge() {
    int k;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);  //  can do graph with weight
    k = dist(gen);
    return k;
}
int& matrixType::operator()(int i, int j) {
    this->numComp(8);
    return this->Graph[i][j];
}
void matrixType::DFS(int start, int f) {
    this->getNumVert();
    if (f != 0) {
        for (int i = 0; i < this->numVert; i++)
            this->used.push_back(false);
        f = 0;
    }
    // std::cout << start << " ";
    this->used[start] = true;
    for (int i = 0; i < this->numVert; i++)
        if (!used[i] && (this->Graph[start][i] != 0))
            DFS(i, f);
}
int matrixType::numComp(int f) {
    if (f != 0) {
        for (int i = 0; i < this->numVert; i++)
            this->used.push_back(false);
        f = 0;
    }
    int n = 0;
    for (int i = 0; i < this->numVert; i++) {
        if (!used[i]) {
            ++n;
            matrixType::DFS(i, f);
        }
    }
    return n;
}
