// Datei: test_hinten_anfuegen.cpp

#define TEST_FILE test_hinten_anfuegen

#include "gip_mini_catch.h"

#include "liste.h"

TEST_CASE("Hinten anfuegen an eine leere Liste") {
    TListenKnoten* anker = nullptr;

    hinten_anfuegen(anker, 1);

    REQUIRE(anker != nullptr);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->next == nullptr);
    REQUIRE(anker->prev == nullptr);

    delete anker;
}

TEST_CASE("Hinten anfuegen an Liste mit einem Knoten") {
    TListenKnoten* anker = new TListenKnoten;
    anker->data = 1;
    anker->prev = nullptr;
    anker->next = nullptr;

    hinten_anfuegen(anker, 2);

    REQUIRE(anker != nullptr);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next != nullptr);

    TListenKnoten* knoten2 = anker->next;
    REQUIRE(knoten2->data == 2);
    REQUIRE(knoten2->prev == anker);
    REQUIRE(knoten2->next == nullptr);

    delete anker;
    delete knoten2;
}

TEST_CASE("Hinten anfuegen an Liste mit mehr als einem Knoten") {
    TListenKnoten* knoten[4] = { nullptr };

    for (size_t i = 0; i < 4; i++) {

        knoten[i] = new TListenKnoten;
        knoten[i]->data = i + 1;
        knoten[i]->prev = nullptr;
        knoten[i]->next = nullptr;

        if (i > 0) {
            knoten[i]->prev = knoten[i-1];
            knoten[i-1]->next = knoten[i];
        }
    }

    hinten_anfuegen(knoten[0], 5);

    // Verkettung der bisherigen Knoten immer noch o.k.?
    REQUIRE(knoten[0] != nullptr);
    REQUIRE(knoten[0]->data == 1);
    REQUIRE(knoten[0]->prev == nullptr);
    REQUIRE(knoten[0]->next != nullptr);

    for (size_t i = 1; i < 3; i++) {
        REQUIRE(knoten[i]->data == int(i + 1));
        REQUIRE(knoten[i]->prev == knoten[i-1]);
        REQUIRE(knoten[i]->next == knoten[i+1]);
    }

    TListenKnoten* knoten5 = knoten[3]->next;
    REQUIRE(knoten5->data == 5);
    REQUIRE(knoten5->prev == knoten[3]);
    REQUIRE(knoten5->next == nullptr);

    for (size_t i = 0; i < 4; i++) {
        delete knoten[i];
    }
    delete knoten5;
}
