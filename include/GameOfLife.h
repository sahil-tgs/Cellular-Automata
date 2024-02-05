// GameOfLife.h

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "Grid.h"

class GameOfLife {
public:
    GameOfLife(int rows, int cols);

    void initializeGridRandom();
    void updateGrid();
    void runSimulation();

    // Make the grid_ member public
    Grid grid_;
};

#endif
