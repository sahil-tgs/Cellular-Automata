#include "GameOfLife.h"

int main() {
    // Create a GameOfLife instance
    GameOfLife game(20, 50);

    // Initialize the grid (you can choose either random or user input)
    game.initializeGridRandom();
    // game.grid_.initializeFromUserInput(); // No longer accessible directly

    // Run the simulation
    game.runSimulation();

    return 0;
}
