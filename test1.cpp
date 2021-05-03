#include <iostream>
#include "ColorImage.hpp"
using namespace std;

int main() {
    ColorImage ci(640, 480);
    Pixel p(0, 255, 255);
    ci.setPixel(p, 50, 50);
    cout << ci.getPixel(50, 50).r << endl;
    cout << ci.getPixel(50, 50).g << endl;
    cout << ci.getPixel(50, 50).b << endl;

    return 0;
}