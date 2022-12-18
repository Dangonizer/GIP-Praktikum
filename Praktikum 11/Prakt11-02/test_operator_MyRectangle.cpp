// Datei: test_operator_MyRectangle.cpp

#define TEST_FILE test_operator_MyRectangle

#include "gip_mini_catch.h"

#include "MyRectangle.h"

TEST_CASE("Test (1,2,6,5) Rectangle operator* ( 2 ).")
{
    const unsigned int size_x = 60, size_y = 20;

    MyCanvas canvas{size_x, size_y};

    unsigned int x1 = 1;
    unsigned int y1 = 2;
    unsigned int x2 = 6;
    unsigned int y2 = 5;
    MyRectangle r1(canvas, x1, y1, x2, y2);

    MyRectangle r2 = r1 * 2;

    REQUIRE( r2.get_x1() == r1.get_x1() );
    REQUIRE( r2.get_y1() == r1.get_y1() );

    REQUIRE( r2.get_x2() == 11 );
    REQUIRE( r2.get_y2() == 8 );
}

TEST_CASE("Test (1,2,6,5) Rectangle operator* ( 3 ).")
{
    const unsigned int size_x = 60, size_y = 20;

    MyCanvas canvas{size_x, size_y};

    unsigned int x1 = 1;
    unsigned int y1 = 2;
    unsigned int x2 = 6;
    unsigned int y2 = 5;
    MyRectangle r1(canvas, x1, y1, x2, y2);

    MyRectangle r2 = r1 * 3;

    REQUIRE( r2.get_x1() == r1.get_x1() );
    REQUIRE( r2.get_y1() == r1.get_y1() );

    REQUIRE( r2.get_x2() == 16 );
    REQUIRE( r2.get_y2() == 11 );
}
