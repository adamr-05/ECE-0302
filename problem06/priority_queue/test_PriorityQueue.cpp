#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "List.hpp"
#include "SortedList.hpp"
#include "PriorityQueue.hpp"

typedef SortedList< int, List<int> > SortedListType;
typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

/* Provided test cases */
TEST_CASE("Priority: Testing List Iterator", "[iterator]") {
  // empty list
  List<int> lst;
  REQUIRE(lst.begin() == lst.end());

  // loop tests
  List<int> lst2;
  int size = 100;
  for (int i=0; i<size; i++) {
    lst2.insert(i,i+10);
  }

  // increment and dereference operators
  ListIterator<int> it = lst2.begin();
  int i=0;
  bool deref_increment_match = true;
  while (it != lst2.end()) {
    if(*it != i+10) {
      deref_increment_match = false;
      break;
    }
    ++it;
    i++;
  }
  REQUIRE(deref_increment_match);

  // range based loop
  bool range_based_match = true;
  int j=0;
  for (int item : lst2) {
    if(item != j+10) {
      range_based_match = false;
      break;
    }
    j++;
  }
  REQUIRE(range_based_match);

}

TEST_CASE("Priority: Testing Sorted List", "[sorted list]") {
  SortedList< int, List<int> >  sort;

  REQUIRE(sort.isEmpty());
  REQUIRE(sort.getLength() == 0);

  sort.insert(1);
  REQUIRE_FALSE(sort.isEmpty());
  REQUIRE(sort.getLength() == 1);
  sort.insert(2);
  REQUIRE(sort.getLength() == 2);
  sort.insert(8);
  REQUIRE(sort.getLength() == 3);
  sort.insert(6);
  REQUIRE(sort.getLength() == 4);
  sort.insert(9);
  REQUIRE(sort.getLength() == 5);
  sort.insert(0);
  REQUIRE(sort.getLength() == 6);

  REQUIRE(sort.getEntry(0) == 0);
  REQUIRE(sort.getPosition(0) == 0);
  REQUIRE(sort.getEntry(1) == 1);
  REQUIRE(sort.getPosition(1) == 1);
  REQUIRE(sort.getEntry(2) == 2);
  REQUIRE(sort.getPosition(2) == 2);
  REQUIRE(sort.getEntry(3) == 6);
  REQUIRE(sort.getPosition(6) == 3);
  REQUIRE(sort.getEntry(4) == 8);
  REQUIRE(sort.getPosition(8) == 4);
  REQUIRE(sort.getEntry(5) == 9);
  REQUIRE(sort.getPosition(9) == 5);
  
  sort.remove(0);
  REQUIRE(sort.getEntry(0) == 1);
  REQUIRE(sort.getLength() == 5);

  sort.remove(1);
  REQUIRE(sort.getEntry(0) == 2);
  REQUIRE(sort.getLength() == 4);

  sort.remove(9);
  REQUIRE(sort.getEntry(0) == 2);
  REQUIRE(sort.getLength() == 3);

  sort.removeAt(2);
  REQUIRE(sort.getEntry(0) == 2);
  REQUIRE(sort.getLength() == 2);

  sort.removeAt(0);
  REQUIRE(sort.getEntry(0) == 6);
  REQUIRE(sort.getLength() == 1);

  sort.removeAt(0);
  REQUIRE(sort.getLength() == 0);
  REQUIRE(sort.isEmpty());
  
}


TEST_CASE("Priority: Testing Priority Queue Add and isEmpty", "[priority queue]") {
  PriorityQueueType pq;

  REQUIRE(pq.isEmpty());

  pq.add(3);

  REQUIRE_FALSE(pq.isEmpty());
}

/* Your test cases here */

TEST_CASE("Priority Queue peek returns highest priority", "[priority queue]") {
  PriorityQueueType pq;
  pq.add(5);
  pq.add(10);
  pq.add(3);
  REQUIRE(pq.peek() == 10);
  pq.remove();
  REQUIRE(pq.peek() == 5);
  pq.remove();
  REQUIRE(pq.peek() == 3);
}

TEST_CASE("Priority Queue remove until empty", "[priority queue]") {
  PriorityQueueType pq;
  pq.add(1);
  pq.add(2);
  pq.remove();
  pq.remove();
  REQUIRE(pq.isEmpty());
}

TEST_CASE("Priority Queue throws on empty peek and remove", "[priority queue]") {
  PriorityQueueType pq;
  REQUIRE_THROWS_AS(pq.peek(), std::out_of_range);
  REQUIRE_THROWS_AS(pq.remove(), std::out_of_range);
}

TEST_CASE("Sorted List duplicate handling", "[sorted list]") {
  SortedListType sl;
  sl.insert(5);
  sl.insert(5);
  sl.insert(5);
  REQUIRE(sl.getLength() == 3);
  REQUIRE(sl.getEntry(0) == 5);
  REQUIRE(sl.getEntry(1) == 5);
  REQUIRE(sl.getEntry(2) == 5);

  sl.remove(5);
  REQUIRE(sl.getLength() == 2);
}

TEST_CASE("Sorted List throws on missing item", "[sorted list]") {
  SortedListType sl;
  sl.insert(1);
  REQUIRE_THROWS_AS(sl.remove(99), std::invalid_argument);
  REQUIRE_THROWS_AS(sl.getPosition(99), std::invalid_argument);
}

TEST_CASE("List throws on invalid positions", "[list]") {
  List<int> lst;
  REQUIRE_THROWS_AS(lst.remove(0), std::out_of_range);
  REQUIRE_THROWS_AS(lst.getEntry(0), std::out_of_range);
  REQUIRE_THROWS_AS(lst.setEntry(0, 5), std::out_of_range);
  REQUIRE_THROWS_AS(lst.insert(5, 10), std::out_of_range);
}

TEST_CASE("Priority Queue with negative values", "[priority queue]") {
  PriorityQueueType pq;
  pq.add(-3);
  pq.add(0);
  pq.add(-10);
  pq.add(7);
  REQUIRE(pq.peek() == 7);
  pq.remove();
  REQUIRE(pq.peek() == 0);
}