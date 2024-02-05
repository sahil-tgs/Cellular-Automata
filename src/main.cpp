// main.cpp

#include "GameOfLife.h"
#include <iostream>

int main() {
    // Create a GameOfLife instance
    GameOfLife game(20, 50);

    // Allow users to choose a pattern
    std::cout << "Choose a pattern to initialize the grid:\n";
    std::cout << "1. Glider\n";
    // Add more patterns as needed

    int patternChoice;
    std::cout << "Enter the pattern number: ";
    std::cin >> patternChoice;

    switch (patternChoice) {
        case 1:
            game.grid_.initializeFromPattern("Glider");
            break;
        // Add more cases for additional patterns

        default:
            std::cout << "Invalid choice. Initializing with random configuration.\n";
            game.initializeGridRandom();
            break;
    }

    // Run the simulation
    game.runSimulation();

    return 0;
}
