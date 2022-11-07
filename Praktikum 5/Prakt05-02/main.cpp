#define CATCH_CONFIG_RUNNER
#include "suchen_rekursiv.h"
#include "catch.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    Catch::Session().run();

    string text = "", zkette = "";
    cout << "Bitte geben Sie den Text ein: ";
    getline(cin, text);
    cout << "Bitte geben sie die zu suchende Zeichenkette ein: ";
    getline(cin, zkette);
    int result = zeichenkette_suchen_rekursiv(text, zkette);
    if (result != -1)
    {
        cout << "Die Zeichenkette '" << zkette << "' ist in dem Text '" << text << "' enthalten.\n"
             << "Sie startet ab Zeichen " << result << " (bei Zaehlung ab 0).\n";
    }
    else
        cout << "Die Zeichenkette '" << zkette << "' ist NICHT in dem Text '" << text << "' enthalten.\n";
    system("PAUSE");
    return 0;
}
