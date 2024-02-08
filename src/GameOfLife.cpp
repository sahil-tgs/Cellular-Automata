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
    // Implementation remains the same
}

void GameOfLife::updateGrid() {
    // Implementation remains the same
}

void GameOfLife::runSimulation() {
    while (true) {
        grid_.print();
        updateGrid();
        // Introduce a small delay for visualization
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Check if the simulation should continue
        if (!grid_.hasAliveCells()) {
            char choice;
            std::cout << "Simulation finished. Do you want to start another simulation? (y/n): ";
            std::cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                std::cout << "Exiting...\n";
                break;
            } else {
                std::cout << "Starting new simulation...\n";
                // Reinitialize the grid for the new simulation
                initializeGridRandom(); // or any other initialization method you prefer
            }
        }
    }
}
