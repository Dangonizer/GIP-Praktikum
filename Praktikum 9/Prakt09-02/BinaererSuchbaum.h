#pragma once
#include "BaumKnoten.h"
class BinaererSuchbaum
{
private:
    BaumKnoten *root;

public:
    BaumKnoten *get_root() { return root; }
    void einfuegen(int wert);
    void ausgeben();
    BinaererSuchbaum() : root{nullptr} {}
};