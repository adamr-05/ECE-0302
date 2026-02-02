#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "DynamicBag.hpp"


TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}

TEST_CASE("test bag is initialized empty", "[DynamicBag]")
{
  DynamicBag<int> bag;

  REQUIRE(bag.isEmpty() == true); //bag empty
  REQUIRE(bag.getCurrentSize() == 0);//bag size is 0
}

TEST_CASE("add items--no size limit", "[DynamicBag]")
{
  DynamicBag<int> bag;

  for (int i = 0; i < 1245; i++)
  {
    REQUIRE(bag.add(i) == true); // adding large amount of items works
  }

  REQUIRE(bag.getCurrentSize() == 1245); // size correct
  REQUIRE(bag.contains(567) == true); //contains number
  REQUIRE(bag.contains(1244) == true); //contains highest number
}

TEST_CASE("test remove items", "[DynamicBag]")
{
  DynamicBag<int> bag;
  bag.add(15);
  bag.add(30);

  REQUIRE(bag.remove(15) == true); // remove works
  REQUIRE(bag.contains(15) == false); //doesnt contain removed item
  REQUIRE(bag.remove(1359) == false); // cant remove nonexistent item
  REQUIRE(bag.getCurrentSize() == 1); //remove item changes size
}

TEST_CASE("test clear", "[DynamicBag]")
{
  DynamicBag<int> bag;
  bag.add(61);
  bag.add(62);
  bag.add(63);
  bag.clear(); //clear all items

  REQUIRE(bag.isEmpty() == true); // after clearing bag is emtpy
  REQUIRE(bag.getCurrentSize() == 0); // size is 0
}

TEST_CASE("test frequency", "[DynamicBag]")
{
  DynamicBag<int> bag;
  bag.add(61);
  bag.add(62);
  bag.add(63);
  bag.add(62);
  bag.add(63);
  bag.add(63);

  REQUIRE(bag.getFrequencyOf(61) == 1); //frequency works with elements of different amounts of occurences
  REQUIRE(bag.getFrequencyOf(62) == 2);
  REQUIRE(bag.getFrequencyOf(63) == 3);
}
  
TEST_CASE("test contain", "[DynamicBag]")
{
  DynamicBag<int> bag;

  bag.add(42);

  REQUIRE(bag.contains(42) == true);
  REQUIRE(bag.contains(41) == false);
}

TEST_CASE("test copy constructor", "[DynamicBag]")
{
  DynamicBag<int> bag1;
  bag1.add(41);
  bag1.add(42);
  bag1.add(43); // create bag1 and add elements

  DynamicBag<int> bag2 = bag1; // construct bag2 based on copy of bag1

  REQUIRE(bag2.getCurrentSize() == 3); //bag 2 passes tests of bag1
  REQUIRE(bag2.contains(42) == true);

  bag1.clear();

  //after clearing bag1, bag2 should remain unaffected, showing independency
  REQUIRE(bag2.getCurrentSize() == 3); 
  REQUIRE(bag2.contains(42) == true);
}

TEST_CASE("test copy assignment operator", "[DynamicBag]")
{
  DynamicBag<int> bag1;
  bag1.add(302);
  bag1.add(402);

  DynamicBag<int> bag2;
  bag2.add(31531985);

  bag2 = bag1; // set already constructed bag2 to bag1

  REQUIRE(bag2.getCurrentSize() == 2); //bag 2 now passes all test; is identical to bag1
  REQUIRE(bag2.contains(302) == true);
  REQUIRE(bag2.contains(402) == true);
  REQUIRE(bag2.contains(31531985) == false);


  bag1.clear(); //after clearing bag1, bag2 stays same
  REQUIRE(bag2.getCurrentSize() == 2);
}

TEST_CASE("test other data types", "[DynamicBag]")
{
  DynamicBag<std::string> bagString;
  bagString.add("this is");
  bagString.add("a test");
  REQUIRE(bagString.getCurrentSize() == 2);
  REQUIRE(bagString.contains("this is") == true);
  REQUIRE(bagString.contains("a test") == true);

  DynamicBag<double> bagDouble;
  bagDouble.add(1.21);
  bagDouble.add(42);
  bagDouble.add(0.0015);
  REQUIRE(bagDouble.getCurrentSize() == 3);
  REQUIRE(bagDouble.contains(1.21) == true);
  REQUIRE(bagDouble.contains(42) == true);
  REQUIRE(bagDouble.contains(0.0015) == true);
}
