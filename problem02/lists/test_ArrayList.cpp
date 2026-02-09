#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ArrayList.hpp"


TEST_CASE( "Test isEmpty and getLength", "[ArrayList]" ) {

  ArrayList<int> list;
  REQUIRE(list.isEmpty() == true);
  REQUIRE(list.getLength() == 0);
}


TEST_CASE("Test insert", "[ArrayList]") {
  ArrayList<int> list;
  list.insert(0, 10);
  list.insert(1, 20);
  list.insert(1, 15);
  REQUIRE(list.getLength() == 3);
  REQUIRE(list.getEntry(0) == 10);
  REQUIRE(list.getEntry(1) == 15);
  REQUIRE(list.getEntry(2) == 20);
}

TEST_CASE("Test remove", "[ArrayList]") {
  ArrayList<int> list;
  list.insert(0, 10);
  list.insert(1, 20);
  list.insert(2, 30);
  list.remove(1);
  REQUIRE(list.getLength() == 2);
  REQUIRE(list.getEntry(0) == 10);
  REQUIRE(list.getEntry(1) == 30);
}

TEST_CASE("Test clear", "[ArrayList]") {
  ArrayList<int> list;
  list.insert(0, 10);
  list.insert(1, 20);
  list.clear();
  REQUIRE(list.isEmpty() == true);
  REQUIRE(list.getLength() == 0);
}

TEST_CASE("Test getEntry", "[ArrayList]") {
  ArrayList<int> list;
  list.insert(0, 10);
  list.insert(1, 20);
  REQUIRE(list.getEntry(0) == 10);
  REQUIRE(list.getEntry(1) == 20);
}

TEST_CASE("Test setEntry", "[ArrayList]") {
  ArrayList<int> list;
  list.insert(0, 10);
  list.setEntry(0, 100);
  REQUIRE(list.getEntry(0) == 100);
}

TEST_CASE("Test copy constructor", "[ArrayList]") {
  ArrayList<int> list1;
  list1.insert(0, 10);
  list1.insert(1, 20);
  
  ArrayList<int> list2(list1);
  REQUIRE(list2.getLength() == 2);
  REQUIRE(list2.getEntry(0) == 10);
  
  list1.setEntry(0, 100);
  REQUIRE(list2.getEntry(0) == 10);
}

TEST_CASE("Test assignment operator", "[ArrayList]") {
  ArrayList<int> list1;
  list1.insert(0, 10);
  list1.insert(1, 20);
  
  ArrayList<int> list2;
  list2 = list1;
  REQUIRE(list2.getLength() == 2);
  REQUIRE(list2.getEntry(0) == 10);
  
  list1.setEntry(0, 100);
  REQUIRE(list2.getEntry(0) == 10);
}
