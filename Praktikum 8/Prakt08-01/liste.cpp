// Datei: liste.cpp

#include <string>
#include "liste.h"

std::string liste_als_string(TListenKnoten *anker)
{
    std::string resultat = "";

    if (anker == nullptr)
    {
        return "Leere Liste.";
    }
    else
    {
        resultat += "[ ";
        TListenKnoten *ptr = anker;
        do
        {
            resultat += std::to_string(ptr->data);

            if (ptr->next != nullptr)
            {
                resultat += " , ";
            }
            else
            {
                resultat += " ";
            }

            ptr = ptr->next;
        } while (ptr != nullptr);
        resultat += "]";
    }
    return resultat;
}

std::string liste_als_string_rueckwaerts(TListenKnoten *anker)
{
    std::string resultat = "";

    if (anker == nullptr)
    {
        return "Leere Liste.";
    }
    else
    {
        resultat += "[ ";
        TListenKnoten *ptr = anker;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        do
        {
            resultat += std::to_string(ptr->data);
            if (ptr->prev != nullptr)
            {
                resultat += " , ";
            }
            else
            {
                resultat += " ";
            }
            ptr = ptr->prev;
        } while (ptr != nullptr);
        resultat += "]";
    }
    return resultat;
}
// Wird modifiziert in Aufgabe INF-08.01 ...
void hinten_anfuegen(TListenKnoten *&anker, const int wert)
{
    TListenKnoten *neuer_eintrag = new TListenKnoten;
    neuer_eintrag->data = wert;
    neuer_eintrag->next = nullptr;

    if (anker == nullptr)
    {
        neuer_eintrag->prev = nullptr;
        anker = neuer_eintrag;
    }
    else
    {
        TListenKnoten *ptr = anker;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        neuer_eintrag->prev = ptr;
        ptr->next = neuer_eintrag;
    }
}

void in_liste_einfuegen(TListenKnoten *&anker,
                        int wert_neu,
                        int vor_wert)
{
    TListenKnoten *neuer_eintrag = new TListenKnoten;
    neuer_eintrag->data = wert_neu;
    neuer_eintrag->next = nullptr;
    neuer_eintrag->prev = nullptr;
    if (anker == nullptr)
    {
        anker = neuer_eintrag;
    }
    else
    {
        TListenKnoten *ptr = anker;
        do
        {
            if (ptr->data == vor_wert && ptr->prev != nullptr)
            {
                neuer_eintrag->next = ptr;
                neuer_eintrag->prev = ptr->prev;
                ptr->prev->next = neuer_eintrag;
                ptr->prev = neuer_eintrag;
                return;
            }
            else if (ptr->data == vor_wert)
            {
                neuer_eintrag->next = ptr;
                neuer_eintrag->prev = nullptr;
                anker = neuer_eintrag;
                ptr->prev = neuer_eintrag;
                return;
            }
            if (ptr->next == nullptr)
                break;
            ptr = ptr->next;
        } while (true);
        neuer_eintrag->prev = ptr;
        neuer_eintrag->next = nullptr;
        ptr->next = neuer_eintrag;
        return;
    }
}

void aus_liste_loeschen(TListenKnoten *&anker, int wert)
{
    if (anker == nullptr)
        return;

    TListenKnoten *ptr = anker;
    do
    {
        if (ptr->data == wert)
        {
            if (ptr->next == nullptr && ptr->prev == nullptr)
            {
                anker = nullptr;
                return;
            }
            else if (ptr->prev == nullptr)
            {
                anker = ptr->next;
                anker->prev = nullptr;
            }
            else if (ptr->next == nullptr)
            {
                ptr->prev->next = nullptr;
            }
            else
            {
                ptr->next->prev = ptr->prev;
                ptr->prev->next = ptr->next;
            }
        }
        if (ptr->next == nullptr)
            return;
        ptr = ptr->next;
    } while (true);
}