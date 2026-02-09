#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "LinkedList.hpp"


TEST_CASE( "Test isEmpty and getLength", "[LinkedList]" ) {

    LinkedList<int> list;
    REQUIRE(list.isEmpty() == true);
    REQUIRE(list.getLength() == 0);
}

TEST_CASE("Test insert", "[LinkedList]") {
  LinkedList<int> list;
  list.insert(0, 10);
  list.insert(1, 20);
  list.insert(1, 15);
  REQUIRE(list.getLength() == 3);
  REQUIRE(list.getEntry(0) == 10);
  REQUIRE(list.getEntry(1) == 15);
  REQUIRE(list.getEntry(2) == 20);
}

TEST_CASE("Test remove", "[LinkedList]") {
  LinkedList<int> list;
  list.insert(0, 10);
  list.insert(1, 20);
  list.insert(2, 30);
  list.remove(1);
  REQUIRE(list.getLength() == 2);
  REQUIRE(list.getEntry(0) == 10);
  REQUIRE(list.getEntry(1) == 30);
}

TEST_CASE("Test clear", "[LinkedList]") {
  LinkedList<int> list;
  list.insert(0, 10);
  list.insert(1, 20);
  list.clear();
  REQUIRE(list.isEmpty() == true);
  REQUIRE(list.getLength() == 0);
}

TEST_CASE("Test getEntry", "[LinkedList]") {
  LinkedList<int> list;
  list.insert(0, 10);
  list.insert(1, 20);
  REQUIRE(list.getEntry(0) == 10);
  REQUIRE(list.getEntry(1) == 20);
}

TEST_CASE("Test setEntry", "[LinkedList]") {
  LinkedList<int> list;
  list.insert(0, 10);
  list.setEntry(0, 100);
  REQUIRE(list.getEntry(0) == 100);
}

TEST_CASE("Test copy constructor", "[LinkedList]") {
  LinkedList<int> list1;
  list1.insert(0, 10);
  list1.insert(1, 20);
  
  LinkedList<int> list2(list1);
  REQUIRE(list2.getLength() == 2);
  REQUIRE(list2.getEntry(0) == 10);
  
  list1.setEntry(0, 100);
  REQUIRE(list2.getEntry(0) == 10);
}

TEST_CASE("Test assignment operator", "[LinkedList]") {
  LinkedList<int> list1;
  list1.insert(0, 10);
  list1.insert(1, 20);
  
  LinkedList<int> list2;
  list2 = list1;
  REQUIRE(list2.getLength() == 2);
  REQUIRE(list2.getEntry(0) == 10);
  
  list1.setEntry(0, 100);
  REQUIRE(list2.getEntry(0) == 10);
}