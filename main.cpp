#include <cstdint>
#include <iostream>
#include "ColorImage.hpp"
using namespace std;

int main() {
    const int32_t width = 640;
    const int32_t height = 480;

    ColorImage image(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel p(0, 255, 255);
            image.setPixel(p, x, y);
        } 
    }

    image.Export("image.bmp");

    return 0;
}
