#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "List.hpp"
#include "Queue.hpp"

/* Provided test cases */
TEST_CASE("Queue: Testing Enqueue", "[queue]") {

  Queue<int, List<int>> queue;

  REQUIRE(queue.isEmpty());
  queue.enqueue(12);
  REQUIRE_FALSE(queue.isEmpty());

}

/* Your test cases here */

TEST_CASE("Queue: Testing peekFront", "[queue]") {
  Queue<int, List<int>> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  REQUIRE(queue.peekFront() == 1);
}

TEST_CASE("Queue: Testing Dequeue", "[queue]") {
  Queue<int, List<int>> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.dequeue();
  REQUIRE(queue.peekFront() == 2);
  queue.dequeue();
  REQUIRE(queue.peekFront() == 3);
}

TEST_CASE("Queue: Testing FIFO order", "[queue]") {
  Queue<int, List<int>> queue;
  for (int i = 0; i < 5; i++) {
    queue.enqueue(i);
  }
  for (int i = 0; i < 5; i++) {
    REQUIRE(queue.peekFront() == i);
    queue.dequeue();
  }
  REQUIRE(queue.isEmpty());
}

TEST_CASE("Queue: Dequeue on empty throws", "[queue]") {
  Queue<int, List<int>> queue;
  REQUIRE_THROWS_AS(queue.dequeue(), std::out_of_range);
}

TEST_CASE("Queue: peekFront on empty throws", "[queue]") {
  Queue<int, List<int>> queue;
  REQUIRE_THROWS_AS(queue.peekFront(), std::out_of_range);
}