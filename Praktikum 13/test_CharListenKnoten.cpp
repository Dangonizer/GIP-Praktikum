// Datei: tests_CharListenKnoten.cpp

#define TEST_FILE test_CharListenKnoten

#include "gip_mini_catch.h"

#include "CharListenKnoten.h"

TEST_CASE("Pruefung der Methoden CharListenKnoten::get_data() / CharListenKnoten::set_data()") {

	CharListenKnoten k{'a'};

	REQUIRE(k.get_data() == 'a');

	k.set_data('b');
	REQUIRE(k.get_data() == 'b');
}

TEST_CASE("Pruefung der Methoden CharListenKnoten::get_next() / ::set_next()") {

	CharListenKnoten k1{'a'}, k2{'b'};

	REQUIRE(k1.get_next() == nullptr);
	REQUIRE(k2.get_next() == nullptr);

	k1.set_next(&k2);

	REQUIRE(k1.get_next() == &k2);
	REQUIRE(k2.get_next() == nullptr);
}
