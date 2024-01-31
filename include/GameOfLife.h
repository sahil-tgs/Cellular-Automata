// In GameOfLife.h
#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "Grid.h"
#include <ncurses.h>

class GameOfLife {
public:
    GameOfLife(int rows, int cols);

    void initializeGridRandom();
    void updateGrid();
    void runSimulation();

private:
    int countNeighbors(int x, int y);
    void drawGrid();

    Grid grid_;
};

#endif // GAMEOFLIFE_H
