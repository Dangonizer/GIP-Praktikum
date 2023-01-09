// Datei: test_CharListenKnoten_id.cpp

#define TEST_FILE test_CharListenKnoten_id

#include "gip_mini_catch.h"

#include "CharListenKnoten.h"

TEST_CASE("Pruefung der CharListenKnoten ID:s") 
{
	int old_next_available_id = CharListenKnoten::next_available_id;

	CharListenKnoten k1('a'), k2('b');

	REQUIRE(k1.get_my_id() == old_next_available_id);
	REQUIRE(k1.get_my_id() + 1 == k2.get_my_id());
	REQUIRE(k2.get_my_id() + 1 == CharListenKnoten::next_available_id);
}
