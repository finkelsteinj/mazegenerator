#include <fstream>
#include <iostream>
#include <cstdint>
#include "ColorImage.hpp"

Pixel ColorImage::getPixel(int32_t x, int32_t y) const {
    return pixels.at(y * width + x);
}

void ColorImage::setPixel(Pixel& p, int32_t x, int32_t y) {
    pixels.at(y * width + x).r = p.r;
    pixels.at(y * width + x).g = p.g;
    pixels.at(y * width + x).b = p.b;
}

void ColorImage::Export(const string path) {
    ofstream file;
    file.open(path, ios::out | ios::binary);

    if(!file.is_open()) {
        cout << "File could not be opened." << endl;
        return;
    }

    int32_t imageSize = width * height * 3;
    BmpHeader bmpHeader(imageSize);
    DibHeader dibHeader(width, height);

    // file.write((char*)&bmpHeader, sizeof(BmpHeader));
    // file.write((char*)&dibHeader, sizeof(DibHeader));
    file.write((char*)&bmpHeader, 14);
    file.write((char*)&dibHeader, 40);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uint8_t r = getPixel(x, y).r;
            uint8_t g = getPixel(x, y).g;
            uint8_t b = getPixel(x, y).b;
            
            Pixel p(b, g, r);
            file.write((char*)&p, 3);
        } 
    }

    file.close();
    cout << "Image has been created." << endl;
}