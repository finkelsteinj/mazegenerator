#include <cstdint>
#include <string>
#include <vector>
using namespace std;

struct BmpHeader {
    char bitmapSignatureBytes[2] = {'B', 'M'};
    uint32_t sizeOfBitmapFile;
    uint16_t reserved1 = 0;
    uint16_t reserved2 = 0;
    uint32_t pixelDataOffset = 54;

    BmpHeader(int32_t imageSize) : sizeOfBitmapFile(54 + imageSize) {};
    ~BmpHeader() {};
} __attribute__((packed));

struct DibHeader {
    uint32_t sizeOfThisHeader = 40;
    int32_t width; // in pixels
    int32_t height; // in pixels
    uint16_t numberOfColorPlanes = 1;
    uint16_t colorDepth = 24;
    uint32_t compressionMethod = 0;
    uint32_t rawBitmapDataSize = 0;
    int32_t horizontalResolution = 0; // in pixel per meter
    int32_t verticalResolution = 0; // in pixel per meter
    uint32_t colorTableEntries = 0;
    uint32_t importantColors = 0;

    DibHeader(int32_t _width, int32_t _height) : width(_width), height(_height) {};
    ~DibHeader() {};
};

struct Pixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;

    Pixel() : r(0), g(0), b(0) {};
    Pixel(uint8_t _r, uint8_t _g, uint8_t _b) : r(_r), g(_g), b(_b) {};
    ~Pixel() {};
};


class ColorImage {

private:
    int32_t width;
    int32_t height;
    vector<Pixel> pixels;
    
public:
    BmpHeader bmpHeader();
    DibHeader dibHeader(int32_t width, int32_t height);

    ColorImage(int32_t _width, int32_t _height) 
    : width(_width),
      height(_height),  
      pixels(vector<Pixel>(width * height))
    {};
    ~ColorImage() {};

    int32_t getWidth() const;
    int32_t getHeight() const;

    Pixel getPixel(int32_t x, int32_t y) const;
    void setPixel(Pixel& p, int32_t x, int32_t y);

    void Export(const string path);

};
