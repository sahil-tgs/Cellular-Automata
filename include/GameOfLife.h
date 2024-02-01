#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "Grid.h"

class GameOfLife {
public:
    GameOfLife(int rows, int cols);

    void initializeGridRandom();
    void updateGrid();
    void runSimulation();

private:
    int countNeighbors(int x, int y);

    Grid grid_;
};

#endif



//comment to setup fall back