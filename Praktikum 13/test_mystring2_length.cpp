// Datei: test_mystring2_length.cpp

#define TEST_FILE test_mystring2_length

#include <string>

#include "gip_mini_catch.h"

#include "MyString2.h"

TEST_CASE("Pruefung der Methode unsigned int MyString2::length()")
{
	// MyString2::length() bei einem leeren MyString2
	MyString2 s1;
	REQUIRE(s1.length() == 0);

	// MyString2::length() bei einem nicht-leeren MyString2
	MyString2 s2 = std::string{"abc"};
	REQUIRE(s2.length() == 3);
}
