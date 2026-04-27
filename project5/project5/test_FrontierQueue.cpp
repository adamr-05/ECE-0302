#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "FrontierQueue.hpp"

/* Provided test cases */
TEST_CASE("Simple push test", "[FrontierQueue]")
{
    FrontierQueue<int> fq;
    REQUIRE(fq.empty());

    fq.push(1, 0, 1);

    REQUIRE_FALSE(fq.empty());
    REQUIRE(fq.contains(1));
}

TEST_CASE("Simple contains test", "[FrontierQueue]")
{
    FrontierQueue<int> fq;

    REQUIRE_FALSE(fq.contains(1));
    REQUIRE_FALSE(fq.contains(2));

    fq.push(1, 1, 1);
    fq.push(2, 2, 2);

    REQUIRE(fq.contains(1));
    REQUIRE(fq.contains(2));
    REQUIRE_FALSE(fq.contains(3));
}

TEST_CASE("Simple pop test", "[FrontierQueue]")
{
    FrontierQueue<int> fq;
    
    fq.push(1, 1, 1);

    State<int> state = fq.pop();
    REQUIRE(state.getValue() == 1);
    REQUIRE(state.getPathCost() == 1);
    REQUIRE(state.getFCost() == 2);
    REQUIRE(fq.empty());
}

TEST_CASE("Simple replaceif test", "[FrontierQueue]")
{
    FrontierQueue<int> fq;

    fq.push(1, 100, 100);

    fq.replaceif(1, 1);
    State<int> state = fq.pop();
    REQUIRE(state.getValue() == 1);
    REQUIRE(state.getPathCost() == 1);
    REQUIRE(state.getFCost() == 101);
}


/* Your test cases here */

TEST_CASE("Pop returns lowest f-cost", "[FrontierQueue]")
{
    FrontierQueue<int> fq;
    fq.push(1, 5, 5);  // f=10
    fq.push(2, 1, 1);  // f=2
    fq.push(3, 3, 3);  // f=6
 
    State<int> state = fq.pop();
    REQUIRE(state.getValue() == 2);
    REQUIRE(state.getFCost() == 2);
}
 
TEST_CASE("Pop order is ascending by f-cost", "[FrontierQueue]")
{
    FrontierQueue<int> fq;
    fq.push(10, 5, 5);  // f=10
    fq.push(20, 1, 2);  // f=3
    fq.push(30, 2, 1);  // f=3
    fq.push(40, 0, 1);  // f=1
 
    State<int> s1 = fq.pop();
    REQUIRE(s1.getFCost() == 1);
 
    State<int> s2 = fq.pop();
    REQUIRE(s2.getFCost() == 3);
 
    State<int> s3 = fq.pop();
    REQUIRE(s3.getFCost() == 3);
 
    State<int> s4 = fq.pop();
    REQUIRE(s4.getFCost() == 10);
 
    REQUIRE(fq.empty());
}
 
TEST_CASE("Contains returns false after pop", "[FrontierQueue]")
{
    FrontierQueue<int> fq;
    fq.push(1, 1, 1);
    fq.push(2, 2, 2);
 
    fq.pop();
    // popped lowest f-cost (value 1, f=2)
    REQUIRE_FALSE(fq.contains(1));
    REQUIRE(fq.contains(2));
}
 
TEST_CASE("Replaceif does nothing when cost is not lower", "[FrontierQueue]")
{
    FrontierQueue<int> fq;
    fq.push(1, 5, 5);
 
    fq.replaceif(1, 10);  // 10 > 5, should not replace
    State<int> state = fq.pop();
    REQUIRE(state.getPathCost() == 5);
}
 
TEST_CASE("Replaceif does nothing when value not found", "[FrontierQueue]")
{
    FrontierQueue<int> fq;
    fq.push(1, 5, 5);
 
    fq.replaceif(99, 1);  // value 99 not in queue
    REQUIRE(fq.contains(1));
    REQUIRE_FALSE(fq.contains(99));
}
 
TEST_CASE("Replaceif updates heap order", "[FrontierQueue]")
{
    FrontierQueue<int> fq;
    fq.push(1, 10, 1);  // f=11
    fq.push(2, 1, 1);   // f=2
 
    // replace value 1's cost from 10 to 0, new f=1
    fq.replaceif(1, 0);
 
    // now value 1 should pop first since f=1 < f=2
    State<int> state = fq.pop();
    REQUIRE(state.getValue() == 1);
    REQUIRE(state.getFCost() == 1);
}
 
TEST_CASE("Push and pop single element", "[FrontierQueue]")
{
    FrontierQueue<int> fq;
    fq.push(42, 3, 7);
 
    State<int> state = fq.pop();
    REQUIRE(state.getValue() == 42);
    REQUIRE(state.getPathCost() == 3);
    REQUIRE(state.getFCost() == 10);
    REQUIRE(fq.empty());
}