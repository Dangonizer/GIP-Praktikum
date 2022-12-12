#include "BaumKnoten.h"
#include <iostream>
int BaumKnoten::ausgeben(unsigned int tiefe)
{
    if (rechts != nullptr)
    {
        rechts->ausgeben(tiefe + 1);
    }
    for (int i = 0; i < tiefe * 2; i++)
    {
        std::cout << "+";
    }
    std::cout << data << std::endl;
    if (links != nullptr)
    {
        links->ausgeben(tiefe + 1);
    }
    return 0;
}