// Datei: test_mystring2_at.cpp

#define TEST_FILE test_mystring2_at

#include <string>

#include "gip_mini_catch.h"

#include "MyString2.h"

TEST_CASE("Pruefung der Methode char MyString2::at(unsigned int pos)")
{
	// MyString2::at() bei einem leeren MyString2
	MyString2 s1;
	REQUIRE(s1.at(0) == '\0');
	REQUIRE(s1.at(99) == '\0');

	// MyString2::at() bei einem nicht-leeren MyString2
	MyString2 s2 = std::string{"abc"};
	REQUIRE(s2.at(0) == 'a');
	REQUIRE(s2.at(1) == 'b');
	REQUIRE(s2.at(2) == 'c');
	REQUIRE(s2.at(3) == '\0');
	REQUIRE(s2.at(4) == '\0');
	REQUIRE(s2.at(5) == '\0');
	REQUIRE(s2.at(99) == '\0');
}
