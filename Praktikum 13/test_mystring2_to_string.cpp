// Datei: test_mystring2_to_string.cpp

#define TEST_FILE test_mystring2_to_string

#include <string>

#include "gip_mini_catch.h"

#include "MyString2.h"

TEST_CASE("Pruefung der Methode std::string MyString2::to_string()")
{
	// MyString2::to_string() bei einem leeren MyString2
	MyString2 s1;
	REQUIRE(s1.to_string() == std::string(""));

	// MyString2::to_string() bei einem nicht-leeren MyString2
	MyString2 s2 = std::string("abc");
	REQUIRE(s2.to_string() == std::string("abc"));
}
