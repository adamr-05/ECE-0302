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
	
TEST_CASE("test add vector method", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> v;
	v.push_back("hello");
	v.push_back("world");
	REQUIRE(b.add(v) == true);

	// duplicate within vector should fail
	std::vector<std::string> v2;
	v2.push_back("test");
	v2.push_back("test");
	FindPalindrome c;
	REQUIRE(c.add(v2) == false);

	// duplicate against existing words should fail
	std::vector<std::string> v3;
	v3.push_back("hello");
	REQUIRE(b.add(v3) == false);

	// non-alpha in vector should fail
	std::vector<std::string> v4;
	v4.push_back("good");
	v4.push_back("bad1");
	FindPalindrome d;
	REQUIRE(d.add(v4) == false);
}

TEST_CASE("test clear method", "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("a");
	b.add("AA");
	b.add("AaA");
	REQUIRE(b.number() == 6);

	b.clear();
	REQUIRE(b.number() == 0);
	REQUIRE(b.toVector().empty());

	// can add again after clear
	REQUIRE(b.add("a") == true);
}

TEST_CASE("test number with no palindromes", "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("hello");
	b.add("world");
	REQUIRE(b.number() == 0);
}

TEST_CASE("test single word palindrome", "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("racecar");
	REQUIRE(b.number() == 1);
}

TEST_CASE("test toVector returns correct sentences", "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("a");
	b.add("b");
	b.add("a");  // should fail, duplicate
	REQUIRE(b.number() == 0);  // "ab" or "ba" not palindromes
}

TEST_CASE("test case insensitive palindrome", "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("Ab");
	b.add("bA");
	REQUIRE(b.number() == 2);  // "Ab bA" and "bA Ab" both palindromes
}

TEST_CASE("test add vector none added on failure", "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("exist");

	// vector with one bad word - none should be added
	std::vector<std::string> v;
	v.push_back("good");
	v.push_back("b4d");
	v.push_back("fine");
	REQUIRE(b.add(v) == false);

	// "good" and "fine" should NOT have been added
	REQUIRE(b.add("good") == true);
	REQUIRE(b.add("fine") == true);
}

TEST_CASE("test empty string", "[FindPalindrome]")
{
	FindPalindrome b;
	REQUIRE(b.add("") == false);  // no alpha chars
}

TEST_CASE("test add after palindromes recomputes", "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("a");
	REQUIRE(b.number() == 1);  // "a" is a palindrome

	b.add("b");
	REQUIRE(b.number() == 0);  // "ab" and "ba" are not palindromes
}

