#pragma once
namespace suchbaum
{
    struct BaumKnoten
    {
        int wert;
        BaumKnoten *links;
        BaumKnoten *rechts;
    };
    void ausgeben(BaumKnoten *anker);
    void einfuegen(BaumKnoten *&anker, int wert);
    void knoten_ausgeben(BaumKnoten *knoten,
                         unsigned int tiefe);
}