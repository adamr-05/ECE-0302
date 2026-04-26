#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "Graph.hpp"

/* Provided test cases */
TEST_CASE("Test Construction", "[construction]") {
  Graph<int>  g;
  REQUIRE(g.getNumVertices() == 0);
}

/* Your test cases here */
