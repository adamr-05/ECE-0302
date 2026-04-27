#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "PuzzleSolver.hpp"

/* Provided tests */
TEST_CASE( "Solver: Test-0", "[PuzzleSolver]" ) {

  // same as goal puzzle configuration should have cost 0
  Puzzle puzzle1, puzzle2;
  REQUIRE(puzzle1.fromString("ABCDEFGH_"));
  REQUIRE(puzzle2.fromString("ABCDEFGH_"));
    
  {
    PuzzleSolver solver(puzzle1, puzzle2);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 0);
  }


  { // symmetric case
    PuzzleSolver solver(puzzle2, puzzle1);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 0);
  }
  
  
}


TEST_CASE( "Solver: Test-1", "[PuzzleSolver]" ) {

  Puzzle puzzle1, puzzle2;
  REQUIRE(puzzle1.fromString("ABCDEFGH_"));
  REQUIRE(puzzle2.fromString("ABCDEFG_H"));
    
  {
    PuzzleSolver solver(puzzle1, puzzle2);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 1);
  }

  { // symmetric case
    PuzzleSolver solver(puzzle2, puzzle1);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 1);
  }
}

TEST_CASE( "Solver: Test-2", "[PuzzleSolver]" ) {

  Puzzle puzzle1, puzzle2;
  REQUIRE(puzzle1.fromString("ABCDEFGH_"));
  REQUIRE(puzzle2.fromString("ABCDEF_GH"));
    
  {
    PuzzleSolver solver(puzzle1, puzzle2);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 2);
  }

  { // symmetric case
    PuzzleSolver solver(puzzle2, puzzle1);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 2);
  }
}

TEST_CASE( "Solver: Test-5", "[PuzzleSolver]" ) {

  Puzzle puzzle1, puzzle2;
  REQUIRE(puzzle1.fromString("ABCDEFGH_"));
  REQUIRE(puzzle2.fromString("B_CAEFDGH"));
    
  {
    PuzzleSolver solver(puzzle1, puzzle2);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 5);
  }

  { // symmetric case
    PuzzleSolver solver(puzzle2, puzzle1);
    bool found;
    std::size_t solution_cost;
    std::tie(found, solution_cost) = solver.search();
    
    REQUIRE(found);
    REQUIRE(solution_cost == 5);
  }
}
