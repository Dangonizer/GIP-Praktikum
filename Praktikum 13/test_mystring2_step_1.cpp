// Datei: test_mystring2_step_1.cpp

#define TEST_FILE test_mystring2_step_1

#include "gip_mini_catch.h"

#include "CharListenKnoten.h"
#include "MyString2.h"

TEST_CASE("Pruefung der Methoden MyString2::get_anker() / CharListenKnoten::set_anker()") {

	MyString2 s;
	CharListenKnoten* k_ptr = new CharListenKnoten('a');

	REQUIRE(s.get_anker() == nullptr);

	s.set_anker(k_ptr);

	REQUIRE(s.get_anker() == k_ptr);

	delete k_ptr;
	s.set_anker(nullptr);
	REQUIRE(s.get_anker() == nullptr);
}
