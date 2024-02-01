// ~/GameOfLife.cpp

#include "GameOfLife.h"
#include <thread>
#include <chrono>

GameOfLife::GameOfLife(int rows, int cols) : grid_(rows, cols) {
}

void GameOfLife::initializeGridRandom() {
    grid_.initializeRandom();
}

int GameOfLife::countNeighbors(int x, int y) {
    int count = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;  // Skip the center cell (current cell)
            }

            int newX = x + i;
            int newY = y + j;

            // Check if the neighbor is within bounds and alive
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

            // Apply Conway's Game of Life rules
            if (grid_.getCell(i, j)) {
                // Cell is alive
                if (neighbors < 2 || neighbors > 3) {
                    newGrid.setCell(i, j, false);  // Cell dies due to underpopulation or overpopulation
                } else {
                    newGrid.setCell(i, j, true);  // Cell survives
                }
            } else {
                // Cell is dead
                if (neighbors == 3) {
                    newGrid.setCell(i, j, true);  // Cell becomes alive due to reproduction
                }
            }
        }
    }

    // Update the original grid with the new state
    grid_ = newGrid;
}

void GameOfLife::runSimulation() {
    while (true) {
        grid_.print();
        updateGrid();
        // Introduce a small delay for visualization
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}



//comment to setup fall back