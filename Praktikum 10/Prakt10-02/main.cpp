// Datei: main.cpp

#include <random>
#include <chrono>

#define CATCH_CONFIG_RUNNER
#include "gip_mini_catch.h"

#include "MyCanvas.h"
#include "MyRectangle.h"

unsigned int random_unsigned(unsigned int low, unsigned int high)
{
    static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine gen(seed);
    std::uniform_int_distribution<> dist(low, high);
    unsigned int result = 0;
    do
    {
        result = unsigned(dist(gen));
    } while (result < low || result > high);
    return result;
}

int main()
{
    // Aufruf der Unit Tests ...
    Catch::Session().run();

    const unsigned int size_x = 20, size_y = 15;

    MyCanvas canvas{size_x, size_y};

    unsigned int x1 = random_unsigned(0, size_x / 2);
    unsigned int y1 = random_unsigned(0, size_y / 2);
    unsigned int x2 = random_unsigned(x1, size_x - 1);
    unsigned int y2 = random_unsigned(y1, size_y - 1);

    std::cout << "(" << x1 << ", " << y1 << ") bis ("
              << x2 << ", " << y2 << ")\n";

    MyRectangle r1(canvas, x1, y1, x2, y2);

    r1.draw();
    canvas.print();

    system("PAUSE");
    return 0;
}
