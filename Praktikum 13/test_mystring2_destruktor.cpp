// Datei: test_mystring2_destruktor.cpp

#define TEST_FILE test_mystring2_destruktor

#include "gip_mini_catch.h"

#include "CharListenKnoten.h"
#include "MyString2.h"

TEST_CASE("Pruefung des Destruktors der Klasse MyString2") 
{
	int current_count = CharListenKnoten::object_count;
	{
		MyString2 s;
		s.set_anker(new CharListenKnoten('a'));

		REQUIRE(CharListenKnoten::object_count == current_count + 1);
	}

	REQUIRE(CharListenKnoten::object_count == current_count);
}
