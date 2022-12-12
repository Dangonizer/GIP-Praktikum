#include "binaerer_suchbaum.h"
#include <iostream>
void suchbaum::einfuegen(BaumKnoten *&anker, int wert)
{
    BaumKnoten *neuereintrag = new BaumKnoten;
    neuereintrag->wert = wert;
    neuereintrag->links = nullptr;
    neuereintrag->rechts = nullptr;
    if (anker == nullptr)
    {
        anker = neuereintrag;
        return;
    }
    if (anker->wert == wert)
    {
        return;
    }
    if (wert < anker->wert)
    {
        if (anker->links == nullptr)
        {
            anker->links = neuereintrag;
        }
        else
        {
            suchbaum::einfuegen(anker->links, wert);
        }
    }
    if (wert > anker->wert)
    {
        if (anker->rechts == nullptr)
        {
            anker->rechts = neuereintrag;
        }
        else
        {
            suchbaum::einfuegen(anker->rechts, wert);
        }
    }
}

void suchbaum::knoten_ausgeben(BaumKnoten *knoten,
                               unsigned int tiefe)
{
    if (knoten->rechts != nullptr)
    {
        knoten_ausgeben(knoten->rechts, tiefe + 1);
    }
    for (int i = 0; i < tiefe * 2; i++)
    {
        std::cout << "+";
    }
    std::cout << knoten->wert << std::endl;
    if (knoten->links != nullptr)
    {
        knoten_ausgeben(knoten->links, tiefe + 1);
    }
}

void suchbaum::ausgeben(BaumKnoten *anker)
{
    if (anker == nullptr)
    {
        std::cout << "Leerer Baum.\n";
        return;
    }
    knoten_ausgeben(anker, 0);
}