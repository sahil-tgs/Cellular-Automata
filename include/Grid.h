// Grid.h

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>

class Grid {
public:
    Grid(int rows, int cols);
    void initializeRandom();
    void initializeFromUserInput();
    void initializeFromPattern(const std::string& patternName);
    void print() const;
    int getRows() const { return rows_; }
    int getCols() const { return cols_; }
    bool getCell(int x, int y) const;
    void setCell(int x, int y, bool value);

private:
    int rows_;
    int cols_;
    std::vector<std::vector<bool>> data_;
};

#endif
