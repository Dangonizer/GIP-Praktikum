// Datei: test_deep_copy.cpp

#define TEST_FILE test_deep_copy

#include "gip_mini_catch.h"

#include "CharListenKnoten.h"

TEST_CASE("Pruefung der deep_copy() Funktion fuer den Fall nullptr")
{
	int current_count = CharListenKnoten::object_count;

	CharListenKnoten* result = deep_copy(nullptr);

	REQUIRE(result == nullptr);
	REQUIRE(CharListenKnoten::object_count == current_count);
}

TEST_CASE("Pruefung der deep_copy() Funktion fuer den Fall 'ein Knoten' ")
{
	CharListenKnoten* anker = nullptr;
	int current_count = CharListenKnoten::object_count;

	hinten_anfuegen(anker, 'a');
	int id_a = anker->get_my_id();

	REQUIRE(CharListenKnoten::object_count == current_count + 1);

	CharListenKnoten* result = deep_copy(anker);

	REQUIRE(result != nullptr);
	REQUIRE(CharListenKnoten::object_count == current_count + 2);
	int id_1 = result->get_my_id();
	REQUIRE(id_1 != id_a);

	loesche_alle(anker);
}

TEST_CASE("Pruefung der deep_copy() Funktion fuer eine nicht-leere Kette von Knoten")
{
	CharListenKnoten* anker = nullptr;
	int current_count = CharListenKnoten::object_count;

	hinten_anfuegen(anker, 'a');
	int id_a = anker->get_my_id();

	hinten_anfuegen(anker, 'b');
	int id_b = anker->get_next()->get_my_id();

	hinten_anfuegen(anker, 'c');
	int id_c = anker->get_next()->get_next()->get_my_id();

	REQUIRE(CharListenKnoten::object_count == current_count + 3);

	CharListenKnoten* result = deep_copy(anker);

	REQUIRE(result != nullptr);
	REQUIRE(CharListenKnoten::object_count == current_count + 6);
	int id_1 = result->get_my_id();
	REQUIRE((id_1 != id_a && id_1 != id_b && id_1 != id_c));
	int id_2 = result->get_next()->get_my_id();
	REQUIRE((id_2 != id_a && id_2 != id_b && id_2 != id_c && id_2 != id_1));
	int id_3 = result->get_next()->get_next()->get_my_id();
	REQUIRE((id_3 != id_a && id_3 != id_b && id_3 != id_c && id_3 != id_1 && id_3 != id_2));

	loesche_alle(anker);
}
