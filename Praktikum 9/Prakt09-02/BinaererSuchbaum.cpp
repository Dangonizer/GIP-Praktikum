#include "BinaererSuchbaum.h"
#include <iostream>
void BinaererSuchbaum::einfuegen(int wert)
{
    BaumKnoten *neuereintrag = new BaumKnoten{wert, nullptr, nullptr};
    if (root == nullptr)
    {
        root = neuereintrag;
        return;
    }
    BaumKnoten *h = root;
    while (true)
    {
        if (h->get_data() == wert)
        {
            return;
        }
        if (wert < h->get_data())
        {
            if (h->get_links() == nullptr)
            {
                h->set_links(neuereintrag);
            }
            else
            {
                h = h->get_links();
                continue;
            }
        }
        if (wert > h->get_data())
        {
            if (h->get_rechts() == nullptr)
            {
                h->set_rechts(neuereintrag);
            }
            else
            {
                h = h->get_rechts();
                continue;
            }
        }
    }
}

void BinaererSuchbaum::ausgeben()
{
    if (root == nullptr)
    {
        std::cout << "Leerer Baum.\n";
        return;
    }
    root->ausgeben(0);
}