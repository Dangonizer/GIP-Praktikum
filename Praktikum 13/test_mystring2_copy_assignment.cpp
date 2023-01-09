// Datei: test_mystring2_copy_assignment.cpp

#define TEST_FILE test_mystring2_copy_assignment

#include "gip_mini_catch.h"

#include "CharListenKnoten.h"
#include "MyString2.h"

TEST_CASE("Pruefung des Copy-Konstruktors von MyString2") 
{
	int current_count = CharListenKnoten::object_count;

	MyString2 s = std::string{ "abc" };

	int id_a = s.get_anker()->get_my_id();
	int id_b = s.get_anker()->get_next()->get_my_id();
	int id_c = s.get_anker()->get_next()->get_next()->get_my_id();

	REQUIRE(CharListenKnoten::object_count == current_count + 3);

	MyString2 s2 = s;

	REQUIRE(CharListenKnoten::object_count == current_count + 6);
		
	REQUIRE(s2.get_anker() != nullptr);
	REQUIRE(s2.get_anker() != s.get_anker());
	REQUIRE(s2.get_anker()->get_data() == 'a');
	int id_1 = s2.get_anker()->get_my_id();
	REQUIRE((id_1 != id_a && id_1 != id_b && id_1 != id_c));

	REQUIRE(s2.get_anker()->get_next() != nullptr);
	REQUIRE(s2.get_anker()->get_next()->get_data() == 'b');
	REQUIRE(s2.get_anker()->get_next() != s.get_anker()->get_next());
	int id_2 = s2.get_anker()->get_next()->get_my_id();
	REQUIRE((id_2 != id_a && id_2 != id_b && id_2 != id_c && id_2 != id_1));

	REQUIRE(s2.get_anker()->get_next()->get_next() != nullptr);
	REQUIRE(s2.get_anker()->get_next()->get_next()->get_data() == 'c');
	REQUIRE(s2.get_anker()->get_next()->get_next() != s.get_anker()->get_next()->get_next());
	int id_3 = s2.get_anker()->get_next()->get_next()->get_my_id();
	REQUIRE((id_3 != id_a && id_3 != id_b && id_3 != id_c && id_3 != id_1 && id_3 != id_2));
	REQUIRE(s2.get_anker()->get_next()->get_next()->get_next() == nullptr);
}

TEST_CASE("Pruefung des Assignment Operators von MyString2") 
{
	int current_count = CharListenKnoten::object_count;

	MyString2 s = std::string{ "abc" };

	int id_a = s.get_anker()->get_my_id();
	int id_b = s.get_anker()->get_next()->get_my_id();
	int id_c = s.get_anker()->get_next()->get_next()->get_my_id();

	REQUIRE(CharListenKnoten::object_count == current_count + 3);

	MyString2 s2 = std::string{ "def" }; // ... mittels Copy-Konstruktor

	int id_1 = s2.get_anker()->get_my_id();
	int id_2 = s2.get_anker()->get_next()->get_my_id();
	int id_3 = s2.get_anker()->get_next()->get_next()->get_my_id();

	REQUIRE(CharListenKnoten::object_count == current_count + 6);

	s2 = s; // ... mittels Assignment-Operator

	// Gesamtzahl unverändert, da alter Wert freigegeben ...
	REQUIRE(CharListenKnoten::object_count == current_count + 6);

	REQUIRE(s2.get_anker() != nullptr);
	REQUIRE(s2.get_anker()->get_data() == 'a');
	int id_ass_1 = s2.get_anker()->get_my_id();
	REQUIRE((id_ass_1 != id_a && id_ass_1 != id_b && id_ass_1 != id_c &&
		id_ass_1 != id_1 && id_ass_1 != id_2 && id_ass_1 != id_3));

	REQUIRE(s2.get_anker()->get_next() != nullptr);
	REQUIRE(s2.get_anker()->get_next()->get_data() == 'b');
	int id_ass_2 = s2.get_anker()->get_next()->get_my_id();
	REQUIRE((id_ass_2 != id_a && id_ass_2 != id_b && id_ass_2 != id_c &&
		id_ass_2 != id_1 && id_ass_2 != id_2 && id_ass_2 != id_3 &&
		id_ass_2 != id_ass_1));


	REQUIRE(s2.get_anker()->get_next()->get_next() != nullptr);
	REQUIRE(s2.get_anker()->get_next()->get_next()->get_data() == 'c');
	int id_ass_3 = s2.get_anker()->get_next()->get_next()->get_my_id();
	REQUIRE((id_ass_3 != id_a && id_ass_3 != id_b && id_ass_3 != id_c &&
		id_ass_3 != id_1 && id_ass_3 != id_2 && id_ass_3 != id_3 &&
		id_ass_3 != id_ass_1 && id_ass_3 != id_ass_2));
	REQUIRE(s2.get_anker()->get_next()->get_next()->get_next() == nullptr);
}
