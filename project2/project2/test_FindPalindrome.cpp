#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

/* Provided test cases */

TEST_CASE("Test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

/* Your test cases here */
TEST_CASE("test add method", "[FindPalindrome]")
{
	FindPalindrome b;
	REQUIRE(b.add("TEST")==true);
	REQUIRE(b.add("TEST")==false);
	REQUIRE(b.add("tESt")==true); //case sensitive adding works
	REQUIRE(b.add("test15].")==false);
	REQUIRE(b.add("testing")==true);
}


