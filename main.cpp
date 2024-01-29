#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

const int rows = 20;
const int cols = 50;

void printGrid(const vector<vector<bool>>& grid) {
    system("clear");  // For Linux/Mac. Use "cls" for Windows.
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << (grid[i][j] ? '#' : ' ');
        }
        cout << endl;
    }

    // Introduce a small delay for visualization
    this_thread::sleep_for(chrono::milliseconds(100));
}

int countNeighbors(const vector<vector<bool>>& grid, int x, int y) {
    int count = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;  // Skip the current cell
            int newX = x + i;
            int newY = y + j;

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                count += grid[newX][newY] ? 1 : 0;
            }
        }
    }

    return count;
}

void updateGrid(vector<vector<bool>>& grid) {
    vector<vector<bool>> newGrid(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = countNeighbors(grid, i, j);

            // Apply the rules of the Game of Life
            if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = false;  // Cell dies
            } else if (!grid[i][j] && neighbors == 3) {
                newGrid[i][j] = true;  // Cell is born
            } else {
                newGrid[i][j] = grid[i][j];  // Cell stays the same
            }
        }
    }

    grid = newGrid;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Initialize the grid with random values
    vector<vector<bool>> grid(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = rand() % 2 == 0;
        }
    }

    // Run the simulation
    while (true) {
        printGrid(grid);
        updateGrid(grid);
    }

    return 0;
}
