// Datei: test_aus_liste_loeschen.cpp

#define TEST_FILE test_aus_liste_loeschen

#include "gip_mini_catch.h"

#include "liste.h"

TEST_CASE("Loeschen aus leerer Liste") {
    TListenKnoten* anker = nullptr;

    aus_liste_loeschen(anker, 1);

    REQUIRE(anker == nullptr);
}

TEST_CASE("Loeschen aus einer Liste mit einem Knoten: Loesche den Wert in der Liste") {
    TListenKnoten* anker = new TListenKnoten;
    anker->data = 1;
    anker->prev = nullptr;
    anker->next = nullptr;

    aus_liste_loeschen(anker, 1);

    REQUIRE(anker == nullptr);
}

TEST_CASE("Loeschen aus einer Liste mit einem Knoten: Loesche einen anderen Wert als den Wert in der Liste") {
    TListenKnoten* anker = new TListenKnoten;
    anker->data = 1;
    anker->prev = nullptr;
    anker->next = nullptr;

    aus_liste_loeschen(anker, 99);

    REQUIRE(anker != nullptr);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next == nullptr);

    delete anker;
}

TEST_CASE("Loeschen aus einer Liste mit zwei Knoten: Loesche den ersten Wert in der Liste") {
    TListenKnoten* anker = new TListenKnoten;
    anker->data = 1;
    anker->prev = nullptr;
    TListenKnoten* knoten2 = new TListenKnoten;
    knoten2->data = 2;
    knoten2->next = nullptr;
    knoten2->prev = anker;
    anker->next = knoten2;

    aus_liste_loeschen(anker, 1);

    REQUIRE(anker == knoten2);
    REQUIRE(anker->data == 2);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next == nullptr);

    delete anker;
}

TEST_CASE("Loeschen aus einer Liste mit zwei Knoten: Loesche den zweiten Wert in der Liste") {
    TListenKnoten* anker = new TListenKnoten;
    anker->data = 1;
    anker->prev = nullptr;
    TListenKnoten* knoten1 = anker;
    TListenKnoten* knoten2 = new TListenKnoten;
    knoten2->data = 2;
    knoten2->next = nullptr;
    knoten2->prev = anker;
    anker->next = knoten2;

    aus_liste_loeschen(anker, 2);

    REQUIRE(anker == knoten1);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next == nullptr);

    delete anker;
}

TEST_CASE("Loeschen aus einer Liste mit zwei Knoten: Loesche einen anderen Wert als den Wert in der Liste") {
    TListenKnoten* anker = new TListenKnoten;
    anker->data = 1;
    anker->prev = nullptr;
    TListenKnoten* knoten1 = anker;
    TListenKnoten* knoten2 = new TListenKnoten;
    knoten2->data = 2;
    knoten2->next = nullptr;
    knoten2->prev = anker;
    anker->next = knoten2;

    aus_liste_loeschen(anker, 99);

    REQUIRE(anker == knoten1);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next == knoten2);
    REQUIRE(knoten2->data == 2);
    REQUIRE(knoten2->prev == knoten1);
    REQUIRE(knoten2->next == nullptr);

    delete anker;
}

TEST_CASE("Loeschen aus einer Liste mit mehr als zwei Knoten: Loesche den ersten Wert in der Liste") {
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

    aus_liste_loeschen(anker, 1);

    REQUIRE(anker == knoten[1]);
    REQUIRE(anker->data == 2);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next == knoten[2]);

    REQUIRE(knoten[2]->data == 3);
    REQUIRE(knoten[2]->prev == knoten[1]);
    REQUIRE(knoten[2]->next == knoten[3]);

    REQUIRE(knoten[3]->data == 4);
    REQUIRE(knoten[3]->prev == knoten[2]);
    REQUIRE(knoten[3]->next == nullptr);

    for (size_t i = 0; i < 4; i++) {
        if (i != 0) delete knoten[i];
    }
}

TEST_CASE("Loeschen aus einer Liste mit mehr als zwei Knoten: Loesche den zweiten Wert in der Liste") {
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

    aus_liste_loeschen(anker, 2);

    REQUIRE(anker == knoten[0]);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next == knoten[2]);

    REQUIRE(knoten[2]->data == 3);
    REQUIRE(knoten[2]->prev == knoten[0]);
    REQUIRE(knoten[2]->next == knoten[3]);

    REQUIRE(knoten[3]->data == 4);
    REQUIRE(knoten[3]->prev == knoten[2]);
    REQUIRE(knoten[3]->next == nullptr);

    for (size_t i = 0; i < 4; i++) {
        if (i != 1) delete knoten[i];
    }
}

TEST_CASE("Loeschen aus einer Liste mit mehr als zwei Knoten: Loesche den vorletzten Wert in der Liste") {
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

    aus_liste_loeschen(anker, 3);

    REQUIRE(anker == knoten[0]);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next == knoten[1]);

    REQUIRE(knoten[1]->data == 2);
    REQUIRE(knoten[1]->prev == knoten[0]);
    REQUIRE(knoten[1]->next == knoten[3]);

    REQUIRE(knoten[3]->data == 4);
    REQUIRE(knoten[3]->prev == knoten[1]);
    REQUIRE(knoten[3]->next == nullptr);

    for (size_t i = 0; i < 4; i++) {
        if (i != 2) delete knoten[i];
    }
}

TEST_CASE("Loeschen aus einer Liste mit mehr als zwei Knoten: Loesche den letzten Wert in der Liste") {
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

    aus_liste_loeschen(anker, 4);

    REQUIRE(anker == knoten[0]);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next == knoten[1]);

    REQUIRE(knoten[1]->data == 2);
    REQUIRE(knoten[1]->prev == knoten[0]);
    REQUIRE(knoten[1]->next == knoten[2]);

    REQUIRE(knoten[2]->data == 3);
    REQUIRE(knoten[2]->prev == knoten[1]);
    REQUIRE(knoten[2]->next == nullptr);

    for (size_t i = 0; i < 4; i++) {
        if (i != 3) delete knoten[i];
    }
}

TEST_CASE("Loeschen aus einer Liste mit mehr als zwei Knoten: Loesche einen anderen Wert als den Wert in der Liste") {
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

    aus_liste_loeschen(anker, 99);

    REQUIRE(anker == knoten[0]);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next == knoten[1]);

    REQUIRE(knoten[1]->data == 2);
    REQUIRE(knoten[1]->prev == knoten[0]);
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
}

TEST_CASE("Loeschen aus einer Liste mit mehr als vier Knoten: Loesche einen Wert in der Mitte der Liste") {
    const size_t knotenanzahl = 5;

    TListenKnoten* knoten[knotenanzahl] = { nullptr };

    for (size_t i = 0; i < knotenanzahl; i++) {

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

    aus_liste_loeschen(anker, 3);

    REQUIRE(anker == knoten[0]);
    REQUIRE(anker->data == 1);
    REQUIRE(anker->prev == nullptr);
    REQUIRE(anker->next == knoten[1]);

    REQUIRE(knoten[1]->data == 2);
    REQUIRE(knoten[1]->prev == knoten[0]);
    REQUIRE(knoten[1]->next == knoten[3]);

    REQUIRE(knoten[3]->data == 4);
    REQUIRE(knoten[3]->prev == knoten[1]);
    REQUIRE(knoten[3]->next == knoten[4]);

    REQUIRE(knoten[4]->data == 5);
    REQUIRE(knoten[4]->prev == knoten[3]);
    REQUIRE(knoten[4]->next == nullptr);

    for (size_t i = 0; i < knotenanzahl; i++) {
        if (i != 2) delete knoten[i];
    }
}
