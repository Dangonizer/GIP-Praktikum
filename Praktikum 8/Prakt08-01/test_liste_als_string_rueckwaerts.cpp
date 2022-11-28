// Datei: test_liste_als_string_rueckwaerts.cpp

#include <string>

#define TEST_FILE test_liste_als_string_rueckwaerts

#include "gip_mini_catch.h"

#include "liste.h"

TEST_CASE("liste_als_string_rueckwaerts(), leere Liste") {
    TListenKnoten* anker = nullptr;

    std::string result = liste_als_string_rueckwaerts(anker);

    REQUIRE(result == std::string("Leere Liste."));

}

TEST_CASE("liste_als_string_rueckwaerts(), Liste mit einem Knoten") {
    TListenKnoten* anker = new TListenKnoten;
    anker->data = 1;
    anker->prev = nullptr;
    anker->next = nullptr;

    std::string result = liste_als_string_rueckwaerts(anker);

    REQUIRE(result == std::string("[ 1 ]"));

    delete anker;
}

TEST_CASE("liste_als_string_rueckwaerts(), Liste mit mehr als einem Knoten") {
    TListenKnoten* knoten[4] = { nullptr };

    for (size_t i = 0; i < 4; i++) {

        knoten[i] = new TListenKnoten;
        knoten[i]->data = i + 1;
        knoten[i]->prev = nullptr;
        knoten[i]->next = nullptr;

        if (i > 0) {
            knoten[i]->prev = knoten[i - 1];
            knoten[i - 1]->next = knoten[i];
        }
    }

    std::string result = liste_als_string_rueckwaerts(knoten[0]);

    REQUIRE(result == std::string("[ 4 , 3 , 2 , 1 ]"));

    for (size_t i = 0; i < 4; i++) {
        delete knoten[i];
    }
}
