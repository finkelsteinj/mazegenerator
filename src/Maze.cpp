#include "Maze.hpp"

void Maze::generateMaze() {
    for (int32_t y = 0; y < WIDTH; y++) {
        for (int32_t x = 0; x < HEIGHT; x++) {
            depthFirstSearch(x, y);
        }
    }
}

void Maze::depthFirstSearch(int32_t x, int32_t y) {
    if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;

    if(visitedCells[y * WIDTH + x]) return;

    if(getVisitedNeighbors(x, y) > 1) return;

    visitedCells[y * WIDTH + x] = true;
    

    // for
}

int getVisitedNeighbors(int32_t x, int32_t y) {

}