#pragma once
#include "CharListenKnoten.h"
#include <string>
class MyString2
{
private:
    CharListenKnoten *anker;

public:
    CharListenKnoten *get_anker() { return anker; };
    void set_anker(CharListenKnoten *a) { anker = a; };

    MyString2() : anker{nullptr} {};
    MyString2(std::string s) : anker{nullptr}
    {
        for (size_t i = 0; i < s.length(); i++)
        {
            hinten_anfuegen(anker, s.at(i));
        }
    }

    MyString2(const MyString2 &orig)
    {
        anker = deep_copy(orig.anker);
    }

    MyString2 &operator=(const MyString2 &orig)
    {
        loesche_alle(anker);
        anker = deep_copy(orig.anker);
        return *this;
    }

    ~MyString2() { loesche_alle(anker); }

    unsigned int length() const
    {
        if (anker == nullptr)
        {
            return 0;
        }
        else
        {
            size_t counter = 0;
            CharListenKnoten *helper = anker;
            while (helper != nullptr)
            {
                counter++;
                helper = helper->get_next();
            }
            return counter;
        }
    }

    char at(unsigned int pos) const
    {
        if (anker == nullptr)
        {
            return '\0';
        }
        else
        {
            char c;
            CharListenKnoten *helper = anker;
            for (size_t i = 0; i <= pos; i++)
            {
                if (helper == nullptr)
                {
                    c = '\0';
                    break;
                }
                c = helper->get_data();
                helper = helper->get_next();
            }
            return c;
        }
    }

    std::string to_string() const
    {
        std::string s = "";
        if (anker == nullptr)
            return s;
        else
        {
            CharListenKnoten *h = anker;
            while (h != nullptr)
            {
                s += h->get_data();
                h = h->get_next();
            }
            return s;
        }
    }
    MyString2 operator+(char c) const
    {
        MyString2 new_string = *this;
        hinten_anfuegen(new_string.anker, c);
        return new_string;
    }
};