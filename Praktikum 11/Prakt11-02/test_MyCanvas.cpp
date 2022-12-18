// Datei: test_MyCanvas.cpp

#include <iostream>

#include "gip_mini_catch.h"

#include "MyCanvas.h"

void do_test(MyCanvas &canvas, unsigned int size_x, unsigned int size_y)
{
    unsigned int x = 0, y = 0;
    char c = '0';
    canvas.set(x, y, c);
    REQUIRE(canvas.get(x, y) == c);

    x = 1; y = 0; c = '1';
    canvas.set(x, y, c);
    REQUIRE(canvas.get(x, y) == c);

    x = 2; y = 0; c = '2';
    canvas.set(x, y, c);
    REQUIRE(canvas.get(x, y) == c);

    x = 0; y = 1; c = 'a';
    canvas.set(x, y, c);
    REQUIRE(canvas.get(x, y) == c);

    x = 0; y = 2; c = 'b';
    canvas.set(x, y, c);
    REQUIRE(canvas.get(x, y) == c);

    x = 0; y = 3; c = 'c';
    canvas.set(x, y, c);
    REQUIRE(canvas.get(x, y) == c);

    x = size_x - 1; y = size_y - 1; c = 'X';
    canvas.set(x, y, c);
    REQUIRE(canvas.get(x, y) == c);
}

void do_check(const MyCanvas &canvas, unsigned int size_x, unsigned int size_y)
{
    unsigned int x = 0, y = 0;
    char c = '0';
    REQUIRE(canvas.get(x, y) == c);

    x = 1; y = 0; c = '1';
    REQUIRE(canvas.get(x, y) == c);

    x = 2; y = 0; c = '2';
    REQUIRE(canvas.get(x, y) == c);

    x = 0; y = 1; c = 'a';
    REQUIRE(canvas.get(x, y) == c);

    x = 0; y = 2; c = 'b';
    REQUIRE(canvas.get(x, y) == c);

    x = 0; y = 3; c = 'c';
    REQUIRE(canvas.get(x, y) == c);

    x = size_x - 1; y = size_y - 1; c = 'X';
    REQUIRE(canvas.get(x, y) == c);
}

TEST_CASE("Test 5x3 MyCanvas init().")
{
    const unsigned int size_x = 5, size_y = 3;

    MyCanvas canvas{size_x, size_y};

    REQUIRE( canvas.get_size_x() == size_x );
    REQUIRE( canvas.get_size_y() == size_y );

    REQUIRE( canvas.get_canvas_array_ptr() != nullptr );

    REQUIRE( canvas.to_string() == ".....\n.....\n.....\n" );
}

TEST_CASE("Test 7x4 MyCanvas.")
{
    const unsigned int size_x = 7, size_y = 4;

    MyCanvas canvas{size_x, size_y};

    REQUIRE(canvas.get_size_x() == size_x);
    REQUIRE(canvas.get_size_y() == size_y);
    REQUIRE( canvas.get_canvas_array_ptr() != nullptr );

    do_test(canvas, size_x, size_y);

    REQUIRE(canvas.to_string() == "012....\na......\nb......\nc.....X\n" );
}

TEST_CASE("Test 9x6 MyCanvas.")
{
    const unsigned int size_x = 9, size_y = 6;

    MyCanvas canvas{size_x, size_y};

    REQUIRE(canvas.get_size_x() == size_x);
    REQUIRE(canvas.get_size_y() == size_y);
    REQUIRE( canvas.get_canvas_array_ptr() != nullptr );

    do_test(canvas, size_x, size_y);

    REQUIRE(canvas.to_string() == "012......\na........\nb........\nc........\n.........\n........X\n");
}

TEST_CASE("Test MyCanvas Copy Constructor.")
{
    const unsigned int size_x = 9, size_y = 6;

    MyCanvas canvas1{size_x, size_y};
    do_test(canvas1, size_x, size_y);

    MyCanvas canvas2 = canvas1;
    REQUIRE( canvas2.get_size_x() == size_x );
    REQUIRE( canvas2.get_size_y() == size_y );
    REQUIRE( canvas2.get_canvas_array_ptr() != nullptr );
    REQUIRE( canvas2.get_canvas_array_ptr() != canvas1.get_canvas_array_ptr() );

    do_check(canvas2, size_x, size_y);

    unsigned int x, y; char c;
    x = size_x - 1; y = size_y - 1; c = 'Y';
    canvas2.set(x, y, c);
    REQUIRE(canvas2.get(x, y) == c);
    REQUIRE(canvas1.get(x, y) == 'X');
}

TEST_CASE("Test MyCanvas Assignment Operator.")
{
    const unsigned int size_x1 = 9, size_y1 = 6;

    MyCanvas canvas1{size_x1, size_y1};
    do_test(canvas1, size_x1, size_y1);

    const unsigned int size_x2 = size_x1 + 9, size_y2 = size_y1 + 6;
    MyCanvas canvas2{size_x2, size_y2};
    REQUIRE(canvas2.get_size_x() == size_x2);
    REQUIRE(canvas2.get_size_y() == size_y2);
    char* canvas2_array_ptr_old = canvas2.get_canvas_array_ptr();
    REQUIRE( canvas2_array_ptr_old != nullptr );

    int old_delete_count = Catch::Session::get_delete_count();

    // The assignment ...
    canvas2 = canvas1;

    REQUIRE(Catch::Session::get_delete_count() == old_delete_count + 1);

    REQUIRE( canvas2.get_size_x() == size_x1 );
    REQUIRE( canvas2.get_size_y() == size_y1 );
    REQUIRE( canvas2.get_canvas_array_ptr() != nullptr );
    REQUIRE( canvas2.get_canvas_array_ptr() != canvas1.get_canvas_array_ptr() );
    REQUIRE( canvas2.get_canvas_array_ptr() != canvas2_array_ptr_old );

    unsigned int x, y; char c;
    x = size_x1 - 1; y = size_y1 - 1; c = 'Y';
    canvas2.set(x, y, c);
    REQUIRE(canvas2.get(x, y) == c);
    REQUIRE(canvas1.get(x, y) == 'X');

    do_test(canvas2, size_x1, size_y1);
}
