#pragma once
template <typename T1, typename T2>
struct Tupel
{
    T1 komponente1;
    T2 komponente2;
};
template <typename T1, typename T2>
int vergleiche(Tupel<T1, T2> t1, Tupel<T1, T2> t2);