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

TEST_CASE("add duplicates", "[LimitedSizeBag]")
{
  LimitedSizeBag<int> bag;
  
  REQUIRE(bag.add(302) == true);
  REQUIRE(bag.add(302) == true);
  REQUIRE(bag.add(302) == true);

  REQUIRE(bag.getCurrentSize() == 3);
  REQUIRE(bag.contains(302) == true);
  REQUIRE(bag.getFrequencyOf(302) == 3);
}

TEST_CASE("add to max size", "[LimitedSizeBag]")
{
  LimitedSizeBag<int> bag;

  for (std::size_t i = 0; i < 100; i++)
  {
    REQUIRE(bag.add(i) == true);
  }

  //REQUIRE(bag.getCurrentSize() == LimitedSizeBag<int>::maxsize);
  REQUIRE(bag.getCurrentSize() == 100);

  REQUIRE_FALSE(bag.add(100) == true); // add fails when bag is full
  REQUIRE_FALSE(bag.contains(100) == true);
  REQUIRE_FALSE(bag.getCurrentSize() == 101);
}

TEST_CASE("remove item", "[LimitedSizeBag]")
{
  LimitedSizeBag<int> bag;

  REQUIRE(bag.add(102) == true);
  REQUIRE(bag.add(202) == true);
  REQUIRE(bag.add(302) == true);

  REQUIRE(bag.remove(302) == true);
  REQUIRE(bag.getCurrentSize() == 2);
  REQUIRE(bag.contains(302) == false);

  REQUIRE_FALSE(bag.remove(302) == true); //cant remove item that isnt there
}

TEST_CASE("clear bag", "[LimitedSizeBag]")
{
  LimitedSizeBag<int> bag;

  REQUIRE(bag.add(102) == true);
  REQUIRE(bag.add(202) == true);
  REQUIRE(bag.add(302) == true);

  bag.clear();

  REQUIRE(bag.isEmpty() == true);
  REQUIRE(bag.getCurrentSize() == 0);
  REQUIRE(bag.contains(302) == false);

  REQUIRE(bag.add(302) == true);
  REQUIRE(bag.isEmpty() == false);
  REQUIRE(bag.contains(302) == true);
  REQUIRE(bag.getCurrentSize() == 1);
}

TEST_CASE("test other types", "[LimitedSizeBag]")
{
  LimitedSizeBag<std::string> bag;

  REQUIRE(bag.add("hello") == true);
  REQUIRE(bag.add("how are you") == true);
  REQUIRE(bag.add("goodbye") == true);

  REQUIRE(bag.isEmpty() == false);
  REQUIRE(bag.getCurrentSize() == 3);
  REQUIRE(bag.contains("hello") == true);
  REQUIRE(bag.contains("how are you") == true);

  REQUIRE(bag.getFrequencyOf("hello") == 1);
  REQUIRE(bag.remove("hello") ==true);
  REQUIRE(bag.contains("hello") == false);

  bag.clear();

  REQUIRE(bag.isEmpty() == true);
}
  
