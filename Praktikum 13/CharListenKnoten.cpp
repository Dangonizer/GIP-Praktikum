#include "CharListenKnoten.h"
int CharListenKnoten::next_available_id = 1;
int CharListenKnoten::object_count = 0;

void hinten_anfuegen(CharListenKnoten *&anker, const char wert)
{
    CharListenKnoten *new_entry = new CharListenKnoten{wert};
    if (anker == nullptr)
        anker = new_entry;
    else
    {
        CharListenKnoten *helper = anker;
        while (helper->get_next() != nullptr)
        {
            helper = helper->get_next();
        }
        helper->set_next(new_entry);
    }
}

void loesche_alle(CharListenKnoten *&anker)
{
    if (anker == nullptr)
        return;
    else
    {
        CharListenKnoten *helper = anker, *helper2 = anker;
        do
        {
            helper2 = helper->get_next();
            delete helper;
            helper = helper2;
        } while (helper != nullptr);
        anker = nullptr;
    }
}

CharListenKnoten *deep_copy(CharListenKnoten *orig)
{
    if (orig == nullptr)
    {
        CharListenKnoten *result = nullptr;
        return result;
    }
    else
    {
        CharListenKnoten *result = nullptr;
        while (orig != nullptr)
        {
            hinten_anfuegen(result, orig->get_data());
            orig = orig->get_next();
        }
        return result;
    }
}