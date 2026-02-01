#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "LimitedSizeBag.hpp"


TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}

TEST_CASE("bag is empty when created", "[LimitedSizeBag]")
{
  LimitedSizeBag<int> bag;

  REQUIRE(bag.isEmpty() == true);
  REQUIRE(bag.getCurrentSize() == 0);
}

TEST_CASE("add one item to bag", "[LimitedSizeBag]")
{
  LimitedSizeBag<int> bag;

  REQUIRE(bag.add(302) == true);
  REQUIRE(bag.isEmpty() == false);
  REQUIRE(bag.getCurrentSize() == 1);
  REQUIRE(bag.contains(302) == true);
}

TEST_CASE("add multiple bag items", "[LimitedSizeBag]")
{
  LimitedSizeBag<int> bag;

  REQUIRE(bag.add(102) == true);
  REQUIRE(bag.add(202) == true);
  REQUIRE(bag.add(302) == true);
  REQUIRE(bag.add(402) == true);

  REQUIRE(bag.getCurrentSize() == 4);
  REQUIRE(bag.isEmpty() == false);
  REQUIRE(bag.contains(102) == true);
  REQUIRE(bag.contains(202) == true);
  REQUIRE(bag.contains(302) == true);
  REQUIRE(bag.contains(402) == true);
}
