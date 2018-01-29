#include "image.h"
#include <iostream>

int main()
{
    Image christmas = readPGM("christmas.pgm");

    Image christmas_x = mirror_x(christmas);
    writePGM(christmas_x, "christmas-mirror-x.pgm");


    Image christmas_y = mirror_y(christmas);
    writePGM(christmas_y, "christmas-mirror-y.pgm");

    // Image christmas_4 = kaleidoscope4(christmas);
    // writePGM(christmas_4, "christmas-kaleidoscope-4.pgm");
    // Image christmas_8 = kaleidoscope8(christmas);
    // writePGM(christmas_8, "christmas-kaleidoscope-8.pgm");

    Image my_image = readPGM("my_image.pgm");
    Image my_image8 = kaleidoscope8(my_image);
    writePGM(my_image8, "my_kaleidoscope.pgm");

    return 0;
}