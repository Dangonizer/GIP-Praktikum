// Datei: test_mystring2_operator_plus.cpp

#define TEST_FILE test_mystring2_operator_plus

#include "gip_mini_catch.h"

#include "MyString2.h"

TEST_CASE("Pruefung der Methode MyString2 MyString2::operator+(char c)") {

	MyString2 s;

	MyString2 s2 = s + 'x';
	REQUIRE(s2.get_anker() != nullptr);
	REQUIRE(s2.get_anker()->get_data() == 'x');
	REQUIRE(s2.get_anker()->get_next() == nullptr);
	REQUIRE(s2.length() == 1);
	REQUIRE(s2.get_anker() != s.get_anker());

	MyString2 s3 = s2 + 'y';
	REQUIRE(s3.get_anker() != nullptr);
	REQUIRE(s3.get_anker()->get_data() == 'x');
	REQUIRE(s3.get_anker()->get_next() != nullptr);
	REQUIRE(s3.get_anker()->get_next()->get_data() == 'y');
	REQUIRE(s3.get_anker()->get_next()->get_next() == nullptr);
	REQUIRE(s3.length() == 2);
	REQUIRE(s3.get_anker() != s2.get_anker());
	REQUIRE(s3.get_anker()->get_next() != s2.get_anker()->get_next());

}
