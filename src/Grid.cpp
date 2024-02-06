#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Grid::Grid(int rows, int cols) : rows_(rows), cols_(cols), data_(rows, std::vector<bool>(cols, false)) {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Grid::initializeRandom() {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = std::rand() % 2 == 0;
        }
    }
}

// void Grid::initializeFromUserInput() {
//     // Implement user input for initializing the grid
//     // You can use std::cin to get input from the user
// }

void Grid::initializeFromPattern(const std::string& patternName) {
    if (patternName == "Glider") {
        initializeGlider();
    } else if (patternName == "Blinker") {
        initializeBlinker();
    } else if (patternName == "Beacon") {
        initializeBeacon();
    } else if (patternName == "Toad") {
        initializeToad();
    } else if (patternName == "Pulsar") {
        initializePulsar();
    } else {
        std::cerr << "Invalid pattern name. Initializing with random configuration.\n";
        initializeRandom();
    }
}

void Grid::print() const {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

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
    return false;
}

void Grid::setCell(int x, int y, bool value) {
    if (x >= 0 && x < rows_ && y >= 0 && y < cols_) {
        data_[x][y] = value;
    }
}

void Grid::initializeGlider() {
    data_[0][1] = true;
    data_[1][2] = true;
    data_[2][0] = true;
    data_[2][1] = true;
    data_[2][2] = true;
}

void Grid::initializeBlinker() {
    data_[0][1] = true;
    data_[1][1] = true;
    data_[2][1] = true;
}

void Grid::initializeBeacon() {
    data_[0][0] = true;
    data_[0][1] = true;
    data_[1][0] = true;
    data_[2][3] = true;
    data_[3][2] = true;
    data_[3][3] = true;
}

void Grid::initializeToad() {
    data_[1][1] = true;
    data_[1][2] = true;
    data_[1][3] = true;
    data_[2][0] = true;
    data_[2][1] = true;
    data_[2][2] = true;
}

void Grid::initializePulsar() {
    data_[2][4] = true;
    data_[2][5] = true;
    data_[2][6] = true;
    data_[2][10] = true;
    data_[2][11] = true;
    data_[2][12] = true;

    data_[4][2] = true;
    data_[4][7] = true;
    data_[4][9] = true;
    data_[4][14] = true;

    data_[7][2] = true;
    data_[7][7] = true;
    data_[7][9] = true;
    data_[7][14] = true;

    data_[9][4] = true;
    data_[9][5] = true;
    data_[9][6] = true;
    data_[9][10] = true;
    data_[9][11] = true;
    data_[9][12] = true;

    data_[10][4] = true;
    data_[10][5] = true;
    data_[10][6] = true;
    data_[10][10] = true;
    data_[10][11] = true;
    data_[10][12] = true;

    data_[12][2] = true;
    data_[12][7] = true;
    data_[12][9] = true;
    data_[12][14] = true;

    data_[14][4] = true;
    data_[14][5] = true;
    data_[14][6] = true;
    data_[14][10] = true;
    data_[14][11] = true;
    data_[14][12] = true;
}