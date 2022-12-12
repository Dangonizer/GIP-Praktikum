// Datei: test_binaerer_suchbaum.cpp

#include "gip_mini_catch.h"

#include "BaumKnoten.h"
#include "BinaererSuchbaum.h"

TEST_CASE("Suchbaum bestehend aus einem Knoten.") {
    BinaererSuchbaum baum;
    baum.einfuegen(50);

    REQUIRE(baum.get_root()->get_data() == 50);
    REQUIRE(baum.get_root()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_rechts() == nullptr);
}

TEST_CASE("Balancierter Suchbaum, bestehend aus drei Knoten.") {
    BinaererSuchbaum baum;
    baum.einfuegen(50);
    baum.einfuegen(25);
    baum.einfuegen(75);

    REQUIRE(baum.get_root()->get_data() == 50);
    REQUIRE(baum.get_root()->get_links() != nullptr);
    REQUIRE(baum.get_root()->get_rechts() != nullptr);
    REQUIRE(baum.get_root()->get_links()->get_data() == 25);
    REQUIRE(baum.get_root()->get_links()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_links()->get_rechts() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_data() == 75);
    REQUIRE(baum.get_root()->get_rechts()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts() == nullptr);
}

TEST_CASE("Unbalancierter Suchbaum, bestehend aus drei Knoten, nur links.") {
    BinaererSuchbaum baum;
    baum.einfuegen(50);
    baum.einfuegen(25);
    baum.einfuegen(10);

    REQUIRE(baum.get_root()->get_data() == 50);
    REQUIRE(baum.get_root()->get_links() != nullptr);
    REQUIRE(baum.get_root()->get_rechts() == nullptr);
    REQUIRE(baum.get_root()->get_links()->get_data() == 25);
    REQUIRE(baum.get_root()->get_links()->get_links() != nullptr);
    REQUIRE(baum.get_root()->get_links()->get_rechts() == nullptr);
    REQUIRE(baum.get_root()->get_links()->get_links()->get_data() == 10);
    REQUIRE(baum.get_root()->get_links()->get_links()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_links()->get_links()->get_rechts() == nullptr);
}

TEST_CASE("Unbalancierter Suchbaum, bestehend aus drei Knoten, links-rechts.") {
    BinaererSuchbaum baum;
    baum.einfuegen(50);
    baum.einfuegen(25);
    baum.einfuegen(35);

    REQUIRE(baum.get_root()->get_data() == 50);
    REQUIRE(baum.get_root()->get_links() != nullptr);
    REQUIRE(baum.get_root()->get_rechts() == nullptr);
    REQUIRE(baum.get_root()->get_links()->get_data() == 25);
    REQUIRE(baum.get_root()->get_links()->get_rechts() != nullptr);
    REQUIRE(baum.get_root()->get_links()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_links()->get_rechts()->get_data() == 35);
    REQUIRE(baum.get_root()->get_links()->get_rechts()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_links()->get_rechts()->get_rechts() == nullptr);
}

TEST_CASE("Unbalancierter Suchbaum, bestehend aus drei Knoten, nur rechts.") {
    BinaererSuchbaum baum;
    baum.einfuegen(50);
    baum.einfuegen(75);
    baum.einfuegen(100);

    REQUIRE(baum.get_root()->get_data() == 50);
    REQUIRE(baum.get_root()->get_rechts() != nullptr);
    REQUIRE(baum.get_root()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_data() == 75);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts() != nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts()->get_data() == 100);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts()->get_rechts() == nullptr);
}

TEST_CASE("Unbalancierter Suchbaum, bestehend aus drei Knoten, rechts-links.") {
    BinaererSuchbaum baum;
    baum.einfuegen(50);
    baum.einfuegen(75);
    baum.einfuegen(65);

    REQUIRE(baum.get_root()->get_data() == 50);
    REQUIRE(baum.get_root()->get_rechts() != nullptr);
    REQUIRE(baum.get_root()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_data() == 75);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_links() != nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_links()->get_data() == 65);
    REQUIRE(baum.get_root()->get_rechts()->get_links()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_links()->get_rechts() == nullptr);
}

TEST_CASE("Balancierter Suchbaum, bestehend aus sieben Knoten.") {
    BinaererSuchbaum baum;
    baum.einfuegen(50);
    baum.einfuegen(25);
    baum.einfuegen(35);
    baum.einfuegen(75);
    baum.einfuegen(100);
    baum.einfuegen(95);
    baum.einfuegen(10);
    baum.einfuegen(65);

    REQUIRE(baum.get_root()->get_data() == 50);
    REQUIRE(baum.get_root()->get_links() != nullptr);
    REQUIRE(baum.get_root()->get_rechts() != nullptr);
    REQUIRE(baum.get_root()->get_links()->get_data() == 25);
    REQUIRE(baum.get_root()->get_links()->get_links() != nullptr);
    REQUIRE(baum.get_root()->get_links()->get_links()->get_data() == 10);
    REQUIRE(baum.get_root()->get_links()->get_links()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_links()->get_links()->get_rechts() == nullptr);
    REQUIRE(baum.get_root()->get_links()->get_rechts()->get_data() == 35);
    REQUIRE(baum.get_root()->get_links()->get_rechts()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_links()->get_rechts()->get_rechts() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_data() == 75);
    REQUIRE(baum.get_root()->get_rechts()->get_links() != nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts() != nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_links()->get_data() == 65);
    REQUIRE(baum.get_root()->get_rechts()->get_links()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_links()->get_rechts() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts()->get_data() == 100);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts()->get_links() != nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts()->get_rechts() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts()->get_links()->get_data() == 95);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts()->get_links()->get_links() == nullptr);
    REQUIRE(baum.get_root()->get_rechts()->get_rechts()->get_links()->get_rechts() == nullptr);
}
