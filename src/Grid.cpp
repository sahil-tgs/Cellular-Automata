// In Grid.cpp
#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Grid::Grid(int rows, int cols) : rows_(rows), cols_(cols), data_(rows, std::vector<bool>(cols, false)) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));  // Seed the random number generator
}

void Grid::initializeRandom() {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = std::rand() % 2 == 0;
        }
    }
}

void Grid::initializeFromUserInput() {
    // Implement user input for initializing the grid
    // You can use std::cin to get input from the user
}

void Grid::print() const {
    system("clear");  // For Linux/Mac. Use "cls" for Windows.

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cout << (data_[i][j] ? '#' : ' ');
        }
        std::cout << std::endl;
    }
}

bool Grid::getCell(int x, int y) const {
    if (x >= 0 && x < rows_ && y >= 0 && y < cols_) {
        return data_[x][y];
    }
    return false; // Consider out-of-bounds as a dead cell
}

void Grid::setCell(int x, int y, bool value) {
    if (x >= 0 && x < rows_ && y >= 0 && y < cols_) {
        data_[x][y] = value;
    }
}
