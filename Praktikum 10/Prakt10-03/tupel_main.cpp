// Datei: tupel_main.cpp

#include <string>
#include <iostream>

#include "tupel.h"

int main()
{
    Tupel<std::string, int> hansi = {"Hansi", 8};
    Tupel<std::string, int> willi = {"Willi", 77};

    std::cout << vergleiche<std::string, int>(hansi, willi) << std::endl;

    Tupel<int, int> t1 = {3, 4};
    Tupel<int, int> t2 = {1, 2};

    std::cout << vergleiche<int, int>(t1, t2) << std::endl;

    Tupel<int, int> t3 = {9, 1};
    Tupel<int, int> t4 = {3, 5};

    std::cout << vergleiche<int, int>(t3, t4) << std::endl;

    Tupel<char, bool> t5 = {'a', true};
    Tupel<char, bool> t6 = {'b', false};

    std::cout << vergleiche<char, bool>(t5, t6) << std::endl;

    system("PAUSE");
    return 0;
}
