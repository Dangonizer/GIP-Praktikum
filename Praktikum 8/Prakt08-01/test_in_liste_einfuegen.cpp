// Datei: test_in_liste_einfuegen.cpp

#define TEST_FILE test_in_liste_einfuegen

#include "gip_mini_catch.h"

#include "liste.h"

TEST_CASE("Einfuegen an eine leere Liste") {
    TListenKnoten* anker = nullptr;

    in_liste_einfuegen(anker, 99, 88);

    REQUIRE(anker != nullptr);
    REQUIRE(anker->data == 99);
    REQUIRE(anker->next == nullptr);
    REQUIRE(anker->prev == nullptr);

    delete anker;
}

TEST_CASE("Einfuegen in eine Liste mit einem Knoten: vorne einfuegen") {
    TListenKnoten* anker = new TListenKnoten;
    anker->data = 1;
    anker->prev = nullptr;
    anker->next = nullptr;

    in_liste_einfuegen(anker, 99, 1);

    REQUIRE(anker != nullptr);
    REQUIRE(anker->data == 99);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next != nullptr);

    TListenKnoten* knoten2 = anker->next;
    REQUIRE(knoten2->data == 1);
    REQUIRE(knoten2->prev == anker);
    REQUIRE(knoten2->next == nullptr);

    delete anker;
    delete knoten2;
}

TEST_CASE("Einfuegen in eine Liste mit einem Knoten: hinten einfuegen") {
    TListenKnoten* anker = new TListenKnoten;
    anker->data = 1;
    anker->prev = nullptr;
    anker->next = nullptr;

    in_liste_einfuegen(anker, 99, 88);

    REQUIRE(anker != nullptr);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next != nullptr);

    TListenKnoten* knoten2 = anker->next;
    REQUIRE(knoten2->data == 99);
    REQUIRE(knoten2->prev == anker);
    REQUIRE(knoten2->next == nullptr);

    delete anker;
    delete knoten2;
}

TEST_CASE("Einfuegen in eine Liste mit zwei Knoten: vorne einfuegen") {
    TListenKnoten* anker = new TListenKnoten;
    anker->data = 1;
    anker->prev = nullptr;
    TListenKnoten* knoten2 = new TListenKnoten;
    knoten2->data = 2;
    knoten2->next = nullptr;
    knoten2->prev = anker;
    anker->next = knoten2;

    in_liste_einfuegen(anker, 99, 1);

    REQUIRE(anker != nullptr);
    REQUIRE(anker->data == 99);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next != nullptr);

    TListenKnoten* knoten1 = anker->next;
    REQUIRE(knoten1->data == 1);
    REQUIRE(knoten1->prev == anker);
    REQUIRE(knoten1->next == knoten2);

    REQUIRE(knoten2->data == 2);
    REQUIRE(knoten2->prev == knoten1);
    REQUIRE(knoten2->next == nullptr);

    delete anker;
    delete knoten1;
    delete knoten2;
}

TEST_CASE("Einfuegen in eine Liste mit zwei Knoten: in der Mitte einfuegen") {
    TListenKnoten* anker = new TListenKnoten;
    anker->data = 1;
    anker->prev = nullptr;
    TListenKnoten* knoten2 = new TListenKnoten;
    knoten2->data = 2;
    knoten2->next = nullptr;
    knoten2->prev = anker;
    anker->next = knoten2;

    in_liste_einfuegen(anker, 99, 2);

    REQUIRE(anker != nullptr);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next != nullptr);

    TListenKnoten* knoten1 = anker->next;
    REQUIRE(knoten1->data == 99);
    REQUIRE(knoten1->prev == anker);
    REQUIRE(knoten1->next == knoten2);

    REQUIRE(knoten2->data == 2);
    REQUIRE(knoten2->prev == knoten1);
    REQUIRE(knoten2->next == nullptr);

    delete anker;
    delete knoten1;
    delete knoten2;
}

TEST_CASE("Einfuegen in eine Liste mit zwei Knoten: Hinten einfuegen") {
    TListenKnoten* anker = new TListenKnoten;
    anker->data = 1;
    anker->prev = nullptr;
    TListenKnoten* knoten2 = new TListenKnoten;
    knoten2->data = 2;
    knoten2->next = nullptr;
    knoten2->prev = anker;
    anker->next = knoten2;

    in_liste_einfuegen(anker, 99, 88);

    REQUIRE(anker != nullptr);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next == knoten2);

    REQUIRE(knoten2->data == 2);
    REQUIRE(knoten2->prev == anker);
    REQUIRE(knoten2->next != nullptr);

    TListenKnoten* knoten3 = knoten2->next;
    REQUIRE(knoten3->data == 99);
    REQUIRE(knoten3->prev == knoten2);
    REQUIRE(knoten3->next == nullptr);

    delete anker;
    delete knoten3;
    delete knoten2;
}

TEST_CASE("Einfuegen in eine Liste mit mehr als zwei Knoten: vorne einfuegen") {
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
    TListenKnoten* anker = knoten[0];

    in_liste_einfuegen(anker, 99, 1);

    // Verkettung der bisherigen Knoten immer noch o.k.?
    REQUIRE(knoten[0] != nullptr);
    REQUIRE(knoten[0]->data == 1);
    REQUIRE(knoten[0]->prev == anker);
    REQUIRE(knoten[0]->next != nullptr);

    for (size_t i = 1; i < 3; i++) {
        REQUIRE(knoten[i]->data == int(i + 1));
        REQUIRE(knoten[i]->prev == knoten[i-1]);
        REQUIRE(knoten[i]->next == knoten[i+1]);
    }

    REQUIRE(anker->data == 99);
    REQUIRE(anker->next == knoten[0]);
    REQUIRE(anker->prev == nullptr);

    for (size_t i = 0; i < 4; i++) {
        delete knoten[i];
    }
    delete anker;
}

TEST_CASE("Einfuegen in eine Liste mit mehr als zwei Knoten: Hinter dem ersten Knoten einfuegen") {
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
    TListenKnoten* anker = knoten[0];

    in_liste_einfuegen(anker, 99, 2);

    REQUIRE(anker == knoten[0]);

    // Verkettung der bisherigen Knoten immer noch o.k.?
    REQUIRE(knoten[0] != nullptr);
    REQUIRE(knoten[0]->data == 1);
    REQUIRE(knoten[0]->prev == nullptr);
    REQUIRE(knoten[0]->next != nullptr);

    TListenKnoten* knoten_neu = knoten[0]->next;
    REQUIRE(knoten_neu->data == 99);
    REQUIRE(knoten_neu->prev == knoten[0]);
    REQUIRE(knoten_neu->next == knoten[1]);

    REQUIRE(knoten[1]->data == 2);
    REQUIRE(knoten[1]->prev == knoten_neu);
    REQUIRE(knoten[1]->next == knoten[2]);

    REQUIRE(knoten[2]->data == 3);
    REQUIRE(knoten[2]->prev == knoten[1]);
    REQUIRE(knoten[2]->next == knoten[3]);

    REQUIRE(knoten[3]->data == 4);
    REQUIRE(knoten[3]->prev == knoten[2]);
    REQUIRE(knoten[3]->next == nullptr);

    for (size_t i = 0; i < 4; i++) {
        delete knoten[i];
    }
    delete knoten_neu;
}

TEST_CASE("Einfuegen in eine Liste mit mehr als zwei Knoten: In der Mitte einfuegen") {
    TListenKnoten* knoten[5] = { nullptr };

    for (size_t i = 0; i < 5; i++) {

        knoten[i] = new TListenKnoten;
        knoten[i]->data = i + 1;
        knoten[i]->prev = nullptr;
        knoten[i]->next = nullptr;

        if (i > 0) {
            knoten[i]->prev = knoten[i-1];
            knoten[i-1]->next = knoten[i];
        }
    }
    TListenKnoten* anker = knoten[0];

    in_liste_einfuegen(anker, 99, 3);

    REQUIRE(anker == knoten[0]);

    // Verkettung der bisherigen Knoten immer noch o.k.?
    REQUIRE(knoten[0] != nullptr);
    REQUIRE(knoten[0]->data == 1);
    REQUIRE(knoten[0]->prev == nullptr);
    REQUIRE(knoten[0]->next == knoten[1]);

    REQUIRE(knoten[1]->data == 2);
    REQUIRE(knoten[1]->prev == knoten[0]);
    REQUIRE(knoten[1]->next != nullptr);

    TListenKnoten* knoten_neu = knoten[1]->next;
    REQUIRE(knoten_neu->data == 99);
    REQUIRE(knoten_neu->prev == knoten[1]);
    REQUIRE(knoten_neu->next == knoten[2]);


    REQUIRE(knoten[2]->data == 3);
    REQUIRE(knoten[2]->prev == knoten_neu);
    REQUIRE(knoten[2]->next == knoten[3]);

    REQUIRE(knoten[3]->data == 4);
    REQUIRE(knoten[3]->prev == knoten[2]);
    REQUIRE(knoten[3]->next == knoten[4]);

    REQUIRE(knoten[4]->data == 5);
    REQUIRE(knoten[4]->prev == knoten[3]);
    REQUIRE(knoten[4]->next == nullptr);

    for (size_t i = 0; i < 5; i++) {
        delete knoten[i];
    }
    delete knoten_neu;
}

TEST_CASE("Einfuegen in eine Liste mit mehr als zwei Knoten: Vor dem vorletzten Knoten einfuegen") {
    TListenKnoten* knoten[5] = { nullptr };

    for (size_t i = 0; i < 5; i++) {

        knoten[i] = new TListenKnoten;
        knoten[i]->data = i + 1;
        knoten[i]->prev = nullptr;
        knoten[i]->next = nullptr;

        if (i > 0) {
            knoten[i]->prev = knoten[i-1];
            knoten[i-1]->next = knoten[i];
        }
    }
    TListenKnoten* anker = knoten[0];

    in_liste_einfuegen(anker, 99, 4);

    REQUIRE(anker == knoten[0]);

    // Verkettung der bisherigen Knoten immer noch o.k.?
    REQUIRE(knoten[0] != nullptr);
    REQUIRE(knoten[0]->data == 1);
    REQUIRE(knoten[0]->prev == nullptr);
    REQUIRE(knoten[0]->next == knoten[1]);

    REQUIRE(knoten[1]->data == 2);
    REQUIRE(knoten[1]->prev == knoten[0]);
    REQUIRE(knoten[1]->next != nullptr);

    REQUIRE(knoten[2]->data == 3);
    REQUIRE(knoten[2]->prev == knoten[1]);
    REQUIRE(knoten[2]->next != nullptr);

    TListenKnoten* knoten_neu = knoten[2]->next;
    REQUIRE(knoten_neu->data == 99);
    REQUIRE(knoten_neu->prev == knoten[2]);
    REQUIRE(knoten_neu->next == knoten[3]);

    REQUIRE(knoten[3]->data == 4);
    REQUIRE(knoten[3]->prev == knoten_neu);
    REQUIRE(knoten[3]->next == knoten[4]);

    REQUIRE(knoten[4]->data == 5);
    REQUIRE(knoten[4]->prev == knoten[3]);
    REQUIRE(knoten[4]->next == nullptr);

    for (size_t i = 0; i < 5; i++) {
        delete knoten[i];
    }
    delete knoten_neu;
}

TEST_CASE("Einfuegen in eine Liste mit mehr als zwei Knoten: Vor dem letzten Knoten einfuegen") {
    TListenKnoten* knoten[5] = { nullptr };

    for (size_t i = 0; i < 5; i++) {

        knoten[i] = new TListenKnoten;
        knoten[i]->data = i + 1;
        knoten[i]->prev = nullptr;
        knoten[i]->next = nullptr;

        if (i > 0) {
            knoten[i]->prev = knoten[i-1];
            knoten[i-1]->next = knoten[i];
        }
    }
    TListenKnoten* anker = knoten[0];

    in_liste_einfuegen(anker, 99, 5);

    REQUIRE(anker == knoten[0]);

    // Verkettung der bisherigen Knoten immer noch o.k.?
    REQUIRE(knoten[0] != nullptr);
    REQUIRE(knoten[0]->data == 1);
    REQUIRE(knoten[0]->prev == nullptr);
    REQUIRE(knoten[0]->next == knoten[1]);

    REQUIRE(knoten[1]->data == 2);
    REQUIRE(knoten[1]->prev == knoten[0]);
    REQUIRE(knoten[1]->next == knoten[2]);

    REQUIRE(knoten[2]->data == 3);
    REQUIRE(knoten[2]->prev == knoten[1]);
    REQUIRE(knoten[2]->next == knoten[3]);

    REQUIRE(knoten[3]->data == 4);
    REQUIRE(knoten[3]->prev == knoten[2]);
    REQUIRE(knoten[3]->next != nullptr);

    TListenKnoten* knoten_neu = knoten[3]->next;
    REQUIRE(knoten_neu->data == 99);
    REQUIRE(knoten_neu->prev == knoten[3]);
    REQUIRE(knoten_neu->next == knoten[4]);

    REQUIRE(knoten[4]->data == 5);
    REQUIRE(knoten[4]->prev == knoten_neu);
    REQUIRE(knoten[4]->next == nullptr);

    for (size_t i = 0; i < 5; i++) {
        delete knoten[i];
    }
    delete knoten_neu;
}

TEST_CASE("Einfuegen in eine Liste mit mehr als zwei Knoten: Hinter dem letzten Knoten einfuegen") {
    TListenKnoten* knoten[5] = { nullptr };

    for (size_t i = 0; i < 5; i++) {

        knoten[i] = new TListenKnoten;
        knoten[i]->data = i + 1;
        knoten[i]->prev = nullptr;
        knoten[i]->next = nullptr;

        if (i > 0) {
            knoten[i]->prev = knoten[i-1];
            knoten[i-1]->next = knoten[i];
        }
    }
    TListenKnoten* anker = knoten[0];

    in_liste_einfuegen(anker, 99, 88);

    REQUIRE(anker == knoten[0]);

    // Verkettung der bisherigen Knoten immer noch o.k.?
    REQUIRE(knoten[0] != nullptr);
    REQUIRE(knoten[0]->data == 1);
    REQUIRE(knoten[0]->prev == nullptr);
    REQUIRE(knoten[0]->next == knoten[1]);

    REQUIRE(knoten[1]->data == 2);
    REQUIRE(knoten[1]->prev == knoten[0]);
    REQUIRE(knoten[1]->next == knoten[2]);

    REQUIRE(knoten[2]->data == 3);
    REQUIRE(knoten[2]->prev == knoten[1]);
    REQUIRE(knoten[2]->next == knoten[3]);

    REQUIRE(knoten[3]->data == 4);
    REQUIRE(knoten[3]->prev == knoten[2]);
    REQUIRE(knoten[3]->next == knoten[4]);

    REQUIRE(knoten[4]->data == 5);
    REQUIRE(knoten[4]->prev == knoten[3]);
    REQUIRE(knoten[4]->next != nullptr);

    TListenKnoten* knoten_neu = knoten[4]->next;
    REQUIRE(knoten_neu->data == 99);
    REQUIRE(knoten_neu->prev == knoten[4]);
    REQUIRE(knoten_neu->next == nullptr);

    for (size_t i = 0; i < 5; i++) {
        delete knoten[i];
    }
    delete knoten_neu;
}
