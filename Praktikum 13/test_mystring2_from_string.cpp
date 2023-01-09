// Datei: test_mystring2_from_string.cpp

#define TEST_FILE test_mystring2_from_string

#include <string>

#include "gip_mini_catch.h"

#include "CharListenKnoten.h"
#include "MyString2.h"

TEST_CASE("Pruefung des Konstruktors MyString2(std::string )") {

	MyString2 s = std::string{ "abc" };

	REQUIRE(s.get_anker() != nullptr);
	REQUIRE(s.get_anker()->get_data() == 'a');
	REQUIRE(s.get_anker()->get_next() != nullptr);
	REQUIRE(s.get_anker()->get_next()->get_data() == 'b');
	REQUIRE(s.get_anker()->get_next()->get_next() != nullptr);
	REQUIRE(s.get_anker()->get_next()->get_next()->get_data() == 'c');
	REQUIRE(s.get_anker()->get_next()->get_next()->get_next() == nullptr);
}
