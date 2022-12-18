// Datei: test_MyFramedRectangle.cpp

#define TEST_FILE test_MyFramedRectangle

#include "gip_mini_catch.h"

#include "MyFramedRectangle.h"

TEST_CASE("Test (3,4,16,9) FramedRectangle on 20x15 MyCanvas.")
{
    const unsigned int size_x = 20, size_y = 15;

    MyCanvas canvas{size_x, size_y};

    unsigned int x1 = 3;
    unsigned int y1 = 4;
    unsigned int x2 = 16;
    unsigned int y2 = 9;
    MyFramedRectangle r1(canvas, x1, y1, x2, y2);

    r1.draw();

    REQUIRE( canvas.to_string() == "....................\n....................\n....................\n....................\n...++++++++++++++...\n...+############+...\n...+############+...\n...+############+...\n...+############+...\n...++++++++++++++...\n....................\n....................\n....................\n....................\n....................\n" );
}
