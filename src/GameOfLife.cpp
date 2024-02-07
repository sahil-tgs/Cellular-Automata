#include "GameOfLife.h"
#include <thread>
#include <chrono>

GameOfLife::GameOfLife(int rows, int cols) : grid_(rows, cols) {
}

void GameOfLife::initializeGridRandom() {
    grid_.initializeRandom();
}

void GameOfLife::initializeGridFromPattern(const std::string& patternName) {
    grid_.initializeFromPattern(patternName);
}

int GameOfLife::countNeighbors(int x, int y) {
    int count = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }

            int newX = x + i;
            int newY = y + j;

            if (newX >= 0 && newX < grid_.getRows() && newY >= 0 && newY < grid_.getCols()) {
                if (grid_.getCell(newX, newY)) {
                    ++count;
                }
            }
        }
    }

    return count;
}

void GameOfLife::updateGrid() {
    Grid newGrid(grid_.getRows(), grid_.getCols());

    for (int i = 0; i < grid_.getRows(); ++i) {
        for (int j = 0; j < grid_.getCols(); ++j) {
            int neighbors = countNeighbors(i, j);

            if (grid_.getCell(i, j)) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid.setCell(i, j, false);
                } else {
                    newGrid.setCell(i, j, true);
                }
            } else {
                if (neighbors == 3) {
                    newGrid.setCell(i, j, true);
                }
            }
        }
    }

    grid_ = newGrid;
}

void GameOfLife::runSimulation() {
    while (true) {
        grid_.print();
        updateGrid();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
