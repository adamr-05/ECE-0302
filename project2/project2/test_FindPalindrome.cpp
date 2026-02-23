#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

/*first i implemented the add function because that seemed the simplest and the valildations seemed easy for me to check using isalpha and checking uniqueness
with loops. i added the private methods here, i realized that i definitely need a vector to store all the data from the words and then thought of a way to
hold all the successful palindrome finds and determined i could create a vector of the vectors, to store all the ones that are palindromes. then i added some
testing cases to verify functionality of add. From here i realized implementing Number would be really simple with my design, only returning size of the
palindrome vector of vectors, where every vector of  vectors in it would be the palindrome.



/* Provided test cases */

TEST_CASE("Test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

/* Your test cases here */
TEST_CASE("test add method w/ string", "[FindPalindrome]")
{
	FindPalindrome b;
	REQUIRE(b.add("TEST")==true);
	REQUIRE(b.add("TEST")==false);
	REQUIRE(b.add("tESt")==true); //case sensitive adding works
	REQUIRE(b.add("test15].")==false);
	REQUIRE(b.add("testing")==true);
}

TEST_CASE("test add method w/ vector", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> v;
	for (int i = 0; i < 5; i++)
	{
		std::string q = "word";
		q = q + (char)('A' + i);	//trick where adding 0 to 'A' gives 'A', 1 to 'A' gives B, etc. cast to char and append to string
		v.push_back(q);
	}
	REQUIRE(b.add(v)==true);
	REQUIRE(b.number() == 0); // no palindromes
}
	


