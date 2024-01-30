#include "GameOfLife.h"
#include <thread>
#include <chrono>

GameOfLife::GameOfLife(int rows, int cols) : grid_(rows, cols) {
}

void GameOfLife::initializeGridRandom() {
    grid_.initializeRandom();
}

void GameOfLife::updateGrid() {
    // Implementation of updateGrid
    // ...

    // You can access the grid using grid_.getCell(x, y) and modify cells with grid_.setCell(x, y, value)
}

void GameOfLife::runSimulation() {
    while (true) {
        grid_.print();
        updateGrid();
        // Introduce a small delay for visualization
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
