#include "GameOfLife.h"
#include <iostream>

int main() {
    GameOfLife game(20, 50);

    std::cout << "Choose a pattern to initialize the grid:\n";
    std::cout << "1. Glider\n";
    std::cout << "2. Blinker\n";
    std::cout << "3. Beacon\n";
    std::cout << "4. Toad\n";
    std::cout << "5. Pulsar\n";
    std::cout << "6. Random\n";
    std::cout << "Enter the pattern number: ";

    int patternChoice;
    std::cin >> patternChoice;

    switch (patternChoice) {
        case 1:
            game.initializeGridFromPattern("Glider");
            break;
        case 2:
            game.initializeGridFromPattern("Blinker");
            break;
        case 3:
            game.initializeGridFromPattern("Beacon");
            break;
        case 4:
            game.initializeGridFromPattern("Toad");
            break;
        case 5:
            game.initializeGridFromPattern("Pulsar");
            break;
        case 6:
            game.initializeGridRandom();
            break;
        default:
            std::cout << "Invalid choice. Initializing with random configuration.\n";
            game.initializeGridRandom();
            break;
    }

    game.runSimulation();

    return 0;
}
