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

TEST_CASE("Add edge to empty graph", "[add]") {
  Graph<int> g;
  REQUIRE(g.add(1, 2) == true);
  REQUIRE(g.getNumVertices() == 2);
  REQUIRE(g.getNumEdges() == 1);
}
 
TEST_CASE("Add edge with one existing vertex", "[add]") {
  Graph<int> g;
  g.add(1, 2);
  REQUIRE(g.add(2, 3) == true);
  REQUIRE(g.getNumVertices() == 3);
  REQUIRE(g.getNumEdges() == 2);
}
 
TEST_CASE("Reject self-loop", "[add]") {
  Graph<int> g;
  g.add(1, 2);
  REQUIRE(g.add(3, 3) == false);
}
 
TEST_CASE("Reject duplicate edge", "[add]") {
  Graph<int> g;
  g.add(1, 2);
  REQUIRE(g.add(1, 2) == false);
  REQUIRE(g.add(2, 1) == false);
  REQUIRE(g.getNumEdges() == 1);
}
 
TEST_CASE("Reject disconnected edge", "[add]") {
  Graph<int> g;
  g.add(1, 2);
  REQUIRE(g.add(3, 4) == false);
  REQUIRE(g.getNumVertices() == 2);
  REQUIRE(g.getNumEdges() == 1);
}
 
TEST_CASE("Build triangle graph", "[add]") {
  Graph<int> g;
  g.add(1, 2);
  g.add(2, 3);
  REQUIRE(g.add(1, 3) == true);
  REQUIRE(g.getNumVertices() == 3);
  REQUIRE(g.getNumEdges() == 3);
}
 
/* ---- remove() tests ---- */
 
TEST_CASE("Remove existing edge", "[remove]") {
  Graph<int> g;
  g.add(1, 2);
  g.add(2, 3);
  REQUIRE(g.remove(1, 2) == true);
  REQUIRE(g.getNumEdges() == 1);
}
 
TEST_CASE("Remove nonexistent edge", "[remove]") {
  Graph<int> g;
  g.add(1, 2);
  REQUIRE(g.remove(1, 3) == false);
  REQUIRE(g.remove(5, 6) == false);
}
 
TEST_CASE("Remove edge cleans up orphaned node", "[remove]") {
  Graph<int> g;
  g.add(1, 2);
  g.add(2, 3);
  g.remove(1, 2);
  // node 1 had only one edge, should be removed
  REQUIRE(g.getNumVertices() == 2);
}
 
TEST_CASE("Remove last edge empties graph", "[remove]") {
  Graph<int> g;
  g.add(1, 2);
  g.remove(1, 2);
  REQUIRE(g.getNumVertices() == 0);
  REQUIRE(g.getNumEdges() == 0);
}
 
TEST_CASE("Remove reversed order", "[remove]") {
  Graph<int> g;
  g.add(1, 2);
  REQUIRE(g.remove(2, 1) == true);
  REQUIRE(g.getNumEdges() == 0);
}
 
/* ---- traversal tests ---- */
 
std::vector<int> bfsOrder;
void bfsVisit(int& v) { bfsOrder.push_back(v); }
 
std::vector<int> dfsOrder;
void dfsVisit(int& v) { dfsOrder.push_back(v); }
 
TEST_CASE("BFS traversal order", "[bfs]") {
  Graph<int> g;
  g.add(1, 2);
  g.add(1, 3);
  g.add(2, 4);
  g.add(3, 4);
 
  bfsOrder.clear();
  g.breadthFirstTraversal(1, bfsVisit);
 
  // BFS from 1: visit 1, then neighbors 2,3 (ascending), then 4
  REQUIRE(bfsOrder.size() == 4);
  REQUIRE(bfsOrder[0] == 1);
  REQUIRE(bfsOrder[1] == 2);
  REQUIRE(bfsOrder[2] == 3);
  REQUIRE(bfsOrder[3] == 4);
}
 
TEST_CASE("DFS traversal order", "[dfs]") {
  Graph<int> g;
  g.add(1, 2);
  g.add(1, 3);
  g.add(2, 4);
  g.add(3, 4);
 
  dfsOrder.clear();
  g.depthFirstTraversal(1, dfsVisit);
 
  // DFS preorder from 1: visit 1, go to 2 (ascending), go to 4, then 3
  REQUIRE(dfsOrder.size() == 4);
  REQUIRE(dfsOrder[0] == 1);
  REQUIRE(dfsOrder[1] == 2);
  REQUIRE(dfsOrder[2] == 4);
  REQUIRE(dfsOrder[3] == 3);
}