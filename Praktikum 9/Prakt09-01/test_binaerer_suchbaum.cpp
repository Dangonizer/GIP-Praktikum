// Datei: test_binaerer_suchbaum.cpp

#include "gip_mini_catch.h"

#include "binaerer_suchbaum.h"

TEST_CASE("Suchbaum bestehend aus einem Knoten.") {
    suchbaum::BaumKnoten* anker = nullptr;
    suchbaum::einfuegen(anker, 50);

    REQUIRE(anker->wert == 50);
    REQUIRE(anker->links == nullptr);
    REQUIRE(anker->rechts == nullptr);
}

TEST_CASE("Balancierter Suchbaum, bestehend aus drei Knoten.") {
    suchbaum::BaumKnoten* anker = nullptr;
    suchbaum::einfuegen(anker, 50);
    suchbaum::einfuegen(anker, 25);
    suchbaum::einfuegen(anker, 75);

    REQUIRE(anker->wert == 50);
    REQUIRE(anker->links != nullptr);
    REQUIRE(anker->rechts != nullptr);
    REQUIRE(anker->links->wert == 25);
    REQUIRE(anker->links->links == nullptr);
    REQUIRE(anker->links->rechts == nullptr);
    REQUIRE(anker->rechts->wert == 75);
    REQUIRE(anker->rechts->links == nullptr);
    REQUIRE(anker->rechts->rechts == nullptr);
}

TEST_CASE("Unbalancierter Suchbaum, bestehend aus drei Knoten, nur links.") {
    suchbaum::BaumKnoten* anker = nullptr;
    suchbaum::einfuegen(anker, 50);
    suchbaum::einfuegen(anker, 25);
    suchbaum::einfuegen(anker, 10);

    REQUIRE(anker->wert == 50);
    REQUIRE(anker->links != nullptr);
    REQUIRE(anker->rechts == nullptr);
    REQUIRE(anker->links->wert == 25);
    REQUIRE(anker->links->links != nullptr);
    REQUIRE(anker->links->rechts == nullptr);
    REQUIRE(anker->links->links->wert == 10);
    REQUIRE(anker->links->links->links == nullptr);
    REQUIRE(anker->links->links->rechts == nullptr);
}

TEST_CASE("Unbalancierter Suchbaum, bestehend aus drei Knoten, links-rechts.") {
    suchbaum::BaumKnoten* anker = nullptr;
    suchbaum::einfuegen(anker, 50);
    suchbaum::einfuegen(anker, 25);
    suchbaum::einfuegen(anker, 35);

    REQUIRE(anker->wert == 50);
    REQUIRE(anker->links != nullptr);
    REQUIRE(anker->rechts == nullptr);
    REQUIRE(anker->links->wert == 25);
    REQUIRE(anker->links->rechts != nullptr);
    REQUIRE(anker->links->links == nullptr);
    REQUIRE(anker->links->rechts->wert == 35);
    REQUIRE(anker->links->rechts->links == nullptr);
    REQUIRE(anker->links->rechts->rechts == nullptr);
}

TEST_CASE("Unbalancierter Suchbaum, bestehend aus drei Knoten, nur rechts.") {
    suchbaum::BaumKnoten* anker = nullptr;
    suchbaum::einfuegen(anker, 50);
    suchbaum::einfuegen(anker, 75);
    suchbaum::einfuegen(anker, 100);

    REQUIRE(anker->wert == 50);
    REQUIRE(anker->rechts != nullptr);
    REQUIRE(anker->links == nullptr);
    REQUIRE(anker->rechts->wert == 75);
    REQUIRE(anker->rechts->rechts != nullptr);
    REQUIRE(anker->rechts->links == nullptr);
    REQUIRE(anker->rechts->rechts->wert == 100);
    REQUIRE(anker->rechts->rechts->links == nullptr);
    REQUIRE(anker->rechts->rechts->rechts == nullptr);
}

TEST_CASE("Unbalancierter Suchbaum, bestehend aus drei Knoten, rechts-links.") {
    suchbaum::BaumKnoten* anker = nullptr;
    suchbaum::einfuegen(anker, 50);
    suchbaum::einfuegen(anker, 75);
    suchbaum::einfuegen(anker, 65);

    REQUIRE(anker->wert == 50);
    REQUIRE(anker->rechts != nullptr);
    REQUIRE(anker->links == nullptr);
    REQUIRE(anker->rechts->wert == 75);
    REQUIRE(anker->rechts->rechts == nullptr);
    REQUIRE(anker->rechts->links != nullptr);
    REQUIRE(anker->rechts->links->wert == 65);
    REQUIRE(anker->rechts->links->links == nullptr);
    REQUIRE(anker->rechts->links->rechts == nullptr);
}

TEST_CASE("Balancierter Suchbaum, bestehend aus sieben Knoten.") {
    suchbaum::BaumKnoten* anker = nullptr;
    suchbaum::einfuegen(anker, 50);
    suchbaum::einfuegen(anker, 25);
    suchbaum::einfuegen(anker, 35);
    suchbaum::einfuegen(anker, 75);
    suchbaum::einfuegen(anker, 100);
    suchbaum::einfuegen(anker, 95);
    suchbaum::einfuegen(anker, 10);
    suchbaum::einfuegen(anker, 65);

    REQUIRE(anker->wert == 50);
    REQUIRE(anker->links != nullptr);
    REQUIRE(anker->rechts != nullptr);
    REQUIRE(anker->links->wert == 25);
    REQUIRE(anker->links->links != nullptr);
    REQUIRE(anker->links->links->wert == 10);
    REQUIRE(anker->links->links->links == nullptr);
    REQUIRE(anker->links->links->rechts == nullptr);
    REQUIRE(anker->links->rechts->wert == 35);
    REQUIRE(anker->links->rechts->links == nullptr);
    REQUIRE(anker->links->rechts->rechts == nullptr);
    REQUIRE(anker->rechts->wert == 75);
    REQUIRE(anker->rechts->links != nullptr);
    REQUIRE(anker->rechts->rechts != nullptr);
    REQUIRE(anker->rechts->links->wert == 65);
    REQUIRE(anker->rechts->links->links == nullptr);
    REQUIRE(anker->rechts->links->rechts == nullptr);
    REQUIRE(anker->rechts->rechts->wert == 100);
    REQUIRE(anker->rechts->rechts->links != nullptr);
    REQUIRE(anker->rechts->rechts->rechts == nullptr);
    REQUIRE(anker->rechts->rechts->links->wert == 95);
    REQUIRE(anker->rechts->rechts->links->links == nullptr);
    REQUIRE(anker->rechts->rechts->links->rechts == nullptr);
}
