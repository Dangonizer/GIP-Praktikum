// Datei: test_loesche_alle.cpp

#define TEST_FILE test_loesche_alle

#include "gip_mini_catch.h"

#include "CharListenKnoten.h"

TEST_CASE("Pruefung der loesche_alle() Funktion fuer den Fall nullptr")
{
	CharListenKnoten* anker = nullptr;
	int current_count = CharListenKnoten::object_count;

	loesche_alle(anker);

	REQUIRE(anker == nullptr);
	REQUIRE(CharListenKnoten::object_count == current_count);
}

TEST_CASE("Pruefung der loesche_alle() Funktion fuer eine nicht-leere Kette von Knoten")
{
	CharListenKnoten* anker = nullptr;
	int current_count = CharListenKnoten::object_count;

	hinten_anfuegen(anker, 'a');
	hinten_anfuegen(anker, 'b');
	hinten_anfuegen(anker, 'c');

	REQUIRE(CharListenKnoten::object_count == current_count + 3);

	loesche_alle(anker);

	REQUIRE(anker == nullptr);
	REQUIRE(CharListenKnoten::object_count == current_count);
}


