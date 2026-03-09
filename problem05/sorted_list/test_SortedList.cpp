#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "SortedList.hpp"
#include "List.hpp"

/* Provided tests */
TEST_CASE("SortedList: Testing size", "[sorted list]") {
  SortedList<char> lst;

  REQUIRE(lst.isEmpty());
  REQUIRE(lst.getLength() == 0);

  lst.insert('b');
  REQUIRE(!lst.isEmpty());
  REQUIRE(lst.getLength() == 1);

  lst.insert('a');
  REQUIRE(lst.getLength() == 2);

  lst.removeAt(0);
  REQUIRE(lst.getLength() == 1);

  lst.removeAt(0);
  REQUIRE(lst.getLength() == 0);
  REQUIRE(lst.isEmpty());
}


TEST_CASE("SortedList: Testing insert", "[sorted list]") {
  SortedList<char> lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  bool getEntryCheck;
  for (int i = 0; i < 26; ++i) {
    getEntryCheck = (lst.getEntry(i) == 'a' + i);
    if (!getEntryCheck) {
      break;
    }
  }
  REQUIRE(getEntryCheck);
}


TEST_CASE("SortedList: Testing remove", "[sorted list]") {
  SortedList<char> lst;

  char c = 'a';
  int size = 10;
  while (c < 'a'+size) {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == size);

  lst.remove('c');
  REQUIRE(lst.getLength() == size-1);
  REQUIRE(lst.getEntry(2) == 'd');

  lst.remove('e');
  REQUIRE(lst.getLength() == size-2);
  REQUIRE(lst.getEntry(5) == 'h');

  lst.remove('a');
  REQUIRE(lst.getLength() == size-3);
  REQUIRE(lst.getEntry(0) == 'b');
}


TEST_CASE("SortedList: Testing getPosition", "[sorted list]") {
  SortedList<char> lst;
  
  lst.insert('a');
  lst.insert('d');
  lst.insert('e');
  lst.insert('c');
  lst.insert('b');

  REQUIRE(lst.getPosition('a') == 0);
  REQUIRE(lst.getPosition('b') == 1);
  REQUIRE(lst.getPosition('c') == 2);
  REQUIRE(lst.getPosition('d') == 3);
  REQUIRE(lst.getPosition('e') == 4);
}


TEST_CASE("Testing init from list", "[sorted list]") {
  List<char> unsorted;
  
  unsorted.insert(0,'a');
  unsorted.insert(1,'d');
  unsorted.insert(2,'e');
  unsorted.insert(3,'c');
  unsorted.insert(4,'b');

  SortedList<char> sorted(unsorted);

  REQUIRE(sorted.getPosition('a') == 0);
  REQUIRE(sorted.getPosition('b') == 1);
  REQUIRE(sorted.getPosition('c') == 2);
  REQUIRE(sorted.getPosition('d') == 3);
  REQUIRE(sorted.getPosition('e') == 4);
}

/* Your tests here */

/* Your tests here */

TEST_CASE("SortedList: Insert out of order integers", "[sorted list]") {
  SortedList<int> lst;

  lst.insert(5);
  lst.insert(1);
  lst.insert(3);
  lst.insert(2);
  lst.insert(4);

  REQUIRE(lst.getEntry(0) == 1);
  REQUIRE(lst.getEntry(1) == 2);
  REQUIRE(lst.getEntry(2) == 3);
  REQUIRE(lst.getEntry(3) == 4);
  REQUIRE(lst.getEntry(4) == 5);
}

TEST_CASE("SortedList: Insert duplicates", "[sorted list]") {
  SortedList<int> lst;

  lst.insert(3);
  lst.insert(1);
  lst.insert(3);
  lst.insert(1);
  lst.insert(2);

  REQUIRE(lst.getLength() == 5);
  REQUIRE(lst.getEntry(0) == 1);
  REQUIRE(lst.getEntry(1) == 1);
  REQUIRE(lst.getEntry(2) == 2);
  REQUIRE(lst.getEntry(3) == 3);
  REQUIRE(lst.getEntry(4) == 3);
}

TEST_CASE("SortedList: Remove throws when not found", "[sorted list]") {
  SortedList<int> lst;

  lst.insert(1);
  lst.insert(2);
  lst.insert(3);

  REQUIRE_THROWS_AS(lst.remove(5), std::invalid_argument);
}

TEST_CASE("SortedList: getPosition throws when not found", "[sorted list]") {
  SortedList<int> lst;

  lst.insert(1);
  lst.insert(2);

  REQUIRE_THROWS_AS(lst.getPosition(9), std::invalid_argument);
}

TEST_CASE("SortedList: Remove duplicates removes first only", "[sorted list]") {
  SortedList<int> lst;

  lst.insert(3);
  lst.insert(3);
  lst.insert(3);

  lst.remove(3);
  REQUIRE(lst.getLength() == 2);
  REQUIRE(lst.getEntry(0) == 3);
  REQUIRE(lst.getEntry(1) == 3);
}

TEST_CASE("SortedList: Clear", "[sorted list]") {
  SortedList<int> lst;

  lst.insert(5);
  lst.insert(2);
  lst.insert(8);
  lst.clear();

  REQUIRE(lst.isEmpty());
  REQUIRE(lst.getLength() == 0);
}

TEST_CASE("SortedList: Init from unsorted int list", "[sorted list]") {
  List<int> unsorted;

  unsorted.insert(0, 50);
  unsorted.insert(1, 10);
  unsorted.insert(2, 40);
  unsorted.insert(3, 20);
  unsorted.insert(4, 30);

  SortedList<int> sorted(unsorted);

  REQUIRE(sorted.getLength() == 5);
  REQUIRE(sorted.getEntry(0) == 10);
  REQUIRE(sorted.getEntry(1) == 20);
  REQUIRE(sorted.getEntry(2) == 30);
  REQUIRE(sorted.getEntry(3) == 40);
  REQUIRE(sorted.getEntry(4) == 50);
}

TEST_CASE("SortedList: Copy constructor", "[sorted list]") {
  SortedList<int> lst;

  lst.insert(3);
  lst.insert(1);
  lst.insert(2);

  SortedList<int> copy(lst);

  REQUIRE(copy.getLength() == 3);
  REQUIRE(copy.getEntry(0) == 1);
  REQUIRE(copy.getEntry(1) == 2);
  REQUIRE(copy.getEntry(2) == 3);
}

TEST_CASE("SortedList: Assignment operator", "[sorted list]") {
  SortedList<int> lst;
  lst.insert(3);
  lst.insert(1);

  SortedList<int> other;
  other.insert(9);

  other = lst;

  REQUIRE(other.getLength() == 2);
  REQUIRE(other.getEntry(0) == 1);
  REQUIRE(other.getEntry(1) == 3);
}

TEST_CASE("SortedList: Insert at beginning", "[sorted list]") {
  SortedList<int> lst;

  lst.insert(5);
  lst.insert(10);
  lst.insert(1);

  REQUIRE(lst.getEntry(0) == 1);
}

TEST_CASE("SortedList: Insert at end", "[sorted list]") {
  SortedList<int> lst;

  lst.insert(1);
  lst.insert(2);
  lst.insert(100);

  REQUIRE(lst.getEntry(2) == 100);
}

TEST_CASE("SortedList: getPosition returns first occurrence", "[sorted list]") {
  SortedList<int> lst;

  lst.insert(5);
  lst.insert(5);
  lst.insert(5);

  REQUIRE(lst.getPosition(5) == 0);
}

TEST_CASE("SortedList: removeAt", "[sorted list]") {
  SortedList<int> lst;

  lst.insert(1);
  lst.insert(2);
  lst.insert(3);

  lst.removeAt(1);
  REQUIRE(lst.getLength() == 2);
  REQUIRE(lst.getEntry(0) == 1);
  REQUIRE(lst.getEntry(1) == 3);
}