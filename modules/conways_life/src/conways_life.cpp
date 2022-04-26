// Copyright 2022 Pinezhanin Evgeny

#include "include/conways_life.h"

#include <vector>

void ConwaysLife::initGrid() {
    grid->resize(5);
    for (int i = 0; i < 5; i++) {
        (*grid)[i].resize(5, 0);
    }
}

int ConwaysLife::numberLivingNeighbours(int x, int y, int width, int height,
    std::vector<std::vector<bool>> *_grid) const {
    int number = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i != x || j != y) {
                number += (*_grid)[(j + height) % height][(i + width) % width];
            }
        }
    }
    return number;
}

void ConwaysLife::generation(std::vector<std::vector<bool>> *_grid) const {
    std::vector<std::vector<bool>> *tmp_grid =
        new std::vector<std::vector<bool>>(*_grid);
    int height = _grid->size(), width = (*_grid)[0].size();
    int liveNeighbours;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            liveNeighbours = numberLivingNeighbours(j, i, width, height, _grid);
            if (!(*_grid)[i][j]) {
                if (liveNeighbours == 3) {
                    (*tmp_grid)[i][j] = true;
                }
            } else {
                if (liveNeighbours < 2 || liveNeighbours > 3) {
                    (*tmp_grid)[i][j] = false;
                }
            }
        }
    }
    *_grid = *tmp_grid;
    delete tmp_grid;
}

ConwaysLife::ConwaysLife() : grid(new std::vector<std::vector<bool>>) {
    initGrid();
}

ConwaysLife::ConwaysLife(const ConwaysLife &cl)
    : grid(new std::vector<std::vector<bool>>) {
    *grid = *(cl.grid);
}

void ConwaysLife::setGrid(const std::vector<std::vector<bool>> &_grid) {
    if (_grid.size() < 3) {
        throw "Error! Height less three";
    }
    for (unsigned int i = 1; i < _grid.size(); i++) {
        if (_grid[0].size() != _grid[i].size()) {
            throw "Error! Grid is not rectangle";
        }
    }
    if (_grid[0].size() < 3) {
        throw "Error! Width less three";
    }
    *grid = _grid;
}

std::vector<std::vector<bool>> ConwaysLife::getGrid() {
    return *grid;
}

bool ConwaysLife::isStable() const {
    std::vector<std::vector<bool>> *tmp_grid =
        new std::vector<std::vector<bool>>(*grid);
    generation(tmp_grid);
    if (*tmp_grid == *grid) {
        delete tmp_grid;
        return true;
    }
    delete tmp_grid;
    return false;
}

int ConwaysLife::isPeriodic(int max_per) const {
    if (max_per < 1) throw "Error! Period less one";
    std::vector<std::vector<bool>> *tmp_grid =
        new std::vector<std::vector<bool>>(*grid);
    for (int i = 0; i < max_per; i++) {
        generation(tmp_grid);
        if (*tmp_grid == *grid) {
            delete tmp_grid;
            return i + 1;
        }
    }
    delete tmp_grid;
    return -1;
}

void ConwaysLife::nextGen(int gen) {
    if (gen < 1) throw "Error! Gen less one";
    std::vector<std::vector<bool>> *tmp_grid =
        new std::vector<std::vector<bool>>(*grid);
    for (int i = 0; i < gen; i++) {
        generation(tmp_grid);
    }
    *grid = *tmp_grid;
    delete tmp_grid;
}
