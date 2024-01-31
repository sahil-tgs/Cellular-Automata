// main.cpp
#include "GameOfLife.h"

int main(int argc, char **argv) {
    // Create a GameOfLife instance
    GameOfLife game(20, 50);

    // Initialize the grid (you can choose either random or user input)
    game.initializeGridRandom();

    // Run the simulation
    game.runSimulation();

    return 0;
}
