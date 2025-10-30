#include <iostream>
#include "Image.h"

int main() {

    Image img;

    img.readPPM("test.ppm");

    img += 50; //increase brightness by 50;

    img.writePPM("brightened.ppm");

    img += -100; //darkend by 100

    img.writePPM("darkened.ppm");

    return 0;

}

