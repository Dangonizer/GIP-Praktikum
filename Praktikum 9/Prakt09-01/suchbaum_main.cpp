// Datei: suchbaum_main.cpp

#define CATCH_CONFIG_RUNNER
#include "gip_mini_catch.h"

#include <iostream>

#include "binaerer_suchbaum.h"

int main()
{
    // Aufruf der Unit Tests ...
    Catch::Session().run();

    int wert = 99;

    suchbaum::BaumKnoten *anker = nullptr;

    suchbaum::ausgeben(anker);

    do
    {
        std::cout << "Naechster Wert (99 beendet): ? ";
        std::cin >> wert;

        if (wert != 99)
        {
            suchbaum::einfuegen(anker, wert);
        }

    } while (wert != 99);

    suchbaum::ausgeben(anker);

    system("PAUSE");
    return 0;
}
