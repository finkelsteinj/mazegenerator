#include <cstdint>
#include <iostream>
#include "Maze.hpp"
using namespace std;

int main() {
    const int32_t WIDTH = 640;
    const int32_t HEIGHT = 480;

    ColorImage image(WIDTH, HEIGHT);
    Maze maze(image, 0, 0);
    maze.generateMaze();

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Pixel p(0, 255, 255);
            image.setPixel(p, x, y);
        }
        
    }

    image.Export("image.bmp");
    return 0;
}
