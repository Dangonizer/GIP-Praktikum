#include "suchen_rekursiv.h"
#include <string>
using namespace std;
int zeichenkette_suchen_rekursiv(string text,
                                 string zkette,
                                 size_t text_pos,
                                 size_t text_such_pos,
                                 size_t zkette_such_pos)
{
    if (zkette.length() == zkette_such_pos)
    {
        return text_pos;
    }
    if (text.length() == text_such_pos)
    {
        return -1;
    }
    if (text.at(text_such_pos) == zkette.at(zkette_such_pos))
    {
        text_such_pos += 1;
        zkette_such_pos += 1;
    }
    else
    {
        text_pos += 1;
        text_such_pos = text_pos;
        zkette_such_pos = 0;
    }
    return zeichenkette_suchen_rekursiv(text, zkette, text_pos, text_such_pos, zkette_such_pos);
}
