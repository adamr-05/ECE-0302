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

TEST_CASE("Test add double", "[Add]")
{
  Add<double> b;
  REQUIRE(b.call(1.5,2.5)==4.0);
}