#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "List.hpp"
#include "sort.hpp"

/* Provided test cases */
TEST_CASE("Sort: Test move entry", "[sorting]") {
  List<int> lst;

  lst.insert(0, 100);
  lst.insert(1, 4);
  lst.insert(2, 10);
  lst.insert(3, 25);
  lst.insert(4, 11);

  // move forward
  lst.moveEntry(0, 2);

  REQUIRE(lst.getLength() == 5);
  REQUIRE(lst.getEntry(0) == 4);
  REQUIRE(lst.getEntry(1) == 10);
  REQUIRE(lst.getEntry(2) == 100);
  REQUIRE(lst.getEntry(3) == 25);
  REQUIRE(lst.getEntry(4) == 11);

  // move backward
  lst.moveEntry(4, 0);

  REQUIRE(lst.getLength() == 5);
  REQUIRE(lst.getEntry(0) == 11);
  REQUIRE(lst.getEntry(1) == 4);
  REQUIRE(lst.getEntry(2) == 10);
  REQUIRE(lst.getEntry(3) == 100);
  REQUIRE(lst.getEntry(4) == 25);

  // invalid moves
  REQUIRE_THROWS_AS(lst.moveEntry(5,0), std::out_of_range);
  REQUIRE_THROWS_AS(lst.moveEntry(0,5), std::out_of_range);
}


TEST_CASE("Sort: Integer sorting", "[sorting]"){

  List<int> lst;

  lst.insert(0, 100);
  lst.insert(1, 25);
  lst.insert(2, 10);
  lst.insert(3, 4);
  lst.insert(4, 11);

  quick_sort(lst, 0, lst.getLength()-1);

  // check sorted list
  REQUIRE(lst.getEntry(0) == 4);
  REQUIRE(lst.getEntry(1) == 10);
  REQUIRE(lst.getEntry(2) == 11);
  REQUIRE(lst.getEntry(3) == 25);
  REQUIRE(lst.getEntry(4) == 100);
}

TEST_CASE("Sort: Test partitioning", "[sorting]") {
    List<int> lst;
  
    lst.insert(0, 100);
    lst.insert(1, 30);
    lst.insert(2, 50);
    lst.insert(3, 4);
    lst.insert(4, 256);
    lst.insert(5, 1);
    lst.insert(6, 0);
    lst.insert(7, 25);
    lst.insert(8, 10);
    lst.insert(9, 512);
  
    // partition whole list
    int test = partition(lst, 0, lst.getLength()-1);
    // first item (100) should now be at index 7
    REQUIRE(test == 7);
}

/* Your test cases here */

TEST_CASE("Sort: Single element list", "[sorting]") {
  List<int> lst;

  lst.insert(0, 42);

  // single element list should already be sorted
  quick_sort(lst, 0, lst.getLength()-1);

  REQUIRE(lst.getLength() == 1);
  REQUIRE(lst.getEntry(0) == 42);
}

TEST_CASE("Sort: Two element list", "[sorting]") {
  List<int> lst;

  lst.insert(0, 99);
  lst.insert(1, 3);

  quick_sort(lst, 0, lst.getLength()-1);

  REQUIRE(lst.getLength() == 2);
  REQUIRE(lst.getEntry(0) == 3);
  REQUIRE(lst.getEntry(1) == 99);
}

TEST_CASE("Sort: Already sorted list", "[sorting]") {
  List<int> lst;

  lst.insert(0, 1);
  lst.insert(1, 2);
  lst.insert(2, 3);
  lst.insert(3, 4);
  lst.insert(4, 5);

  quick_sort(lst, 0, lst.getLength()-1);

  REQUIRE(lst.getEntry(0) == 1);
  REQUIRE(lst.getEntry(1) == 2);
  REQUIRE(lst.getEntry(2) == 3);
  REQUIRE(lst.getEntry(3) == 4);
  REQUIRE(lst.getEntry(4) == 5);
}

TEST_CASE("Sort: Reverse sorted list", "[sorting]") {
  List<int> lst;

  lst.insert(0, 5);
  lst.insert(1, 4);
  lst.insert(2, 3);
  lst.insert(3, 2);
  lst.insert(4, 1);

  quick_sort(lst, 0, lst.getLength()-1);

  REQUIRE(lst.getEntry(0) == 1);
  REQUIRE(lst.getEntry(1) == 2);
  REQUIRE(lst.getEntry(2) == 3);
  REQUIRE(lst.getEntry(3) == 4);
  REQUIRE(lst.getEntry(4) == 5);
}

TEST_CASE("Sort: Character sorting", "[sorting]") {
  List<char> lst;

  lst.insert(0, 'z');
  lst.insert(1, 'a');
  lst.insert(2, 'm');
  lst.insert(3, 'f');
  lst.insert(4, 'b');

  quick_sort(lst, 0, lst.getLength()-1);

  // should be sorted alphabetically
  REQUIRE(lst.getEntry(0) == 'a');
  REQUIRE(lst.getEntry(1) == 'b');
  REQUIRE(lst.getEntry(2) == 'f');
  REQUIRE(lst.getEntry(3) == 'm');
  REQUIRE(lst.getEntry(4) == 'z');
}

TEST_CASE("Sort: String sorting", "[sorting]") {
  List<std::string> lst;

  lst.insert(0, "banana");
  lst.insert(1, "apple");
  lst.insert(2, "mango");
  lst.insert(3, "cherry");
  lst.insert(4, "blueberry");

  quick_sort(lst, 0, lst.getLength()-1);

  // should be sorted alphabetically
  REQUIRE(lst.getEntry(0) == "apple");
  REQUIRE(lst.getEntry(1) == "banana");
  REQUIRE(lst.getEntry(2) == "blueberry");
  REQUIRE(lst.getEntry(3) == "cherry");
  REQUIRE(lst.getEntry(4) == "mango");
}

TEST_CASE("Sort: Large integer list", "[sorting]") {
  List<int> lst;

  lst.insert(0, 500);
  lst.insert(1, 23);
  lst.insert(2, 987);
  lst.insert(3, 1);
  lst.insert(4, 76);
  lst.insert(5, 334);
  lst.insert(6, 12);
  lst.insert(7, 654);
  lst.insert(8, 45);
  lst.insert(9, 210);

  quick_sort(lst, 0, lst.getLength()-1);

  REQUIRE(lst.getEntry(0) == 1);
  REQUIRE(lst.getEntry(1) == 12);
  REQUIRE(lst.getEntry(2) == 23);
  REQUIRE(lst.getEntry(3) == 45);
  REQUIRE(lst.getEntry(4) == 76);
  REQUIRE(lst.getEntry(5) == 210);
  REQUIRE(lst.getEntry(6) == 334);
  REQUIRE(lst.getEntry(7) == 500);
  REQUIRE(lst.getEntry(8) == 654);
  REQUIRE(lst.getEntry(9) == 987);
}