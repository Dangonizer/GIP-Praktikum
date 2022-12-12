// Datei: main.cpp

#define CATCH_CONFIG_RUNNER
#include "gip_mini_catch.h"

#include "MyCanvas.h"

int main()
{
    // Aufruf der Unit Tests ...
    Catch::Session().run();

    system("PAUSE");
    return 0;
}
