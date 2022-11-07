// Datei: test_suchen_rekursiv.cpp

#include "catch.h"
#include "suchen_rekursiv.h"

TEST_CASE("Zeichenkette suchen, Text mit Laenge groesser 1, Zeichenkette mit Laenge groesser 1")
{
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "cda") == 2);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "de") == 7);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "dex") == -1);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "xyz") == -1);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "abcdabcd") == 0);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "abcdabcdx") == -1);
}

TEST_CASE("Zeichenkette suchen, Text mit Laenge groesser 1, Zeichenkette mit Laenge 1")
{
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "a") == 0);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "c") == 2);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "e") == 8);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdabcde", "x") == -1);
}

TEST_CASE("Zeichenkette suchen, Text mit Laenge 1")
{
	REQUIRE(zeichenkette_suchen_rekursiv("a", "a") == 0);
	REQUIRE(zeichenkette_suchen_rekursiv("a", "c") == -1);
	REQUIRE(zeichenkette_suchen_rekursiv("a", "xy") == -1);
	REQUIRE(zeichenkette_suchen_rekursiv("a", "aa") == -1);
}

TEST_CASE("Zeichenkette suchen, leerer Text")
{
	REQUIRE(zeichenkette_suchen_rekursiv("", "a") == -1);
	REQUIRE(zeichenkette_suchen_rekursiv("", "abc") == -1);
}

TEST_CASE("Zeichenkette suchen, Text mit Laenge 20 Zeichen")
{
	REQUIRE(zeichenkette_suchen_rekursiv("abcdefghij1234567890", "90") == 18);
	REQUIRE(zeichenkette_suchen_rekursiv("12345678901234567890", "90") == 8);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdefghij1234567890", "9012") == -1);
}

TEST_CASE("Zeichenkette suchen, langer Prefix")
{
	REQUIRE(zeichenkette_suchen_rekursiv("aaaaaaabcdef", "aaabcd") == 4);
}

// Vorgegebene Testl�ufe m�ssen selbst als Testcases programmiert werden ...
TEST_CASE("Vorgegebene Testlaeufe")
{
	REQUIRE(zeichenkette_suchen_rekursiv("abcdefg", "bcd99") == -1);
	REQUIRE(zeichenkette_suchen_rekursiv("xy abc abcdefgh", "abcde") == 7);
	REQUIRE(zeichenkette_suchen_rekursiv("xyz 123 456 abc", "123 4") == 4);
	REQUIRE(zeichenkette_suchen_rekursiv("abc defg", "abc d") == 0);
	REQUIRE(zeichenkette_suchen_rekursiv("abcdefg", "efg") == 4);
}
