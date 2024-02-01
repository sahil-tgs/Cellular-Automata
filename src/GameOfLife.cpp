#include "GameOfLife.h"
#include "Grid.h"
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
            if (i == 0 && j == 0) continue;  // Skip the current cell
            int newX = x + i;
            int newY = y + j;

            if (newX >= 0 && newX < grid_.getRows() && newY >= 0 && newY < grid_.getCols()) {
                count += grid_.getCell(newX, newY) ? 1 : 0;
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

            // Apply the rules of Conway's Game of Life
            if (grid_.getCell(i, j) && (neighbors < 2 || neighbors > 3)) {
                newGrid.setCell(i, j, false);  // Cell dies
            } else if (!grid_.getCell(i, j) && neighbors == 3) {
                newGrid.setCell(i, j, true);   // Cell is born
            } else {
                newGrid.setCell(i, j, grid_.getCell(i, j));  // Cell stays the same
            }
        }
    }

    // Update the original grid with the new grid
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
