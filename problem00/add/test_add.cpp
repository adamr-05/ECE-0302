#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Add.hpp"

/* Provided tests */

TEST_CASE("Test add", "[Add]")
{

  Add<int> a;
  REQUIRE(a.call(1,2)==3);
}

/* Your tests here */

TEST_CASE("Test add with double", "[Add]") // should work with doubles too, doubles use decimal points
{
  Add<double> b;
  REQUIRE(b.call(1.5,2.5)==4.0);
}

TEST_CASE("Test add with string", "[Add]") // adding strings togethers concats them (concatenates) so one gets appended onto the other
{
  Add<std::string> c;
  REQUIRE(c.call("bat","man")=="batman");
}

TEST_CASE("Test add with char", "[Add]") // adding chars adds the ASCII values together, then casts back to hex
{
  Add<char> d;
  REQUIRE(d.call('A','!')==98); // ASCII values of 'A' and '!' are 65,33, which add up to 98.

  REQUIRE
    (
    static_cast<char>
    ( d.call('A','!') )  // converting this same value back to a char gives us ASCII value 98, which is lowercase b.
    == 'b'
    );
}