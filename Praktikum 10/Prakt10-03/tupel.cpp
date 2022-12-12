#include "tupel.h"
#include <string>
template <typename T1, typename T2>
int vergleiche(Tupel<T1, T2> t1, Tupel<T1, T2> t2)
{
    if (t1.komponente1 < t2.komponente1 && t1.komponente2 < t2.komponente2)
        return -1;
    else if (t1.komponente1 > t2.komponente1 && t1.komponente2 > t2.komponente2)
        return 1;
    else
        return 0;
}
template int vergleiche<int, int>(Tupel<int, int> t1, Tupel<int, int> t2);
template int vergleiche<std::string, int>(Tupel<std::string, int> t1, Tupel<std::string, int> t2);
template int vergleiche<char, bool>(Tupel<char, bool> t1, Tupel<char, bool> t2);