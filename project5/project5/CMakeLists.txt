cmake_minimum_required(VERSION 3.10)
project(P5)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_FrontierQueue.cpp test_PuzzleSolver.cpp 
  FrontierQueue.hpp FrontierQueue.tpp 
  PuzzleSolver.hpp PuzzleSolver.cpp)

add_executable(test-frontier-queue test_FrontierQueue.cpp
  State.hpp State.tpp
  FrontierQueue.hpp FrontierQueue.tpp)

add_executable(test-solver test_PuzzleSolver.cpp
  Puzzle.hpp Puzzle.cpp
  State.hpp State.tpp
  FrontierQueue.hpp FrontierQueue.tpp
  PuzzleSolver.hpp PuzzleSolver.cpp)

enable_testing()
add_test(test-frontier test-frontier-queue)
add_test(test-solver test-solver)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/p5_puzzle_solver.zip" --format=zip
  ${SOURCE}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
