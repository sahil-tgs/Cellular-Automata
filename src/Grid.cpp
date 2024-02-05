// Grid.cpp

#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

Grid::Grid(int rows, int cols) : rows_(rows), cols_(cols), data_(rows, std::vector<bool>(cols, false)) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Grid::initializeRandom() {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = std::rand() % 2 == 0;
        }
    }
}

void Grid::initializeFromUserInput() {
    std::cout << "Enter initial configuration (0 for dead, 1 for alive):\n";

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            int userInput;
            std::cout << "Cell (" << i << ", " << j << "): ";
            std::cin >> userInput;
            data_[i][j] = userInput == 1;
        }
    }
}

void Grid::initializeFromPattern(const std::string& patternName) {
    std::unordered_map<std::string, std::vector<std::vector<bool>>> patterns = {
        {"Glider", {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}}},
        // Add more patterns as needed
    };

    auto it = patterns.find(patternName);
    if (it != patterns.end()) {
        const auto& pattern = it->second;
        for (int i = 0; i < pattern.size() && i < rows_; ++i) {
            for (int j = 0; j < pattern[i].size() && j < cols_; ++j) {
                data_[i][j] = pattern[i][j];
            }
        }
    } else {
        std::cout << "Pattern not found. Using random initialization.\n";
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

//comment to setup fall back