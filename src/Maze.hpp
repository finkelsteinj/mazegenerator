#include <stdint.h>
#include <vector>
#include "ColorImage.hpp"
using namespace std;

class Maze {
    private:
        int32_t x;
        int32_t y;
        const int32_t WIDTH;
        const int32_t HEIGHT;
        ColorImage *image;
        vector<bool> visitedCells;

        void depthFirstSearch(int32_t x, int32_t y);
        int getVisitedNeighbors(int32_t x, int32_t y);

    public: 
        Maze(ColorImage &i, int32_t initialX, int32_t initialY) 
        : x(initialX),
          y(initialY),
          WIDTH(i.getWidth()),
          HEIGHT(i.getHeight()),
          image(&i),
          visitedCells(vector<bool>(WIDTH * HEIGHT))
        {};
        ~Maze() {};
        
        void generateMaze();
};
